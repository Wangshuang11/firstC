#include<stdio.h>
#include<conio.h>//Ϊʹ��getch()����
#include<stdlib.h>
#include<string.h> 
#include"Data.h"
#include"StudentData.h"
#ifndef _AdministratorData_h_
#define _AdministratorData_h_


/****************************    
*   ���ܣ�����Ա����		*
*   ���룺��	            *
*   �������			    *
****************************/
void registe(void)
{
	printf("==========�� ӭ ʹ �� ѧ �� �� Ϣ �� �� ϵ ͳ=========\n");
	printf("                     1. ��½                         \n");
	printf("                     2. ע��                         \n");
	printf("                     3. �˳�                         \n");
	printf("=====================================================\n");
}
/****************************    
*   ���ܣ�����Ա��Ϣע��	*
*   ���룺��	            *
*   �������			    *
****************************/
void zhuce(void)
{
	Administrator k,q;
	FILE *fp;
	printf("������ע���˺ţ�");
	scanf("%s",&(k.Number));
    printf("���������룺");
	scanf("%s",&(k.PassWord));
	printf("���ٴ��������룺");
	scanf("%s",&(q.PassWord));
	if (strcmp(k.PassWord, q.PassWord)==0)
	{
		fp=fopen("����Ա��Ϣ.txt","a+");/*�Զ�дģʽ("a+")���ļ�*/
	    fputs(k.Number,fp);
		fputs("\t",fp);
        fputs(k.PassWord,fp);/*�����ƺ��������ַ�����ʽд���ļ�*/
        fclose(fp);
		printf("ע��ɹ���\n");
		return ;
	}
	else
		printf("�������벻һ�£�ע��ʧ��\n");
}
/****************************    
*   ���ܣ�����Ա��¼	    *
*   ���룺��	            *
*   �����mֵ			    *
****************************/
int dengluone(void)
{
	Administrator *p,*q;
	int m=5;
	FILE *fp;
	fp=fopen("����Ա��Ϣ.txt","r");
	q=(Administrator *)malloc(sizeof(Administrator));
	p=(Administrator *)malloc(sizeof(Administrator));
	fscanf(fp,"%s %s",p->Number,p->PassWord);
	fclose(fp);
	while(m)
	{
		printf("�������˺ţ�");
	    scanf("%s",&(q->Number));
        printf("���������룺");
	    scanf("%s",&(q->PassWord));
		if (strcmp(p->Number,q->Number)==0 && strcmp(p->PassWord,q->PassWord)==0)
		{
			printf("��¼�ɹ���");
			system("cls");
            menu();
			return m;
		}
		else
		{
			m--;
			printf("�����˺���������㻹��%d������������ᣡ\n",m);
			printf("�밴���������...\n");
            _getch();
		}
	}
	free(p);
	free(q);
	return m;
}

#endif