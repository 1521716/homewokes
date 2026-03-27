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
				cout << "前插入创建失败！" << endl;
			else
				cout << "前插入创建成功！" << endl;
			break;
		}
		case 2:
		{
			if (TailCreateList(L) == OK)
				cout << "尾插入创建成功！" << endl;
			else
				cout << "尾插入创建失败！" << endl;
			break;
		}
		case 3:
		{
			cout << "请输入插入数据位置：" << endl;
			int i;
			cin >> i;
			cout << "请输入插入数据大小：" << endl;
			ElemType x;
			cin >> x;
			if (InsertList(L,i,x) == OK)
			{
				cout << "插入成功！" << endl;
			}
			else
			{
				cout << "插入失败！" << endl;
			}
			break;
		}
		case 4:
		{
			cout << "请输入删除结点位置：" << endl;
			int i;
			cin >> i;
			if (DeleteList(L, i) == OK)
			{
				cout << "删除成功！" << endl;
			}
			else
			{
				cout << "删除失败！" << endl;
			}
			break;
		}
		case 5:
		{
			ShowList(L);
			break;
		}
		case 6:
		{
			if (SortList(L) == OK)
			{
				cout << "排序成功！" << endl;
			}
			else
			{
				cout << "排序失败！" << endl;
			}
			break;
		}
		case 7:
		{
			cout << "请输入要插入的数据：";
			ElemType x;
			cin >> x;
			if (InsertOrderList(L, x) == OK)
			{
				cout << "插入成功！" << endl;
			}
			else
			{
				cout << "插入失败！" << endl;
			}
			break;
		}
		case 8:
		{
			LinkList L2;
			LNode* HeadNode = new LNode;
			L2 = HeadNode;
			L2->next = NULL;
			LNode* p = L2;
			for (int i = 5; i > 0; i--)
			{
				LNode* tem = new LNode;
				tem->data = i;
				tem->next = p->next;
				p->next = tem;
			}
			if (MergeList(L, L2) == OK)
			{
				cout << "合并成功！" << endl;
			}
			else
			{
				cout << "合并失败！" << endl;
			}
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
//插入操作
Status InsertList(LinkList& L, int i, ElemType x)
{
	LNode* p = L;
	int j = 0;
	while (p&& j < i - 1)
	{
		p = p->next;
		j++;
	}

	if (!p||j>i-1)
	{
		return ERROR;
	}
	LNode* newNode = new LNode;
	newNode->data = x;
	newNode->next = p->next;
	p->next = newNode;

	return OK;
}
//删除操作
Status DeleteList(LinkList& L, int i)
{
	if (!L->next)
		return ERROR;

	LNode* p = L;
	int j = 0;
	while (p && j < i - 1)
	{
		p = p->next;
		j++;
	}

	if (!p || j > i - 1)
	{
		return ERROR;
	}

	LNode* tem = p->next;
	p->next = tem->next;
	delete tem;

	return OK;
}
//输出操作
void ShowList(LinkList L)
{
	if (L->next == NULL)
	{
		cout << "当前链表为空！" << endl;
		return;
	}

	LNode* p = L->next;
	cout << "当前链表为：" << endl;
	while (p != NULL)
	{
		cout << p->data << "\t";
		p = p->next;
	}
	cout << endl;
}

//排序操作
Status SortList(LinkList& L)
{
	if (L->next == NULL)
		return ERROR;

	LNode* p = L->next;

	//选择排序
	while (p->next != NULL)
	{
		LNode* tem = p->next;
		ElemType min = p->data;
		LNode* n = NULL;
		while (tem != NULL)
		{
			if (tem->data < min)
			{
				n = tem;
				min = tem->data;
			}
			tem = tem->next;
		}

		if (n != NULL)
		{
			n->data = p->data;
			p->data = min;
		}

		p = p->next;
	}

	return OK;
}

//有序表插入操作 
Status InsertOrderList(LinkList& L, ElemType x)
{
	LNode* p = L;

	while (p->next != NULL && p->next->data < x)
	{
		p = p->next;
	}

	LNode* newNode = new LNode;
	newNode->data = x;
	newNode->next = p->next;
	p->next = newNode;

	return OK;
}
//有序表合并
Status MergeList(LinkList& L1, LinkList L2)
{
	LNode* p1 = L1, * p2 = L2,*tem;

	while (p1->next != NULL && p2->next != NULL)
	{
		if(p1->next->data <= p2->next->data)
		{
			p1 = p1->next;
		}
		else
		{
			tem = p1->next;
			p1->next = p2->next;
			p2->next = tem;
		}
		
	}

	p1->next = p2->next;

	return OK;
}