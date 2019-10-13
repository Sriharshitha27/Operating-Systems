#include"header.h"
void fgg(void)
{
	char s[60];
	char str[60];
	FILE *fp1;
	char str1[60];
	sprintf(str,"%d",array_pid[atoi(second)]);
	strcpy(s,str);
	char slash1[]="/proc/";
	strcat(slash1,s);
	strcat(slash1,"/");
	strcat(slash1,"stat");
	fp1 = fopen(slash1, "r");
	if(fp1 == NULL)
	{
		perror("Error:No such process in background");
		return;
	}
	if(count>2)
	{
		printf("Extra arguments provded\n");
		return ;
	}
	else if(count<2)
	{
		printf("Missing arguments.\n");
		return ;
	}
	else if(atoi(argv[1])>flag5)
	{
		printf("Process does'nt exist.\n");
		return;
	}
	else
	{
		int status;
		kill(array_pid[atoi(second)],SIGCONT);
		waitpid(array_pid[atoi(second)], &status, WUNTRACED);
		int j=atoi(second);
		flag5--;
		for(long long int i=j;i<flag5;i++)
		{
			array_pid[i]=array_pid[i+1];
		}
		childpid=array_pid[atoi(second)];
		array_pid[flag5]=0;
	}
}


