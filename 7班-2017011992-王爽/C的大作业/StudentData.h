#include<stdio.h>
#include<conio.h>//Ϊʹ��getch()����
#include<stdlib.h>
#include<string.h> 
#include"Data.h"
#ifndef _StudentData_h_
#define _StudentData_h_
/****************************    
*   ���ܣ�ѧ����Ϣ�������  *
*   ���룺��	            *
*   �������			    *
****************************/
void menu(void)
{ 
	printf("===========�� ӭ ʹ �� ѧ �� �� �� ϵ ͳ===========\n");
	printf("                   1. ���ѧ����Ϣ                 \n");
	printf("                   2. ���ѧ����Ϣ                 \n");
	printf("                   3. ɾ��ѧ����Ϣ                 \n");
	printf("                   4. �༭ѧ����Ϣ                 \n");
	printf("                   5. ͳ��ѧ����Ϣ                 \n");
	printf("                   6. ����ѧ����Ϣ                 \n");
	printf("                   7. �˳�ϵͳ                     \n");
	printf("===================================================\n");
}
/****************************    
*   ���ܣ�ͳ��ѧ����Ϣ����  *
*   ���룺��	            *
*   �������			    *
****************************/
void count(void)
{
	printf("=================ͳ �� ѧ �� �� Ϣ =================\n");
	printf("                   1.����ѧ������                     \n");
	printf("                   2.���ܳɼ�����                     \n");
	printf("                   3.�� �� ͳ ��                      \n");
	printf("===================================================\n");
}
/****************************    
*   ���ܣ����ѧ����Ϣ      *
*   ���룺��	            *
*   �������			    *
****************************/
void skiminformation(void)
{
	FILE *fp;
	char *one_line;
	fp=fopen("ѧ����Ϣ.txt","a+");
	printf("===================ѧ����Ϣ����====================\n");
    one_line = (char*)malloc( 20 * sizeof(char) );
    while( fgets(one_line, 20, fp) != NULL )
    {
         printf("%s",one_line);
    }
	printf("\n");
    fclose(fp);
	free(one_line);
	printf("�밴���������...");
    _getch();
}
/****************************    
*   ���ܣ����ѧ����Ϣ      *
*   ���룺��	            *
*   �������			    *
****************************/
void addinformation(void)
{
	FILE *fp;
	int n;
	List *p;
	p=(List *)malloc(sizeof(List));
	p->length=10;
	fp=fopen("ѧ����Ϣ.txt","a+");
	for(n=0;n<9;n++)	
	  fscanf(fp,"%s %s %s %d %d %d %d \n",&p->Head[n].ID,&p->Head[n].Name,&p->Head[n].Sex,&p->Head[n].ScoreC,&p->Head[n].ScoreChinese,&p->Head[n].ScoreMath,&p->Head[n].ScoreEnglish);	
	fclose(fp);
	printf("Ҫ��ӵ�ѧ��ѧ��:");
	scanf("%s",&p->Head[9].ID);
	printf("Ҫ��ӵ�ѧ������:");
	scanf("%s",&p->Head[9].Name);
	printf("Ҫ��ӵ�ѧ���Ա�:");
	scanf("%s",&p->Head[9].Sex);
	printf("Ҫ��ӵ�ѧ��C���Գɼ�:");
	scanf("%d",&p->Head[9].ScoreC);
	printf("Ҫ��ӵ�ѧ�����ĳɼ�:");
	scanf("%d",&p->Head[9].ScoreChinese);
	printf("Ҫ��ӵ�ѧ����ѧ�ɼ�:");
	scanf("%d",&p->Head[9].ScoreMath);
	printf("Ҫ��ӵ�ѧ��Ӣ��ɼ�:");
	scanf("%d",&p->Head[9].ScoreEnglish);
	fp=fopen("ѧ����Ϣ.txt","w+");
	for(n=0;n<10;n++)	
	  fprintf(fp,"%s %s %s %d %d %d %d \n",p->Head[n].ID,p->Head[n].Name,p->Head[n].Sex,p->Head[n].ScoreC,p->Head[n].ScoreChinese,p->Head[n].ScoreMath,p->Head[n].ScoreEnglish);	
	fclose(fp);
	printf("��ӳɹ�!\n");
	printf("�밴���������...");
    _getch();
	free(p);
}
/****************************    
*   ���ܣ�ɾ��ѧ����Ϣ      *
*   ���룺��	            *
*   �������			    *
****************************/
void deleteinformation(void)
{
	FILE *fp;
	char xuehao[20];
	int n,j,m=0;
	List *p;
	printf("Ҫɾ����ѧ����ѧ�ţ�");
	scanf("%s",xuehao);
	p=(List *)malloc(sizeof(List));
	p->length=10;
	fp=fopen("ѧ����Ϣ.txt","a+");
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
		fp=fopen("ѧ����Ϣ.txt","w+");
		for(n=0;n<9;n++)	
	      fprintf(fp,"%s %s %s %d %d %d %d \n",p->Head[n].ID,p->Head[n].Name,p->Head[n].Sex,p->Head[n].ScoreC,p->Head[n].ScoreChinese,p->Head[n].ScoreMath,p->Head[n].ScoreEnglish);	
	    printf("ɾ���ɹ���\n");
		fclose(fp);
	}
	else
		printf("ɾ����ѧ����Ϣ�����ڣ�\n");
	free(p);
	printf("�밴���������...");
    _getch();
}
/****************************    
*   ���ܣ��༭ѧ����Ϣ      *
*   ���룺��	            *
*   �������			    *
****************************/
void editinformation(void)
{
	FILE *fp;
	char xuehao[20];
	int n,j;
	List *p;
	printf("Ҫ�༭��ѧ����ѧ�ţ�");
	scanf("%s",xuehao);
	printf("���ҽ�����£�\n");
	p=(List *)malloc(sizeof(List));
	p->length=9;
	fp=fopen("ѧ����Ϣ.txt","a+");
	for(n=0;n<9;n++)	
	  fscanf(fp,"%s %s %s %d %d %d %d \n",&p->Head[n].ID,&p->Head[n].Name,&p->Head[n].Sex,&p->Head[n].ScoreC,&p->Head[n].ScoreChinese,&p->Head[n].ScoreMath,&p->Head[n].ScoreEnglish);	
	fclose(fp);
	for(n=0;n<9;n++)
	  if (strcmp(p->Head[n].ID,xuehao)==0)
	  {
		  printf("%s %s %s %d %d %d %d\n",p->Head[n].ID,p->Head[n].Name,p->Head[n].Sex,p->Head[n].ScoreC,p->Head[n].ScoreChinese,p->Head[n].ScoreMath,p->Head[n].ScoreEnglish);	
	      j=n;
	  }
	printf("�޸�ѧ������Ϊ��");
	scanf("%s",&p->Head[j].Name);
	printf("�޸�ѧ���Ա�Ϊ��");
	scanf("%s",&p->Head[j].Sex);
	printf("�޸�ѧ����C���Գɼ�Ϊ��");
	scanf("%d",&p->Head[j].ScoreC);
	printf("�޸�ѧ�������ĳɼ�Ϊ��");
	scanf("%d",&p->Head[j].ScoreChinese);
	printf("�޸�ѧ������ѧ�ɼ�Ϊ��");
	scanf("%d",&p->Head[j].ScoreMath);
	printf("�޸�ѧ����Ӣ��ɼ�Ϊ��");
	scanf("%d",&p->Head[j].ScoreEnglish);
	fp=fopen("ѧ����Ϣ.txt","w+");
	for(n=0;n<9;n++)	
	      fprintf(fp,"%s %s %s %d %d %d %d \n",p->Head[n].ID,p->Head[n].Name,p->Head[n].Sex,p->Head[n].ScoreC,p->Head[n].ScoreChinese,p->Head[n].ScoreMath,p->Head[n].ScoreEnglish);	
	printf("�޸ĳɹ���\n");
	fclose(fp);
	free(p);
	printf("�밴���������...");
    _getch();
}
/****************************    
*   ���ܣ�����ѧ����Ϣ      *
*   ���룺��	            *
*   �������			    *
****************************/
void searchinformation(void)
{
	FILE *fp;
	char xuehao[20];
	int n,m=0;
	List *p;
	printf("Ҫ���ҵ�ѧ��ѧ�ţ�");
	scanf("%s",xuehao);
	p=(List *)malloc(sizeof(List));
	p->length=9;
	fp=fopen("ѧ����Ϣ.txt","a+");
	for(n=0;n<9;n++)	
	  fscanf(fp,"%s %s %s %d %d %d %d \n",&p->Head[n].ID,&p->Head[n].Name,&p->Head[n].Sex,&p->Head[n].ScoreC,&p->Head[n].ScoreChinese,&p->Head[n].ScoreMath,&p->Head[n].ScoreEnglish);	
	fclose(fp);
	for(n=0;n<9;n++)
	{
	  if (strcmp(p->Head[n].ID,xuehao)==0)
	  {
		  printf("���ҽ�����£�\n");
		  printf("%s %s %s %d %d %d %d\n",p->Head[n].ID,p->Head[n].Name,p->Head[n].Sex,p->Head[n].ScoreC,p->Head[n].ScoreChinese,p->Head[n].ScoreMath,p->Head[n].ScoreEnglish);	
	      m=1;
	  }
	}
	if(m==0)
		printf("δ�ҵ��ó�Ա��\n");
	free(p);
	printf("�밴���������...");
    _getch();
}
/****************************    
*   ���ܣ���ѧ������        *
*   ���룺��	            *
*   �������			    *
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
	fp=fopen("ѧ����Ϣ.txt","a+");
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
    fp=fopen("ѧ����Ϣ.txt","w+");
	for(n=0;n<9;n++)	
	      fprintf(fp,"%s %s %s %d %d %d %d \n",p->Head[n].ID,p->Head[n].Name,p->Head[n].Sex,p->Head[n].ScoreC,p->Head[n].ScoreChinese,p->Head[n].ScoreMath,p->Head[n].ScoreEnglish);	
	fclose(fp);
	free(p);
	fp=fopen("ѧ����Ϣ.txt","a+");
	printf("===================ѧ����Ϣ����====================\n");
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
*   ���ܣ����ܳɼ�����      *
*   ���룺��	            *
*   �������			    *
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
	fp=fopen("ѧ����Ϣ.txt","a+");
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
	fp=fopen("ѧ����Ϣ.txt","w+");
	for(n=0;n<9;n++)	
	    fprintf(fp,"%s %s %s %d %d %d %d \n",p->Head[n].ID,p->Head[n].Name,p->Head[n].Sex,p->Head[n].ScoreC,p->Head[n].ScoreChinese,p->Head[n].ScoreMath,p->Head[n].ScoreEnglish);	
	fclose(fp);
	free(p);
	fp=fopen("ѧ����Ϣ.txt","a+");
	printf("===================ѧ����Ϣ����====================\n");
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
*   ���ܣ�ѧ����Ϣ������ѡ�� *
*   ���룺��	               *
*   �������			       *
*******************************/
void stuselect(void)
{
	int n,m;
	printf("��ѡ��:");
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
		printf("��ѡ��:");
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