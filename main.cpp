#include<iostream>
#include<string>
using namespace std;
#define NUM 1000
void read();
void menu();
void find_num();
void write()
void add();
void modify_num();
void del_num();
void grsds();
void load(); 
void list()
struct emploee  //职工数据结构
int n;      //员工总人数
{
 char no[10];
 char name[30];
 float wage1;      //员工的基本工资
 float wage2;      //员工的职务工资
 float wage3;      //员工的职务津贴
 float wage4;   //员工的绩效工资
 float wage5;    //员工的应发工资
 float TAXfee;     //员工的个人所得税
 float wage6;      //员工的实发工资
}emp[NUM],newemp;
void main()
{
 menu();
}
void menu()//主界面
{  int n,w1;
   
   do
   { system("cls");  
      printf("************* 职工工资管理系统 **************\n");
      printf("*            1-----查找职工信息                     *\n");
      printf("*            2-----添加职工信息                     *\n");
      printf("*            3-----修改职工信息	                             *\n");
      printf("*            4-----删除职工信息             *\n");
      printf("*            5-----退出程序                           *\n");
      printf("***************************************************\n");
  printf("       输入您的选择(1-9):[ ]\b\b");
  scanf("%d",&n);
  if(n<1||n>9)                                    //对选择的数字作判断
         {
            w1=1;
            printf("your choice is not between 1 and 9,Please input again:");
            getchar();
          }
         else    w1=0;
      } 
    while(w1==1);
  switch(n)
  { case 1:search_num();    break;   
    case 2:add();   break;  
    case 3:modi_num();   break;    
    case 4:dele_num();   break;    
    case 5:count ();    break;    
    case 9:printf("\n×××××××谢谢，欢迎下次光临！×××××××\n\n");
    default:exit(0);  //退出系统,exit(0)函数功能是退出程序。
  }
}
/*************************读取模块**********************/
void read()
{
     FILE *fp;
     int n,i;
     if ((fp=fopen("emp.txt","wb"))==NULL)
     {
 
     printf("不能建立emp文件\n");
     exit(1);
     }
     printf("输入职工人数:");
    scanf("%d",&n);
     printf("输入格式:职工号 姓名  基本工资 职务工资 职务津贴  绩效工资   应发工资  税 实发工资<Enter>\n");
     for(i=0;i<n;i++)   /*  循环获取n个职工记录 */
     {
         printf("第%d个职工:",i+1);
         scanf("%s%s%s%d%f%f%f%f%f",emp[i].no,emp[i].name,
           &emp[i].wage1,&emp[i].wage2,&emp[i].wage3,&emp[i].wage4,&emp[i].wage5,&emp[i].&emp[i].TAXfee); emp[i].wage6=emp[i].wage1+emp[i].wage2+emp[i].wage3+emp[i].wage4+emp[i].wage5.TAXfee;
     }
     for(i=0;i<n;i++)      /*将n个职工记录写入文件*/
          fwrite(&emp[i],sizeof(struct emploee),1,fp);
     fclose(fp);
}
/*************************统计模块**********************/
void grsds()
{
     FILE *fp;
     int n,num;
     if((fp=fopen("emp.txt","rb"))==NULL)
     {
         printf("不能打开emp文件\n");
         exit(1);
     }
     printf("请输入工资数:");
     scanf("%d",&num);
     printf("记录号 职工号 姓名 姓名  基本工资 职务工资 职务津贴  绩效工资   应发工资  税 实发工资\n");
     for(n=0;fread(&emp[n],sizeof(struct emploee),1,fp)!=0;n++)
     if(emp[n].wage3>=num)
     printf("%6d%6s%9s%4s%5d   %.1f   %.1f  %.1f   %.1f   %.1f   %.1f\n",n+1,emp[n].no,emp[n].name,emp[n].wage1,
             emp[n].wage2,emp[n].wage3,emp[n].wage4,emp[n].wage5,emp[n].TAXfee,emp[n].wage6);
     fclose(fp);
}
/********************删除模块*******************/

