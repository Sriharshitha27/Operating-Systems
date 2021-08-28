#include"header.h"
void jobs(void)
{
	for(int i=1;i<flag5;i++)
	{
		printf("[%d]",i);
		printf("%s ",arr_comm[array_pid[i]]);
		printf("[%d] -",array_pid[i]);
		char s[60];
		char str[60];
		FILE *fp1;
		char str1[60];
		sprintf(str,"%d",array_pid[i]);
		strcpy(s,str);
		char slash1[]="/proc/";
		strcat(slash1,s);
		strcat(slash1,"/");
		strcat(slash1,"stat");
		fp1 = fopen(slash1, "r");
		if(fp1 == NULL)
		{
			perror("Error:Process not found");
			return;
		}
		if( fgets (str1, 60, fp1)!=NULL )
		{
			int id;
			char exec[40];
			char status;
			sscanf(str1,"%d %s %c",&id,exec,&status);
			if((int)status==(int)'T')
			  {
			  array_status[array_pid[i]]=-1;
			  }
			  else if ((int)status==(int)'R' | (int)status==(int)'S')
			  {
			  array_status[array_pid[i]]=1;
			  }
			  if(array_status[array_pid[i]]==1)
			  {
			  printf(" RUNNING/SLEEPING");
			  }
			  else if(array_status[array_pid[i]]==-1)
			  {
			  printf(" STOPPED");
			  }
			 printf("(status:%c)\n",status);
		}
	}
	return ;
}

