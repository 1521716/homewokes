#include "Stack.h"



//菜单操作
void menu()  
{
	SqStack L;  //定义栈
	int x, num;
	ElemType elem;

	while (1)
	{
		cout << "********************************************" << endl;
		cout << "     1-初始化   2-创建         3-输出       " << endl;
		cout << "     4-查找     5-插入         6-删除       " << endl;
		cout << "     7-排序     8-有序表插入   0-退出       " << endl;
		cout << "********************************************" << endl;
		cin >> x;
		switch (x)
		{
		case 1:
		{
			if (InitStack(L) == OK)
				cout << "初始化成功！" << endl;
			else
				cout << "初始化失败！" << endl;
			break;
		}
		case 2:
		{
			if (CreateStack(L) == OK)
				cout << "创建成功！" << endl;
			else
				cout << "创建失败！" << endl;
			break;
		}
		case 3:
		{
			ShowStack(L);
			break;
		}
		case 4:
		{
			cout << "请输入所要查找的元素：";
			cin >> elem;
			num = LocateStack(L, elem);
			if (num == 0)
				cout << "查找失败！" << endl;
			else
				cout << "查找成功，是第" << num << "个元素！" << endl;
			break;
		}
		case 5:
		{
			cout << "请输入所要插入的元素：";
			cin >> elem;
			cout << "请输入所要插入的位置：";
			cin >> num;
			if (InsertStack(L, num, elem) == OK)
				cout << "插入成功！" << endl;
			else
				cout << "插入失败！" << endl;
			break;
		}
		case 6:
		{
			cout << "请输入所要删除的位置：";
			cin >> num;
			if (DeleteStack(L, num) == OK)
				cout << "删除成功！" << endl;
			else
				cout << "删除失败！" << endl;
			break;
		}
		case 7:
		{
			SortStack(L);
			cout << "排序操作结束！" << endl;
			break;
		}
		case 8:
		{
			cout << "请输入所要插入的元素：";
			cin >> elem;
			if (InsertOrderStack(L, elem) == OK)
				cout << "有序表插入成功！" << endl;
			else
				cout << "有序表插入失败！" << endl;
			break;
		}
		case 0:
		{
			cout << "退出系统！" << endl;
			return;
		}
		default: cout << "输入有误，请重新输入！" << endl;
		}
		system("pause");
		system("cls");
	}
}

Status InitStack(SqStack& L)//初始化操作 
{
	L.elem = new ElemType[MAXSIZE];
	if (L.elem == NULL)
		return ERROR;
	L.top = 0;
	return OK;
}
Status CreateStack(SqStack& L)//创建操作 
{
	int i;
	cout << "请输入整数个数：";
	cin >> L.top;
	if (L.top<0 || L.top>MAXSIZE)
		return ERROR;
	cout << "请依次输入各个整数：" << endl;
	for (i = 0; i < L.top; i++)
	{
		cin >> L.elem[i];
	}
	return OK;
}
void ShowStack(SqStack L)//输出操作 
{
	int i;
	if (L.top == 0)
		cout << "当前表为空表！" << endl;
	else
	{
		for (i = 0; i < L.top; i++)
			cout << L.elem[i] << "  ";
		cout << endl;
	}
}
int LocateStack(SqStack L, ElemType x)//查找操作
{
	//代码省略！
}
Status InsertStack(SqStack& L, int i, ElemType x)//插入操作
{
	//代码省略！
}
Status DeleteStack(SqStack& L, int i)//删除操作
{
	//代码省略！
}
void SortStack(SqStack& L)//排序操作
{
	//代码省略！
//可使用上学期学过的冒泡排序或选择排序！
}
Status InsertOrderStack(SqStack& L, ElemType x)//有序表插入操作 
{
	//代码省略！
}
