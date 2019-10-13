#include "header.h"
void func10_redir2(void)
{
	long long int ii;
	char *argv1[64];
	for(ii=0;ii<input_redir_point;ii++)
	{
		argv1[ii]=argv[ii];	
	}
	argv1[ii]=NULL;
	int fd;
	if((fd=open(argv[input_redir_point+1],O_RDONLY))==-1)
	{
		perror("Error opening the file");
	}
	int pid;
	if((pid=fork())<0)
	{
		printf("*** ERROR: forking child process failed\n");
		exit(1);
	}
	if(pid==0)
	{
		close(0);
		if(dup2(fd,0)!=0)
		{
			perror("dup2 failed");
		}
		close(fd);
		if(execvp(argv1[0],argv1)<0)
		{
			printf("*** ERROR: exec failed\n");
			exit(1);
		}
		exit(0);
	}
	else
	{
		 while (wait(NULL) != pid);
	}
	return;
}

 