void del_num()
{
     FILE *fp;
     int i,j,n;
     char num[5];
     if((fp=fopen("emp.txt","rb"))==NULL)
     {
         printf("不能打开emp文件\n");
         exit(1);
      }
     printf("删除前:\n");
     printf("记录号 职工号 姓名  基本工资 职务工资 职务津贴  绩效工资   应发工资  税 实发工资\n");
    for(n=0;fread(&emp[n],sizeof(struct emploee),1,fp);n++)
     printf("%6d%6s%9s%4s%5d   %.1f   %.1f   %.1f   %.1f   %.1f   %.1f\n",n+1,emp[n].no,emp[n].name,emp[n].wage1,emp[n].wage2,emp[n].wage3,emp[n].wage4,emp[n].wage5,
	 emp[n].TAXfee,emp[n].wage6);/*n为emp文件中记录数*/
     printf("要删除的职工号:");
     scanf("%s",num);
     for(i=0;(strcmp(emp[i].no,num)!=0&&i<n);i++)
     if(i>=n)
     {
          printf("\t没有%s职工号的职工\n",num);
          exit(2);
     }
     fclose(fp);
     fp=fopen("emp.dat","w+");
     if(n==1)  /*一个记录已经删除了*/
     {
           fclose(fp);
           exit(3);
     }
     for(j=0;j<i;j++)
        fwrite(&emp[j],sizeof(struct emploee),1,fp);
     for(j=i+1;j<n;j++)
         fwrite(&emp[j],sizeof(struct emploee),1,fp);
     printf("删除后:\n");
     fseek(fp,0,SEEK_SET);
     printf("记录号 职工号 姓名  基本工资 职务工资 职务津贴  绩效工资   应发工资  税 实发工资\n");
     for(i=0;fread(&emp[i],sizeof(struct emploee),1,fp);i++)
         printf("%6d%6s%9s%4s%5d%   %.1f    %.1f   %.1f   %.1f   %.1f   %.1f\n",i+1,emp[i].no,emp[i].name,emp[i].wage1,
                 emp[i].wage2,emp[i].wage3,emp[i].wage4,emp[i].wage5,emp[i].TAXfee,emp[i].wage6);
       fclose(fp);
}
/********************修改模块*******************/
void modify _num()
{
     FILE *fp;
     int i,j;
     char num[5];
     if((fp=fopen("emp.txt","rb+"))==NULL)
     {
         printf("不能 打开emp文件\n");
         exit(1);
     }
     printf("要修改的职工号:");
     scanf("%s",num);
     for(i=0;fread(&emp[i],sizeof(struct emploee),1,fp);i++)
    if(!strcmp(emp[i].no,num))break;
     if(feof(fp))
     {
          printf("\t没有%s职工号的职工\n",num);
          exit(2);
     }
     printf("记录号 职工号   姓名  基本工资 职务工资 职务津贴  绩效工资   应发工资  税  实发工资\n");
     printf("%6d%6s%9s%4s%5d%   %.1f   %.1f   %.1f   %.1f   %.1f   %.1f\n",i+1,emp[i].no,emp[i].name,emp[i].wage1,
              emp[i].wage2,emp[i].wage3,emp[i].wage4,emp[i].wage5,emp[i].TAXfee,emp[i].wage6);
    printf("输入格式:职工号   姓名  基本工资 职务工资 职务津贴  绩效工资   应发工资  税 <Enter>\n");
    printf("第%d个记录:",i+1);
    scanf("%s%s%s%d%f%f%f%f%f",newemp.no,newemp.name,
               &newemp.wage1,&newemp.wage2,&newemp.wage3,&newemp.wage4,&newemp.wage5,&newemp.TAXfee);//获取新的职工记录
             newemp.wage6=newemp.wage1+newemp.wage2+&newemp.wage3+&newemp.wage4+&newemp.wage5-newemp.TAXfee;
    fseek(fp,-(long)sizeof(struct emploee),SEEK_CUR);  //文件指针指向该修改的记录开头
     fwrite(&newemp,sizeof(struct emploee),1,fp);  //用newemp覆盖当前记录
     printf(" 修改后:\n");
    fseek(fp,0,SEEK_SET);        //显示修改后的文件数据
     printf("记录号 职工号    姓名  基本工资 职务工资 职务津贴  绩效工资   应发工资  税  实发工资\n");
     for(i=0;fread(&emp[i],sizeof(struct emploee),1,fp)!=0;i++)
         printf("%6d%6s%9s%4s%5d   %.1f   %.1f  %.1f   %.1f  %.1f   %.1f\n",i+1,emp[i].no,emp[i].name,emp[i].wage1,
                   emp[i].wage2,emp[i].wage3,emp[i].wage4,emp[i].wage5,emp[i].TAXfee,emp[i].wage6);
    fclose(fp);
}
 /*************************查询模块***********************/
