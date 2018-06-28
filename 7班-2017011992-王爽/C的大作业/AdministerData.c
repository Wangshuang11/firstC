#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<conio.h>//为使用getch()函数
#include"Data.h"
#include"AdministratorData.h"
#include"StudentData.h"
int main(void)
{  
	int n,m;
	registe();
	printf("请选择：");
    scanf("%d",&n);
	switch (n)
	{
	case 1:
		m=dengluone();
		if(m!=0)
		   stuselect();
		break;
	case 2:
		zhuce();
		break;
	case 3:
		break;
	default:
        break;
	}
    return 0;
}