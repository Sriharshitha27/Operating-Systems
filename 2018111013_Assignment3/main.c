#include "header.h"
int main(void)
{
	int user_name_max=4096;
	int host_name_max=4096;
	char username[user_name_max];
	char hostname[host_name_max];
	flag5=1;
	getlogin_r(username, user_name_max);
	gethostname(hostname, host_name_max);
	char command[1000];
	for(int i=0;i<1000;i++)
	{
		command[i]='\0';
	}
	clear();
	printf("\n\n\n\n\n                         *** Hello World !! *** \n");
	printf("                      *** THIS IS MY FIRST SHELL ***\n");
	getcwd(cwd,sizeof(cwd));
	strcpy(pwd,cwd);
	shellpid=getpid();
	childpid=-1;
	using_history();
	while(1)
	{
	 	signal(SIGCHLD,proc_exit);
		signal(SIGINT, sigint_handler);
		signal(SIGTSTP,sigtstp_handler);
		flag2=0;
		flag1=0;
		flag6=0;
		flag8=0;
		flag9=0;
		flag10=0;
		getcwd(cwd,sizeof(cwd));
		if(flag==0)
		{
			if(strcmp(cwd,pwd)==0)
			{
				sprintf(har,"<%s@%s:~> ",username,hostname);
				strcpy(prev,username);
				strcat(prev,"@");
				strcat(prev,hostname);
				strcat(prev,":");
				strcat(prev,"~");
			}
			else
			{
				sprintf(har,"<%s@%s:%s> ",username,hostname,cwd);
				strcpy(prev,username);
				strcat(prev,"@");
				strcat(prev,hostname);
				strcat(prev,":");
				strcat(prev,cwd);
			}
		}
		if(flag==2)
		{
			sprintf(har,"<%s> ",prev);
		}
		if(flag==1 && flag3==0)
		{
			sprintf(har,"<%s> ",prev);
		}
		flag3=0;
		if(input(command))
		{
			flag=2;
			continue;
		}
		add_history(command);
		char *S=malloc(4096*sizeof(char));
		strcpy(S,command);
		while((str1 = strsep(&S,";"))!= NULL)
		{
			char * emp=malloc(100*sizeof(char));
			emp=strdup("\0");
			if(strcmp(str1,emp)!=0)
			{
				char *str3=malloc(1000*sizeof(char));
				char *str2=malloc(1000*sizeof(char));
				char *str5=malloc(1000*sizeof(char));
				strcpy(str3,str1);
				strcpy(str5,str1);
				test=0;
				test2=0;
				str2=strtok(str3, "|");
				while(str2!=NULL)
				{
					test++;
					str2=strtok(NULL,"|");
				}
				if(test>1)
				{
					aaa=0;
					bbb=0;
					str4=strtok(str5, "|");
					while(str4!=NULL) 
			 		{
						parsepipe();
						str4 = strtok(NULL,"|");
						test2++;
					}
					//printf("%s %s \n %s",cmd[0][0],cmd[0][1],cmd[1][0]);
					func12_pipe1();
				}
				if(test==1)
				{
					rem_space(str1);
					if(flag8==1 && flag9==1)
					{
						func11_redir3();
						if(strcmp(first,"cd")==0)
                                                {
                                                        call_cd(username,hostname);
                                                }
					}
					else if(flag8==1)
					{
						func9_redir1();
						flag=2;
						if(strcmp(first,"cd")==0)
						{
							call_cd(username,hostname);
						}
					}
					else if(flag9==1)
					{
						func10_redir2();
						flag=2;
						if(strcmp(first,"cd")==0)
                                                {
                                                        call_cd(username,hostname);
                                                }
					}
					else if(strcmp(first,"quit")==0)
					{
						return 0;
					}
					else if(strcmp(first,"cd")==0)
					{
						func1_cd(username,hostname);
					}
					else if(strcmp(first,"ls")==0 && count<=2 && flag8!=1)
					{
						func2_ls();
					}
					else if(strcmp(first,"ls")==0 && count>=3 && flag8!=1)
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
					else if(strcmp(first,"setenv")==0)
					{
						setenvvar();
						flag=2;
					}
					else if(strcmp(first,"unsetenv")==0)
					{
						unsetenvvar();
						flag=2;
					}
					else if(strcmp(first,"jobs")==0)
					{
						jobs();
						flag=2;
					}
					else if(strcmp(first,"kjob")==0)
					{
						kjobs();
						flag=2;
					}
					else if(strcmp(first,"overkill")==0)
					{
						overkill();
					}
					else if(strcmp(first,"bg")==0)
					{
						bgg();
					}
					 else if(strcmp(first,"fg")==0)
                                        {
                                                fgg();
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
				free(str2);
				free(str3);
				free(str5);
			}
			free(emp);
		}
		free(S);
	}
	return 0;
} 
