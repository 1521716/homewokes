#include "functions.h"

void initData(SqList& students) 
{
    ifstream ifs;
    ifs.open("Students_data.txt", ios::in);

    if (!ifs.is_open())
    {
        cout << "文件打开失败！" << endl;
        exit(1);
    }

    int count;
    ifs >> count;
    students.count = count;

    for (int i = 0; i < students.count; i++)
    {
        ifs >> students.elem[i].id >> students.elem[i].name >> students.elem[i].dataStructure >> students.elem[i].programming;
    }

    ifs.close();

}

void displayStudents(SqList& students) 
{
    cout<<"学号\t姓名\t数据结构\t程序设计"<<endl;
    cout<<"----------------------------------------"<<endl;
    for (int i = 0; i < students.count; i++) {
        cout<<students.elem[i].id<<"\t"<<students.elem[i].name<<"\t"
		<<students.elem[i].dataStructure<<"\t\t"<<students.elem[i].programming<<endl;
    }
}

void sequentialSearchByName(SqList& students,char name[],int (&index)[MAXSIZE]) 
{
	int j = 0;
	for(int i = 0;i<students.count;i++)
	{
		if(strcmp(students.elem[i].name,name) == 0)
			index[j++] = i;
	}
}

int binarySearchById(SqList& students, int id) 
{
	int left = 0;
	int right = students.count-1;
	while(left<=right)
	{
		int mid = (left + right)/2;
		if(mid+1 == id)	return mid;
		else if(mid+1<id) left = mid+1;
		else right = mid-1;
	}
    return -1;
}

void insertSortByName(SqList& students) 
{
	for(int i = 1;i<students.count;i++)
	{
		int right = i-1;
		Student temp = students.elem[i];
		while(right>=0)
		{
			if(strcmp(students.elem[right].name,temp.name)>0)
			{
				students.elem[right+1] = students.elem[right];
				right--;
			}
			else
				break;
		}
		students.elem[++right] = temp;
	}
}

void selectSortByDataStructure(SqList& students) 
{
	for(int i = 0;i<students.count-1;i++)
	{
		int MAX = students.elem[i].dataStructure;
		int MAXPos = i;
		for(int j = i+1;j<students.count;j++)
		{
			if(students.elem[j].dataStructure>MAX)
			{
				MAX = students.elem[j].dataStructure;
				MAXPos = j;
			}
		}
		if(MAXPos!=i)
		{
			Student temp = students.elem[i];
			students.elem[i] = students.elem[MAXPos];
			students.elem[MAXPos] = temp;
		}
	}
}

void bubbleSortByProgramming(SqList& students)
{
	for(int i = 0;i<students.count-1;i++)
	{
		int tap = 0;
		for(int j = 0;j<students.count-i-1;j++)
		{
			if(students.elem[j].programming<students.elem[j+1].programming)
			{
				Student temp = students.elem[j];
				students.elem[j] = students.elem[j+1];
				students.elem[j+1] = temp;
				tap = 1;
			}
		}
		if(tap == 0)
			break;
	} 
}

void menu()
{
    SqList students;
	students.elem = new Student[MAXSIZE];
	students.count = 0;
    int choice;

    while (true) {
        cout<<"***********************************学生成绩管理系统**************************************"<<endl;
        cout<<"	1.信息初始化\t2.顺序查找\t3.二分查找\t4.直接插入排序"<<endl;
        cout<<"	5.直接选择排序\t6.冒泡排序\t7.显示全部信息\t0.退出"<<endl;
        cout<<"*****************************************************************************************"<<endl;
        cout<<"请选择操作数：";
        cin>>choice;

        switch (choice) {
            case 1:
                initData(students);
                cout<<"信息初始化成功！"<<endl;
                break;
            case 2: {
                char name[20];
                cout<<"请输入要查找的学生姓名：";
                cin>>name;
                int index[MAXSIZE];
                for(int i = 0;i<MAXSIZE;i++)
                	index[i] = -1;
                sequentialSearchByName(students,name,index);
                if (index[0] != -1) {
                    cout<<"查找成功！"<<endl;
                    cout<<"学号\t姓名\t数据结构\t程序设计"<<endl;
                    int i = 0;
                    while(index[i]!=-1)
                    {
                        cout<<students.elem[i].id<<"\t"<<students.elem[i].name<<"\t"
						<<students.elem[i].dataStructure<<"\t"<<students.elem[i].programming<<endl;
                        i++;
                    }
                           
                } else {
                    cout<<"查找失败！未找到姓名为"<<name<<"的学生。"<<endl;
                }
                break;
            }
            case 3: {
                int id;
                cout<<"请输入要查找的学生学号：";
                cin>>id;
                int index = binarySearchById(students, id);
                if (index != -1) 
                {
                    cout << "查找成功！" << endl;
                    cout << "学号：" << students.elem[index].id << "\t姓名：" << students.elem[index].name << "\t数据结构："
                        << students.elem[index].dataStructure << "\t程序设计：" << students.elem[index].programming << endl;
                } 
                else 
                {
                    cout << "查找失败！未找到学号为" << id << "的学生。" << endl;
                }
                break;
            }
            case 4: {
                cout<<"排序前的学生信息："<<endl;
                displayStudents(students);
                insertSortByName(students);
                cout<<"排序后的学生信息（按姓名）："<<endl;
                displayStudents(students);
                break;
            }
            case 5: {
                cout << "排序前的学生信息：" << endl;
                displayStudents(students);
                selectSortByDataStructure(students);
                cout << "排序后的学生信息（按数据结构成绩）：" << endl;
                displayStudents(students);
                break;
            }
            case 6: {
                cout << "排序前的学生信息：" << endl;
                displayStudents(students);
                bubbleSortByProgramming(students);
                cout << "排序后的学生信息（按程序设计成绩）：" << endl;
                displayStudents(students);
                break;
            }
            case 7:{
            	displayStudents(students);
            	break;
            } 
            case 0:
                cout << "程序使用结束！" << endl;
                return;
            default:
                cout << "操作数不合法，请重新输入！" << endl;
        }
        system("pause");
        system("cls");
    }
}
