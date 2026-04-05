#include "Stack.h"

//菜单操作
void menu()  
{
	SqStack S;  //定义栈
	int x;

	while (1)
	{
		cout << "*****************************************************" << endl;
		cout << "     1-初始化        2-判断空栈         3-入栈       " << endl;
		cout << "     4-出栈          5-获取栈顶元素     6-遍历       " << endl;
		cout << "                     0-退出                          " << endl;
		cout << "*****************************************************" << endl;
		cin >> x;
		switch (x)
		{
		case 1:
		{
			if (InitStack(S) == OK)
				cout << "初始化成功！" << endl;
			else
				cout << "初始化失败！" << endl;
			break;
		}
		case 2:
		{
			if (IsEmpty(S) == OK)
				cout << "当前栈为空！" << endl;
			else
				cout << "当前栈非空！" << endl;
			break;
		}
		case 3:
		{
			ElemType x;
			cout << "请输入要入栈的元素：";
			cin >> x;
			if (PushStack(S, x) == OK)
				cout << "入栈成功！" << endl;
			else
				cout << "栈已满，入栈失败！" << endl;
			break;
		}
		case 4:
		{
			ElemType e;
			if (PopStack(S, e) == OK)
				cout << "元素" << e << "已出栈！" << endl;
			else
				cout << "栈为空！" << endl;
			break;
		}
		case 5:
		{
			ElemType e;
			if (GetTop(S, e) == OK)
				cout << "当前栈顶元素为：" << e << endl;
			else
				cout << "获取栈顶元素失败！" << endl;
			break;
		}
		case 6:
		{
			ShowStack(S);
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
Status InitStack(SqStack& S) 
{
	S.elem = new ElemType[MAXSIZE];

	if (S.elem == NULL)
		return ERROR;

	S.top = -1;

	return OK;
}

//判断栈是否为空
Status IsEmpty(SqStack S)
{
	if (S.top == -1)
		return OK;

	return ERROR;
}

//入栈
Status PushStack(SqStack& S, ElemType x)
{
	if (S.top == MAXSIZE - 1)
		return ERROR;

	S.elem[++S.top] = x;

	return OK;
}

//出栈
Status PopStack(SqStack& S, ElemType &e)
{
	if (S.top<0 || S.top>MAXSIZE - 1)
		return ERROR;

	e = S.elem[S.top--];

	return OK;
}

//获取栈顶元素
Status GetTop(SqStack S, ElemType& e)
{
	if (S.top<0 || S.top>MAXSIZE - 1)
		return ERROR;

	e = S.elem[S.top];

	return OK;
}

//遍历栈
void ShowStack(SqStack S)
{
	if (S.top<-1 || S.top>MAXSIZE - 1)
	{
		cout << "栈状态异常！" << endl;
		return;
	}

	if (S.top == -1)
	{
		cout << "当前栈为空！" << endl;
		return;
	}

	cout << "当前栈元素为：" << endl;
	int i = S.top;
	while (i > -1)
	{
		cout << S.elem[i] << " ";
		i--;
	}
	cout << endl;

}
