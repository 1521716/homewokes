#pragma once


#define MAXSIZE 100
#define OK 1
#define ERROR 0
typedef int Status;

typedef struct
{
	char ISBN[25];
	char Bname[30];
	double price;
}Book;


typedef struct
{
	Book* books;
	int length;
}BSqList;