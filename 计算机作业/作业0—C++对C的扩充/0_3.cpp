#include<iostream>
using namespace std;

//函数声明
//输入
void Input(double* score, int n);
//计算平均成绩
double calculate(double* score, int n);
//输出成绩
void Show(double* score, int n);
int main()
{
	int n = 0;
	cout << "请输入学生个数：";
	cin >> n;
	double *score = new double[n];
	Input(score, n);
	Show(score, n);

	delete[]score;
	return 0;
}

//函数声明
//输入
void Input(double* score, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "请输入第" << i + 1 << "个同学的成绩：";
		cin >> score[i];
	}
}
//计算平均成绩
double calculate(double* score, int n)
{
	double sum = .0, ave;
	for (int i = 0; i < n; i++)
	{
		sum += score[i];
	}
	ave = sum / n;
	return ave;
}
//输出成绩
void Show(double* score, int n)
{
	cout << "成绩依次为：" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << score[i] << endl;
	}
	cout << n << "个平均成绩为：" << calculate(score, n);
}