#include<iostream>
using namespace std;
#include<string.h>
#include<stdlib.h>
#include<iomanip> 

#define OK 1
#define ERROR 0
#define MAXSIZE 11

typedef int Status;
typedef struct{
	char ID[20];
	char Name[30];
}Patient;
typedef struct{
	Patient* P;
	int head;
	int tail;
}SqQueue;

//用于统计当天就诊总人数
extern int num; 


//菜单
void menu(); 
//上班
Status InitQueue(SqQueue &Q); 
//候诊
Status PushQueue(SqQueue &Q,Patient p);
//就诊
Status PopQueue(SqQueue &Q,Patient &t);
//查看排队情况
void ShowFront(SqQueue Q,char *ID);
//查看看诊
int ShowNum(SqQueue Q);
//统计 
void Statistic(SqQueue Q);
//下班 
Status Exit(SqQueue &Q);
