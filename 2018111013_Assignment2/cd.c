#include "header.h"
void func1_cd(char* username,char* hostname)
{
	char full[4096];
	//if(input(command)){ continue;}
	//rem_space(command);
	if(flag2==1)
	{
		flag=2;
		return;
	}
	if(flag1==1)
	{
		if(strcmp(first,"cd")==0)
		{
			chdir(pwd);
			flag=0;
			return;
		}
		else
		{
			printf("Dont try to play around. Only 'cd' command is allowed.\n");
			flag=2;
			return;
		}
	}
	if(strcmp(first,"cd")==0)
	{
		flag=0;
		if(strcmp(second,"~")==0)
		{
			chdir(pwd);
			flag=0;
		}
		else if(strcmp(second,".")==0)
		{
			flag=2;
		}
		else
		{
			char slash[]="/";
			char slashh[100];
			char cwdd[4096];
			char cwdd2[4096];
			strcat(slash,second);
			getcwd(cwdd,sizeof(cwdd));
			strcat(cwdd,slash);
			strcpy(slashh,slash);
			strcpy(full,pwd);
			strcat(full,slashh);
			if(chdir(cwdd)!=0)
			{
				perror("Error");
				flag=2;
			}
			getcwd(cwdd,sizeof(cwdd));
			strcpy(cwdd2,cwdd);
			strcat(cwdd2,"/");
			if(strcmp(full,cwdd)==0 || strcmp(full,cwdd2)==0)
			{
				flag=1;
				flag3=1;
				printf("<%s@%s:~/%s>",username,hostname,second);
				strcpy(prev,username);
				strcat(prev,"@");
				strcat(prev,hostname);
				strcat(prev,":");
				strcat(prev,"~");
				strcat(prev,"/");
				strcat(prev,second);
			}
		}
	}
	else
	{
		flag=2;
		printf("Don't try to play around.Only 'cd' command is allowed\n");
	}
	return;
}
/*void rem_space(char *str)
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
  if(count==2)
  {
  strcpy(second,no_space_str);
  }
  if(count==3)
  {
  flag2=1;
  printf("Too many arguments\n");
  }
  }
  }
  if(count==1)
  {
  flag1=1;
  }
  }*/


