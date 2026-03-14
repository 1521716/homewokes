#define  _CRT_SECURE_NO_WARNINGS
#include"Function.h"


//按任意键清屏函数
void Clear()
{
	system("pause");
	system("cls");
}
//初始化线性表+读取文件数据
Status InitList(BSqList* BL)
{
	//分配空间
	BL->books = new Book[MAXSIZE];
	if (!(BL->books))
	{
		cout << "分配空间失败！" << endl;
		return ERROR;
	}
	BL->length = 0;

	//开始读文件
	
	//创建流对象
	ifstream ifs;

	//打开文件
	ifs.open("book.txt", ios::in);

	//判断文件是否打开成功
	if (!ifs.is_open())
	{
		cout << "初文件打开失败，原始数据无法加载！" << endl;
		return ERROR;
	}

	//读文件

	//临时辅助变量
	char line[100];

	//跳过第一行的表头
	ifs.getline(line, sizeof(line));

	//开始读取，并拷贝到表中
	while (ifs.getline(line, sizeof(line)))
	{
		if (sscanf(line, "%s%s%lf", BL->books[BL->length].ISBN, BL->books[BL->length].Bname, &BL->books[BL->length].price) == 3)
		{
			BL->length++;
		}
		else
		{
			cout << "文件储存格式错误，已跳过该条数据！" << endl;
		}
	}

	//关闭文件
	ifs.close();

	////打印数据，测试用
	//cout << left;
	////表头
	//cout << setw(25) << "ISBN" << setw(30) << "书名" << "价格" << endl;
	//for (int i = 0; i < BL->length; i++)
	//{
	//	cout << setw(25)<<BL->books[i].ISBN <<setw(30) << BL->books[i].Bname <<  BL->books[i].price << endl;
	//}

	cout << "初始化成功！" << endl;

	return OK;
}

//菜单
void menu()
{
	cout << "*********************************************************************" << endl;
	cout << "         ***************    图书管理系统    ****************         " << endl;
	cout << "         ***************  1-查找    2-插入  ****************         " << endl;
	cout << "         ***************  3-删除    4-修改  ****************         " << endl;
	cout << "         **************  5-排序    6-计数  ****************         " << endl;
	cout << "         ***************       0-退出       ****************         " << endl;
	cout << "*********************************************************************" << endl;
	cout << "请选择操作数  >";
}

//查找（ISBN或书名）

//插入（按位置）

//删除（按ISBN或者书名）

//修改价格（按ISBN）

//排序（价格由低到高，也可以额外实现从高到低，逻辑一致）

//计数

//销毁顺序表
Status DeleteList(BSqList* BL)
{
	delete[]BL->books;
	if (!(BL->books))
	{
		cout << "顺序表销毁失败！" << endl;
		return ERROR;
	}
	BL->length = 0;

	delete BL;

	return OK;
}