#include<dos.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 20
#define Q 40

//�����˿ͽṹ��
typedef struct
{
    char number[10];             //���
    char id[20];                 //֤����
    char name[10];               //����
    int count;                   //��Ʊ��
    char flightname[10];         //���������
}GUEST;

 //��������ṹ��
typedef struct
{
    char planenumber[12];           //�����
    char Take_off_city[15];         //��ɳ���
    char Arrived_in_city[8];        //�������
    char takeoff_time[8];           //���ʱ��
    char Landing_time[12];          //����ʱ��
    int shipping;                   //��λ��
    char price[15];                 //Ʊ��
    char discount[10];              //�ۿ�
    GUEST guest[20];
    int sit;
}FLY;

//�˵���������
void menu()
{
    printf("\n\n\n\n\n");
    printf("\t\t|--------------------------------------------|\n");
    printf("\t\t|------------------���ܲ˵�ѡ��--------------|\n");
    printf("\t\t|--------------------------------------------|\n");
    printf("\t\t|\t            1-¼�뺽��               |\n");
    printf("\t\t|\t            2-��������               |\n");
    printf("\t\t|\t            3-�����в�ѯ����         |\n");
    printf("\t\t|\t            4-�ͻ���Ʊ               |\n");
    printf("\t\t|\t            5-�ͻ���Ʊ               |\n");
    printf("\t\t|\t            6-�޸ķɻ�������Ϣ       |\n");
    printf("\t\t|\t            7-�˳���Ʊϵͳ           |\n");
    printf("\t\t|--------------------------------------------|\n");
    printf("\t\t|--------------------------------------------|\n");
    printf("\t\t|--------------------------------------------|\n");

}

//���뺯��
int enter(FLY t[])
{
    int i,k,n,m,w,j;
    char *s;
    printf("\t\t|\t��Ҫ¼�뺽��������(����40��):");
    scanf("%d",&n);
    while(n>40||n<0)
    {
        printf("\t\t|\t�������!!�ٴ�����(0<n<=40):");
        scanf("%d",&n);
    }
    printf("\t\t|\t��¼�뺽�����Ϣ:\n");
    printf("\t\t|--------------------------------------------|\n");
    for(i=0;i<n;i++)
    {
        printf("\n\n\t ����ſ�ͷ�涨:CA-�й����ʺ���CZ-�й��Ϻ���MU-�й�����\n\n");
        printf("\t\t|\t �����(����CZ1303):");
        scanf("%s",t[i].planenumber);//��������
        printf("\t\t|\t ��ɳ��У������Ϻ���:");
        scanf("%s",t[i].Take_off_city);//������ɳ���
        printf("\t\t|\t ������У������㶫��:");
        scanf("%s",t[i].Arrived_in_city);//���뽵�����
        printf("\t\t|\t ���ʱ�䣨����00��00��:");
        scanf("%s",t[i].takeoff_time);//�������ʱ��
        printf("\t\t|\t ����ʱ�䣨����00��00��:");
        scanf("%s",t[i].Landing_time);//���뽵��ʱ��
        printf("\t\t|\t ��λ��������:");
        scanf("%d",&t[i].shipping);//�����λ��
        printf("\t\t|\t Ʊ�ۣ�Ԫ��:");
        scanf("%s",t[i].price);//����Ʊ��
        printf("\t\t|\t �ۿۣ��ۣ�:");
        scanf("%s",t[i].discount);//�����ۿ�
        printf("\t\t|--------------------------------------------|\n");
    }
    printf("\t\t|--------------------------------------------|\n");
    for(i=0;i<n;i++)t[i].sit=0;
    return n; //���ؼ�¼����
}

//��ʾ��¼������Ϊ��¼����ͼ�¼����
void list(FLY t[],int n)
{
   int i;
   printf("\t\t|\t�����   ��ɳ���   �������      ����ʱ��       ����ʱ��       ����     �۸�Ԫ��  �ۿۣ��ۣ�\n");
   printf("\t\t|----------------------------------------------------------------------------------------\n");
   for(i=0;i<n;i++)
   printf("\t\t|\t% s\t  % s\t     % s\t  % s\t  % s\t% d  \t  % s\t     % s\n",t[i].planenumber,t[i].Take_off_city,t[i].Arrived_in_city,t[i].takeoff_time,t[i].Landing_time,t[i].shipping,t[i].price,t[i].discount);
   printf("\t\t|----------------------------------------------------------------------------------------\n");
}

