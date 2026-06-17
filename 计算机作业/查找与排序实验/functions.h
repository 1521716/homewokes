#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fstream>
using namespace std;

#define MAXSIZE 100

typedef struct {
    int id;
    char name[20];
    int dataStructure;
    int programming;
} Student;

typedef struct SqList{
	Student* elem;
	int count = 0;
}SqList;

void initData(SqList& students);
void displayStudents(SqList& students);
void sequentialSearchByName(SqList& students,char name[],int (&index)[MAXSIZE]);
int binarySearchById(SqList& students, int id);
void insertSortByName(SqList& students);
void selectSortByDataStructure(SqList& students);
void bubbleSortByProgramming(SqList& students);
void menu();
