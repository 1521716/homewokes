#include"SqList.h"

void menu()  //菜单操作
{
	SqList L;  //定义顺序表
	int x, num;
	ElemType elem;

	while (1)
	{
		cout << "********************************************" << endl;
		cout << "     1-初始化   2-创建         3-输出       " << endl;
		cout << "     4-查找     5-插入         6-删除       " << endl;
		cout << "     7-排序     8-有序表插入   0-退出       " << endl;
		cout << "********************************************" << endl;
		cout << "请输入操作数 >";
		cin >> x;
		switch (x)
		{
		case 1:
		{
			if (InitList(L) == OK)
				cout << "初始化成功！" << endl;
			else
				cout << "初始化失败！" << endl;
			break;
		}
		case 2:
		{
			if (CreateList(L) == OK)
				cout << "创建成功！" << endl;
			else
				cout << "创建失败！" << endl;
			break;
		}
		case 3:
		{
			ShowList(L);
			break;
		}
		case 4:
		{
			cout << "请输入所要查找的元素：";
			cin >> elem;
			num = LocateList(L, elem);
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
			if (InsertList(L, num, elem) == OK)
				cout << "插入成功！" << endl;
			else
				cout << "插入失败！" << endl;
			break;
		}
		case 6:
		{
			cout << "请输入所要删除的位置：";
			cin >> num;
			if (DeleteList(L, num) == OK)
				cout << "删除成功！" << endl;
			else
				cout << "删除失败！" << endl;
			break;
		}
		case 7:
		{
			SortList(L);
			cout << "排序操作结束！" << endl;
			break;
		}
		case 8:
		{
			cout << "请输入所要插入的元素：";
			cin >> elem;
			if (InsertOrderList(L, elem) == OK)
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

Status InitList(SqList& L)//初始化操作 
{
	L.elem = new ElemType[MAXSIZE];
	if (L.elem == NULL)
		return ERROR;
	L.length = 0;
	return OK;
}
Status CreateList(SqList& L)//创建操作 
{
	int i;
	cout << "请输入整数个数：";
	cin >> L.length;
	if (L.length<0 || L.length>MAXSIZE)
		return ERROR;
	cout << "请依次输入各个整数：" << endl;
	for (i = 0; i < L.length; i++)
	{
		cin >> L.elem[i];
	}
	return OK;
}
void ShowList(SqList L)//输出操作 
{
	int i;
	if (L.length == 0)
		cout << "当前表为空表！" << endl;
	else
	{
		for (i = 0; i < L.length; i++)
			cout << L.elem[i] << "  ";
		cout << endl;
	}
}
int LocateList(SqList L, ElemType x)//查找操作
{
	//判断空表
	if (L.length == 0)
		return ERROR;

	//遍历查询
	int i;
	for (i = 0; i < L.length; i++)
	{
		if (L.elem[i] == x)
			return i + 1;
	}

	//表中没有值为x的元素
	return 0;
}
Status InsertList(SqList& L, int i, ElemType x)//插入操作
{
	//判断表是否已满
	if (L.length == MAXSIZE)
		return ERROR;
	//判断插入位置是否合法
	if (i<1 || i>L.length + 1)
		return ERROR;

	//插入
	int pos = L.length;
	while (pos >= i)
	{
		L.elem[pos] = L.elem[pos - 1];
		pos--;
	}
	L.elem[pos] = x;
	L.length++;

	return OK;
}
Status DeleteList(SqList& L, int i)//删除操作
{
	//判断空表
	if (L.length == 0)
		return ERROR;
	//判断删除位置合法性
	if (i<1 || i>L.length)
		return ERROR;

	int pos = i;
	while (pos < L.length)
	{
		L.elem[pos - 1] = L.elem[pos];
		pos++;
	}
	L.length--;

	return OK;
}
void SortList(SqList& L)//排序操作
{
	if (L.length == 0 || L.length == 1)
		return;

	int i, j, tap;
	for (i = 0; i < L.length - 1; i++)
	{
		tap = 0;
		for (j = 0; j < L.length - 1 - i; j++)
		{
			if (L.elem[j] > L.elem[j + 1])
			{
				int tem = L.elem[j];
				L.elem[j] = L.elem[j + 1];
				L.elem[j + 1] = tem;
				tap = 1;
			}
		}
		if (!tap)
			break;
	}

}
Status InsertOrderList(SqList& L, ElemType x)//有序表插入操作 
{
	if (L.length == MAXSIZE)
		return ERROR;

	int i = L.length - 1;
	while (i >= 0 && L.elem[i] > x)
	{
		L.elem[i + 1] = L.elem[i];
		i--;
	}
	L.elem[i + 1] = x;
	L.length++;

	return OK;
}