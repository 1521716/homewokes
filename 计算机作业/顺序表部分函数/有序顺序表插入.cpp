#include<iostream>
using namespace std;

#define MAXSIZE 100
#define OK 1
#define ERROR 0

typedef int Status;
typedef int ElemType;
typedef struct {
	ElemType * elem;
	int len;
}SqList;


//函数声明
//有序插入
Status InsertOrderList(SqList& L, ElemType e);
//打印
void ShowList(SqList L);
int main()
{
	SqList L;
	L.elem = new ElemType[MAXSIZE];
	L.len = 0;
	for (int i = 1; i < 10; i++)
	{
		InsertOrderList(L, i);
	}
	InsertOrderList(L, 4);
	ShowList(L);
	delete[]L.elem;
	return 0;
}

//函数定义
//有序插入
Status InsertOrderList(SqList& L, ElemType e)
{
	if (L.len == MAXSIZE)
		return ERROR;
	if (L.len == 0)
		L.elem[0] = e;
	int i;
	for (i = 0; i < L.len; i++)
	{
		if (L.elem[i] >= e)
		{
			for (int j = L.len - 1; j >= i; j--)
				L.elem[j + 1] = L.elem[j];
			L.elem[i] = e;
			break;
		}
	}
	if (i == L.len)
		L.elem[i] = e;
	L.len++;
	return OK;
}
//打印
void ShowList(SqList L)
{
	for (int i = 0; i < L.len; i++)
	{
		cout << L.elem[i] << " ";
	}
	cout << endl;
}