#include "header.h"
void func6_bg(void)
{
	/*argv[0]=first;
	argv[1]=second;
	argv[3]=NULL;*/
	//pid_t  pid;
	//int p=pid;
	//int status;
	if((pid = fork())<0)
	{
		printf("*** ERROR: forking child process failed\n");
		exit(1);
	}
	else if(pid==0)
	{
		if (execvp(*argv,argv) < 0)
		{  
			printf("*** ERROR: exec failed\n");
			exit(1);
		}
	}
	else if(pid>0)
	{
		signal(SIGCHLD,proc_exit);
		array_pid[flag5]=pid;
		arr_comm[pid]=(char*)malloc(sizeof(char)*1027);
		strcpy(arr_comm[pid],first);
		flag5++;
	}
	else
	{
		printf("Error occured");
	}
	return;
}
