#ifndef _Data_h_
#define _Data_h_

typedef struct student
{
	char ID[20];
	char Name[20];
	char Sex[4];
	int ScoreC;
	int ScoreChinese;
	int ScoreMath;
	int ScoreEnglish;
}Student;
typedef struct administrator
{
	char Number[20];
	char PassWord[20];
}Administrator;
typedef struct List
{
	Student Head[200];
	int length;
}List;
#endif