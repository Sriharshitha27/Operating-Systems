#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#define WAITING 0
#define SERVED 1
int M,N,K;
pthread_t chef_thread[10000];
pthread_t serve_table[10000];
pthread_t students[10000];
pthread_mutex_t mutex1;
pthread_mutex_t mutex2;
typedef struct chef
{
	int r;
	int w;
	int p;
}Chef;
Chef chef[10000];
typedef struct container
{
	int flag;
	int slots;
	int p;
}Container;
Container container[10000];
typedef struct stu
{
	int status;
	int arrived;
}Stu;
Stu stu[1000000];
int count;
int temp[100000];
void student_in_slot(int id)
{
	sleep(1);
	printf("Student %d has been served and left.\n",id);
	return;
}
void wait_for_slot(int id)
{
	printf("Student %d is waiting to be allocated a slot on the serving table.\n",id);
	stu[id].arrived=1;
	while(1)
	{
		if(stu[id].status==1)
		{
			student_in_slot(id);
			break;
		}
	}
	return;
}
void ready_to_serve_table(int id)
{
	while(count!=0)
	{
		if(container[id].flag==1)
		{
			printf("Container %d is filled and ready to serve with slots %d and capacity %d\n",id,container[id].slots,container[id].p);
			while(container[id].p!=0)
			{
				if(container[id].p<container[id].slots)
				{
					container[id].slots=container[id].p;
				}
				if(count==0)
				{
					//printf("Served all the students.\n");
					break;
				}	
				temp[id]=container[id].slots;
				printf("Container %d enters the serving phase and has started serving with slots %d\n",id,container[id].slots);
				while(temp[id]>0)
				{
					for(int i=1;i<=K;i++)
					{
						if(temp[id]==0)
						{
							break;
						}
						pthread_mutex_lock(&mutex2);
						if(stu[i].arrived==1 && stu[i].status==0)
						{
							temp[id]--;
							printf("------%d----------%d-------",temp[id],container[id].slots);
							count--;
							printf("Student %d is assigned a slot on serving table %d and is waiting to be served.\n",i,id);
							stu[i].status=1;
						}
						pthread_mutex_unlock(&mutex2);
					}
				}
				container[id].p-=container[id].slots;
				printf("Container %d is done with a round of slots(%d).Balance capacity is %d.\n",id,container[id].slots,container[id].p);
				container[id].slots=(rand()%(10-1+1))+1;	
			}
			if(container[id].p==0)
			{
				printf("Container %d has finished serving and is now empty,waiting for refill.\n",id);
				container[id].flag=0;
			}
		}
	}
	return;
}
void biryani_ready(int chef_id)
{
	while(chef[chef_id].r!=0)
	{
		if(count==0)
		{
			//printf("Served all the students.\n");
			break;
		}
		for(int i=1;i<=N;i++)
		{
			if(chef[chef_id].r==0)
			{
				break;
			}
			pthread_mutex_lock(&mutex1);
			if(container[i].flag==0)
			{
				printf("Chef %d filled food in container %d\n",chef_id,i);
				container[i].p=chef[chef_id].p;
				container[i].slots=(rand()%(10-1+1))+1;
				container[i].flag=1;
				chef[chef_id].r--;
			}
			pthread_mutex_unlock(&mutex1);
		}
	}
	if(chef[chef_id].r==0)
	{
		printf("Chef %d vessels are emptied and is ready to cook.\n",chef_id);
	}
	return;
}
void cooking(int chef_id)
{
	while(count!=0)
	{
		chef[chef_id].r=(rand()%(10-1+1))+1;
		chef[chef_id].w=(rand()%(5-2+1))+2;
		chef[chef_id].p=(rand()%(50-25+1))+25;	
		//chef[chef_id].p=2;
		printf("{Chef %d is cooking %d vessels - w%d - p%d}\n",chef_id,chef[chef_id].r,chef[chef_id].w,chef[chef_id].p);
		sleep(chef[chef_id].w);
		printf("Chef %d cooking is done and is waiting for the vessels to be emptied.\n",chef_id);
		biryani_ready(chef_id);
	}
	return;
}
int main(void)
{
	printf("ENTER THE NUMBER OF CHEFS\n");
	scanf("%d",&M);
	printf("ENTER THE NUMBER OF SERVING TABLES\n");
	scanf("%d",&N);
	printf("ENTER THE NUMBER OF STUDENTS\n");
	scanf("%d",&K);
	count=K;
	int i=0;
	pthread_mutex_init(&mutex1, NULL);
	pthread_mutex_init(&mutex2, NULL);
	while(i<M)
	{
		int error = pthread_create(&(chef_thread[i]),NULL,cooking,i+1);
		if (error != 0)
		{
			printf("\nThread can't be created :[%s]",strerror(error));
		}
		i++;
	}
	i=0;
	while(i<N)
	{
		int error = pthread_create(&(serve_table[i]),NULL,ready_to_serve_table,i+1);
		if (error != 0)
		{
			printf("\nThread can't be created :[%s]",strerror(error));
		}
		i++;
	}
	i=0;
	while(i<K)
	{
		printf("Student %d has arrived.\n",i+1);
		//stu[i+1].arrived=1;
		int error=pthread_create(&(students[i]),NULL,wait_for_slot,i+1);
		if (error != 0)
		{
			printf("\nThread can't be created :[%s]",strerror(error));
		}
		i++;
		int k=(rand()%(10-0+1))+0;
		sleep(k);
	}
	i=0;
	while(i<K)
	{
		pthread_join(students[i],NULL);
		i++;
	}
	if(count==0)
	{
		printf("All the students are served. Simulation is over\n");
	}
	pthread_mutex_destroy(&mutex1);
	pthread_mutex_destroy(&mutex2);
	return 0;
}

