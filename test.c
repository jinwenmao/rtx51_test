   /*******************************************************/
#include <rtx51tny.h>
#include <reg52.h>
typedef unsigned char uchar;
typedef unsigned int  uint;
uchar dat[10];
uchar ch=0;
void job0(void) _task_ 0  
{      
os_create_task(1); //��������1
os_create_task(2);   //��������2
       os_delete_task(0);   //ɾ���Լ�(task0),ʹtask0�˳���������
}  
   
void job1(void) _task_ 1  
{  
while(1)
{
       os_wait(K_SIG,0, 0);  //�ȴ�һ���źţ��˴��ȴ�����2���͵���Ϣ
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
       os_wait(K_TMO,5,0);   //�ȴ�50��ʱ�ӵδ�(ticks)
       }
       if(j%20==0)
       os_send_signal(1);    //������һ�����ź�
}
}