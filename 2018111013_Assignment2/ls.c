#include "header.h"
void func2_ls(void)
{
	//if(input(command)){ continue;}
	//rem_space(command);
	if(strcmp(first,"ls")==0)
	{
		if(count==1)
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
				char name1[100];
				strcpy(name1,de->d_name);
				if((int)name1[0]!=46)
				{
					printf("%s\n",de->d_name);
				}
			}
			closedir(dr);
			return;
		}
		if(count==2)
		{
			if(strcmp(second,"-a")==0)
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
					printf("%s\n",de->d_name);
				}
				closedir(dr);
			}
			else if(strcmp(second,"-la")==0 || strcmp(second,"-al")==0)
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
			else if(strcmp(second,"-l")==0)
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
			}
			else
			{
				char name1[100];
				struct dirent *de;
				DIR *dr;
				if(strcmp(second,"~")!=0)
				{
					dr=opendir(second);
				}
				else
				{
					dr=opendir(cwd);
				}
				if(dr==NULL)
				{
					printf("Could not open the directory.It does'nt exist.\n");
					return;
				}
				while((de=readdir(dr))!=NULL)
				{
					strcpy(name1,de->d_name);
					if((int)name1[0]!=46)
					{
						printf("%s\n",de->d_name);
					}
				}
				closedir(dr);
			}

		}

	}
	else
	{
		printf("Don't try to play around.Only 'ls' operations are allowed\n");
	}
}
/*
   void rem_space(char *str)
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
   }
   if(count==2)
   {
   strcpy(second,no_space_str);
   }
   if(count==3)
   {
//flag2=1;
printf("Too many arguments\n");
}
}
}
}
*/
