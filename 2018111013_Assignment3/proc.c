#include "header.h"
int func7_proc(void)
{
	int p_id;
	FILE *fp1;
	char str[60];
	char str1[60];
	char s[60];
	if(count==1)
	{
		p_id=getpid();
		sprintf(str,"%d",p_id);
		strcpy(s,str);
	}
	if(count==2)
	{
		strcpy(s,second);
	}
	char slash1[]="/";
	strcat(slash1,"proc");
	strcat(slash1,"/");
	strcat(slash1,s);
	strcat(slash1,"/");
	strcat(slash1,"stat");
	fp1 = fopen(slash1, "r");
	if(fp1 == NULL)
       	{
		perror("Error opening file");
		return(-1);
	}
	if( fgets (str1, 60, fp1)!=NULL ) 
	{
		int id;
		char exec[40];
		char status;
		printf("%s",str1);
		sscanf(str1,"%d %s %c",&id,exec,&status);
		printf(" Pid -- %d\n Process status -- %c\n Executable file -- %s\n",id,status,exec);
		char buf[PATH_MAX];
		char *res = realpath(exec, buf);
		if (res) 
		{
			printf(" Path of the executable -- %s\n", buf);
		}
		else 
		{
			//perror("Real path");
		}
	}
	fclose(fp1);
	FILE *fp2;
	char str2[60];
	char slash2[]="/";
	strcat(slash2,"proc");
	strcat(slash2,"/");
	strcat(slash2,s);
	strcat(slash2,"/");
	strcat(slash2,"statm");
	fp2 = fopen(slash2, "r");
	if(fp2 == NULL) {
		perror("Error opening file");
		return(-1);
	}
	if( fgets (str2, 60, fp2)!=NULL ) {
		int memory;
		sscanf(str2,"%d",&memory);
		printf(" Memory -- %d\n",memory);
	}
	fclose(fp2);
	return 0;
}
