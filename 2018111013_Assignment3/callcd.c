#include"header.h"
void call_cd(char *username,char *hostname)
{
	int num;
	char* f[20];
	if(flag9==1 && flag8==1)
        {
                for(num=0;num<input_redir_point;num++)
                {
                        f[num]=argv[num];
                }
        }
	else if(flag8==1)
	{
		for(num=0;num<output_redir_point;num++)
		{
			f[num]=argv[num];
		}
	}
	else if(flag9==1)
	{
		for(num=0;num<input_redir_point;num++)
		{
			f[num]=argv[num];
		}
	}
	if(num==1)
	{
		chdir(pwd);
		flag=0;
	}
	if(num==2)
	{
		char full[100];
		flag=0;
		if(strcmp(f[1],"~")==0)
		{
			chdir(pwd);
			flag=0;
		}
		else if(strcmp(f[1],".")==0)
		{
			flag=2;
		}
		else
		{
			char slash[]="/";
			char slashh[100];
			char cwdd[4096];
			char cwdd2[4096];
			strcat(slash,f[1]);
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
				sprintf(har,"<%s@%s:~/%s> ",username,hostname,f[1]);
				strcpy(prev,username);
				strcat(prev,"@");
				strcat(prev,hostname);
				strcat(prev,":");
				strcat(prev,"~");
				strcat(prev,"/");
				strcat(prev,f[1]);
			}
		}
	}
	return;
}
