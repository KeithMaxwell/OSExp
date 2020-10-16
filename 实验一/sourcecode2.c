#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
    //fork()结果为-1，则创建进程失败。结果为0则为子进程，结果>0则为父进程。结果为子进程的pid。
    fork();     //父进程1创建子进程2
    fork();     //父进程1返回后创建子进程3，子进程2返回后创建子进程4
    fork();     //父进程1返回后创建子进程5，子进程2返回后创建子进程6，子进程3返回后创建子进程7，子进程4返回后创建子进程8
    
    printf("%s","A");   //所以总共会有8次输出
    // printf("%d\n",(int)getpid());
    
    return 0;
}