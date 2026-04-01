#define _CRT_SECURE_NO_WARNINGS
#include<string.h> 
#include<iostream>
#include<stdio.h>
using namespace std;
#include<fstream>
#include<iomanip>

#define OK 1
#define ERROR 0
#define MAXSIZE 100

typedef int Status;
typedef struct
{
	char isbn[20];//ISBN号
	char name[30];//书名
	char writer[20];//作者
	double price;//价格
	char PHouse[20];//出版社
} Book;
typedef struct
{
	Book* elem;//首地址/数组名 
	int length;
}BookList;


//更新文件
void UpdataList(BookList L);
//菜单
void menu();
//初始化 
Status InitList(BookList& L);
//创建 
Status CreateList(BookList& L);
//输出已有的图书
void ShowBook(BookList L);
//按ISBN查找
int LocateISBN(BookList L, const char isbn[]); 
//按书名查找 
int LocateName(BookList L, const char name[]);
//判断ISBN号是否已经存在
Status	ISBNis(BookList L, const char isbn[]);
//按位置插入图书 				
Status InsertList(BookList& L, int i, Book x);
//有序表的插入 (按价格排列)(升序)
Status InsertOrderList(BookList& L, Book x);
//按ISBN删除图书 
Status DeleteListISBN(BookList& L, const char isbn[]);
//按书名删除图书 
Status DeleteListNAME(BookList& L, const char name[]);
//按作者删除图书 
Status DeleteListWriter(BookList& L, const char writer[]);
//按照ISBN号修改图书信息
Status UpdatePrice(BookList& L, char* ISBN);
//按照价格从低到高排序
void SortBooks(BookList& L);
//返回图书数量
int CountBooks(BookList L);
//按照出版社统计图书数量
void CountBooksByPHouse(BookList L);
//销毁线性表
void DestroyList(BookList &L);
