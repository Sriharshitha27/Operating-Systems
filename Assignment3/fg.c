#include "header.h"
void func5_fg(void)
{
	//char *argv[]={first,NULL};
	//pid_t  pid;
	//int p=pid;
	int status;
	if((pid=fork())<0)
	{
		printf("*** ERROR: forking child process failed\n");
		exit(1);
	}
	else if(pid==0)
	{
		if(execvp(argv[0],argv)<0)
		{     
			printf("*** ERROR: exec failed\n");
			exit(1);
		}
	}
	else
	{
	        childpid=pid;	
		//wait(NULL);
		//while (wait(NULL) != pid);
		waitpid(pid,&status,WUNTRACED);
	}
	return;
}

