#pragma once
#include<iostream>
using namespace std;
#include<stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 10  //最初开辟的存储空间大小被定义为10

typedef int Status;
typedef int ElemType;  //顺序表的元素类型被定义为整型
typedef struct         //顺序表存储类型定义
{
	ElemType* elem;
	int top;
}SqStack;

Status InitStack(SqStack& L);//初始化操作 
Status CreateStack(SqStack& L);//创建操作 
void ShowStack(SqStack L);//输出操作
int LocateStack(SqStack L, ElemType x);//查找操作
Status InsertStack(SqStack& L, int i, ElemType x);//插入操作
Status DeleteStack(SqStack& L, int i);//删除操作
void SortStack(SqStack& L);//排序操作
Status InsertOrderStack(SqStack& L, ElemType x);//有序表插入操作 
void menu();//菜单操作 

