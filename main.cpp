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
*/

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
