#include"BiTree.h"

//创建二叉树 
TNode* createTree(BTree T)
{
	cout << "请输入当前节点的val('#'表示空):";
	char ch = '\0';
	cin >> ch;

	if (ch != '#')
	{
		T = new TNode;
		T->val = ch;
		T->lchild = T->rchild = NULL;
		T->lchild = createTree(T->lchild);
		T->rchild = createTree(T->rchild);
		return T;
	}
	return NULL;

}
//递归遍历 
//先序遍历 
void showDLR(const BTree T)
{
	if (T != NULL)
	{
		cout << T->val << " ";
		showDLR(T->lchild);
		showDLR(T->rchild);
	}
}
//中序遍历
void showLDR(const BTree T)
{
	if (T != NULL)
	{
		showLDR(T->lchild);
		cout << T->val << " ";
		showLDR(T->rchild);
	}
}
//后序遍历
void showLRD(const BTree T)
{
	if (T != NULL)
	{
		showLRD(T->lchild);
		showLRD(T->rchild);
		cout << T->val << " ";
	}
}

//左右交换二叉树
TNode* transfer(BTree T)
{
	if (T == NULL)
		return NULL;

	TNode* p = T->lchild;
	T->lchild = T->rchild;
	T->rchild = p;

	T->lchild = transfer(T->lchild);
	T->rchild = transfer(T->rchild);

	return T;
}
//非递归遍历
//先序遍历
void noShowDLR(const BTree T)
{
	stack<TNode*> s;
	TNode* p = T;
	while (p || !s.empty())
	{
		while (p)
		{
			cout << p->val << " ";
			s.push(p);
			p = p->lchild;
		}
		if (!s.empty())
		{
			p = s.top();
			s.pop();
			p = p->rchild;
		}

	}
}

//中序遍历
void noShowLDR(const BTree T)
{
	stack<TNode*> s;
	TNode* p = T;
	while (p || !s.empty())
	{
		while (p)
		{
			s.push(p);
			p = p->lchild;
		}
		if (!s.empty())
		{
			p = s.top();
			cout << p->val << " ";
			s.pop();
			p = p->rchild;
		}

	}
}

//统计二叉树结点个数
int totalTreeNode(const BTree T)
{
	if (T == NULL)
		return 0;
	return totalTreeNode(T->lchild) + totalTreeNode(T->rchild) + 1;
}

//统计二叉树叶子节点个数
int totalLastTreeNode(const BTree T)
{
	if (T && T->lchild == NULL && T->rchild == NULL)
		return 1;
	if (!T)
		return 0;
	return totalLastTreeNode(T->lchild) + totalLastTreeNode(T->rchild);
}

//菜单函数
void menu()
{
	BTree T = NULL;
	while (true)
	{
		cout << "****************************************二叉树小程序*******************************************" << endl;
		cout << "	1.创建			2.遍历（递归）			3.左右子树交换	" << endl;
		cout << "	4.遍历（非递归）	5.统计二叉树节点个数		6.统计二叉树叶子结点个数	" << endl;
		cout << "					0.退出		" << endl;
		cout << "***********************************************************************************************" << endl;
		int select = 0;
		int option = 0;
		cout << "请选择操作数：";
		cin >> select;



		switch (select)
		{
		case 1:
			T = createTree(T);
			break;
		case 2:
			cout << "*************************************遍历（递归）功能************************************" << endl;
			cout << "	1.先序遍历		2.中序遍历		3.后序遍历		0.退出	" << endl;
			cout << "*****************************************************************************************" << endl;
			cout << "请选择操作数：";
			cin >> option;
			switch (option)
			{
			case 1:
				showDLR(T);
				cout << endl;
				break;
			case 2:
				showLDR(T);
				cout << endl;
				break;
			case 3:
				showLRD(T);
				cout << endl;
				break;
			case 0:
				cout << "遍历（递归）功能已退出！" << endl;
				break;
			default:
				cout << "操作数不合法，已默认退出！" << endl;
			}
			break;
		case 3:
			T = transfer(T);
			cout << "二叉树所有子树已交换！" << endl;
			break;
		case 4:
			cout << "*************************************遍历（非递归）功能**********************************" << endl;
			cout << "	1.先序遍历		2.中序遍历			0.退出	" << endl;
			cout << "*****************************************************************************************" << endl;
			cout << "请选择操作数：";
			cin >> option;
			switch (option)
			{
			case 1:
				noShowDLR(T);
				cout << endl;
				break;
			case 2:
				noShowLDR(T);
				cout << endl;
				break;
			case 0:
				cout << "遍历（非递归）功能已退出！" << endl;
				break;
			default:
				cout << "操作数不合法，已默认退出！" << endl;
			}
			break;
		case 5:
			cout << "二叉树结点个数为：" << totalTreeNode(T) << endl;
			break;
		case 6:
			cout << "二叉树叶子结点个数为：" << totalLastTreeNode(T) << endl;
			break;
		case 0:
			cout << "程序使用结束！" << endl;
			return;
		default:
			cout << "操作数不合法，请重新输入！" << endl;
		}
		system("pause");
		system("cls");
	}

}
