#include "header.h"
int input(char* str)
{
	char * temp;
	temp=readline(har);
	if(strlen(temp)!=0)
	{
		strcpy(str,temp);
		return 0;
	}
	else
	{
		return 1;
	}
}
