#define _POSIX_C_SOURCE 199309L //required for clock
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <limits.h>
#include <fcntl.h>
#include <time.h>
#include <pthread.h>
#include <inttypes.h>
#include <math.h>
int * shareMem(size_t size)
{   
	key_t mem_key = IPC_PRIVATE;
	int shm_id = shmget(mem_key, size, IPC_CREAT | 0666);
	return (int*)shmat(shm_id, NULL, 0);
}
void swap(int * a,int * b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
int partition(int *arr,int low,int high)
{
	int pivot;
	pivot=high;
	int i=low-1;
	for(int j=low;j<high;j++)
	{
		if(arr[j]<arr[pivot])
		{
			i++;
			swap(&arr[j],&arr[i]);
		}
	}
	swap(&arr[i+1],&arr[pivot]);
	return (i+1);
}
void normal_quicksort(int * arr,int low,int high)
{
	if(low>high)
	{
		return;
	}
	else if(high-low+1<=5)
	{
		int mi=INT_MAX, mid=-1;
		for(int i=low;i<high;i++)
		{
			int j=i+1; 
			for(;j<=high;j++)            
				if(arr[j]<arr[i] && j<=high) 
				{
					int temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
		}
		return;
	}
	else
	{
		int p=partition(arr,low,high);
		normal_quicksort(arr,low,p-1);
		normal_quicksort(arr,p+1,high);
	}
}
void conc_quicksort(int *arr,int low,int high)
{
	if(low>high)
	{
		return;
	}
	if(high-low+1<=5)
	{
		int mi=INT_MAX, mid=-1;
		for(int i=low;i<high;i++)
		{
			int j=i+1; 
			for(;j<=high;j++)
				if(arr[j]<arr[i] && j<=high) 
				{
					swap(&arr[i],&arr[j]);
				}
		}
		return;
	} 
	int pid1 = fork();
	int pid2;
	int p;
	p=partition(arr,low,high);
	if(pid1==0)
	{
		//sort left half array
		//p=partition(arr,low,high);
		conc_quicksort(arr,low,p-1);
		_exit(1);
	}
	else
	{
		pid2 = fork();
		if(pid2==0)
		{
			//sort right half array
			conc_quicksort(arr,p+1,high);
			_exit(1);
		}
		else
		{
			//wait for the right and the left half to get sorted
			int status;
			waitpid(pid1, &status, 0);
			waitpid(pid2, &status, 0);
		}
	}                                          
	return;
}
struct arg
{
	int l;
	int r;
	int* arr;    
};
void *threaded_quicksort(void* a)
{
	//note that we are passing a struct to the threads for simplicity.
	struct arg *args = (struct arg*) a;

	int l = args->l;
	int r = args->r;
	int *arr = args->arr;
	if(l>r) return NULL;    

	//insertion sort
	if(r-l+1<=5)
	{
		int a[5], mi=INT_MAX, mid=-1;
		for(int i=l;i<r;i++)
		{
			int j=i+1; 
			for(;j<=r;j++)            
				if(arr[j]<arr[i] && j<=r) 
				{
					int temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
		}
		return NULL;
	}
	int p=partition(arr,l,r);
	//sort left half array
	struct arg a1;
	a1.l = l;
	a1.r = p-1;
	a1.arr = arr;
	pthread_t tid1;
	pthread_create(&tid1, NULL, threaded_quicksort, &a1);

	//sort right half array
	struct arg a2;
	a2.l = p+1;
	a2.r = r;
	a2.arr = arr;
	pthread_t tid2;
	pthread_create(&tid2, NULL, threaded_quicksort, &a2);

	//wait for the two halves to get sorted
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

}

void runSorts(int n)
{
	struct timespec ts;
	int *arr = shareMem(sizeof(int)*(n+1));
	for(int i=0;i<n;i++)
	{
		scanf("%d", arr+i);
	}
	int brr[n+1];
	int crr[n+1];
	for(int i=0;i<n;i++) 
	{
		brr[i]=arr[i];
		crr[i]=arr[i];
	}
	printf("Running concurrent_quicksort for n = %d\n", n);
	clock_gettime(CLOCK_MONOTONIC_RAW,&ts);
	long double st = ts.tv_nsec/(1e9)+ts.tv_sec;
	//multiprocess quicksort
	conc_quicksort(arr,0,n-1);
	clock_gettime(CLOCK_MONOTONIC_RAW,&ts);
	long double en = ts.tv_nsec/(1e9)+ts.tv_sec;
	printf("time = %Lf\n", en - st);
	long double t1 = en-st;
	/*for(int i=0;i<n;i++)
	  {
	  printf("%d ",*(arr+i));
	  }
	  printf("\n");*/

	pthread_t tid;
	struct arg a;
	a.l = 0;
	a.r = n-1;
	a.arr = brr;
	printf("Running threaded_concurrent_quicksort for n = %d\n", n);
	clock_gettime(CLOCK_MONOTONIC_RAW, &ts);
	st = ts.tv_nsec/(1e9)+ts.tv_sec;
	//multithreaded quicksort
	pthread_create(&tid, NULL, threaded_quicksort, &a);
	pthread_join(tid, NULL);    

	clock_gettime(CLOCK_MONOTONIC_RAW, &ts);
	en = ts.tv_nsec/(1e9)+ts.tv_sec;
	printf("time = %Lf\n", en - st);
	long double t2 = en-st;
	/*for(int i=0;i<n;i++)
	  {
	  printf("%d ",*(brr+i));
	  }
	  printf("\n");*/


	printf("Running normal_quicksort for n = %d\n",n);
	clock_gettime(CLOCK_MONOTONIC_RAW,&ts);
	st = ts.tv_nsec/(1e9)+ts.tv_sec;
	// normal quicksort
	normal_quicksort(crr, 0, n-1);      
	clock_gettime(CLOCK_MONOTONIC_RAW, &ts);
	en = ts.tv_nsec/(1e9)+ts.tv_sec;
	printf("time = %Lf\n", en - st);
	long double t3 = en - st;
	/* for(int i=0;i<n;i++)
	   {
	   printf("%d ",*(crr+i));
	   }
	   printf("\n");*/
	shmdt(arr);

	printf("normal_quicksort ran:\n\t[ %Lf ] times faster than concurrent_quicksort\n\t[ %Lf ] times faster than threaded_concurrent_quicksort\n", t1/t3, t2/t3);
	return;
}
int main(void)
{
	int n;
	scanf("%d", &n);
	runSorts(n);
	return 0;
}
