#include<iostream>
using namespace std;

#define MAXSIZE 100
#define OK 1
#define ERROR 0

typedef int Status;
typedef int ElemType;
typedef struct {
	ElemType* elem;
	int len;
}SqList;


//函数声明
//删除首个指定值
Status DeleteElemList(SqList& L, ElemType e);
//打印
void ShowList(SqList L);
int main()
{
	SqList L;
	L.elem = new ElemType[MAXSIZE];
	L.len = 0;
	for (int i = 0; i < 10; i++)
	{
		L.elem[i] = i;
		L.len++;
	}
	ShowList(L);
	DeleteElemList(L, 4);
	ShowList(L);
	delete[]L.elem;
	return 0;
}

//函数定义
//删除首个指定值
Status DeleteElemList(SqList& L, ElemType e)
{
	if (L.len == 0)
		return ERROR;
	int i;
	for (i = 0; i < L.len; i++)
	{
		if (L.elem[i] == e)
		{
			for (int j = i; j < L.len - 1; j++)
			{
				L.elem[j] = L.elem[j + 1];
			}
			break;
		}
	}
	if (i == L.len)
		return ERROR;
	L.len--;
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