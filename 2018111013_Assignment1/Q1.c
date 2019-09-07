#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
void main(int argc,char *argv[])
{
	int ret;
	ret=mkdir("Assignment", S_IRUSR | S_IWUSR | S_IXUSR | S_IROTH | S_IRGRP | S_IXOTH);
	if (ret!=0)
	{
		write(1,"Directory already exists\n",strlen("Directory already exists\n"));
	}
	else
	{
		write(1,"Created the folder Assignment\n",strlen("Created the folder Assignment\n"));
	}
	FILE *fp1;
	fp1=fopen(argv[1],"r");
	fseek(fp1,-1L,SEEK_END);
	long long int count=ftell(fp1);
	fclose(fp1);
	int f1=open(argv[1],O_RDONLY);
	if(f1==-1)
	{
		perror("r1");
		exit(1);
	}
        char name[100];
        char *token = strtok(argv[1], "/");
        while (token != NULL)
        {
                strcpy(name,token);
                token = strtok(NULL, "/");
        }
	chdir("Assignment");
	int f2=creat(name,S_IRUSR | S_IWUSR | S_IROTH | S_IRGRP | S_IXOTH);
	char buffer[4096];	
	long long int temp=count;
	long long int i=0;
	double percentage;
	char perc[100];
	if(temp>4096)
	{
		while(temp>=4096)
		{
			write(1,"\r",strlen("\r"));
			i++;
			lseek(f1,-(i*4096),SEEK_END);
			read(f1,buffer,4096);
			for(long long int k=0;k<2048;k++)
			{
				char t;
				t=buffer[k];
				buffer[k]=buffer[4095-k];
				buffer[4095-k]=t;
			}				
			write(f2,buffer,4096);
			temp=temp-4096;
			percentage=(double)(4096*i)/(double)count;
			sprintf(perc,"%f",percentage*100);
			write(1,&perc,strlen(perc));
			fflush(stdout);
		}
		lseek(f1,-(i*4096+temp+1),SEEK_END);
		read(f1,buffer,temp+1);
		temp++;
		count++;
		for(long long int k=0;k<temp/2;k++)
		{
			char t;
			t=buffer[k];
			buffer[k]=buffer[temp-k-1];
			buffer[temp-k-1]=t;
		}
		write(f2,buffer,temp);
		percentage=(double)(4096*i+temp)/(double)count;
		sprintf(perc,"%f",percentage*100);
		write(1,"\r",strlen("\r"));
		write(1,&perc,strlen(perc));
		write(1,"\n",strlen("\n"));
		fflush(stdout);
	}
	else
	{
		lseek(f1,-(i*4096+temp+1),SEEK_END);
		read(f1,buffer,temp+1);
		temp=temp+1;
		count++;
		for(long long int k=0;k<temp/2;k++)
		{
			char t;
			t=buffer[k];
			buffer[k]=buffer[temp-k-1];
			buffer[temp-k-1]=t;
		}
		write(f2,buffer,temp);
		percentage=(double)(4096*i+temp)/(double)count;
		sprintf(perc,"%f",percentage*100);
		write(1,&perc,strlen(perc));
		write(1,"\n",strlen("\n"));
		fflush(stdout);
	}
	write(1,"The given file is reversed and stored in the directory Assignment\n",strlen("The given file is reversed and stored in the directory Assignment\n"));
	if(close(f1)<0)  
	{ 
		perror("c1"); 
		exit(1); 
	}
	if(close(f2)<0)
	{ 
		perror("c1"); 
		exit(1); 
	}  	
	return 0;
}








