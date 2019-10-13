#include"header.h"
void sigint_handler(int signo)
{
	pid_t pnow=getpid();
	if(pnow!=shellpid)
	{
		return;
	}
	else if(childpid!=-1)
	{
		kill(childpid,SIGKILL);
		childpid=-1;
	}
	signal(SIGINT,sigint_handler);
	fflush(stdout);
}