//���𽵳��в��Ҽ�¼
void search2(FLY t[],int n)
{
   char s1[20];
   char s2[20];
   int i;
   printf("\t\t|\t������ɳ�������:");
   scanf("%s",s1); //������ɳ�����
   printf("\t\t|\t���뽵���������:");
   scanf("%s",s2); //���뽵�������
   for(i=0;i<n;i++)//�ӵ�һ����¼��ʼ��ֱ�����һ��
   {
       if((strcmp(s1,t[i].Take_off_city)==0)&&(strcmp(s2,t[i].Arrived_in_city)==0))  //��¼�еĳ��кʹ��Ƚϵ��Ƿ����
       break;   //��ȣ��򷵻ظü�¼���±�ţ�������ǰ�����
   }
   if(i>n-1)  //�������iֵ����n-1��˵��û�ҵ�
       printf("\t\t|\tû���ҵ�\n");
   else
    {
       printf("\t\t|\t�����   ��ɳ���   �������      ����ʱ��       ����ʱ��       ����     �۸�Ԫ��  �ۿۣ��ۣ�\n");
       printf("\t\t|----------------------------------------------------------------------------------------\n");
       printf("\t\t|\t% s\t  % s\t     % s\t  % s\t  % s\t% d  \t  % s\t     % s\n", t[i].planenumber, t[i].Take_off_city, t[i].Arrived_in_city, t[i].takeoff_time, t[i].Landing_time, t[i].shipping, t[i].price, t[i].discount);
   }
}

//��Ʊ
void book(FLY t[],int n)
{
   char s[20],number1[10],name1[10],id1[20],flightname1[10];
   int i,j=0,m,k,count1;
     printf("\t\t|\t��������Ԥ����Ʊ��:");
     scanf("%d",&m);
     printf("\t\t|\t����     ����       ֤����         ����Ʊ��  �����\n"); //��ʾ��Ϣ
     printf("\t\t|\t------------------------------------------------------------\n");
  for(k=0;k<m;k++)
   {
     printf("\t\t|\t �������:");
     scanf("%s",number1);//�������
     printf("\t\t|\t ����ͻ�����:");
     scanf("%s",name1);//���붩Ʊ�ͻ�����
     printf("\t\t|\t ����֤����:");
     scanf("%s",id1);//����֤����
     printf("\t\t|\t ���붩ƱƱ��:");
     scanf("%d",&count1);//���붩ƱƱ��
     printf("\t\t|\t ���뺽���:");
     scanf("%s",flightname1);//���뺽���
     for(i=0;i<n;i++)//�ӵ�һ����¼��ʼ��ֱ�����һ��
     {
          if(strcmp(flightname1,t[i].planenumber)==0)  //��¼�еĺ������ʹ��Ƚϵ��Ƿ����
          {
             j=t[i].sit;
             strcpy(t[i].guest[j].number,number1);
             strcpy(t[i].guest[j].name,name1);
             strcpy(t[i].guest[j].id,id1);
             t[i].guest[j].count=count1;
             strcpy(t[i].guest[j].flightname,flightname1);
             t[i].shipping=t[i].shipping-count1;
             t[i].sit++;
             break;   //��ȣ��򷵻ظü�¼���±�ţ�������ǰ�����
          }
     }
   if(i>n-1)  //�������iֵ����n-1��˵��û�ҵ�
   {
       printf("\t\t|\t �Բ���û�д˺���\n");
       m=m+2;
       k++;
    }
  }
}

