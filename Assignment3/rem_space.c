#include "header.h"
void rem_space(char *str)
{
	count=0;
	output_redir_point=0;
	while((no_space_str = strsep(&str," "))!= NULL)
	{
		char * empty=malloc(100*sizeof(char));
		empty=strdup("\0");
		int h=strcmp(empty,no_space_str);
		if(strcmp(empty,no_space_str)!=0)
		{
			if(strcmp(no_space_str,"&")!=0)
			{
				argv[count]=no_space_str;
			}
			//count++;
			if(strcmp(no_space_str,">>")==0 || strcmp(no_space_str,">")==0)
			{
				flag8=1;
				output_redir_point=count;
			}
			if(strcmp(no_space_str,"<")==0)
			{
				flag9=1;
				input_redir_point=count;
			}
			if(strcmp(no_space_str,"|")==0)
			{
				flag10=1;
				break;
			}
			count++;
			if(strcmp(no_space_str,"&")==0)
			{
				flag6=1;
			}
			if(count==1)
			{
				strcpy(first,no_space_str);
				if(strcmp(first,"echo")!=0)
				{
					continue;
				}
			}
			if(count==2 && strcmp(first,"echo")!=0)
			{
				strcpy(second,no_space_str);
			}
			if(count==2 && strcmp(first,"echo")==0)
			{
				strcpy(prev2,no_space_str);
				strcat(prev2," ");
			}
			if(count>2 && strcmp(first,"cd")==0 && flag8!=1 && flag9!=1)
			{
				flag2=1;
				printf("Too many arguments\n");
			}
			if(count>2 && strcmp(first,"echo")==0 )
			{
				strcat(prev2,no_space_str);
				strcat(prev2," ");
			}
			if(count>2 && strcmp(first,"ls")==0)
			{
				arr_ls[count-3]=no_space_str;
			}
		}
		free(empty);	
	}
	if(count==1 && strcmp(first,"cd")==0)
	{
		flag1=1;
	}
	argv[count]=NULL;
}
