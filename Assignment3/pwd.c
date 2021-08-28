#include "header.h"
void func4_pwd(void)
{
	if(strcmp(first,"pwd")==0)
	{
		getcwd(cwd,sizeof(cwd));
		printf("%s \n",cwd);
	}
	else
	{
		printf("Dont play around.This code is only for command 'pwd'\n");
	}
}
/*
void rem_space(char *str)
{
	int count=0;
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
			}
		}
	}
}


*/