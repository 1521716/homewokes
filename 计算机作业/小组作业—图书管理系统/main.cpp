#include"function.h"

int main()
{
	//创建线性表（顺序表或者链表）(此为顺序表)
	BookList L;

	//初始化线性表+读取文件数据
	if (!InitList(L))
	{
		cout << "初始化失败" << endl;
		return 0;
	}
	cout << "初始化成功！" << endl;

	//用户选择
	int option = 0;

	do
	{
		//菜单
		menu();

		//用户输入
		cin >> option;

		switch (option)
		{
		case 0:
		{
			// 退出
			cout << "程序使用结束，感谢体验！" << endl;
			break;
		}
		case 1:
		{
			// 批量添加图书
			if (CreateList(L) == OK)
				cout << "添加成功！" << endl;
			else
				cout << "添加失败！" << endl;
			break;
		}
		case 2:
		{
			// 输出图书
			ShowBook(L);
			break;
		}
		case 3:
		{
			cout << "*********************************************************************" << endl;
			cout << "******************************查找程序*******************************" << endl;
			cout << "	1-按照ISBN号查找	2-按照书名查找		0-退出		" << endl;
			cout << "*********************************************************************" << endl;
			cout << "请选择查找方式：" << endl;
			int tem;
			cin >> tem;

			switch (tem)
			{
			case 1:
			{
				// 按ISBN查找
				char isbn[20];
				cout << "请输入要查找的ISBN：";
				cin >> isbn;
				int pos = LocateISBN(L, isbn);
				if (pos)
					cout << "找到图书，位置为：" << pos << endl;
				else
					cout << "未找到该ISBN图书！" << endl;
				break;
			}
			case 2:
			{
				// 按书名查找
				char name[20];
				cout << "请输入要查找的书名：";
				cin >> name;
				int pos = LocateName(L, name);
				if (pos)
					cout << "找到书名为："<<name<<"的图书，位置为：" << pos << endl;
				else
					cout << "未找到书名为：" << name << "的图书！" << endl;
				break;
			}
			case 0:
			{
				// 退出
				cout << "查找程序使用结束！" << endl;
				break;
			}
			default:
				cout << "输入错误，默认退出查找程序！" << endl;
			}
			break;
		}
		case 4:
		{
			// 按位置插入图书
			int i;
			Book x;
			cout << "请输入插入的位置：";
			cin >> i;
			cout << "ISBN:";
			cin >> x.isbn;
			//判断ISBN号是否已经存在
			if (ISBNis(L, x.isbn) == OK)
			{
				cout << "该ISBN号已存在，插入失败！" << endl;
				break;
			}
			cout << "书名：";
			cin >> x.name;
			cout << "作者：";
			cin >> x.writer;
			cout << "价格：";
			cin >> x.price;
			cout << "出版社：";
			cin >> x.PHouse;
			InsertList(L, i, x);
			break;
		}
		case 5:
		{
			// 有序表插入（按价格升序）
			Book x;
			cout << "ISBN:";
			cin >> x.isbn;
			//判断ISBN号是否已经存在
			if (ISBNis(L, x.isbn) == OK)
			{
				cout << "该ISBN号已存在，插入失败！" << endl;
				break;
			}
			cout << "书名：";
			cin >> x.name;
			cout << "作者：";
			cin >> x.writer;
			cout << "价格：";
			cin >> x.price;
			cout << "出版社：";
			cin >> x.PHouse;
			InsertOrderList(L, x);
			break;
		}
		case 6:
		{
			cout << "********************************************************************************************" << endl;
			cout << "*****************                       删除程序                      **********************" << endl;
			cout << "*****************        1-按照ISBN号删除      2-按照书名删除         **********************" << endl;
			cout << "*****************        3-按照作者删除        0-退出                 **********************" << endl;
			cout << "********************************************************************************************" << endl;
			cout << "请选择删除方式：" << endl;
			int tem;
			cin >> tem;

			switch (tem)
			{
			case 1:
			{
				// 按ISBN删除
				char isbn[20];
				cout << "请输入要删除的书籍的ISBN号：";
				cin >> isbn;
				DeleteListISBN(L, isbn);
				break;
			}
			case 2:
			{
				// 按书名删除
				char name[20];
				cout << "请输入要删除的书籍的书名：";
				cin >> name;
				DeleteListNAME(L, name);
				break;
			}
			case 3:
			{
				//按照作者删除
				char writer[20];
				cout << "请输入要删除的书籍的作者：";
				cin >> writer;
				DeleteListWriter(L,writer);
			}
			case 0:
			{
				// 退出
				cout << "删除程序使用结束！" << endl;
				break;
			}
			default:
				cout << "输入错误，默认退出删除程序！" << endl;
			}
			break;
			
		}
		case 7:
		{
			// 按ISBN修改图书信息
			char isbn[20];
			cout << "请输入要修改的ISBN：";
			cin >> isbn;
			if (UpdatePrice(L, isbn) == OK)
				cout << "修改成功" << endl;
			else
				cout << "修改失败" << endl;
			break;
		}
		case 8:
		{
			// 按照价格从低到高排序
			SortBooks(L);
			break;
		}
		case 9:
		{
			cout << "*********************************************************************" << endl;
			cout << "******************************统计程序*******************************" << endl;
			cout << "          1-统计书籍数量     2-按出版社统计     0-退出    " << endl;
			cout << "*********************************************************************" << endl;
			cout << "请选择查找方式：" << endl;
			int tem;
			cin >> tem;
			switch (tem)
			{
			case 1:
			{
				// 返回图书数量
				cout << "当前图书总数：" << CountBooks(L) << " 本" << endl;
				break;
			}
			case 2:
			{
				//按出版社统计
				CountBooksByPHouse(L);
				break;
			}
			case 0:
			{
				// 退出
				cout << "统计程序使用结束！" << endl;
				break;
			}
			default:
				cout << "输入错误，默认退出统计程序！" << endl;
			}
			break;
		}
		    
		default:
			cout << "输入错误，请重新选择！" << endl;
		}
		system("pause");
		system("cls");
	} while (option);

	//销毁线性表
	DestroyList(L);
	return 0;
}
