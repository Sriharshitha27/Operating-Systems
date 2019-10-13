#include "header.h"
void setenvvar(void)
{
	if(count==1)
	{
		printf("ERROR: Arguments not given\n");
		return;
	}
	else if(count>3)
	{
		printf("ERROR: Takes only 2 arguments format is - setenv <var> <val>\n");
		return;
	}
	else if(count==2)
	{
	        int a=setenv(argv[1],"",1);
		  if(a!=0)
                {
                        perror("Could'nt set the variable");
                }
	}
	else
	{
		int a;
		char *d;
		a=setenv(argv[1],argv[2],1);
		if(a!=0)
		{
			perror("Could'nt set the variable");
		}
	}
	/*d=getenv(argv[1]);
	  printf("%s\n",d);
	  d=getenv(argv[1]);
	  if(d!=NULL)
	  {
	  printf("%s\n",d);
	  }*/
	return;
}
