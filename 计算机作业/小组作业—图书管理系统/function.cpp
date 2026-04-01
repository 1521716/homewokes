#include"function.h"



//更新文件
void UpdataList(BookList L)
{
	ofstream ofs;
	ofs.open("books.txt", ios::out);

	//默认改为左对齐，并且先写入表头
	ofs << left;
	ofs << setw(41) << "ISBN" << setw(49) << "书名" << setw(29) << "作者" 
		<< setw(10) << "价格" << setw(29) << "出版社" << endl;
	//开始写图书数据
	for (int t = 0; t < L.length; t++)
	{
		//统计书名中汉字个数以及字母个数，便于文本的对齐
		int tem1 = 0,tem2 = 0;
		int j = 0;
		while (L.elem[t].name[j] != '\0')
		{
			if(L.elem[t].name[j] < 'A' || L.elem[t].name[j]>'z')
				tem1++;
			if (L.elem[t].name[j] <= 'a' && L.elem[t].name[j] < -'z')
				tem2++;
			j++;
		}
		ofs << setw(29) << L.elem[t].isbn << setw(tem1 / 2+tem2) << L.elem[t].name <<setw(50-tem1*2-tem2)<< "" << setw(29)
			<< L.elem[t].writer << setw(10) << L.elem[t].price << setw(29) << L.elem[t].PHouse << endl;

	}

	ofs.close();
}

//主菜单
void menu()
{
	cout << "****************************************************************************************************" << endl;
	cout << "     *************                          图书管理系统                             **********     " << endl;
	cout << "     *************         1.批量添加                       2.输出图书               **********     " << endl;
	cout << "     *************         3.查找图书                       4.按位置插入图书         **********     " << endl;
	cout << "     *************         5.有序表的插入（价格升序）       6.删除图书               **********     " << endl;
	cout << "     *************         7.按照ISBN号修改图书             8.价格升序排序           **********     " << endl;
	cout << "     *************         9.统计                           0.退出                   **********     " << endl;
	cout << "****************************************************************************************************" << endl;
	cout << "请选择操作数:";
}

