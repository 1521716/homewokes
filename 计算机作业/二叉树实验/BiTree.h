#include<iostream>
#include<stdlib.h>
#include<stack>
using namespace std;

//树节点
typedef struct TreeNode {
	char val;
	TreeNode* lchild;
	TreeNode* rchild;
} TNode, * BTree;

//创建二叉树 
TNode* createTree(BTree T);
//递归遍历 
//先序遍历 
void showDLR(const BTree T);
//中序遍历
void showLDR(const BTree T);
//后序遍历
void showLRD(const BTree T);
//左右交换二叉树
TNode* transfer(BTree T);
//非递归遍历
//先序遍历
void noShowDLR(const BTree T);
//中序遍历
void noShowLDR(const BTree T);
//统计二叉树结点个数
int totalTreeNode(const BTree T);
//统计二叉树叶子节点个数
int totalLastTreeNode(const BTree T);
//菜单函数
void menu();


