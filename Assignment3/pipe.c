#include"header.h"
void func12_pipe1()
{
	int status;
	int num_of_pipes=test-1;
	int p[2*num_of_pipes];
	for(int i=0;i<num_of_pipes;i++)
	{
		if(pipe(p+i*2)<0)
		{
			exit(1);
		}
	}
	int j=0;
	for(int k=0;k<test;k++)
	{
		int pid=fork();
		if(pid==0)
		{
			char * argv1[20];
			int jj=0;
			int ccc=0;
			while(cmd[k][jj]!=NULL)
			{
				argv1[jj]=cmd[k][jj];
				jj++;
			}
			argv1[jj]=NULL;
			if(k!=0)
			{
				if(k==test-1)
				{
					if(aaa==0 && bbb==0)
					{
						if(dup2(p[(j-1)*2],0)<0)
						{
							exit(0);
						}
					}
					else
					{
						int fd;
						if(aaa==1)
						{
							fd=open(argv1[jj-1], O_WRONLY | O_APPEND | O_CREAT, 0644);
						}
						else if(bbb==1)
						{
							fd=open(argv1[jj-1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
						}
						close(1);
						if(dup2(fd,1)!=1)
						{
							perror("dup2 failed");
						}
						close(fd);
						dup2(1,fd);
						if(dup2(p[(j-1)*2],0)<0)
						{
							exit(0);
						}
						argv1[jj-2]=NULL;
					}
				}
				else
				{
					if(dup2(p[(j-1)*2],0)<0)
					{
						exit(0);
					}
				}
			}
			if(k!=test-1)
			{
				if(dup2(p[2*j+1],1)<0)
				{
					exit;
				}
			}
			for(int i=0;i<2*num_of_pipes;i++)
			{
				close(p[i]);
			}

			if(execvp(argv1[0],argv1)<0)
			{
				perror("*** ERROR: exec failed\n");
				exit(1);
			}

			exit(1);
		}
		else if (pid<0)
		{
			perror("Error in forking the process\n");
			exit(0);
		}
		j++;
	}
	for(int i=0;i<2*num_of_pipes;i++)
	{
		close(p[i]);
	}
	for(int i=0;i<num_of_pipes+1;i++)
	{
		wait(&status);
	}
	return;
}

































