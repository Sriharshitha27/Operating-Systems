#include "header.h"
int main(void)
{
	int user_name_max=4096;
	int host_name_max=4096;
	char username[user_name_max];
	char hostname[host_name_max];
	getlogin_r(username, user_name_max);
	gethostname(hostname, host_name_max);
	char command[1000];
	clear();
	printf("\n\n\n\n\n                         *** Hello World !! *** \n");
	printf("                      *** THIS IS MY FIRST SHELL ***\n");
	getcwd(cwd,sizeof(cwd));
	strcpy(pwd,cwd);
	while(1)
	{
		flag2=0;
		flag1=0;
		flag6=0;
		getcwd(cwd,sizeof(cwd));
		if(flag==0)
		{
			if(strcmp(cwd,pwd)==0)
			{
				printf("<%s@%s:~>",username,hostname);
				strcpy(prev,username);
				strcat(prev,"@");
				strcat(prev,hostname);
				strcat(prev,":");
				strcat(prev,"~");
			}
			else
			{
				printf("<%s@%s:%s>",username,hostname,cwd);
				strcpy(prev,username);
				strcat(prev,"@");
				strcat(prev,hostname);
				strcat(prev,":");
				strcat(prev,cwd);
			}
		}
		if(flag==2)
		{
			printf("<%s>",prev);
		}
		if(flag==1 && flag3==0)
		{
			printf("<%s>",prev);
		}
		flag3=0;
		if(input(command))
		{
			flag=2;
			continue;
		}
		char *S=malloc(4096*sizeof(char));
		strcpy(S,command);
		while((str1 = strsep(&S,";"))!= NULL)
		{
			char * emp=malloc(100*sizeof(char));
			emp=strdup("\0");
			if(strcmp(str1,emp)!=0)
			{
				rem_space(str1);
				//printf("%s\n",first);
				if(strcmp(first,"cd")==0)
				{
					func1_cd(username,hostname);
				}
				else if(strcmp(first,"ls")==0 && count<=2)
				{
					func2_ls();
				}
				else if(strcmp(first,"ls")==0 && count>=3)
				{
					func8_big_ls();
				}
				else if(strcmp(first,"echo")==0)
				{
					func3_echo();
				}
				else if(strcmp(first,"pwd")==0)
				{
					func4_pwd();
				}
				else if(strcmp(first,"pinfo")==0)
				{
					func7_proc();
				}
				else
				{
					if(count==1)
					{
						flag4=1;
						func5_fg();
						flag=2;
					}
					if(flag6==1)
					{
						func6_bg();
						flag=2;
					}
					else if (count!=1 && flag6!=1)
					{
						func5_fg();
						flag=2;
					}
				}
			}
		}
		free(S);
	}
	return 0;
}
