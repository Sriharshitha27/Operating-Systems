#include<stdio.h> 
#include<pthread.h> 
#include<semaphore.h> 
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
//max_wait_time is "20-50" seconds
//ride_time is "1-10" seconds
int N,M,K;
int count;
int count2;
int count3;
time_t start,end;
pthread_t cabs_thread[1000];
pthread_t rider_thread[1000];
pthread_t rider_wait_thread[1000];
pthread_t server_thread[1000];
pthread_mutex_t mutex1=PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2=PTHREAD_MUTEX_INITIALIZER;;
pthread_mutex_t mutex3=PTHREAD_MUTEX_INITIALIZER;
typedef struct rider
{
	int type; //1->premier 2->pool
	int max_wait_time;
	int ride_time;
	int flag;
	int cab_id;
	int status;
	int payment;
}Rider;
Rider rider[1000];
typedef struct cabs
{
	int status;//0->waiting // 1->busy
	int type; //0->waiting 1->premier 2->pool_1 3->pool_2
	int ride_time;
}Cabs;
Cabs cabs[1000];
typedef struct servers
{
	int status;//0->waiting // 1->busy
}Servers;
Servers servers[1000];
void accept_payment(int id)
{
	while(count2!=1)
	{
		for(int i=1;i<=M;i++)
		{
			pthread_mutex_lock(&mutex3);
			if(rider[i].payment==1 && servers[id].status==0)
			{
				rider[i].payment=0;
				pthread_mutex_unlock(&mutex3);
				servers[id].status==1;
				sleep(2);
				printf("Server %d accepted the payment from %d\n",id,i);
				servers[id].status=0;
			}
			else
			{
			pthread_mutex_unlock(&mutex3);	
			}
		}
	}
}
void cab_alotted(int id)
{	
	while(rider[id].status!=2)
	{
		if(rider[id].status==1)
		{
			sleep(rider[id].ride_time);
			printf("    Cab-%d Rider-%d finished the ride.\n",rider[id].cab_id,id);
			if(cabs[rider[id].cab_id].type==1)
			{
				cabs[rider[id].cab_id].type=0;
				cabs[rider[id].cab_id].status=0;
			}
			if(cabs[rider[id].cab_id].type==2)
			{
				cabs[rider[id].cab_id].type=0;
				cabs[rider[id].cab_id].status=0;
			}
			if(cabs[rider[id].cab_id].type==3)
			{
				cabs[rider[id].cab_id].type=2;
				cabs[rider[id].cab_id].status=1;
			}
			rider[id].status=2;
		}
	}
}
int bookcab(int id)
{
	for(int j=1;j<=N;j++)
	{
		if(rider[id].flag==1)
		{
			rider[id].flag=2;
			printf("Rider %d exited.\n",id);
		}
		if(rider[id].type==2)
		{
			pthread_mutex_lock(&mutex1);
			if(cabs[j].status==1 && cabs[j].type==2)
			{
				printf("Rider %d found a pool_2 cab %d\n",id,j);
				cabs[j].type=3;
				rider[id].payment=1;
				rider[id].cab_id=j;
				rider[id].status=1;
				pthread_mutex_unlock(&mutex1);
				return 1;
			}
			pthread_mutex_unlock(&mutex1);
			pthread_mutex_lock(&mutex1);
			if(cabs[j].status==0)
			{
				printf("Rider %d found a pool_1 cab %d\n",id,j);
				cabs[j].status=1;
				cabs[j].type=rider[id].type;
				rider[id].cab_id=j;
				rider[id].status=1;
				rider[id].payment=1;
				cabs[j].ride_time=rider[id].ride_time;
				pthread_mutex_unlock(&mutex1);
				return 1;
			}
			pthread_mutex_unlock(&mutex1);
		}
		pthread_mutex_lock(&mutex1);		
		if(cabs[j].status==0)
		{
			printf("Rider %d found a premier cab %d\n",id,j);
			cabs[j].status=1;
			cabs[j].type=rider[id].type;
			rider[id].cab_id=j;
			rider[id].status=1;
			rider[id].payment=1;
			cabs[j].ride_time=rider[id].ride_time;
			pthread_mutex_unlock(&mutex1);
			return 1;
		}
		pthread_mutex_unlock(&mutex1);
	}
	return 0;
}
void rider_waiting(int id)
{
	sleep(rider[id].max_wait_time);
	rider[id].flag=1;
	return;
}
void rider_arrived(int id)
{
	rider[id].type=(rand()%(2-1+1))+1;
	rider[id].max_wait_time=(rand()%(50-20+1))+20;
	//rider[id].max_wait_time=50;
	rider[id].ride_time=(rand()%(10-1+1))+1;
	printf("Rider %d has arrived.[Cab_type:%d,Wait_time:%d,Ride_time:%d].\n",id,rider[id].type,rider[id].max_wait_time,rider[id].ride_time);
	int error = pthread_create(&(rider_wait_thread[id]),NULL,rider_waiting,id);
	if(error!=0)
	{
		printf("\nThread1 can't be created :[%s]",strerror(error));
	}
	while(rider[id].flag==0)
	{
		int p=bookcab(id);
		if(p==1)
		{
			break;
		}
	}
	if(rider[id].flag==1)
	{
		printf("Rider %d exited.\n",id);
		rider[id].status=2;
	}
	return;
}
int main(void)
{
	printf("----------- 	OBER CAB SERVICES     ------------\n");
	printf("            #cab_type - 1 - PREMIER\n            #cab_type - 2 - POOL\n");
	printf("ENTER THE NUMBER OF CABS\n");
	scanf("%d",&N);
	printf("ENTER THE NUMBER OF RIDERS\n");
	scanf("%d",&M);
	printf("ENTER THE NUMBER OF PAYMENT PORTALS/SERVERS\n");
	scanf("%d",&K);
	count=K;
	int i=1;
	while(i<M+1)
        {
                int error = pthread_create(&(cabs_thread[i]),NULL,cab_alotted,i);
                if(error!=0)
                {
                        printf("\nThread1 can't be created :[%s]",strerror(error));
                }
                i++;
        }
	i=1;
	while(i<=K)
        {
                int error = pthread_create(&(server_thread[i]),NULL,accept_payment,i);
                if(error!=0)
                {
                        printf("\nThread1 can't be created :[%s]",strerror(error));
                }
                i++;
        }
	i=0;
	while(i<M)
	{
		int error = pthread_create(&(rider_thread[i]),NULL,rider_arrived,i+1);
		++count3;
		if(error!=0)
		{
			printf("\nThread1 can't be created :[%s]",strerror(error));
		}
		i++;
		int k=(rand()%(4-0+1))+0;
                sleep(k);
	}
	i=0;
	while(i<M)
	{
		pthread_join(rider_thread[i],NULL);
		i++;
	}
	i=1;
	while(i<=M)
	{
		pthread_join(cabs_thread[i],NULL);
		i++;
	}
	count2=1;
	i=1;
	while(i<=K)
	{
		pthread_join(server_thread[i],NULL);
		i++;
	}
	printf("-----------------------END   OF  THE   SIMULATION-------------------\n");
	pthread_mutex_destroy(&mutex1);
	pthread_mutex_destroy(&mutex2);
	pthread_mutex_destroy(&mutex3);
	return 0;
}



