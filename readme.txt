（初次使用，不知道怎么发图，只好添加附件）


新建一个测试文件夹里面建四个文件夹用于存放响应文件  

新建一个keil工程，最好单独建立一个文件夹（便于文件管理），输入工程名，(以at89c52为例)
点击OK，
打开文件路径XX:|\XXXXX\Keil_4\C51\RtxTiny2\SourceCode找到conf_tny.A51文件，拷贝到新建项目下lib文件夹
下面配置keil软件
如下图
1，在Operating system上选择RTX-51 Tiny

2将输出文件指定在output文件夹中
如果要生成hex文件，需要在create HEXfile前打钩，本例子使用keil调试看结果，可打可不打。
3，指定过程文件文件夹

4，下面最重要的一点就是在debug栏下，在loadapplication at startup前面打钩，如下图
如此，keil设置就可以了，
开始编写测试代码
新建一个c文件，保存到code文件夹下面，再加入到工程中去
编写测试代码
一定要加头文件rtx51tny.h
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
inti,j=0;
   while(1)
{   
      j++;   
       for(i=0;i<10;i++)
       {
       dat=i+j;
       os_wait(K_TMO,5,0);   //等待50个时钟滴答(ticks)
       }
       if(j%20==0)
       os_send_signal(1);    //给任务一发送信号
}
}
编译无错后调试，运行可看到下面结果，watch1窗口数字一直在变化

至此，一个rtx51tiny测试工程完成，总的来说只需要注意三个点就可以了，
1，        在operating system 中选择RTX-51 Tiny
2，        在Debug中的load  applicationat startup前打钩

3，        在代码前面加rtx51tny.h头文件


其他rtx51技术，及函数使用，请参考相关技术文档
