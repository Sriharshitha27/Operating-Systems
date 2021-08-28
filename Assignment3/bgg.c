#include"header.h"
void bgg(void)
{
	if(count<2)
	{
		printf("Missing arguments\n");
		return;
	}
	else if(count >2)
	{
		printf("Extra argument provided\n");
		return;
	}
	else
	{
		if(atoi(second)>=flag5)
		{
			printf("Process doesnt exist\n");
			return;
		}
		else
		{
			kill(array_pid[atoi(second)],SIGCONT);
		}
	}
	return;
}

