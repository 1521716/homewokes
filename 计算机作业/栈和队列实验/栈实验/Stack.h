#pragma once
#include<iostream>
using namespace std;
#include<stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 10  //最初开辟的存储空间大小被定义为10

typedef int Status;
typedef int ElemType;  //栈的元素类型被定义为整型
typedef struct         //栈存储类型定义
{
	ElemType* elem;
	int top;
}SqStack;

//初始化操作
Status InitStack(SqStack& S); 
//判断栈是否为空
Status IsEmpty(SqStack S);
//入栈
Status PushStack(SqStack& S, ElemType x);
//出栈
Status PopStack(SqStack& S, ElemType &e);
//获取栈顶元素
Status GetTop(SqStack S, ElemType& e);
//遍历栈
void ShowStack(SqStack S);
//菜单操作 
void menu();

