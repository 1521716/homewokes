#include"Function.h"

int main()
{

	//创建线性表（顺序表或者链表）(此为顺序表)
	BSqList* BL;
	BL = new BSqList;

	//初始化线性表+读取文件数据
	InitList(BL);

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
		case 1:
			//查找（ISBN或书名）
			cout << "查找函数！" << endl;
			Clear();
			break;
		case 2:
			//插入（按位置）
			cout << "插入函数！" << endl;
			Clear();
			break;
		case 3:
			//删除（按ISBN或者书名）
			cout << "删除函数！" << endl;
			Clear();
			break;
		case 4:
			//修改价格（按ISBN）
			cout << "修改价格函数！" << endl;
			Clear();
			break;
		case 5:
			//排序（价格由低到高，也可以额外实现从高到低，逻辑一致）
			cout << "排序函数！" << endl;
			Clear();
			break;
		case 6:
			//计数
			cout << "统计函数！" << endl;
			Clear();
			break;
		case 0:
			//退出
			cout << "程序使用结束，感谢体验！" << endl;
			break;
		default:
			//输入错误，重新输入！
			cout << "操作数输入错误，请重新输入！" << endl;
			Clear();
		}
	} while (option);
	
	//销毁顺序表
	DeleteList(BL);
	return 0;
}