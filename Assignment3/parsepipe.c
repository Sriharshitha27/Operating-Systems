#include"header.h"
void parsepipe(void)
{
	int c=0;
	char *yo;
	char *argv1[100];
	while((yo = strsep(&str4," "))!= NULL)
	{
		char * empty=malloc(100*sizeof(char));
		empty=strdup("\0");
		if(strcmp(empty,yo)!=0)
		{
			if(strcmp(yo,">>")==0)
			{
				aaa=1;
			}
			if(strcmp(yo,">")==0)
			{
				bbb=1;
			}
			cmd[test2][c]=yo;
			//argv1[c]=yo;
			c++;
		}
		
	}
	//argv1[c]=NULL;
	cmd[test2][c]=NULL;
	/*for(int i=0;i<c;i++)
	{
		printf("%s ",cmd[test2][i]);
	}
	printf("\n");*/
	
	return;

}





