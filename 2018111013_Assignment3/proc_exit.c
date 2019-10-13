#include"header.h"

void proc_exit(int signal)
{
	/*	long i;
		int status;
		i=waitpid(WAIT_ANY,&status,WNOHANG);
		if(WIFEXITED(status) && i>0)
		{
		int exit_status=WEXITSTATUS(status);
		if(exit_status==0)
		{
		printf("%s with pid %ld exited normally.\nExit status of the child was %d\n",arr_comm[i],i,exit_status);
		}
		else
		{
		printf("%s with pid %ld exited.\nExit status of the child was %d\n",arr_comm[i],i,exit_status);
		}
		flag5--;
		for(long long int ii=array_index[i];ii<flag5;ii++)
		{
		array_pid[ii]=array_pid[ii+1];
		}
		array_pid[flag5]=0;
		}
		return ;*/
	pid_t pid;
	int x;
	pid = waitpid(WAIT_ANY, &x, WNOHANG);
	for(int i=0;i<flag5;i++)
	{
		if(array_pid[i]==pid && pid>0)
		{
			int exit_status = WEXITSTATUS(x);
			if (exit_status == 0)
			{
				printf("Process %s with pid %d exited normally\n",arr_comm[array_pid[i]],array_pid[i]);
			}
			else
			{
				printf("Process %s with pid %d exited with exit status %d\n",arr_comm[array_pid[i]],array_pid[i], exit_status);
			}
			flag5--;
			for(long long int ii=array_index[i];ii<flag5;ii++)
			{
				array_pid[ii]=array_pid[ii+1];
			}
			array_pid[flag5]=0;
			fflush(stdout);
			break;
		}
	}
	return ; 
}

