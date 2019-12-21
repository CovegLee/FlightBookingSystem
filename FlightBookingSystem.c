#include<dos.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 20
#define Q 40

//创建乘客结构体
typedef struct
{
    char number[10];             //编号
    char id[20];                 //证件号
    char name[10];               //姓名
    int count;                   //订票数
    char flightname[10];         //乘坐航班号
}GUEST;

 //创建航班结构体
typedef struct
{
    char planenumber[12];           //航班号
    char Take_off_city[15];         //起飞城市
    char Arrived_in_city[8];        //降落城市
    char takeoff_time[8];           //起飞时间
    char Landing_time[12];          //降落时间
    int shipping;                   //舱位数
    char price[15];                 //票价
    char discount[10];              //折扣
    GUEST guest[20];
    int sit;
}FLY;

//菜单（函数）
void menu()
{
    printf("\n\n\n\n\n");
    printf("\t\t|--------------------------------------------|\n");
    printf("\t\t|------------------功能菜单选择--------------|\n");
    printf("\t\t|--------------------------------------------|\n");
    printf("\t\t|\t            1-录入航班               |\n");
    printf("\t\t|\t            2-航班总览               |\n");
    printf("\t\t|\t            3-按城市查询航班         |\n");
    printf("\t\t|\t            4-客户订票               |\n");
    printf("\t\t|\t            5-客户退票               |\n");
    printf("\t\t|\t            6-修改飞机航班信息       |\n");
    printf("\t\t|\t            7-退出订票系统           |\n");
    printf("\t\t|--------------------------------------------|\n");
    printf("\t\t|--------------------------------------------|\n");
    printf("\t\t|--------------------------------------------|\n");

}

//输入函数
int enter(FLY t[])
{
    int i,k,n,m,w,j;
    char *s;
    printf("\t\t|\t您要录入航线总数是(限制40条):");
    scanf("%d",&n);
    while(n>40||n<0)
    {
        printf("\t\t|\t输入错误!!再次输入(0<n<=40):");
        scanf("%d",&n);
    }
    printf("\t\t|\t请录入航班的信息:\n");
    printf("\t\t|--------------------------------------------|\n");
    for(i=0;i<n;i++)
    {
        printf("\n\n\t 航班号开头规定:CA-中国国际航，CZ-中国南航，MU-中国东航\n\n");
        printf("\t\t|\t 航班号(例：CZ1303):");
        scanf("%s",t[i].planenumber);//输入姓名
        printf("\t\t|\t 起飞城市（例：上海）:");
        scanf("%s",t[i].Take_off_city);//输入起飞城市
        printf("\t\t|\t 降落城市（例：广东）:");
        scanf("%s",t[i].Arrived_in_city);//输入降落城市
        printf("\t\t|\t 起飞时间（例：00：00）:");
        scanf("%s",t[i].takeoff_time);//输入起飞时间
        printf("\t\t|\t 降落时间（例：00：00）:");
        scanf("%s",t[i].Landing_time);//输入降落时间
        printf("\t\t|\t 舱位数（个）:");
        scanf("%d",&t[i].shipping);//输入舱位数
        printf("\t\t|\t 票价（元）:");
        scanf("%s",t[i].price);//输入票价
        printf("\t\t|\t 折扣（折）:");
        scanf("%s",t[i].discount);//输入折扣
        printf("\t\t|--------------------------------------------|\n");
    }
    printf("\t\t|--------------------------------------------|\n");
    for(i=0;i<n;i++)t[i].sit=0;
    return n; //返回记录条数
}

//显示记录，参数为记录数组和记录条数
void list(FLY t[],int n)
{
   int i;
   printf("\t\t|\t航班号   起飞城市   降落城市      出发时间       降落时间       余座     价格（元）  折扣（折）\n");
   printf("\t\t|----------------------------------------------------------------------------------------\n");
   for(i=0;i<n;i++)
   printf("\t\t|\t% s\t  % s\t     % s\t  % s\t  % s\t% d  \t  % s\t     % s\n",t[i].planenumber,t[i].Take_off_city,t[i].Arrived_in_city,t[i].takeoff_time,t[i].Landing_time,t[i].shipping,t[i].price,t[i].discount);
   printf("\t\t|----------------------------------------------------------------------------------------\n");
}

