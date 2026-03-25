#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string.h> 
#include<iomanip>//用于控制输出格式
#include<fstream>

#define OK 1
#define ERROR 0
#define MAXSIZE 100

typedef int Status;
typedef struct
{
	char isbn[20];
	char name[20];
	double price;
} Book;
typedef struct
{
	Book* elem;//首地址/数组名 
	int length;
}BookList;

//初始化线性表+读取文件数据
Status InitList(BookList & L)
{
	//分配空间
	L.elem = new Book[MAXSIZE];
	if (!(L.elem))
	{
		cout << "分配空间失败！" << endl;
		return ERROR;
	}
	L.length = 0;

	//开始读文件

	//创建流对象
	ifstream ifs;

	//打开文件
	ifs.open("test.txt", ios::in);

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
		if (sscanf(line, "%s%s%lf", L.elem[L.length].isbn, L.elem[L.length].name, &L.elem[L.length].price) == 3)
		{
			L.length++;
		}
		else
		{
			cout << "文件储存格式错误，已跳过该条数据！" << endl;
		}
	}

	//关闭文件
	ifs.close();

	cout << "初始化成功！" << endl;

	return OK;
}

Status CreateList(BookList& L)//创建 
{
	int n;
	std::cout << "请输入图书数量：";
	std::cin >> n;
	if (n<0 || n + L.length>MAXSIZE)
	{
		return ERROR;
	}

	//创建流对象
	ofstream ofs;

	ofs.open("test.txt", ios::app);

	std::cout << "请依次输入ISBN，书名，价格" << endl;
	for (int i = L.length; i < L.length + n; i++)
	{
		std::cout << "第" << i + 1 << "本图书信息：" << endl;
		std::cout << "ISBN:";
		std::cin >> L.elem[i].isbn;
		std::cout << "书名：";
		std::cin >> L.elem[i].name;
		std::cout << "价格：";
		std::cin >> L.elem[i].price;

		//写入文件
		ofs<<std::left;
		ofs << "\n" << setw(25) << L.elem[i].isbn << setw(30) << L.elem[i].name << L.elem[i].price;
	}
	L.length += n;
	
	//关闭文件
	ofs.close();

	return OK;
}
//输出已有的图书
void ShowBook(BookList L)
{


	cout << left;
	//表头
	cout << setw(25) << "ISBN" << setw(30) << "书名" << "价格" << endl;
	//图书数据
	for (int i = 0; i < L.length; i++)
	{
		cout << setw(25) << L.elem[i].isbn << setw(30) << L.elem[i].name << L.elem[i].price << endl;
	}


	/*
	int i = 0;
	if (L.length == 0)
		std::cout << "当前表为空表" << endl;
	else
	{
		std::cout << "------图书列表-------" << endl;
		std::cout << "序号\tISBN\t\t书名\t\t价格" << endl;
		for (i = 0; i < L.length; i++)
		{
			std::cout << i + 1 << "\t"
				<< L.elem[i].isbn << "\t"
				<< L.elem[i].name << "\t\t"
				<< L.elem[i].price << endl;
		}
		std::cout << "==================\n" << endl;
	}*/
}
int LocateISBN(BookList L, const char isbn[])//按ISBN查找 
{
	for (int i = 0; i < L.length; i++)
	{
		if (strcmp(L.elem[i].isbn, isbn) == 0)
			return i + 1;//返回该书所在的位置 
	}
	return 0;//查找失败 
}
int LocateName(BookList L, const char name[])//按书名查找 
{
	for (int i = 0; i < L.length; i++)
	{
		if (strcmp(L.elem[i].name, name) == 0)
			return	i + 1;
	}
	return 0;
}
//插入图书 				//插入的位置 
Status InsertList(BookList& L, int i, Book x)//要插入的书 
{
	if (i<1 || i>L.length + 1)
	{
		std::cout << "插入位置不合法！" << endl;
		return ERROR;
	}
	if (L.length >= MAXSIZE)
	{
		std::cout << "图书表已满，无法继续插入" << endl;
		return ERROR;
	}
	//元素后移 
	for (int j = L.length; j >= i; j--)
	{
		L.elem[j] = L.elem[j - 1];
	}
	L.elem[i - 1] = x;
	L.length++;
	std::cout << "插入成功！" << endl;
	ShowBook(L);
	return OK;
}
//有序表的插入 (按价格排列)(升序)
Status InsertOrderList(BookList& L, Book x)
{
	int i = 0;
	if (L.length >= MAXSIZE)
	{
		std::cout << "图书表已满，无法继续插入" << endl;
		return ERROR;
	}
	//查找插入位置 
	while (i < L.length && L.elem[i].price < x.price)
	{
		i++;
	}
	//元素后移 
	for (int j = L.length; j >= i; j--)
	{
		L.elem[j] = L.elem[j - 1];
	}
	L.elem[i - 1] = x;
	L.length++;
	std::cout << "有序插入成功！" << endl;
	ShowBook(L);
	return OK;
}
Status DeleteListISBN(BookList& L, const char isbn[])//按ISBN删除图书 
{
	int p = LocateISBN(L, isbn);
	if (p == 0)
	{
		std::cout << "未找到ISBN为" << isbn << "的图书！" << endl;
		return ERROR;
	}
	std::cout << "为您找到：" << endl;
	std::cout << "ISBN: " << L.elem[p - 1].isbn << endl;
	std::cout << "书名: " << L.elem[p - 1].name << endl;
	std::cout << "价格: " << L.elem[p - 1].price << endl;
	char con;
	std::cout << "确认删除该图书吗？（y/n）";
	std::cin >> con;
	if (con != 'y')
	{
		std::cout << "删除已取消！" << endl;
		return ERROR;
	}
	for (int i = p; i < L.length; i++)
	{
		L.elem[i - 1] = L.elem[i];
	}
	L.length--;
	std::cout << "删除成功！" << endl;
	return OK;
}
Status DeleteListNAME(BookList& L, const char name[])
{
	int p = LocateName(L, name);
	if (p == 0)
	{
		std::cout << "未找到书名为" << name << "的图书！" << endl;
		return ERROR;
	}
	std::cout << "为您找到：" << endl;
	std::cout << "ISBN: " << L.elem[p - 1].isbn << endl;
	std::cout << "书名: " << L.elem[p - 1].name << endl;
	std::cout << "价格: " << L.elem[p - 1].price << endl;
	char con;
	std::cout << "确认删除该图书吗？（y/n）";
	std::cin >> con;
	if (con != 'y')
	{
		std::cout << "删除已取消！" << endl;
		return ERROR;
	}
	for (int i = p; i < L.length; i++)
	{
		L.elem[i - 1] = L.elem[i];
	}
	L.length--;
	std::cout << "删除成功！" << endl;
	return OK;
}
/*
void UpdatePrice(BookList* L, char* ISBN, double new_Price)
{
	for (int i = 0; i < L->length - 1; i++)
	{
		if (strcmp(L - elem[i].ISBN, ISBN == 0)
		{
			L->elem[i].Price = new_Price;
			SaveBooks(L);
			cout << "修改成功" << endl;
			return;
		}
	}
	cout << "未找到该ISBN的图书" << endl;
}
void SortBooks(BookList* L)
{
	double t;
	for (int i = 0; i < L->length - 1; i++)
	{
		for (int j = 0; j < L->length - i - 1; j++)
		{
			if (L->elem[j].Price > L->elem[j + 1].Price)
			{
				t = L->elem[j];
				L->elem[j] = L->elem[j + 1];
				L->elem[j + 1] = t;
			}
		}
	}
	SaveBooks(L);
	cout << "排序完成" << endl;
}
int CountBooks(BookList* L)
{
	return L->length;
}*/


int main()
{
	BookList L;
	InitList(L);
	ShowBook(L);
	CreateList(L);
	ShowBook(L);
	return 0;
}