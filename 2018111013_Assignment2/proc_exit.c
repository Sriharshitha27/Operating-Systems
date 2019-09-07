#include"header.h"
void proc_exit(int signal)
{
	long i;
	int status;
	i=waitpid(-1,&status,WNOHANG);
	if(WIFEXITED(status))
	{
	printf("%s with pid %ld exited\n",arr_comm[i],i);
	}
}
