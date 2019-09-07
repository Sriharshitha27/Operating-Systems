#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<readline/readline.h>
#include<readline/history.h>
#include<dirent.h>
#include<errno.h>
#include<pwd.h>
#include<grp.h>
#include<time.h>
#include<fcntl.h>
#include<limits.h>
#define clear() printf("\033[H\033[J")
int input(char* );
void rem_space(char *);
void func1_cd(char *,char *);
void func2_ls(void);
void func3_echo(void);
void func4_pwd(void);
void func5_fg(void);
void func6_bg(void);
int func7_proc(void);
void func8_big_ls(void);
void proc_exit(int );
char * no_space_str;
char *str1;// malloc(1024 * sizeof(char));
char *argv[64];
char first[100];
char second[100];
char prev[100];
char prev2[100];
char cwd[4096];
char pwd[4096];
int array_pid[5000];
char * arr_comm[10000000];
char * arr_ls[1000];
int flag2;
int flag;
int flag1;
int flag3;
int flag4;
int flag5;
int flag6;
int count;
int status;
pid_t pid;




