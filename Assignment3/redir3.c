#include "header.h"
void func11_redir3(void)
{
	long long int ii;
        char *argv1[64];
        for(ii=0;ii<input_redir_point;ii++)
        {
                argv1[ii]=argv[ii];
        }
        argv1[ii]=NULL;
	int fin,fout;
	if((fin=open(argv[input_redir_point+1],O_RDONLY))==-1)
        {
                perror("Error opening the file");
        }
	if(strcmp(argv[output_redir_point],">>")==0)
        {
                fout=open(argv[output_redir_point+1], O_WRONLY | O_APPEND | O_CREAT, 0644);
        }
        else
        {

                fout=open(argv[output_redir_point+1], O_WRONLY | O_CREAT | O_TRUNC , 0644);
        }
	int pid;
	if((pid=fork())<0)
        {
                printf("*** ERROR: forking child process failed\n");
                exit(1);
        }
        if(pid==0)
        {
                close(0);
		if(dup2(fin,0)!=0)
                {
                        perror("dup2 failed");
                }
                close(fin);
                if(dup2(fout,1)!=1)
                {
                        perror("dup2 failed");
                }
                close(fout);
                if(execvp(argv1[0],argv1)<0)
                {
                        printf("*** ERROR: exec failed\n");
                        exit(1);
                }
                exit(0);
        }
        else
        {
                //       while (wait(NULL) != pid);
        }
	return ;
}





