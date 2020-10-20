#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
const int looptimes = 5;
int main()
{
    int p = fork(); //结果为-1，则创建进程失败。结果为0则为子进程，结果>0则为父进程。结果为子进程的pid。
    if (p == -1) exit(-1);  
    
    if (p == 0) //  子进程
    {
        for(int i=0;i<looptimes;i++)
        {
            puts("I'm child!");
            sleep(1);
        }
        
    }
    else if(p > 0)  //父进程
    {
        int wc = wait(NULL);
        printf("wc的值为：%d，p的值为：%d\n",wc,p);
        for(int i=0;i<looptimes;i++)
        {
            printf("%s","我是父进程！\n");
            sleep(1);
        }
    }
    
    
    return 0;
}