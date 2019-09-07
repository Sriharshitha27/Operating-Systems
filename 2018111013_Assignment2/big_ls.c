#include "header.h"
void func8_big_ls(void)
{
	if(count==3 && strcmp(second,"-l")==0 && strcmp(arr_ls[0],"-a")==0)
	{
		struct dirent *de;
		DIR *dr=opendir(".");
		if(dr==NULL)
		{
			printf("Could not open the directory.It does'nt exist.\n");
			return;
		}
		while((de=readdir(dr))!=NULL)
		{
			char string[100];
			strcpy(string,de->d_name);
			struct stat S;
			struct passwd *P;
			struct group *G;
			stat(string,&S);
			if(stat(string,&S)<0)
			{
				return;
			}
			printf((S_ISDIR(S.st_mode)) ? "d" : "-");
			printf((S.st_mode & S_IRUSR) ? "r" : "-");
			printf((S.st_mode & S_IWUSR) ? "w" : "-");
			printf((S.st_mode & S_IXUSR) ? "x" : "-");
			printf((S.st_mode & S_IRGRP) ? "r" : "-");
			printf((S.st_mode & S_IWGRP) ? "w" : "-");
			printf((S.st_mode & S_IXGRP) ? "x" : "-");
			printf((S.st_mode & S_IROTH) ? "r" : "-");
			printf((S.st_mode & S_IWOTH) ? "w" : "-");
			printf((S.st_mode & S_IXOTH) ? "x" : "-");
			printf(" %ld ",S.st_nlink);

			if ((P=getpwuid(S.st_uid)) == NULL)
			{
				perror("getpwuid() error");
			}
			else 
			{
				printf("%s ",P->pw_name);
			}
			if ((G=getgrgid(S.st_uid))==NULL)
			{
				perror("getgrgid() error");
			}
			else
			{
				printf("%s ",G->gr_name);
			}
			printf("%ld ",S.st_size);
			/*struct tm *tm;
			  char buf[200];
			  time_t t = S.st_mtime;
			  tm=localtime(&t);
			  strftime(buf, sizeof(buf), "%d.%m.%Y %H:%M:%S", tm);
			  printf("%s", buf);*/
			time_t t = S.st_mtime;
			struct tm lt;
			localtime_r(&t, &lt);
			char timbuf[80];
			strftime(timbuf, sizeof(timbuf), "%c", &lt);
			printf("%s",timbuf);
			printf(" %s\n",string);
		}
		closedir(dr);
	}
	if(count>3 && strcmp(second,"-l")==0 && strcmp(arr_ls[0],"-a")==0)
	{
		getcwd(cwd,sizeof(cwd));
		for(long long int i=1;i<count-2;i++)
		{
			chdir(arr_ls[i]);
			if(count>4)
			{
			printf("%s:\n",arr_ls[i]);
			}
			struct dirent *de;
			DIR *dr=opendir(".");
			if(dr==NULL)
			{
				printf("Could not open the directory.It does'nt exist.\n");
				return;
			}
			while((de=readdir(dr))!=NULL)
			{
				char string[100];
				strcpy(string,de->d_name);
				struct stat S;
				struct passwd *P;
				struct group *G;
				stat(string,&S);
				if(stat(string,&S)<0)
				{
					return;
				}
				printf((S_ISDIR(S.st_mode)) ? "d" : "-");
				printf((S.st_mode & S_IRUSR) ? "r" : "-");
				printf((S.st_mode & S_IWUSR) ? "w" : "-");
				printf((S.st_mode & S_IXUSR) ? "x" : "-");
				printf((S.st_mode & S_IRGRP) ? "r" : "-");
				printf((S.st_mode & S_IWGRP) ? "w" : "-");
				printf((S.st_mode & S_IXGRP) ? "x" : "-");
				printf((S.st_mode & S_IROTH) ? "r" : "-");
				printf((S.st_mode & S_IWOTH) ? "w" : "-");
				printf((S.st_mode & S_IXOTH) ? "x" : "-");
				printf(" %ld ",S.st_nlink);

				if ((P=getpwuid(S.st_uid)) == NULL)
				{
					perror("getpwuid() error");
				}
				else 
				{
					printf("%s ",P->pw_name);
				}
				if ((G=getgrgid(S.st_uid))==NULL)
				{
					perror("getgrgid() error");
				}
				else
				{
					printf("%s ",G->gr_name);
				}
				printf("%ld ",S.st_size);
				/*struct tm *tm;
				  char buf[200];
				  time_t t = S.st_mtime;
				  tm=localtime(&t);
				  strftime(buf, sizeof(buf), "%d.%m.%Y %H:%M:%S", tm);
				  printf("%s", buf);*/
				time_t t = S.st_mtime;
				struct tm lt;
				localtime_r(&t, &lt);
				char timbuf[80];
				strftime(timbuf, sizeof(timbuf), "%c", &lt);
				printf("%s",timbuf);
				printf(" %s\n",string);
			}
			closedir(dr);
			chdir(cwd);
		}
	}
	if(count>2 && strcmp(arr_ls[0],"-a")!=0)
	{
		char cwd2[4096];
		getcwd(cwd2,sizeof(cwd2));
		if(strcmp(second,"-l")==0)
		{
			for(long long int i=0;i<count-2;i++)
			{
				if(count-2>1)
				{
					printf("%s:\n",arr_ls[i]);
				}
				chdir(arr_ls[i]);
				struct dirent *de;
				DIR *dr=opendir(".");
				if(dr==NULL)
				{
					printf("Could not open the directory.It does'nt exist.\n");
					return;
				}
				while((de=readdir(dr))!=NULL)
				{
					char name1[100];
					strcpy(name1,de->d_name);
					if((int)name1[0]!=46)
					{
						char string[100];
						strcpy(string,de->d_name);
						struct stat S;
						struct passwd *P;
						struct group *G;
						stat(string,&S);
						if(stat(string,&S)<0)
						{
							return ;
						}
						printf((S_ISDIR(S.st_mode)) ? "d" : "-");
						printf((S.st_mode & S_IRUSR) ? "r" : "-");
						printf((S.st_mode & S_IWUSR) ? "w" : "-");
						printf((S.st_mode & S_IXUSR) ? "x" : "-");
						printf((S.st_mode & S_IRGRP) ? "r" : "-");
						printf((S.st_mode & S_IWGRP) ? "w" : "-");
						printf((S.st_mode & S_IXGRP) ? "x" : "-");
						printf((S.st_mode & S_IROTH) ? "r" : "-");
						printf((S.st_mode & S_IWOTH) ? "w" : "-");
						printf((S.st_mode & S_IXOTH) ? "x" : "-");
						printf(" %ld ",S.st_nlink);

						if ((P=getpwuid(S.st_uid)) == NULL)
						{
							perror("getpwuid() error");
						}
						else 
						{
							printf("%s ",P->pw_name);
						}
						if ((G=getgrgid(S.st_uid))==NULL)
						{
							perror("getgrgid() error");
						}
						else
						{
							printf("%s ",G->gr_name);
						}
						printf("%ld ",S.st_size);
						/*struct tm *tm;
						  char buf[200];
						  time_t t = S.st_mtime;
						  tm=localtime(&t);
						  strftime(buf, sizeof(buf), "%d.%m.%Y %H:%M:%S", tm);
						  printf("%s", buf);*/
						time_t t = S.st_mtime;
						struct tm lt;
						localtime_r(&t, &lt);
						char timbuf[80];
						strftime(timbuf, sizeof(timbuf), "%c", &lt);
						printf("%s",timbuf);
						printf(" %s\n",string);
					}
				}
				closedir(dr);
				chdir(cwd2);
			}
		}
		if(strcmp(second,"-a")==0)
		{
			for(long long int i=0;i<count-2;i++)
			{
				if(count-2>1)
				{
					printf("%s:\n",arr_ls[i]);
				}
				chdir(arr_ls[i]);
				struct dirent *de;
				DIR *dr=opendir(".");
				if(dr==NULL)
				{
					printf("Could not open the directory.It does'nt exist.\n");
					return;
				}
				while((de=readdir(dr))!=NULL)
				{
					printf("%s\n",de->d_name);
				}
				closedir(dr);
				chdir(cwd2);
			}
		}
		else if (strcmp(second,"-l")!=0 && strcmp(second,"-la")!=0)
		{
			for(long long int i=-1;i<count-2;i++)
			{
				if(i==-1)
				{
						printf("%s:\n",second);
				}
				else
				{
					printf("%s:\n",arr_ls[i]);
				}
				if(i==-1)
				{
					chdir(second);
				}
				else
				{
					chdir(arr_ls[i]);
				}
				struct dirent *de;
				DIR *dr=opendir(".");
				if(dr==NULL)
				{
					printf("Could not open the directory.It does'nt exist.\n");
					return;
				}
				while((de=readdir(dr))!=NULL)
				{
					char name1[100];
					strcpy(name1,de->d_name);
					if((int)name1[0]!=46)
					{
						printf("%s\n",de->d_name);
					}
				}
				closedir(dr);
				chdir(cwd2);
			}
		}
		else if (strcmp(second,"-la")==0)
		{
			for(long long int i=0;i<count-2;i++)
			{
				if(count>3)
				{
					printf("%s-\n",arr_ls[i]);
				}
				chdir(arr_ls[i]);
				struct dirent *de;
                                DIR *dr=opendir(".");
                                if(dr==NULL)
                                {
                                        printf("Could not open the directory.It does'nt exist.\n");
                                        return;
                                }
                                while((de=readdir(dr))!=NULL)
                                {
                                        char string[100];
                                        strcpy(string,de->d_name);
                                        struct stat S;
                                        struct passwd *P;
                                        struct group *G;
                                        stat(string,&S);
                                        if(stat(string,&S)<0)
                                        {
                                                return;
                                        }
                                        printf((S_ISDIR(S.st_mode)) ? "d" : "-");
                                        printf((S.st_mode & S_IRUSR) ? "r" : "-");
                                        printf((S.st_mode & S_IWUSR) ? "w" : "-");
                                        printf((S.st_mode & S_IXUSR) ? "x" : "-");
                                        printf((S.st_mode & S_IRGRP) ? "r" : "-");
                                        printf((S.st_mode & S_IWGRP) ? "w" : "-");
                                        printf((S.st_mode & S_IXGRP) ? "x" : "-");
                                        printf((S.st_mode & S_IROTH) ? "r" : "-");
                                        printf((S.st_mode & S_IWOTH) ? "w" : "-");
                                        printf((S.st_mode & S_IXOTH) ? "x" : "-");
                                        printf(" %ld ",S.st_nlink);

                                        if ((P=getpwuid(S.st_uid)) == NULL)
                                        {
                                                perror("getpwuid() error");
                                        }
                                        else
                                        {
                                                printf("%s ",P->pw_name);
                                        }
                                        if ((G=getgrgid(S.st_uid))==NULL)
                                        {
                                                perror("getgrgid() error");
                                        }
                                        else
                                        {
                                                printf("%s ",G->gr_name);
                                        }
                                        printf("%ld ",S.st_size);
                                        /*struct tm *tm;
                                          char buf[200];
                                          time_t t = S.st_mtime;
                                          tm=localtime(&t);
                                          strftime(buf, sizeof(buf), "%d.%m.%Y %H:%M:%S", tm);
                                          printf("%s", buf);*/
                                        time_t t = S.st_mtime;
                                        struct tm lt;
                                        localtime_r(&t, &lt);
                                        char timbuf[80];
                                        strftime(timbuf, sizeof(timbuf), "%c", &lt);
                                        printf("%s",timbuf);
                                        printf(" %s\n",string);
                                }
                                closedir(dr);
				chdir(cwd2);
			}
		}
	}
}


