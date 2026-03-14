#pragma once
#include<iostream>
using namespace std;
#include<fstream>
#include<stdlib.h>
#include<iomanip>//用于控制输出格式
#include"SqList.h"

//按任意键清屏函数
void Clear();

//初始化线性表+读取文件数据
Status InitList(BSqList* BL);

//菜单
void menu();

//查找（ISBN或书名）

//插入（按位置）

//删除（按ISBN或者书名）

//修改价格（按ISBN）

//排序（价格由低到高，也可以额外实现从高到低，逻辑一致）

//计数

//销毁顺序表
Status DeleteList(BSqList* BL);