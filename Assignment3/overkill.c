#include"header.h"
void overkill(void)
{
	for(int i=1;i<flag5;i++)
	{
		kill(array_pid[i],9);
                printf("Process %s with pid %d exited normally with exit status %d\n",arr_comm[array_pid[i]],array_pid[i],WEXITSTATUS(array_pid[i]));
		array_pid[i]=0;
	}
	flag5=1;
	return ;
}

