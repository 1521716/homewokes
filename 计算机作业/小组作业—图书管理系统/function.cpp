#include"function.h"



//更新文件
void UpdataList(BookList L)
{
	//创建流对象
	ofstream ofs;

	ofs.open("test.txt", ios::out);

	ofs << left;
	ofs << setw(43) << "ISBN" << setw(42) << "书名" << setw(10) << "价格" << endl;
	for (int t = 0; t < L.length; t++)
	{
		ofs << setw(30) << L.elem[t].isbn << setw(40) << L.elem[t].name << setw(10) << L.elem[t].price << endl;
	}

	ofs.close();
	
}
//菜单
void menu()
{
	cout << "****************************************************************************************************" << endl;
	cout << "     *************                          图书管理系统                             **********     " << endl;
	cout << "     *************         1.批量添加                       2.输出图书               **********     " << endl;
	cout << "     *************         3.查找图书                       4.按位置插入图书         **********     " << endl;
	cout << "     *************         5.有序表的插入（价格升序）       6.删除图书               **********     " << endl;
	cout << "     *************         7.按照ISBN号修改单价             8.价格升序排序           **********     " << endl;
	cout << "     *************         9.返回图书数量                   0.退出                   **********     " << endl;
	cout << "****************************************************************************************************" << endl;
	cout << "请选择操作数:";
}
Status InitList(BookList& L)//初始化 
{
	L.elem = new Book[MAXSIZE];
	if (!L.elem)
		return ERROR;
	L.length = 0;

	//开始读文件

	//创建流对象
	ifstream ifs;

	//打开文件
	ifs.open("test.txt", ios::in);

	//判断文件是否打开成功
	if (!ifs.is_open())
	{
		std::cout << "初文件打开失败，原始数据无法加载！" << endl;
		return 0;
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
			std::cout << "文件储存格式错误，已跳过该条数据！" << endl;
		}
	}

	//关闭文件
	ifs.close();

	std::cout << "初始化成功！" << endl;

	return OK;
}
Status CreateList(BookList& L)//批量添加 
{
	int n;
	std::cout << "请输入新增图书数量：";
	cin >> n;

	if (n <= 0 || n + L.length > MAXSIZE)
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
		cin >> L.elem[i].isbn;
		std::cout << "书名：";
		cin >> L.elem[i].name;
		std::cout << "价格：";
		cin >> L.elem[i].price;

		ofs << left;

		ofs <<  setw(30) << L.elem[i].isbn << setw(40) << L.elem[i].name << setw(10) << L.elem[i].price << endl;

	}
	ofs.close();
	L.length += n;


	return OK;
}
//输出已有的图书
void ShowBook(BookList L)
{

	int i = 0;
	if (L.length == 0)
		std::cout << "当前表为空表" << endl;

	else
	{
		cout << left;
		//表头
		cout << setw(25) << "ISBN" << setw(30) << "书名" << "价格" << endl;
		//图书数据
		for (i = 0; i < L.length; i++)
		{
			cout << setw(25) << L.elem[i].isbn << setw(30) << L.elem[i].name << L.elem[i].price << endl;
		}
	}
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
	/*ShowBook(L);*/

	UpdataList(L);

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
	for (int j = L.length; j > i; j--)
	{
		L.elem[j] = L.elem[j - 1];
	}
	L.elem[i] = x;
	L.length++;
	std::cout << "有序插入成功！" << endl;
	/*ShowBook(L);*/

	UpdataList(L);

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
	cin >> con;
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

	UpdataList(L);

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
	cin >> con;
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

	UpdataList(L);

	return OK;
}


//孙高彤


//按照ISBN号修改单价
void UpdatePrice(BookList& L, char* ISBN, double new_Price)
{
	for (int i = 0; i < L.length - 1; i++)
	{
		if (strcmp(L.elem[i].isbn, ISBN) == 0)
		{
			L.elem[i].price = new_Price;
			UpdataList(L);
			cout << "修改成功" << endl;
			return;
		}
	}
	cout << "未找到该ISBN的图书" << endl;
}
//按照价格从低到高排序
void SortBooks(BookList& L)
{
	Book t;
	for (int i = 0; i < L.length - 1; i++)
	{
		for (int j = 0; j < L.length - i - 1; j++)
		{
			if (L.elem[j].price > L.elem[j + 1].price)
			{
				t = L.elem[j];
				L.elem[j] = L.elem[j + 1];
				L.elem[j + 1] = t;
			}
		}
	}
	UpdataList(L);
	cout << "排序完成" << endl;
}
//返回图书数量
int CountBooks(BookList L)
{
	return L.length;
}
