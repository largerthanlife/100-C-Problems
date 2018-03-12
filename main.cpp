/*
//Chapter 1
//1.1 百钱白鸡问题
//描述：中国古代数学家张丘建在他的《算经》中提出了一个著名的“百钱白鸡问题”：
//	公鸡值五钱，一只母鸡值三钱，三只小鸡值一钱，
//	现在要用百钱买百鸡，请问公鸡、母鸡、小鸡各多少只？
//注意 rooster 和 hen 的最大数
#include <stdio.h>
#define TOTALNUM 100
#define TOTALMONEY 100
#define ROOSTERMONEY 5.0
#define HENMONEY 3.0
#define CHICKMONEY 1/3.0
int main()
{
	int roosterNum, henNum;

	for(roosterNum = 0;roosterNum < TOTALNUM/ROOSTERMONEY; roosterNum++)
		for(henNum = 0;henNum < TOTALNUM/HENMONEY; henNum++)
			if(roosterNum*ROOSTERMONEY + henNum*HENMONEY + (TOTALNUM - roosterNum - henNum)*CHICKMONEY == TOTALMONEY)
				printf("roosterNUM = %d\nhenNum = %d\nchickNum = %d\n\n",roosterNum, henNum, TOTALNUM - roosterNum - henNum);
	return 0;
}


//1.2 借书方案知多少
//描述：小明有 5 本新书，要借给 A、B、C 三位朋友，若每人每次只能借 1 本，则可以有多少种不同的借法？
//不是很清楚题意 5本都要借出去吗 每个人都必须要有一本吗
//参考答案：
#include <stdio.h>
#define NUM 5
int main()
{
	int a, b, c;
	int i = 0;
	for(a = 1; a <= NUM; a++)
		for(b = 1; b <= NUM; b++)
			for(c = 1; c <= NUM && a != b; c++)
				if(a != c && b != c)
				{
					printf("A:%2d B:%2d C:%2d	", a, b, c);
					i++;
					if(i % 4 == 0)
						printf("\n");
				}
	printf("%d methods in total\n", i);
	return 0;
}


//1.3 打鱼还是晒网
//描述：某人从1990年1月1日起开始 “三天打鱼两天晒网” 问这个人在以后的某一天中是打鱼还是晒网
//写过
//未考虑输入格式问题 仅从简处理
#include <stdio.h>
#include <string.h>
#define MAX 10
int main()
{
	int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	char date[MAX];
	while(1)
	{
	int year, month, day;
	year = month = day = 0;
	gets(date);
	int i = 0;
	while(date[i] != '.')
		year = year*10 + date[i++] - '0';
	i++;
	while(date[i] != '.')
		month = month*10 + date[i++] - '0';
	i++;
	while(i < strlen(date))
		day = day*10 + date[i++] - '0';
	//printf("%d %d %d", year, month, day);
	int difYear, difMonth, difDay;
	difYear = year - 1990;
	difMonth = month - 1;
	difDay = day - 1;

	int numleap = (difYear+2) / 4; //闰年的次数 1992是闰年 1992 - 1990 = 2

	int nummonth = 0; //差几个月
	for(i = 0; i < difMonth; i++)
		nummonth += months[i];

	//共差几天
	int sum = difYear * 365 + numleap + nummonth + difDay;

	printf("difYear = %d\n, difMonth = %d\n, disDay = %d\n", difYear, difMonth, difDay);
	printf("numleap = %d\n, nummonth = %d\n, sum = %d\n", numleap, nummonth, sum);
	if(sum % 5  < 3)
		printf("In this day, he is fishing\n");
	else
		printf("In this day, he is dring net\n");
	}
	return 0;
}


//1.4 抓交通肇事犯
//描述：一辆卡车违反交通规则，撞人后逃跑，现场有三人目击该事件，但都没有记住车号，只记下一些特征
//  甲说：牌照的前两位数字是相同的
//  乙说：牌照的后两位是相同的，但与前两位不同
//  丙是数学家，他说：四位的车号刚好是一个整数的平方
//请求出车号
//注意车牌号可以首位为零
//如何确定平方根是整数
// 7744
#include <stdio.h>
#include <math.h>
int main()
{
	for(int a = 0; a < 10; a++)
		for(int b = 0; b < 10; b++)
			if(a != b)
				if(sqrt(a*1000 + a*100 + b*10 + b) - (int)(sqrt(a*1000 + a*100 + b*10 + b)) == 0)
					printf("It is %d\n", a*1000 + a*100 + b*10 + b);
	return 0;
}


//1.5兔子产子问题
//有一对兔子，从出生后的第 3 个月起每个月都生一对兔子， 小兔子长到第 3 个月后每个月又生一对兔子
//假设所有的兔子都不死，问 30 个月内每个月的兔子总数是多少？
//递归
//迭代
#include <stdio.h>
int recursion(int month)
{
	int num;
	if(month == 1 || month == 2)
		return 1;
	else
		num =  recursion(month - 1) + recursion(month - 2);
		return num;

}
int main()
{
	for(int i = 1;i <= 30; i++)
	{
		printf("%d:%-10d", i, recursion(i));
		if(i%5 == 0)
			printf("\n");
	}
	return 0;
}


//1.6牛顿迭代法求方程根
//描述：编写用牛顿迭代法求方程根的函数，方程为 ax^3 + bx^2 + cx + d = 0, 系数a, b, c, d由主函数输入， 求 x 在 1 附近的一个实根，由主函数输出
//公式为 x = x0 - f(x0)/f'(x0), 设迭代到 |x - x0| <= 10^(-5)时结束
#include <stdio.h>
#include <math.h>
int main()
{
	float a, b, c, d;
	float x, x0;
	scanf("%f %f %f %f",&a, &b, &c, &d);
	x0 = 20;
	x = x0 - (((a*x0+b)*x0+c)*x0+d) / ((3*a*x0+2*b)*x0+c);
	while(fabs(x - x0) > pow(10.0, -5))
	{
		x0 = x;
		x = x0 - (((a*x0+b)*x0+c)*x0+d) / ((3*a*x0+2*b)*x0+c);
	}
	printf("%f\n", x);
	return 0;
}


//1.7最佳存款方案
//描述：假设银行一年整存零取的月息为 0.63%。 现在某人手中有一笔钱， 他打算在今后的5年中的每年年底取出1000元 ， 到第 5 年时刚好取完
//请算出他存钱时应存入多少。
//本息和还是分开算
#include <stdio.h>
#include <math.h>
#define MONTH 5
#define MINOR 1000
#define RATE (0.63/100)
int main()
{
	float sum = 0;
	for(int i = 0; i < MONTH; i++)
	{
		sum += MINOR;
		sum /= pow((1+RATE), 12) ;
	}
	printf("1. %f\n", sum);
	for(int i = 0; i < MONTH; i++)
	{
		sum += MINOR;
		sum /= (1+ RATE *12) ;
	}
	printf("2. %f\n", sum);

	return 0;
}


//1.8冒泡排序
//对 N 个整数（数据由键盘输入）进行升序排列
//如 N 不固定， 可以用 malloc 分配
//呃我写的这个不是冒泡 是选择
#include <stdio.h>
#define N 15
int main()
{
	int array[] = {8, 7, 9, 5, 3, 10, 11, 20, 6, 11, 15, 21, 18, 22, 23};
	for(int i = 0; i < N; i++)
		for(int j = i; j < N; j++)
			if(array[i] > array[j])
			{
				int temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
	for(int i = 0; i < N; i++)
		printf("%d ", array[i]);
	printf("\n");
	return 0;
}
// answer
#include <stdio.h>
#define N 15
int main()
{
	int array[] = {8, 7, 9, 5, 3, 10, 11, 24, 6, 11, 15, 21, 18, 22, 23};
	for(int i = 1; i <= N - 1; i++)
		for(int j = 0; j < N - i; j++)
			if(array[j] > array[j+1])
			{
				int temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
	for(int i = 0; i < N; i++)
		printf("%d ", array[i]);
	printf("\n");
	return 0;
}


//1.9折半查找
// N 个有序整数数列已放在一维数组中，利用二分查找法查找整数 m 在数组中的位置。若找到，则输出其下标值，反之输出 “Not be found!”
#include <stdio.h>
#define N 9
int main()
{
	int array[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int left, right, mid;

	int unkown;
	printf("input:");
	scanf("%d", &unkown);

	while(unkown != 100) //for test
	{
	left = 0;
	right = N - 1;
	mid = (left + right) / 2 + 1;
	while(left != mid)
	{
		if(unkown > array[mid])
		{
			left = mid;
			mid = (left + right) / 2 + 1; //这里不加一的话 取不到最后一个数

		}
		else if(unkown < array[mid])
		{
			right = mid;
			mid = (left + right) / 2;
		}
		else
			break;
	}
	if(unkown == array[mid])
		printf("%d\n", mid);
	else
		printf("Not be found!\n");

	printf("input:");
	scanf("%d", &unkown);
	}
	return 0;
	
}

//answer
#include <stdio.h>
#define N 9
int main()
{
	int array[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int left, right, mid;

	int unkown;
	printf("input:");
	scanf("%d", &unkown);

	while(unkown != 100) //for test
	{
		left = 0;
		right = N - 1;
		mid = (left + right) / 2;
		while(left <= right)
		{
			mid = (left + right) / 2;
			if(unkown > array[mid])
				left = mid + 1;
			else if(unkown < array[mid])
				right = mid - 1;
			else
				break;
		}
		if(unkown == array[mid])
			printf("%d\n", mid);
		else
			printf("Not be found!\n");

		printf("input:");
		scanf("%d", &unkown);
	}
	return 0;

}
*/

//1.10 数制转换
//描述：给定一个 M 进制的数 x，实现对 x 向任意的一个非 M 进制的数的转换。
//M -> 10， 10 -> N
//处理比 10 大的进制又要判断字母 , 而且要用字符串来接收 以前在Mycalculator写过 不赘述
#include <stdio.h>
#include <math.h>

int main()
{
	int M, N, x;
	int Msum = 0; // M 进制的x 应表示为多大的 10进制数
	int Nsum = 0; // 10 进制的 Msum 表示为多大的 N 进制数
	int remainder = 0;
	int i = 0;
	printf("Input M:");
	scanf("%d", &M);
	printf("Input x:");
	scanf("%d", &x);
	printf("Input N:");
	scanf("%d", &N);

	do
	{
		remainder = x % 10;
		Msum += remainder * pow(M, i);
		i++;
		x /= 10;
	}while(x > 0);
	//printf("%d\n", Msum);

	i = 0;
	while(Msum > 0)
	{
		remainder = Msum % N;
		Nsum += remainder * pow(10, i);
		i++;
		Msum /= N;
	}
	printf("The answer is %d\n", Nsum);
	return 0;
}