//初始化
Status InitList(BookList& L) 
{
	//分配空间
	L.elem = new Book[MAXSIZE];
	if (!L.elem)
		return ERROR;
	L.length = 0;

	//开始读文件，写入线性表中
	ifstream ifs;
	ifs.open("books.txt", ios::in);

	//判断文件是否打开成功
	if (!ifs.is_open())
	{
		cout << "初文件打开失败，原始数据无法加载！" << endl;
		return 0;
	}

	//临时辅助变量
	char line[200];

	//跳过第一行的表头
	ifs.getline(line, sizeof(line));

	//开始读取，并拷贝到表中
	while (ifs.getline(line, sizeof(line)))
	{
		if (sscanf(line, "%19s%29s%19s%lf%19s", L.elem[L.length].isbn, L.elem[L.length].name,
			L.elem[L.length].writer, &L.elem[L.length].price, L.elem[L.length].PHouse) == 5)
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

	return OK;
}

//判断ISBN号是否已经存在
Status	ISBNis(BookList L, const char isbn[])
{
	for (int i = 0; i < L.length; i++)
	{
		if (strcmp(isbn, L.elem[i].isbn) == 0)
			return OK;
	}
	return ERROR;
}

//批量添加
Status CreateList(BookList& L) 
{
	int n;
	cout << "请输入新增图书数量：";
	cin >> n;

	if (n <= 0 || n + L.length > MAXSIZE)
	{
		return ERROR;
	}

	//追加形式写入文件
	ofstream ofs;
	ofs.open("books.txt", ios::app);

	cout << "请依次输入ISBN，书名，作者，价格，出版社：" << endl;
	for (int i = L.length; i < L.length + n; i++)
	{
		cout << "第" << i + 1 << "本图书信息：" << endl;
		cout << "ISBN:";
		cin >> L.elem[i].isbn;

		//判断ISBN号是否已经存在
		if (ISBNis(L, L.elem[i].isbn) == OK)
		{
			cout << "该ISBN号已存在，请重新输入！" << endl;
			i--;
			continue;
		}

		cout << "书名：";
		cin >> L.elem[i].name;
		cout << "作者：";
		cin >> L.elem[i].writer;
		cout << "价格：";
		cin >> L.elem[i].price;
		cout << "出版社：";
		cin >> L.elem[i].PHouse;

		//左对齐
		ofs << left;

		ofs << setw(30) << L.elem[i].isbn << setw(40) << L.elem[i].name << setw(20)
			<< L.elem[i].writer << setw(10) << L.elem[i].price << setw(20) << L.elem[i].PHouse << endl;

	}
	//关闭文件
	ofs.close();

	//更新图书数量
	L.length += n;

	return OK;
}

//输出已有的图书
void ShowBook(BookList L)
{

	
	if (L.length == 0)
	{
		cout << "当前表为空表" << endl;
		return;
	}

	//左对齐格式
	cout << left;

	//表头
	cout << setw(30) << "ISBN" << setw(40) << "书名" << setw(20) 
		<< "作者" << setw(10) << "价格" << setw(20) << "出版社" << endl;

	//图书数据
	int i = 0;
	for (i = 0; i < L.length; i++)
	{
		cout << setw(30) << L.elem[i].isbn << setw(40) << L.elem[i].name << setw(20)
			<< L.elem[i].writer << setw(10) << L.elem[i].price << setw(20) << L.elem[i].PHouse << endl;
	}

}

//按ISBN查找
int LocateISBN(BookList L, const char isbn[]) 
{
	for (int i = 0; i < L.length; i++)
	{
		if (strcmp(L.elem[i].isbn, isbn) == 0)
			//返回该书所在的位置
			return i + 1; 
	}
	//查找失败 
	return 0;
}

//按书名查找 
int LocateName(BookList L, const char name[])
{
	for (int i = 0; i < L.length; i++)
	{
		if (strcmp(L.elem[i].name, name) == 0)
			return	i + 1;
	}
	return 0;
}

//按位置插入图书 				
Status InsertList(BookList& L, int i, Book x)
{
	//判断位置合法性
	if (i<1 || i>L.length + 1)
	{
		cout << "插入位置不合法！" << endl;
		return ERROR;
	}

	//判断线性表空间
	if (L.length >= MAXSIZE)
	{
		cout << "图书表已满，无法继续插入" << endl;
		return ERROR;
	}

	//查找插入位置并后移元素 
	for (int j = L.length; j >= i; j--)
	{
		L.elem[j] = L.elem[j - 1];
	}

	//插入图书
	L.elem[i - 1] = x;

	L.length++;

	cout << "插入成功！" << endl;

	//更新文件
	UpdataList(L);

	return OK;
}

//有序表的插入 (按价格排列)(升序)
Status InsertOrderList(BookList& L, Book x)
{
	if (L.length >= MAXSIZE)
	{
		cout << "图书表已满，无法继续插入" << endl;
		return ERROR;
	}

	int i = 0;
	while (i < L.length && L.elem[i].price < x.price)
	{
		i++;
	}
	
	for (int j = L.length; j > i; j--)
	{
		L.elem[j] = L.elem[j - 1];
	}

	L.elem[i] = x;

	L.length++;

	cout << "有序插入成功！" << endl;

	UpdataList(L);

	return OK;
}

//按ISBN删除图书
Status DeleteListISBN(BookList& L, const char isbn[]) 
{
	//查找图书位置
	int p = LocateISBN(L, isbn);
	if (p == 0)
	{
		std::cout << "未找到ISBN为" << isbn << "的图书！" << endl;
		return ERROR;
	}

	//查询结果
	cout << "为您找到：" << endl;
	cout << "ISBN: " << L.elem[p - 1].isbn << endl;
	cout << "书名: " << L.elem[p - 1].name << endl;
	cout << "作者: " << L.elem[p - 1].writer << endl;
	cout << "价格: " << L.elem[p - 1].price << endl;
	cout << "出版社: " << L.elem[p - 1].PHouse << endl;

	//再次确认删除操作
	char con;
	cout << "确认删除该图书吗？（y/n）";
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

	cout << "删除成功！" << endl;

	UpdataList(L);

	return OK;
}

//按照书名删除
Status DeleteListNAME(BookList& L, const char name[])
{
	int p = LocateName(L, name);
	if (p == 0)
	{
		std::cout << "未找到书名为" << name << "的图书！" << endl;
		return ERROR;
	}

	cout << "为您找到：" << endl;
	cout << "ISBN: " << L.elem[p - 1].isbn << endl;
	cout << "书名: " << L.elem[p - 1].name << endl;
	cout << "作者: " << L.elem[p - 1].writer << endl;
	cout << "价格: " << L.elem[p - 1].price << endl;
	cout << "出版社: " << L.elem[p - 1].PHouse << endl;

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

//按作者删除图书
Status DeleteListWriter(BookList& L, const char writer[]) 
{
	//寻找书籍
	int result[100] = { 0 };//储存符合条件图书的位置
	int i = 0, j = 0;
	for (i = 0; i < L.length; i++)
	{
		if (strcmp(L.elem[i].writer, writer) == 0)
		{
			result[j] = i+1;
			j++;
		}
	}
	
	//没有符合条件的图书
	if (result[0] == 0)
	{
		cout << "未找到作者为" << writer << "的图书！" << endl;
		return ERROR;
	}

	//输出所有符合条件的图书位置及信息，以便用户选择
	cout << "为您找到以下图书："<<endl;
	cout << setw(10) << "位置" << setw(20) << "ISBN" << setw(30)
		<< "书名" << setw(20) << "作者" << setw(10) << "价格" << setw(20) << "出版社" << endl;
	j = 0;
	while (result[j] != 0)
	{
		cout<<setw(10) << result[j] << setw(20) << L.elem[result[j] - 1].isbn << setw(30)
			<< L.elem[result[j] - 1].name << setw(20) << L.elem[result[j] - 1].writer << setw(10)
			<< L.elem[result[j] - 1].price << setw(20) << L.elem[result[j] - 1].PHouse << endl;
		j++;
	}

	//用户选择删除书籍位置
	cout << "请选择你要删除的书籍位置：";
	int pos;
	cin >> pos;
	j = 0;

	//判断用户输入位置是否合法
	while (result[j] != 0)
	{
		if (pos == result[j])
			break;
		j++;
	}
	if (!result[j])
	{
		cout << "删除位置不合法，删除失败！" << endl;
		return ERROR;
	}

	cout << "确认删除该图书吗？（y/n）";
	char con;
	cin >> con;

	if (con != 'y')
	{
		cout << "删除已取消！" << endl;
		return ERROR;
	}

	for (int i = pos; i < L.length; i++)
	{
		L.elem[i - 1] = L.elem[i];
	}

	L.length--;

	cout << "删除成功！" << endl;

	UpdataList(L);

	return OK;
}

//按照ISBN号修改图书信息
Status UpdatePrice(BookList& L, char* ISBN)
{
	//寻找符合条件的书籍
	for (int i = 0; i < L.length - 1; i++)
	{
		if (strcmp(L.elem[i].isbn, ISBN) == 0)
		{
			cout << "为您找到图书：" << endl;
			cout << setw(30) << "ISBN" << setw(40) << "书名" << setw(20)
				<< "作者" << setw(10) << "价格" << setw(20) << "出版社" << endl;
			cout << setw(30) << L.elem[i].isbn << setw(40) << L.elem[i].name << setw(20)
				<< L.elem[i].writer << setw(10) << L.elem[i].price << setw(20) << L.elem[i].PHouse << endl;
			cout << "请输入修改后的书名：";
			cin >> L.elem[i].name;
			cout << "请输入修改后的作者：";
			cin >> L.elem[i].writer;
			cout << "请输入修改后的价格：";
			cin >> L.elem[i].price;
			cout << "请输入修改后的出版社：";
			cin >> L.elem[i].PHouse;

			UpdataList(L);
			return OK;
		}
	}

	return ERROR;
}

//按照价格从低到高排序
void SortBooks(BookList& L)
{
	//冒泡排序
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

//按照出版社统计图书数量
void CountBooksByPHouse(BookList L)
{
	//判断线性表是否为空
	if (L.length == 0)
	{
		cout << "当前图书数量为0" << endl;
		return;
	}

	//j -> result数组最后下标的下一个位置     k -> 从零开始遍历result数组 
	int j = 0, k = 0;

	//储存已有出版社 
	char result[100][30] = { 0 };
	//储存已有出版社的图书个数 
	int tem[100] = { 0 };

	for (int i = 0; i < L.length; i++)
	{
		while (k < j)
		{
			if (strcmp(result[k], L.elem[i].PHouse) == 0)
			{
				tem[k]++;
				break;
			}
			k++;
		}
		if (k == j)
		{
			strcpy(result[j], L.elem[i].PHouse);
			tem[j]++;
			j++;
		}
		k = 0;
	}

	//输出结果
	for (int t = 0; t < j; t++)
	{
		cout << result[t] << "的书籍有：" << tem[t] << "本" << endl;
	}

}

//销毁线性表
void DestroyList(BookList& L)
{
	delete[]L.elem;
	L.length = 0;
}
