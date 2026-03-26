#include"LinkList.h"

//菜单操作
void menu()  
{
	//定义链表
	LinkList L;  
	int x, num;
	ElemType elem;

	if (InitList(L) == OK)
		cout << "初始化成功！" << endl;
	else
		cout << "初始化失败！" << endl;

	while (1)
	{
		cout << "根据所做操作选择以下数字序号：" << endl;
		cout << "1：前插入创建单链表       2：尾插入创建单链表       3：执行插入操作" << endl;
		cout << "4：执行删除操作           5：执行输出操作           6：执行排序操作" << endl;
		cout << "7：执行有序表的插入操作   8：执行有序表的合并操作   0：退出        " << endl;
		cin >> x;
		switch (x)
		{
		case 1:
		{
			if (HeadCreateList(L) == ERROR)
				cout << "创建失败！" << endl;
			else
				cout << "创建成功！" << endl;
			break;
		}
		case 2:
		{
			if (TailCreateList(L) == OK)
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
		/*case 4:
		{
			cout << "请输入所要查找的元素：";
			cin >> elem;
			//num = LocateList(L, elem);
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
		}*/
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

//初始化操作
Status InitList(LinkList& L)
{
	LNode *Head = new Node;
	if (!Head)
		return ERROR;
	L = Head;
	L->next = NULL;
	return OK;
}
//创建操作
//前插创建单链表
Status HeadCreateList(LinkList& L)
{
	if (!L)
		return ERROR;
	cout << "请输入结点个数：";
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		LNode* newNode = new Node;
		cout << "请输入第" << i + 1 << "个元素的值：";
		cin >> newNode->data;
		newNode->next = L->next;
		L->next = newNode;
	}

	return OK;

}
//尾插创建单链表
Status TailCreateList(LinkList& L)
{
	LNode* p = L;

	cout << "请输入结点个数：";
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		LNode* newNode = new Node;
		cout << "请输入第" << i + 1 << "个元素的值：";
		cin >> newNode->data;
		p->next = newNode;
		p = newNode;
	}
	p->next = NULL;

	return OK;
}
/*//插入操作
Status InsertList(LinkList& L, int i, ElemType x);
//删除操作
Status DeleteList(LinkList& L, int i);
//输出操作*/
void ShowList(LinkList L)
{
	if (L->next == NULL)
	{
		cout << "当前链表为空！" << endl;
		return;
	}

	LNode* p = L->next;
	while (p != NULL)
	{
		cout << p->data << "\t";
		p = p->next;
	}
	cout << endl;
}
/*
//排序操作
void SortList(LinkList& L);
//有序表插入操作 
Status InsertOrderList(LinkList& L, ElemType x);
//有序表合并*/