//��Ʊ
void quit(FLY t[],int n)
{
   char s1[20],s2[20];   //��������Һ�������֤�����ַ���
   int i,k,j,h,l,ch;
   printf("\t\t|\t �����������˶��ĺ����:");
   scanf("%s",s1); //��������Һ�����
   printf("\t\t|\t ���������֤����:");
   scanf("%s",s2); //���������֤����
   printf("\t\t|\t����     ����       ֤����         ����Ʊ��  �����\n"); //��ʾ��ʾ
   printf("\t\t|\t------------------------------------------------------------\n");
   for(i=0;i<n;i++)//�ӵ�һ����¼��ʼ��ֱ�����һ��
    {
     for(j=0;j<t[i].sit;j++)
       if((strcmp(s1,t[i].guest[j].flightname)==0)&&(strcmp(s2,t[i].guest[j].id)==0))
      {
          printf("\t\t|\t%-11s%-16s%-16s%-14d%-10s\n",t[i].guest[j].number,t[i].guest[j].name,t[i].guest[j].id,t[i].guest[j].count,t[i].guest[j].flightname);
          t[i].shipping=t[i].shipping+t[i].guest[j].count;
          l=j;
          h=i;
          break;
      }
    }
   i=h;
   if(i>n-1)  //�������iֵ����n-1��˵��û�ҵ�
      printf("\t\t|\t û���ҵ�\n");
   else
   {
      printf("\t\t|\t ���Ƿ�ȷ��ɾ��(1/0)\n");//ȷ���Ƿ�Ҫɾ��
      scanf("%d",&ch);  //����һ��������
    if(ch==1)  //���ȷ��ɾ������Ϊ
     {
    for(k=l+1;k<t[i].sit;k++)
     {
     strcpy(t[i].guest[k-1].number,t[i].guest[k].number); //����һ����¼������������ǰһ��
     strcpy(t[i].guest[k-1].name,t[i].guest[k].name);
     strcpy(t[i].guest[k-1].id,t[i].guest[k].id);
     t[i].guest[k-1].count=t[i].guest[k].count;
     strcpy(t[i].guest[k-1].flightname,t[i].guest[k].flightname);
      }
    t[i].sit--;
     }
     printf("\t\t|\t ��Ʊ�ɹ�!!\n");//��ʾ��Ʊ�ɹ�
   }
}
//�޸ĺ�����Ϣ
void channge(FLY t[],int n)
{
   char s[20];  //Ҫɾ����¼������
   int i,j;
   printf("\t\t|\t ��������Ҫ�޸ĵĺ����:");//��ʾ��Ϣ
   scanf("%s",s);//���뺽����
   for(i=0;i<n;i++)//�ӵ�һ����¼��ʼ��ֱ�����һ��
   {
      if(strcmp(s,t[i].planenumber)==0)  //��¼�еĺ������ʹ��Ƚϵ��Ƿ����
      break;   //��ȣ��򷵻ظü�¼���±�ţ�������ǰ�����
   }
   if(i>n-1)  //�������iֵ����n-1��˵��û�ҵ�
       printf("\t\t|\t û���ҵ���\n");
   else
    {
       printf("\t\t|\t�����   ��ɳ���   �������      ����ʱ��       ����ʱ��       ����     �۸�Ԫ��  �ۿۣ��ۣ�\n");
       printf("\t\t|----------------------------------------------------------------------------------------\n");
       printf("\t\t|\t% s\t  % s\t     % s\t  % s\t  % s\t% d  \t  % s\t     % s\n", t[i].planenumber, t[i].Take_off_city, t[i].Arrived_in_city, t[i].takeoff_time, t[i].Landing_time, t[i].shipping, t[i].price, t[i].discount);
       printf("\t\t|----------------------------------------------------------------------------------------\n");
       printf("\t\t|\t��������Ҫ���ĵ���Ϣ��");
      printf("\t\t|\t��������");
      scanf("%s",t[i].planenumber);//���뺽����
      printf("\t\t|\t��ʼ���У�");
      scanf("%s",t[i].Take_off_city);//������ʼ����
      printf("\t\t|\t�յ���У�");
      scanf("%s",t[i].Arrived_in_city);//�����յ����
      printf("\t\t|\t���ʱ�䣺");
      scanf("%s",t[i].takeoff_time);//�������ʱ��
      printf("\t\t|\t����ʱ�䣺");
      scanf("%s",t[i].Landing_time);//���뽵��ʱ��
      printf("\t\t|\t��λ�ţ�");
      scanf("%d",t[i].shipping);//������λ��
      printf("\t\t|\tƱ�ۣ�");
      scanf("%s",t[i].price);//����Ʊ��
      printf("\t\t|\t�ۿۣ�");
      scanf("%s",t[i].discount);//�����ۿ�
   }
}

//������
main()
{  int i;
   FLY flight[Q];
   int length;  //�����¼����
   int n = 255,x;
    while(n!=1)//����ѭ��
   {
       menu();
       printf("\t\t|--------------------------------------------|\n");
       printf("\t\t|\t ��ѡ���ܣ�");
       scanf("%d", &x);
       printf("\t\t|--------------------------------------------|\n");
      switch(x)  
      {
         case 1:
              length=enter(flight);
              break;//���뺽��
         case 2:
             list(flight,length);
             break; //��ʾ����
         case 3:
             search2(flight,length);
             break; //�����в��Һ���
         case 4:
             book(flight,length);
             break;    //��Ʊ
         case 5:
             quit(flight,length);
             break;    //��Ʊ
         case 6:
             channge(flight,length);
             break; //�޸ĺ�����Ϣ
         case 7:
             exit(0); //�緵��ֵΪ��������
             default:break;
      }
   }

}