#include "header.h"
void unsetenvvar(void)
{
        if(count==1)
        {
                printf("ERROR: Argument is not given\n");
                return;
        }
        else if(count>2)
        {
                printf("ERROR: Takes only 1 argument format is - unsetenv <varname>\n");
                return;
        }
        int a;
        char *d;
        a=unsetenv(argv[1]);
	if(a!=0)
	{
		perror("Could'nt unset the variable");
	}
        /*d=getenv(argv[1]);
        if(d==NULL)
	{
	printf("Done.");
	}*/
	return;
}

