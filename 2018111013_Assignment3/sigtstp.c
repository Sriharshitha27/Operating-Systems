#include"header.h"
void sigtstp_handler(int signo) 
{
	if(childpid!=-1)
	{
		kill(childpid,SIGTSTP); 
		array_pid[flag5]=childpid;
		arr_comm[childpid]=first;
		flag5++;
	}
	signal(SIGTSTP, sigtstp_handler);
}