//按起降城市查找记录
void search2(FLY t[],int n)
{
   char s1[20];
   char s2[20];
   int i;
   printf("\t\t|\t输入起飞城市名称:");
   scanf("%s",s1); //输入起飞城市名
   printf("\t\t|\t输入降落城市名称:");
   scanf("%s",s2); //输入降落城市名
   for(i=0;i<n;i++)//从第一条记录开始，直到最后一条
   {
       if((strcmp(s1,t[i].Take_off_city)==0)&&(strcmp(s2,t[i].Arrived_in_city)==0))  //记录中的城市和待比较的是否相等
       break;   //相等，则返回该记录的下标号，程序提前结结束
   }
   if(i>n-1)  //如果整数i值大于n-1，说明没找到
       printf("\t\t|\t没有找到\n");
   else
    {
       printf("\t\t|\t航班号   起飞城市   降落城市      出发时间       降落时间       余座     价格（元）  折扣（折）\n");
       printf("\t\t|----------------------------------------------------------------------------------------\n");
       printf("\t\t|\t% s\t  % s\t     % s\t  % s\t  % s\t% d  \t  % s\t     % s\n", t[i].planenumber, t[i].Take_off_city, t[i].Arrived_in_city, t[i].takeoff_time, t[i].Landing_time, t[i].shipping, t[i].price, t[i].discount);
   }
}

//订票
void book(FLY t[],int n)
{
   char s[20],number1[10],name1[10],id1[20],flightname1[10];
   int i,j=0,m,k,count1;
     printf("\t\t|\t输入你想预订的票数:");
     scanf("%d",&m);
     printf("\t\t|\t号码     姓名       证件号         订的票数  航班号\n"); //提示信息
     printf("\t\t|\t------------------------------------------------------------\n");
  for(k=0;k<m;k++)
   {
     printf("\t\t|\t 订单编号:");
     scanf("%s",number1);//订单编号
     printf("\t\t|\t 输入客户姓名:");
     scanf("%s",name1);//输入订票客户姓名
     printf("\t\t|\t 输入证件号:");
     scanf("%s",id1);//输入证件号
     printf("\t\t|\t 输入订票票数:");
     scanf("%d",&count1);//输入订票票数
     printf("\t\t|\t 输入航班号:");
     scanf("%s",flightname1);//输入航班号
     for(i=0;i<n;i++)//从第一条记录开始，直到最后一条
     {
          if(strcmp(flightname1,t[i].planenumber)==0)  //记录中的航班名和待比较的是否相等
          {
             j=t[i].sit;
             strcpy(t[i].guest[j].number,number1);
             strcpy(t[i].guest[j].name,name1);
             strcpy(t[i].guest[j].id,id1);
             t[i].guest[j].count=count1;
             strcpy(t[i].guest[j].flightname,flightname1);
             t[i].shipping=t[i].shipping-count1;
             t[i].sit++;
             break;   //相等，则返回该记录的下标号，程序提前结结束
          }
     }
   if(i>n-1)  //如果整数i值大于n-1，说明没找到
   {
       printf("\t\t|\t 对不起！没有此航班\n");
       m=m+2;
       k++;
    }
  }
}

