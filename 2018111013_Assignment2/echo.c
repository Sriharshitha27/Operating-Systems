#include "header.h"
void func3_echo(void)
{
	if(strcmp(first,"echo")==0 && count!=1)
	{
		printf("%s\n",prev2);
	}
	else if(strcmp(first,"echo")==0 && count==1)
	{
		printf("\n");
	}
	else if(strcmp(first,"echo")!=0)
	{
		printf("Don't try to play around.Only 'cd' command is allowed\n");
	}
	return;
}
/*
void rem_space(char *str,char *prev)
{
	count=0;
	while( (no_space_str = strsep(&str," ")) != NULL )
	{
		char * empty;
		empty=strdup("\0");
		int h=strcmp(empty,no_space_str);
		if(strcmp(empty,no_space_str)!=0)
		{
			count++;
			if(count==1)
			{
				strcpy(first,no_space_str);
				continue;
			}
			if(count==2)
			{
				strcpy(prev,no_space_str);
				strcat(prev," ");
			}
			if(count>2)
			{
				strcat(prev,no_space_str);
				strcat(prev," ");
			}
		}
	}
}

*/
