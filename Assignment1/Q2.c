#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include<fcntl.h>
#include<string.h>
#include<dirent.h>
#include<errno.h>
#include<stdlib.h>
int main(int argc,char * argv[])
{
	int flag=0;
	DIR* dir = opendir(argv[3]);
	if (dir) 
	{
		flag=1;
		write(1,"DIRECTORY IS CREATED AND IT EXISTS : YES\n",strlen("DIRECTORY IS CREATED AND IT EXISTS : YES\n"));
		closedir(dir);
	}
	else if (ENOENT == errno)
	{
		write(1,"DIRECTORY IS CREATED AND IT EXISTS : NO\n",strlen("DIRECTORY IS CREATED AND IT EXISTS : NO\n"));
	} 
	else 
	{
		write(1,"It failed for some other reason.\n",strlen("It failed for some other reason.\n"));
	}
	for(int i=1;i<=2;i++)
	{
		if (i==1){ write(1,"File permissions of the NEW FILE are:\n",strlen("File permissions of the NEW FILE are:\n"));}
		else { write(1,"File permissions of the OLD FILE are:\n",strlen("File permissions of the OLD FILE are:\n"));}
		struct stat S;
		stat(argv[i],&S);
		if(stat(argv[i],&S)<0)
		{
			return 1;
		}
		if(S.st_mode & S_IRUSR)
		{
			write(1,"USER HAS READ PERMISSIONS : YES\n",strlen("USER HAS READ PERMISSIONS : YES\n"));
		}
		else
		{
			write(1,"USER HAS READ PERMISSIONS : NO\n",strlen("USER HAS READ PERMISSIONS : NO\n"));
		}
		if(S.st_mode & S_IWUSR)
		{
			write(1,"USER HAS WRITE PERMISSIONS : YES\n",strlen("USER HAS WRITE PERMISSIONS : YES\n"));
		}
		else
		{
			write(1,"USER HAS WRITE PERMISSIONS : NO\n",strlen("USER HAS WRITE PERMISSIONS : NO\n"));
		}
		if(S.st_mode & S_IXUSR)
		{
			write(1,"USER HAS EXECUTE PERMISSIONS : YES\n",strlen("USER HAS EXECUTE PERMISSIONS : YES\n"));
		}
		else
		{
			write(1,"USER HAS EXECUTE PERMISSIONS : NO\n",strlen("USER HAS EXECUTE PERMISSIONS : NO\n"));
		}
		if(S.st_mode & S_IRGRP)
		{
			write(1,"GROUP HAS READ PERMISSIONS : YES\n",strlen("GROUP HAS READ PERMISSIONS : YES\n"));
		}
		else
		{
			write(1,"GROUP HAS READ PERMISSIONS : NO\n",strlen("GROUP HAS READ PERMISSIONS : NO\n"));
		}
		if(S.st_mode & S_IWGRP)
		{
			write(1,"GROUP HAS WRITE PERMISSIONS : YES\n",strlen("GROUP HAS WRITE PERMISSIONS : YES\n"));
		}
		else
		{
			write(1,"GROUP HAS WRITE PERMISSIONS : NO\n",strlen("GROUP HAS WRITE PERMISSIONS : NO\n"));
		}
		if(S.st_mode & S_IXGRP)
		{
			write(1,"GROUP HAS EXECUTE PERMISSIONS : YES\n",strlen("GROUP HAS EXECUTE PERMISSIONS : YES\n"));
		}
		else
		{
			write(1,"GROUP HAS EXECUTE PERMISSIONS : NO\n",strlen("GROUP HAS EXECUTE PERMISSIONS : NO\n"));
		}
		if(S.st_mode & S_IROTH)
		{
			write(1,"OTHERS HAVE READ PERMISSIONS : YES\n",strlen("OTHERS HAVE READ PERMISSIONS : YES\n"));
		}
		else
		{
			write(1,"OTHERS HAVE READ PERMISSIONS : NO\n",strlen("OTHERS HAVE READ PERMISSIONS : NO\n"));
		}
		if(S.st_mode & S_IWOTH)
		{
			write(1,"OTHERS HAVE WRITE PERMISSIONS : YES\n",strlen("OTHERS HAVE WRITE PERMISSIONS : YES\n"));
		}
		else
		{
			write(1,"OTHERS HAVE WRITE PERMISSIONS : NO\n",strlen("OTHERS HAVE WRITE PERMISSIONS : NO\n"));
		}
		if(S.st_mode & S_IXOTH)
		{
			write(1,"OTHERS HAVE EXECUTE PERMISSIONS : YES\n",strlen("OTHERS HAVE EXECUTE PERMISSIONS : YES\n"));
		}
		else
		{
			write(1,"OTHERS HAVE EXECUTE PERMISSIONS : NO\n",strlen("OTHERS HAVE EXECUTE PERMISSIONS : NO\n"));
		}
		write(1,"\n",strlen("\n"));
	}
	if(flag==1)
	{
		write(1,"File permissions of the FOLDER are:\n",strlen("File permissions of the FOLDER are:\n"));
		struct stat S;
		stat(argv[3],&S);
		if(stat(argv[3],&S)<0)
		{
			return 1;
		}
		if(S.st_mode & S_IRUSR)
		{
			write(1,"USER HAS READ PERMISSIONS : YES\n",strlen("USER HAS READ PERMISSIONS : YES\n"));
		}
		else
		{
			write(1,"USER HAS READ PERMISSIONS : NO\n",strlen("USER HAS READ PERMISSIONS : NO\n"));
		}
		if(S.st_mode & S_IWUSR)
		{
			write(1,"USER HAS WRITE PERMISSIONS : YES\n",strlen("USER HAS WRITE PERMISSIONS : YES\n"));
		}
		else
		{
			write(1,"USER HAS WRITE PERMISSIONS : NO\n",strlen("USER HAS WRITE PERMISSIONS : NO\n"));
		}
		if(S.st_mode & S_IXUSR)
		{
			write(1,"USER HAS EXECUTE PERMISSIONS : YES\n",strlen("USER HAS EXECUTE PERMISSIONS : YES\n"));
		}
		else
		{
			write(1,"USER HAS EXECUTE PERMISSIONS : NO\n",strlen("USER HAS EXECUTE PERMISSIONS : NO\n"));
		}
		if(S.st_mode & S_IRGRP)
		{
			write(1,"GROUP HAS READ PERMISSIONS : YES\n",strlen("GROUP HAS READ PERMISSIONS : YES\n"));
		}
		else
		{
			write(1,"GROUP HAS READ PERMISSIONS : NO\n",strlen("GROUP HAS READ PERMISSIONS : NO\n"));
		}
		if(S.st_mode & S_IWGRP)
		{
			write(1,"GROUP HAS WRITE PERMISSIONS : YES\n",strlen("GROUP HAS WRITE PERMISSIONS : YES\n"));
		}
		else
		{
			write(1,"GROUP HAS WRITE PERMISSIONS : NO\n",strlen("GROUP HAS WRITE PERMISSIONS : NO\n"));
		}
		if(S.st_mode & S_IXGRP)
		{
			write(1,"GROUP HAS EXECUTE PERMISSIONS : YES\n",strlen("GROUP HAS EXECUTE PERMISSIONS : YES\n"));
		}
		else
		{
			write(1,"GROUP HAS EXECUTE PERMISSIONS : NO\n",strlen("GROUP HAS EXECUTE PERMISSIONS : NO\n"));
		}
		if(S.st_mode & S_IROTH)
		{
			write(1,"OTHERS HAVE READ PERMISSIONS : YES\n",strlen("OTHERS HAVE READ PERMISSIONS : YES\n"));
		}
		else
		{
			write(1,"OTHERS HAVE READ PERMISSIONS : NO\n",strlen("OTHERS HAVE READ PERMISSIONS : NO\n"));
		}
		if(S.st_mode & S_IWOTH)
		{
			write(1,"OTHERS HAVE WRITE PERMISSIONS : YES\n",strlen("OTHERS HAVE WRITE PERMISSIONS : YES\n"));
		}
		else
		{
			write(1,"OTHERS HAVE WRITE PERMISSIONS : NO\n",strlen("OTHERS HAVE WRITE PERMISSIONS : NO\n"));
		}
		if(S.st_mode & S_IXOTH)
		{
			write(1,"OTHERS HAVE EXECUTE PERMISSIONS : YES\n",strlen("OTHERS HAVE EXECUTE PERMISSIONS : YES\n"));
		}
		else
		{
			write(1,"OTHERS HAVE EXECUTE PERMISSIONS : NO\n",strlen("OTHERS HAVE EXECUTE PERMISSIONS : NO\n"));
		}
		write(1,"\n",strlen("\n"));
	}
	int f_old=open(argv[2],O_RDONLY);
	int f_new=open(argv[1],O_RDONLY);
	if(f_old==-1)
	{
		perror("r1");
		exit(1);
	}
	if(f_new==-1)
	{
		perror("r1");
		exit(1);
	}
	char b1[4096],b2[4096];
	long long int n_old=lseek(f_old,0,SEEK_END);
	long long int n_new=lseek(f_new,0,SEEK_END);
	if(n_old!=n_new)
	{
		write(1,"CONTENTS IN THE OLD FILE ARE REVERSED INTO THE NEWFILE: NO \n",strlen("CONTENTS IN THE OLD FILE ARE REVERSED INTO THE NEWFILE: NO \n"));
	}
	else
	{
		lseek(f_old,0,SEEK_SET);
		long long int i=0;
		long long int count=0;
		long long int flag=0;
		long long int n=n_old;
		long long int flag1=0;
		while(n>=4096)
		{
			count=0;
			i++;
			read(f_old,b1,4096);
			lseek(f_new,-(i*4096),SEEK_END);
			read(f_new,b2,4096);
			for(long long int k=0;k<4096;k++)
			{
				if(b1[k]==b2[4096-k-1])
				{
					count++;
				}
				else
				{
					write(1,"CONTENTS IN THE OLD FILE ARE REVERSED INTO THE NEWFILE: NO \n",strlen("CONTENTS IN THE OLD FILE ARE REVERSED INTO THE NEWFILE: NO \n"));
					flag=0;
					flag1=1;
					break;
				}
			}
			if(flag1==1)
			{
				break;
			}
			if(count==4096)
			{
				flag=1;
			}
			n=n-4096;
		}
		if(n<4096 && flag1!=1)
		{
			read(f_old,b1,n);
			lseek(f_new,0,SEEK_SET);
			read(f_new,b2,n);
			for(long long int k=0;k<n;k++)
			{	
				if(b1[k]==b2[n-k-1])
				{
					count++;
				}
				else
				{
					write(1,"CONTENTS IN THE OLD FILE ARE REVERSED INTO THE NEWFILE: NO \n",strlen("CONTENTS IN THE OLD FILE ARE REVERSED INTO THE NEWFILE: NO \n"));
					flag=0;
					break;
				}
			}
			if(count==n)
			{
				flag=1;
			}
		}
		if(flag==1)
		{
			write(1,"CONTENTS IN THE OLD FILE ARE REVERSED INTO THE NEWFILE: YES \n",strlen("CONTENTS IN THE OLD FILE ARE REVERSED INTO THE NEWFILE: YES \n"));
		}
	}
	if(close(f_new)<0)
        {
                perror("c1");
                exit(1);
        }
        if(close(f_old)<0)
        {
                perror("c1");
                exit(1);
        }
	return 0;
}




