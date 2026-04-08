#include"SqQueue.h"

int num = 0;

//菜单
void menu()
{
	cout << left;

	SqQueue Q;
	
	while(1)
	{
		cout<<"*****************************************"<<endl;
		cout<<"*****         医院看诊系统          *****"<<endl;
		cout<<"*****      1-上班       2-候诊      *****"<<endl;
		cout<<"*****      3-就诊       4-排队情况  *****"<<endl; 
		cout<<"*****      5-查看看诊   6-统计      *****"<<endl;
		cout<<"*****             0-下班            *****"<<endl;
		cout<<"*****************************************"<<endl;
		
		cout<<"请选择操作数："; 
		int option;
		cin>>option;
		
		switch(option)
		{
			case 1:
				{
					if(InitQueue(Q) == OK)
						cout<<"开始上班"<<endl;
					else
						cout<<"程序故障！"<<endl;
					break;
				}
			case 2:
				{
					Patient p;
					cout<<"请输入候诊人病历号：";
					cin>>p.ID;
					cout<<"请输入候诊人姓名：";
					cin>>p.Name;
					if(PushQueue(Q,p) == OK)
						cout<<"排队成功！"<<endl;
					else
						cout<<"排队人数过多，排队失败！"<<endl;
					break;
				}
			case 3:
				{
					Patient t;
					if(PopQueue(Q,t) == OK)
						cout<<"病历号为："<<t.ID<<endl
						<<"姓名为："<<t.Name
						<<endl<<"正在就诊"<<endl; 
					else
						cout<<"当前无人候诊！"<<endl;
					break;
				}
			case 4:
				{
					char ID[20];
					cout<<"请输入要查询的病历号：";
					cin>>ID;
					ShowFront(Q,ID);
					break;
				}
			case 5:
				{
					int sum = ShowNum(Q);
					cout<<"当前共有"<<sum<<"人候诊"<<endl;
					break;
				}
			case 6:
				{
					Statistic(Q); 
					break;
				}
			case 0:
				{
					Exit(Q);
					cout<<"下班!"<<endl; 
					return;
				}
			default:
				cout<<"操作数不合法，请重新输入！"<<endl;
		}
		
		system("pause");
		system("cls");
	}
	
	
}

//上班
Status InitQueue(SqQueue &Q)
{
	Q.P = new Patient [MAXSIZE];
	if(!Q.P)
		return ERROR;
	Q.head = 0;
	Q.tail = 0;
	
	return OK;
}
//候诊
Status PushQueue(SqQueue &Q,Patient p)
{
	if((Q.tail+1)%MAXSIZE == Q.head)
		return ERROR;
		
	Q.P[Q.tail] = p;
	Q.tail = (Q.tail+1)%MAXSIZE;
	
	
	return OK;
}
//就诊
Status PopQueue(SqQueue &Q,Patient &t)
{
	if(Q.head == Q.tail)
		return ERROR;
	
	t = Q.P[Q.head];
	
	Q.head = (Q.head+1)%MAXSIZE;
	
	num++;

	return OK;
}
//查看排队情况
void ShowFront(SqQueue Q,char *ID)
{
	if(Q.head == Q.tail)
	{
		cout<<"当前暂无人候诊！"<<endl;
		return ;
	}
	
	int curr = Q.head;
	
	while(curr != Q.tail)
	{
		if(strcmp(ID ,Q.P[curr].ID) == 0)
			break;
		curr = (curr+1)%MAXSIZE;
	}
	
	if(curr!=Q.tail)
	{
		curr = Q.head;
		int sum = 0;
		if (strcmp(ID, Q.P[Q.head].ID) == 0)
		{
			cout << "您现在位于第一位！" << endl;
			return;
		}
		cout << setw(10) << "序号" << setw(30) << "病历号" << "姓名" << endl;
		while(curr != Q.tail)
		{
			if(strcmp(ID ,Q.P[curr].ID) == 0)
				break;
			sum++;
			cout << setw(10) << sum << setw(30) << Q.P[curr].ID << Q.P[curr].Name << endl;
			curr = (curr+1)%MAXSIZE;
		}
		cout<<"您前面共有"<<sum<<"人"<<endl;
	}
	else
	{
		cout<<"输入病历号无效，候诊人中查无此人！"<<endl;
		cout<<"已退出查看排队情况程序！"<<endl;
		return ;
	}
}
//查看看诊
int ShowNum(SqQueue Q)
{
	int curr = Q.head;
	int sum = 0;
	
	while(curr != Q.tail)
	{
		sum++;
		curr = (curr+1)%MAXSIZE;
	}
	
	return sum;
}
//统计 
void Statistic(SqQueue Q)
{
	cout<<"今天共有"<<num<<"人看诊！"<<endl;
}
//下班 
Status Exit(SqQueue &Q)
{
	delete []Q.P;
	Q.head = 0;
	Q.tail = 0;
	
	return OK;
}
