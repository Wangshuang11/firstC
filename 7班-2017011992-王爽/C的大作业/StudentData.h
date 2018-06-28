#include<stdio.h>
#include<conio.h>//为使用getch()函数
#include<stdlib.h>
#include<string.h> 
#include"Data.h"
#ifndef _StudentData_h_
#define _StudentData_h_
/****************************    
*   功能：学生信息管理界面  *
*   输入：无	            *
*   输出：无			    *
****************************/
void menu(void)
{ 
	printf("===========欢 迎 使 用 学 生 管 理 系 统===========\n");
	printf("                   1. 浏览学生信息                 \n");
	printf("                   2. 添加学生信息                 \n");
	printf("                   3. 删除学生信息                 \n");
	printf("                   4. 编辑学生信息                 \n");
	printf("                   5. 统计学生信息                 \n");
	printf("                   6. 查找学生信息                 \n");
	printf("                   7. 退出系统                     \n");
	printf("===================================================\n");
}
/****************************    
*   功能：统计学生信息界面  *
*   输入：无	            *
*   输出：无			    *
****************************/
void count(void)
{
	printf("=================统 计 学 生 信 息 =================\n");
	printf("                   1.按照学号排序                     \n");
	printf("                   2.按总成绩排序                     \n");
	printf("                   3.退 出 统 计                      \n");
	printf("===================================================\n");
}
/****************************    
*   功能：浏览学生信息      *
*   输入：无	            *
*   输出：无			    *
****************************/
void skiminformation(void)
{
	FILE *fp;
	char *one_line;
	fp=fopen("学生信息.txt","a+");
	printf("===================学生信息如下====================\n");
    one_line = (char*)malloc( 20 * sizeof(char) );
    while( fgets(one_line, 20, fp) != NULL )
    {
         printf("%s",one_line);
    }
	printf("\n");
    fclose(fp);
	free(one_line);
	printf("请按任意键继续...");
    _getch();
}
/****************************    
*   功能：添加学生信息      *
*   输入：无	            *
*   输出：无			    *
****************************/
void addinformation(void)
{
	FILE *fp;
	int n;
	List *p;
	p=(List *)malloc(sizeof(List));
	p->length=10;
	fp=fopen("学生信息.txt","a+");
	for(n=0;n<9;n++)	
	  fscanf(fp,"%s %s %s %d %d %d %d \n",&p->Head[n].ID,&p->Head[n].Name,&p->Head[n].Sex,&p->Head[n].ScoreC,&p->Head[n].ScoreChinese,&p->Head[n].ScoreMath,&p->Head[n].ScoreEnglish);	
	fclose(fp);
	printf("要添加的学生学号:");
	scanf("%s",&p->Head[9].ID);
	printf("要添加的学生姓名:");
	scanf("%s",&p->Head[9].Name);
	printf("要添加的学生性别:");
	scanf("%s",&p->Head[9].Sex);
	printf("要添加的学生C语言成绩:");
	scanf("%d",&p->Head[9].ScoreC);
	printf("要添加的学生语文成绩:");
	scanf("%d",&p->Head[9].ScoreChinese);
	printf("要添加的学生数学成绩:");
	scanf("%d",&p->Head[9].ScoreMath);
	printf("要添加的学生英语成绩:");
	scanf("%d",&p->Head[9].ScoreEnglish);
	fp=fopen("学生信息.txt","w+");
	for(n=0;n<10;n++)	
	  fprintf(fp,"%s %s %s %d %d %d %d \n",p->Head[n].ID,p->Head[n].Name,p->Head[n].Sex,p->Head[n].ScoreC,p->Head[n].ScoreChinese,p->Head[n].ScoreMath,p->Head[n].ScoreEnglish);	
	fclose(fp);
	printf("添加成功!\n");
	printf("请按任意键继续...");
    _getch();
	free(p);
}
/****************************    
*   功能：删除学生信息      *
*   输入：无	            *
*   输出：无			    *
****************************/
void deleteinformation(void)
{
	FILE *fp;
	char xuehao[20];
	int n,j,m=0;
	List *p;
	printf("要删除的学生的学号：");
	scanf("%s",xuehao);
	p=(List *)malloc(sizeof(List));
	p->length=10;
	fp=fopen("学生信息.txt","a+");
	for(n=0;n<10;n++)	
	  fscanf(fp,"%s %s %s %d %d %d %d \n",&p->Head[n].ID,&p->Head[n].Name,&p->Head[n].Sex,&p->Head[n].ScoreC,&p->Head[n].ScoreChinese,&p->Head[n].ScoreMath,&p->Head[n].ScoreEnglish);	
	fclose(fp);
	for(n=0;n<10;n++)
	  if (strcmp(p->Head[n].ID,xuehao)==0)
	  {
		  for(j = n;j<9;j++)
		  {
		     p->Head[j]=p->Head[j+1];
		  }
		  n--;
		  m=1;
	  }
	if(m==1)
	{
		fp=fopen("学生信息.txt","w+");
		for(n=0;n<9;n++)	
	      fprintf(fp,"%s %s %s %d %d %d %d \n",p->Head[n].ID,p->Head[n].Name,p->Head[n].Sex,p->Head[n].ScoreC,p->Head[n].ScoreChinese,p->Head[n].ScoreMath,p->Head[n].ScoreEnglish);	
	    printf("删除成功！\n");
		fclose(fp);
	}
	else
		printf("删除的学生信息不存在！\n");
	free(p);
	printf("请按任意键继续...");
    _getch();
}
/****************************    
*   功能：编辑学生信息      *
*   输入：无	            *
*   输出：无			    *
****************************/
void editinformation(void)
{
	FILE *fp;
	char xuehao[20];
	int n,j;
	List *p;
	printf("要编辑的学生的学号：");
	scanf("%s",xuehao);
	printf("查找结果如下：\n");
	p=(List *)malloc(sizeof(List));
	p->length=9;
	fp=fopen("学生信息.txt","a+");
	for(n=0;n<9;n++)	
	  fscanf(fp,"%s %s %s %d %d %d %d \n",&p->Head[n].ID,&p->Head[n].Name,&p->Head[n].Sex,&p->Head[n].ScoreC,&p->Head[n].ScoreChinese,&p->Head[n].ScoreMath,&p->Head[n].ScoreEnglish);	
	fclose(fp);
	for(n=0;n<9;n++)
	  if (strcmp(p->Head[n].ID,xuehao)==0)
	  {
		  printf("%s %s %s %d %d %d %d\n",p->Head[n].ID,p->Head[n].Name,p->Head[n].Sex,p->Head[n].ScoreC,p->Head[n].ScoreChinese,p->Head[n].ScoreMath,p->Head[n].ScoreEnglish);	
	      j=n;
	  }
	printf("修改学生姓名为：");
	scanf("%s",&p->Head[j].Name);
	printf("修改学生性别为：");
	scanf("%s",&p->Head[j].Sex);
	printf("修改学生的C语言成绩为：");
	scanf("%d",&p->Head[j].ScoreC);
	printf("修改学生的语文成绩为：");
	scanf("%d",&p->Head[j].ScoreChinese);
	printf("修改学生的数学成绩为：");
	scanf("%d",&p->Head[j].ScoreMath);
	printf("修改学生的英语成绩为：");
	scanf("%d",&p->Head[j].ScoreEnglish);
	fp=fopen("学生信息.txt","w+");
	for(n=0;n<9;n++)	
	      fprintf(fp,"%s %s %s %d %d %d %d \n",p->Head[n].ID,p->Head[n].Name,p->Head[n].Sex,p->Head[n].ScoreC,p->Head[n].ScoreChinese,p->Head[n].ScoreMath,p->Head[n].ScoreEnglish);	
	printf("修改成功！\n");
	fclose(fp);
	free(p);
	printf("请按任意键继续...");
    _getch();
}
/****************************    
*   功能：查找学生信息      *
*   输入：无	            *
*   输出：无			    *
****************************/
void searchinformation(void)
{
	FILE *fp;
	char xuehao[20];
	int n,m=0;
	List *p;
	printf("要查找的学生学号：");
	scanf("%s",xuehao);
	p=(List *)malloc(sizeof(List));
	p->length=9;
	fp=fopen("学生信息.txt","a+");
	for(n=0;n<9;n++)	
	  fscanf(fp,"%s %s %s %d %d %d %d \n",&p->Head[n].ID,&p->Head[n].Name,&p->Head[n].Sex,&p->Head[n].ScoreC,&p->Head[n].ScoreChinese,&p->Head[n].ScoreMath,&p->Head[n].ScoreEnglish);	
	fclose(fp);
	for(n=0;n<9;n++)
	{
	  if (strcmp(p->Head[n].ID,xuehao)==0)
	  {
		  printf("查找结果如下：\n");
		  printf("%s %s %s %d %d %d %d\n",p->Head[n].ID,p->Head[n].Name,p->Head[n].Sex,p->Head[n].ScoreC,p->Head[n].ScoreChinese,p->Head[n].ScoreMath,p->Head[n].ScoreEnglish);	
	      m=1;
	  }
	}
	if(m==0)
		printf("未找到该成员！\n");
	free(p);
	printf("请按任意键继续...");
    _getch();
}
/****************************    
*   功能：按学号排序        *
*   输入：无	            *
*   输出：无			    *
****************************/
void xuehaosort(void)
{
	FILE *fp;
	int n,m;
	List *p;
	Student t;
	char *one_line;
	p=(List *)malloc(sizeof(List));
	p->length=9;
	fp=fopen("学生信息.txt","a+");
	for(n=0;n<9;n++)	
	  fscanf(fp,"%s %s %s %d %d %d %d \n",&p->Head[n].ID,&p->Head[n].Name,&p->Head[n].Sex,&p->Head[n].ScoreC,&p->Head[n].ScoreChinese,&p->Head[n].ScoreMath,&p->Head[n].ScoreEnglish);	
	fclose(fp);
	for(n=0;n<9-1;n++)
	{
		for(m=0;m<9-1-n;m++)
		{
			if(strcmp(p->Head[m].ID,p->Head[m+1].ID)>0)
			{
				t=p->Head[m];
				p->Head[m]=p->Head[m+1];
				p->Head[m+1]=t;
			}
		}
	}
    fp=fopen("学生信息.txt","w+");
	for(n=0;n<9;n++)	
	      fprintf(fp,"%s %s %s %d %d %d %d \n",p->Head[n].ID,p->Head[n].Name,p->Head[n].Sex,p->Head[n].ScoreC,p->Head[n].ScoreChinese,p->Head[n].ScoreMath,p->Head[n].ScoreEnglish);	
	fclose(fp);
	free(p);
	fp=fopen("学生信息.txt","a+");
	printf("===================学生信息如下====================\n");
    one_line = (char*)malloc( 20 * sizeof(char) );
    while( fgets(one_line, 20, fp) != NULL )
    {
         printf("%s",one_line);
    }
	printf("\n");
    fclose(fp);
	free(one_line);
}
/****************************    
*   功能：按总成绩排序      *
*   输入：无	            *
*   输出：无			    *
****************************/
void allsort(void)
{
	FILE *fp;
	int n,m;
	List *p;
	Student t;
	char *one_line;
	p=(List *)malloc(sizeof(List));
	p->length=9;
	fp=fopen("学生信息.txt","a+");
	for(n=0;n<9;n++)	
	    fscanf(fp,"%s %s %s %d %d %d %d \n",&p->Head[n].ID,&p->Head[n].Name,&p->Head[n].Sex,&p->Head[n].ScoreC,&p->Head[n].ScoreChinese,&p->Head[n].ScoreMath,&p->Head[n].ScoreEnglish);	
	fclose(fp);
	for(n=0;n<9-1;n++)
	{
		for(m=0;m<9-1-n;m++)
		{
			if((p->Head[m].ScoreC + p->Head[m].ScoreChinese+p->Head[m].ScoreMath+p->Head[m].ScoreEnglish) > (p->Head[m+1].ScoreC+p->Head[m+1].ScoreChinese+p->Head[m+1].ScoreMath+p->Head[m+1].ScoreEnglish))
			{
				t=p->Head[m];
				p->Head[m]=p->Head[m+1];
				p->Head[m+1]=t;
			}
		}
	}
	fp=fopen("学生信息.txt","w+");
	for(n=0;n<9;n++)	
	    fprintf(fp,"%s %s %s %d %d %d %d \n",p->Head[n].ID,p->Head[n].Name,p->Head[n].Sex,p->Head[n].ScoreC,p->Head[n].ScoreChinese,p->Head[n].ScoreMath,p->Head[n].ScoreEnglish);	
	fclose(fp);
	free(p);
	fp=fopen("学生信息.txt","a+");
	printf("===================学生信息如下====================\n");
	one_line = (char*)malloc( 20 * sizeof(char) );
    while( fgets(one_line, 20, fp) != NULL )
    {
         printf("%s",one_line);
    }
	printf("\n");
    fclose(fp);
	free(one_line);
}
/*******************************   
*   功能：学生信息管理功能选择 *
*   输入：无	               *
*   输出：无			       *
*******************************/
void stuselect(void)
{
	int n,m;
	printf("请选择:");
	scanf("%d",&n);
	switch(n)
	{
	case 1:
		skiminformation();
		system("cls");
		menu();
		stuselect();
		break;
	case 2:
		addinformation();
		system("cls");
		menu();
		stuselect();
		break;
	case 3:
		deleteinformation();
		system("cls");
		menu();
		stuselect();
		break;
	case 4:
		editinformation();
		system("cls");
		menu();
		stuselect();
		break;
	case 5:
		system("cls");
		count();
		printf("请选择:");
	    scanf("%d",&m);
		if(m==1)			
			xuehaosort();
		else if(m==2)
			allsort();
		else if(m==3)
		{
			system("cls");
			menu();
			stuselect();
		}
		break;
	case 6:
		searchinformation();
		system("cls");
		menu();
		stuselect();
		break;
	case 7:
		break;
	default:
        break;
	}
 }
#endif