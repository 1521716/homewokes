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
	int length;
}SqList;

Status InitList(SqList& L);//初始化操作 
Status CreateList(SqList& L);//创建操作 
void ShowList(SqList L);//输出操作
int LocateList(SqList L, ElemType x);//查找操作
Status InsertList(SqList& L, int i, ElemType x);//插入操作
Status DeleteList(SqList& L, int i);//删除操作
void SortList(SqList& L);//排序操作
Status InsertOrderList(SqList& L, ElemType x);//有序表插入操作 
void menu();//菜单操作 
