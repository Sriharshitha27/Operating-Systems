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
#include<signal.h>
#include<readline/readline.h>
#include<readline/history.h>
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
void func9_redir1(void);
void func10_redir2(void);
void func11_redir3(void);
void func12_pipe1(void);
void parsepipe(void);
void setenvvar(void);
void unsetenvvar(void);
void jobs(void);
void kjobs(void);
void overkill(void);
void sigint_handler(int);
void sigtstp_handler(int);
void proc_exit(int );
void bgg(void);
void fgg(void);
void call_cd(char* ,char *);
char * no_space_str;
char *str1;
char *str4;
char har[100];
int test;
int test2;
char *argv[64];
char *argv1[64];
char *cmd[64][64];
char first[100];
char second[100];
char prev[100];
char prev2[100];
char cwd[4096];
char pwd[4096];
int array_pid[50000000];
char * arr_comm[10000000];
int array_index[5000000];
int array_status[1000000];
char * arr_ls[1000];
int flag;
int flag2;
int flag1;
int flag3;
int flag4;
int flag5;
int flag6;
int flag8;
int flag9;
int flag10;
int childpid;
int shellpid;
int aaa,bbb;
int output_redir_point;
int input_redir_point;
int count;
int status;
pid_t pid;




