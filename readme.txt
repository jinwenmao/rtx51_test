������ʹ�ã���֪����ô��ͼ��ֻ����Ӹ�����


�½�һ�������ļ������潨�ĸ��ļ������ڴ����Ӧ�ļ�  

�½�һ��keil���̣���õ�������һ���ļ��У������ļ����������빤������(��at89c52Ϊ��)
���OK��
���ļ�·��XX:|\XXXXX\Keil_4\C51\RtxTiny2\SourceCode�ҵ�conf_tny.A51�ļ����������½���Ŀ��lib�ļ���
��������keil���
����ͼ
1����Operating system��ѡ��RTX-51 Tiny

2������ļ�ָ����output�ļ�����
���Ҫ����hex�ļ�����Ҫ��create HEXfileǰ�򹳣�������ʹ��keil���Կ�������ɴ�ɲ���
3��ָ�������ļ��ļ���

4����������Ҫ��һ�������debug���£���loadapplication at startupǰ��򹳣�����ͼ
��ˣ�keil���þͿ����ˣ�
��ʼ��д���Դ���
�½�һ��c�ļ������浽code�ļ������棬�ټ��뵽������ȥ
��д���Դ���
һ��Ҫ��ͷ�ļ�rtx51tny.h
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
inti,j=0;
   while(1)
{   
      j++;   
       for(i=0;i<10;i++)
       {
       dat=i+j;
       os_wait(K_TMO,5,0);   //�ȴ�50��ʱ�ӵδ�(ticks)
       }
       if(j%20==0)
       os_send_signal(1);    //������һ�����ź�
}
}
�����޴����ԣ����пɿ�����������watch1��������һֱ�ڱ仯

���ˣ�һ��rtx51tiny���Թ�����ɣ��ܵ���˵ֻ��Ҫע��������Ϳ����ˣ�
1��        ��operating system ��ѡ��RTX-51 Tiny
2��        ��Debug�е�load  applicationat startupǰ��

3��        �ڴ���ǰ���rtx51tny.hͷ�ļ�


����rtx51������������ʹ�ã���ο���ؼ����ĵ�
