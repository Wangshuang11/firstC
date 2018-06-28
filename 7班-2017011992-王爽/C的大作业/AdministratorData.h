#include<stdio.h>
#include<conio.h>//为使用getch()函数
#include<stdlib.h>
#include<string.h> 
#include"Data.h"
#include"StudentData.h"
#ifndef _AdministratorData_h_
#define _AdministratorData_h_


/****************************    
*   功能：管理员界面		*
*   输入：无	            *
*   输出：无			    *
****************************/
void registe(void)
{
	printf("==========欢 迎 使 用 学 生 信 息 管 理 系 统=========\n");
	printf("                     1. 登陆                         \n");
	printf("                     2. 注册                         \n");
	printf("                     3. 退出                         \n");
	printf("=====================================================\n");
}
/****************************    
*   功能：管理员信息注册	*
*   输入：无	            *
*   输出：无			    *
****************************/
void zhuce(void)
{
	Administrator k,q;
	FILE *fp;
	printf("请输入注册账号：");
	scanf("%s",&(k.Number));
    printf("请输入密码：");
	scanf("%s",&(k.PassWord));
	printf("请再次输入密码：");
	scanf("%s",&(q.PassWord));
	if (strcmp(k.PassWord, q.PassWord)==0)
	{
		fp=fopen("管理员信息.txt","a+");/*以读写模式("a+")打开文件*/
	    fputs(k.Number,fp);
		fputs("\t",fp);
        fputs(k.PassWord,fp);/*将名称和密码以字符串形式写入文件*/
        fclose(fp);
		printf("注册成功！\n");
		return ;
	}
	else
		printf("密码输入不一致，注册失败\n");
}
/****************************    
*   功能：管理员登录	    *
*   输入：无	            *
*   输出：m值			    *
****************************/
int dengluone(void)
{
	Administrator *p,*q;
	int m=5;
	FILE *fp;
	fp=fopen("管理员信息.txt","r");
	q=(Administrator *)malloc(sizeof(Administrator));
	p=(Administrator *)malloc(sizeof(Administrator));
	fscanf(fp,"%s %s",p->Number,p->PassWord);
	fclose(fp);
	while(m)
	{
		printf("请输入账号：");
	    scanf("%s",&(q->Number));
        printf("请输入密码：");
	    scanf("%s",&(q->PassWord));
		if (strcmp(p->Number,q->Number)==0 && strcmp(p->PassWord,q->PassWord)==0)
		{
			printf("登录成功！");
			system("cls");
            menu();
			return m;
		}
		else
		{
			m--;
			printf("输入账号密码错误，你还有%d次重新输入机会！\n",m);
			printf("请按任意键继续...\n");
            _getch();
		}
	}
	free(p);
	free(q);
	return m;
}

#endif