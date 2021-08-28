#include "header.h"
void func9_redir1(void)
{
	//printf("yes im here");
	int pid;
	//char *argv1[64];
	int fd;
	if(strcmp(argv[output_redir_point],">>")==0)
	{
		fd=open(argv[count-1], O_WRONLY | O_APPEND | O_CREAT, 0644);
	}
	else
	{

		fd=open(argv[count-1], O_WRONLY | O_CREAT | O_TRUNC , 0644);
	}
	long long int ii;
	for(ii=0;ii<output_redir_point;ii++)
	{
		argv1[ii]=argv[ii];	
	}
	argv1[ii]=NULL;
	if((pid=fork())<0)
	{
		printf("*** ERROR: forking child process failed\n");
		exit(1);
	}
	if(pid==0)
	{
		close(1);
		if(dup2(fd,1)!=1)
		{
			perror("dup2 failed");
		}
		close(fd);
		if(execvp(argv1[0],argv1)<0)
		{
			printf("*** ERROR: exec failed\n");
			exit(1);
		}
		//dup2(1,fd);
		exit(0);
	}
	else
	{
		//	 while (wait(NULL) != pid);
	}

	return ;
}




