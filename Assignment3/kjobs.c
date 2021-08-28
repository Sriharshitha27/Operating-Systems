#include"header.h"
void kjobs(void)
{
	if(count < 3)
	{
		printf("Missing Arguments\n");
		return;
	}
	if(count > 3)
	{
		printf("Extra Arguments are given\n");
		return ;
	}
	else
	{
		if(atoi(second)>=flag5)
		{
			printf("Process does'nt exist\n");
		}
		else
		{
			kill(array_pid[atoi(second)],atoi(argv[2]));
			if(atoi(argv[2])==9)
			{
				printf("Process %s with pid %d exited with exit status %d\n",arr_comm[array_pid[atoi(second)]],array_pid[atoi(second)],WEXITSTATUS(pid));
				flag5--;
				for(long long int i=atoi(second);i<flag5;i++)
				{
					array_pid[i]=array_pid[i+1];
				}
				array_pid[flag5]=0;
			}
		}
	}
	return ;
}
