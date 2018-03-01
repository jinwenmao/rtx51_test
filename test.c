   /*******************************************************/
#include <rtx51tny.h>
#include <reg52.h>
typedef unsigned char uchar;
typedef unsigned int  uint;
uchar dat[10];
uchar ch=0;
void job0(void) _task_ 0  
{      
os_create_task(1); //创建任务1
os_create_task(2);   //创建任务2
       os_delete_task(0);   //删除自己(task0),使task0退出任务链表
}  
   
void job1(void) _task_ 1  
{  
while(1)
{
       os_wait(K_SIG,0, 0);  //等待一个信号，此处等待任务2发送的消息
       ch=dat[0];  
   }  
}     
void job2(void) _task_ 2  
{  
int i,j=0;

   while(1)
{   
      j++;   
       for(i=0;i<10;i++)
       {
       dat[i]=i+j;
       os_wait(K_TMO,5,0);   //等待50个时钟滴答(ticks)
       }
       if(j%20==0)
       os_send_signal(1);    //给任务一发送信号
}
}