void find_num()
{
     FILE *fp;
     int i; 
     char num[5];
     if((fp=fopen("emp.txt","rb"))==NULL)
     {
          printf("不能打开emp文件\n");
          exit(1);
     }
     printf("要查询的职工号:");
     scanf("%s",num);
     for(i=0;fread(&emp[i],sizeof(struct emploee),1,fp);i++)
         if(!strcmp(emp[i].no,num)) break;
    if(feof(fp))
    {
        printf("\t查无此人\n");
        exit(2);
    }
     printf("记录号 职工号   姓名  基本工资 职务工资 职务津贴  绩效工资   应发工资  税  实发工资\n");
     printf("%6d%6s%9s%4s%5d  %.1f  %.1f  %.1f  %.1f   %.1f   %.1f\n",i+1,emp[i].no,emp[i].name,emp[i].wage1,
               emp[i].wage2,emp[i].wage3,emp[i].wage4,emp[i].wage5,emp[i].TAXfee,emp[i].wage6);
       fclose(fp);
}
/*******************浏览模块********************/
void list()
{    int i;
     FILE *fp;
     if((fp=fopen("emp.txt","r"))==NULL)
     {     
         printf("不能打开emp文件\n");
         exit(0);
     }
     printf("记录号 职工号     姓名  基本工资 职务工资 职务津贴  绩效工资   应发工资  税 实发工资\n");
     for(i=0;fread(&emp[i],sizeof(struct emploee),1,fp)!=0;i++)
     {
          printf("%6d%6s%9s%4s%5d  %.1f  %.1f     %.1f    %.1f    %.1f   %.1f\n",i+1,emp[i].no,emp[i].name,emp[i].wage1,
                   emp[i].wage2,emp[i].wage3emp[i].wage4,emp[i].wage5,emp[i].TAXfee,emp[i].wage6);
    }
    fclose(fp);
}
/******************添加模块*******************/
    void add()
{
      FILE *fp;
      int n,i,j;
      if((fp=fopen("emp.txt","ab+"))==NULL)
      {
          printf("不能打开emp文件\n");
           exit(0);
      }
    printf("要追加的职工人数:");
      scanf("%d",&n);
      for(i=0;i<n;i++) 
      { 
          printf("输入格式:职工号    姓名  基本工资 职务工资 职务津贴  绩效工资   应发工资  税 <Enter>\n");
         printf("追加记录:\n");
         scanf("%s%s%s%d%f%f%f%f%f",newemp.no,newemp.name,
			 &newemp.wage1,&newemp.wage2,&newemp.wage3,&newemp.wage4,&newemp.wage5,&newemp.TAXfee);
             newemp.wage6=newemp.wage1+newemp.wage2+newemp.wage3+newmp.wage4+newemp.wage5-newemp.TAXfee;//获取一个新的职工记录
        fwrite(&newemp,sizeof(struct emploee),1,fp);   //将该职工记录写入文件
      }
      fclose(fp);
}
/*************************载入模块**********************/
void load()          //加载记录或可以计算记录个数的函数
{
     FILE *fp;
     int i,w;
     w=1;
     system( "cls" ); 
    if((fp=fopen("emp.txt","rb"))==NULL)      //以输出打开方式,在此前的记录被覆盖
    {
        printf("\nCannot open file\n");
        w=0;
        return ;
    }
    n=0;
    for(i=0;!feof(fp);i++)
    {   
        fread(&emp[i],sizeof(struct emploee),1,fp);
        n++;
    }
    n=n-1;
          fclose(fp);
    if(w==1) 
    {
        printf("Load file ok!");
        getchar();
        getchar();
        menu();                
    }
}