//退票
void quit(FLY t[],int n)
{
   char s1[20],s2[20];   //保存待查找航班名和证件号字符串
   int i,k,j,h,l,ch;
   printf("\t\t|\t 请输入你想退订的航班号:");
   scanf("%s",s1); //输入待查找航班名
   printf("\t\t|\t 请输入你的证件号:");
   scanf("%s",s2); //输入待查找证件号
   printf("\t\t|\t号码     姓名       证件号         订的票数  航班号\n"); //显示提示
   printf("\t\t|\t------------------------------------------------------------\n");
   for(i=0;i<n;i++)//从第一条记录开始，直到最后一条
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
   if(i>n-1)  //如果整数i值大于n-1，说明没找到
      printf("\t\t|\t 没有找到\n");
   else
   {
      printf("\t\t|\t 你是否确认删除(1/0)\n");//确认是否要删除
      scanf("%d",&ch);  //输入一个整数或
    if(ch==1)  //如果确认删除整数为
     {
    for(k=l+1;k<t[i].sit;k++)
     {
     strcpy(t[i].guest[k-1].number,t[i].guest[k].number); //将后一条记录的姓名拷贝到前一条
     strcpy(t[i].guest[k-1].name,t[i].guest[k].name);
     strcpy(t[i].guest[k-1].id,t[i].guest[k].id);
     t[i].guest[k-1].count=t[i].guest[k].count;
     strcpy(t[i].guest[k-1].flightname,t[i].guest[k].flightname);
      }
    t[i].sit--;
     }
     printf("\t\t|\t 退票成功!!\n");//提示退票成功
   }
}
//修改航班信息
void channge(FLY t[],int n)
{
   char s[20];  //要删除记录的姓名
   int i,j;
   printf("\t\t|\t 请输入你要修改的航班号:");//提示信息
   scanf("%s",s);//输入航班名
   for(i=0;i<n;i++)//从第一条记录开始，直到最后一条
   {
      if(strcmp(s,t[i].planenumber)==0)  //记录中的航班名和待比较的是否相等
      break;   //相等，则返回该记录的下标号，程序提前结结束
   }
   if(i>n-1)  //如果整数i值大于n-1，说明没找到
       printf("\t\t|\t 没有找到！\n");
   else
    {
       printf("\t\t|\t航班号   起飞城市   降落城市      出发时间       降落时间       余座     价格（元）  折扣（折）\n");
       printf("\t\t|----------------------------------------------------------------------------------------\n");
       printf("\t\t|\t% s\t  % s\t     % s\t  % s\t  % s\t% d  \t  % s\t     % s\n", t[i].planenumber, t[i].Take_off_city, t[i].Arrived_in_city, t[i].takeoff_time, t[i].Landing_time, t[i].shipping, t[i].price, t[i].discount);
       printf("\t\t|----------------------------------------------------------------------------------------\n");
       printf("\t\t|\t请输入您要更改的信息：");
      printf("\t\t|\t航班名：");
      scanf("%s",t[i].planenumber);//输入航班名
      printf("\t\t|\t起始城市：");
      scanf("%s",t[i].Take_off_city);//输入起始城市
      printf("\t\t|\t终点城市：");
      scanf("%s",t[i].Arrived_in_city);//输入终点城市
      printf("\t\t|\t起飞时间：");
      scanf("%s",t[i].takeoff_time);//输入起飞时间
      printf("\t\t|\t降落时间：");
      scanf("%s",t[i].Landing_time);//输入降落时间
      printf("\t\t|\t座位号：");
      scanf("%d",t[i].shipping);//输入座位号
      printf("\t\t|\t票价：");
      scanf("%s",t[i].price);//输入票价
      printf("\t\t|\t折扣：");
      scanf("%s",t[i].discount);//输入折扣
   }
}

//主函数
main()
{  int i;
   FLY flight[Q];
   int length;  //保存记录长度
   int n = 255,x;
    while(n!=1)//无限循环
   {
       menu();
       printf("\t\t|--------------------------------------------|\n");
       printf("\t\t|\t 请选择功能：");
       scanf("%d", &x);
       printf("\t\t|--------------------------------------------|\n");
      switch(x)  
      {
         case 1:
              length=enter(flight);
              break;//输入航班
         case 2:
             list(flight,length);
             break; //显示航班
         case 3:
             search2(flight,length);
             break; //按城市查找航班
         case 4:
             book(flight,length);
             break;    //订票
         case 5:
             quit(flight,length);
             break;    //退票
         case 6:
             channge(flight,length);
             break; //修改航班信息
         case 7:
             exit(0); //如返回值为则程序结束
             default:break;
      }
   }

}