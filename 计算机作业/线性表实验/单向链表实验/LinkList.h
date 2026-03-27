#include<iostream>
using namespace std;
#include<stdlib.h>

#define OK 1
#define ERROR 0



typedef int Status;
typedef int ElemType;  //链表的元素类型被定义为整型
typedef struct Node         //链表存储类型定义
{
	ElemType data;
	Node* next;
}LNode,*LinkList;

//初始化操作
Status InitList(LinkList& L); 
//创建操作
//前插创建单链表
Status HeadCreateList(LinkList& L); 
//尾插创建单链表
Status TailCreateList(LinkList& L);
//插入操作
Status InsertList(LinkList& L, int i, ElemType x);
//删除操作
Status DeleteList(LinkList& L, int i);
//输出操作
void ShowList(LinkList L);
//排序操作
Status SortList(LinkList& L);
//有序表插入操作 
Status InsertOrderList(LinkList& L, ElemType x);
//有序表合并
Status MergeList(LinkList& L1, LinkList L2);
//菜单操作 
void menu();
