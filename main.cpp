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

//answer version



//Chapter 2 趣味数学问题
//2.1 个人所得税问题
//描述：编写一个计算个人所得税的程序，要求输入收入金额后，能够输出应缴的个人所得税，其征收办法为：
//起征点为 3500 元
//不超过 1500 元的部分， 征收 3%
//超过 1500 ~ 4500 元的部分，征收 10%
//超过 4500 ~ 9000 元的部分，征收 20%
//超过 9000 ~ 35000 元的部分，征收 25%
//超过 35000 ~ 55000 元的部分，征收 30%
//超过 55000 ~ 80000 元的部分，征收 35%
//超过 80000 元以上的，征收 45%
// 苛政猛于虎哉
// 一开始居然把税的计算方法搞错了
// 君子爱财 取之有道
#include <stdio.h>
#define LEVEL0 3500
#define Level0 0
#define RATE0 0.03

#define LEVEL1 1500
#define Level1 1
#define RATE1  0.1

#define LEVEL2 4500
#define Level2 2
#define RATE2  0.2

#define LEVEL3 9000
#define Level3 3
#define RATE3  0.25

#define LEVEL4 35000
#define Level4 4
#define RATE4  0.3

#define LEVEL5 55000
#define Level5 5
#define RATE5  0.35

#define LEVEL6 80000
#define Level6 6
#define RATE6  0.45

#define sumlevel1  (LEVEL1 * RATE0)
#define sumlevel2  (sumlevel1 + (LEVEL2 - LEVEL1) * RATE1)
#define sumlevel3  (sumlevel2 + (LEVEL3 - LEVEL2) * RATE2)
#define sumlevel4  (sumlevel3 + (LEVEL4 - LEVEL3) * RATE3)
#define sumlevel5  (sumlevel4 + (LEVEL5 - LEVEL4) * RATE4)
#define sumlevel6  (sumlevel5 + (LEVEL6 - LEVEL5) * RATE5)

int whichlevel(float income)
{
	if(income < 0)
		return -1;
	else if(income < LEVEL0)
		return Level0;
	else if(income < LEVEL2)
		return Level1;
	else if(income < LEVEL3)
		return Level2;
	else if(income < LEVEL4)
		return Level3;
	else if(income < LEVEL5)
		return Level4;
	else if(income < LEVEL6)
		return Level5;
	else
		return Level6;
}

int main()
{
	float income = 0;
	float tax = 0;

	while(1)
	{
		printf("Please input your income:");
		scanf("%f", &income);

		if(income > LEVEL0)
		{
			income -= 3500;
			switch (whichlevel(income))
			{
				case Level1: tax = sumlevel1 + (income - LEVEL1) * RATE1;
					break;
				case Level2: tax = sumlevel2 + (income - LEVEL2 - LEVEL1) * RATE2;
					break;
				case Level3: tax = sumlevel3 + (income - LEVEL3 - LEVEL2 - LEVEL1) * RATE3;
					break;
				case Level4: tax = sumlevel4 + (income - LEVEL4 - LEVEL3 - LEVEL2 - LEVEL1) * RATE4;
					break;
				case Level5: tax = sumlevel5 + (income - LEVEL5 - LEVEL4 - LEVEL3 - LEVEL2 - LEVEL1) * RATE5;
					break;
				case Level6: tax = sumlevel6 + (income - LEVEL6 - LEVEL5 - LEVEL4 - LEVEL3 - LEVEL2 - LEVEL1) * RATE6;
					break;
			}
		}

		printf("You should pay %f tax according to your income.\n", tax);
	}
	return 0;
}


//2.2 存钱问题
//描述：假设银行整存整取存款不同期限的月息利率为：
//0.63% 1年
//0.66% 2年
//0.69% 3年
//0.75% 5年
//0.84% 8年
//现已知某人手上有 2000 元，要求通过计算选择出一种存钱方案，使得存入 20 年后利息最多，假定银行对超出存款期限的那部分时间不付利息
//没思路哦
//是不是凑个整数年份就可以了
//请看答案
#include <stdio.h>
#include <math.h>
int main()
{
	int x1, x2, x3, x5, x8;
	int y1, y2, y3, y5, y8;
	double max = 0.0;
	double result;
	for(x8 = 0; x8 < 2; x8++)
		for(x5 = 0; x5 <= (20 - 8*x8)/5; x5++)
			for(x3 = 0; x3 <= (20 - 8*x8 - 5*x5)/3; x3++)
				for(x2 = 0; x2 <= (20 - 8*x8 - 5*x5 - 3*x3)/2; x2++)
				{
					x1 = 20 - 8*x8 - 5*x5 - 3*x3 - 2*x2; //存款期限限定条件

					//判断条件
					result = 2000.0 * pow((1+0.0063*12), x1)
									* pow((1+2*0.0066*12), x2)
									* pow((1+3*0.0069*12), x3)
									* pow((1+5*0.0075*12), x5)
									* pow((1+8*0.0084*12), x8);

					// y* 用于记录获利最多的存放方式
					if(result > max)
					{
						max = result;
						y1 = x1;
						y2 = x2;
						y3 = x3;
						y5 = x5;
						y8 = x8;
					}
				}

				printf("从 1 -》 8：%d, %d, %d, %d, %d\n本息合计共 %f 元", y1, y2, y3, y5, y8, result);
	return 0;
}


//2.3 分糖果
//描述：10个小孩围成一圈分糖果，老师分别分给 1 - 10号小孩  各 10, 2, 8, 22, 16, 4, 10, 6, 14, 20.
//然后所有的小孩同时将手中的糖分一半给右边的小孩，糖块数为奇数的人可向老师要一块
//问经过几次后大家手中的糖果一样多吗 各有多少块？
//还不知道会不会一样多
//largerthanlife
//17/03/2018
#include<stdio.h>
#define N 10

bool AllEqual(int a[], int n)
{
	for(int i = 1; i < n; i++)
	{
		if(a[i] != a[0])
			return false;
	}
	return true;
}
int main()
{
	int children[N] = {10, 2, 8, 22, 16, 4, 10, 6, 14, 20};
	int temp[N] = {0};
	int right;
	while( !AllEqual(children, N))
	{
		for(int i = 0; i < N; i++)
		{
			if(i == N-1)
				right = 0;
			else
				right = i + 1;
				
			children[i] /= 2;
			temp[right] = children[i];
		}
		for(int i =0; i < N; i++)
		{
			children[i] += temp[i];
			if(children[i] % 2 == 1)
				children[i] += 1;
		}
	}	
	for(int i = 0; i < N; i++)
		printf("%d ", children[i]);
	printf("\n");
	return 0;
}


//2.4 三色球问题
//描述：一个口袋中放有12个球，已知其中三个是红的，三个是白的，六个是黑的，现从中任意取八个
//问有多少种可能的搭配？
//largerthanlife
//18/03/2018
#include<stdio.h>
#define REDNUM 3
#define WHITENUM 3
#define BLACKNUM 6
int main()
{
	for(int red = 0; red <= REDNUM ; red++)
		for(int white = 0; white <= WHITENUM ; white++)
			for(int black = 0; black <= BLACKNUM ; black++)
			{
				if(red + white + black == 8)
					printf("%d %d %d\n", red, white, black);
			}
	return 0;
}


//2.5出售金鱼
//描述：小明将养的一缸金鱼分 5 次出售
//  第一次卖出全部的一半加1/2条
//  第二次卖出余下的三分之一加1/3条
//  第三次卖出余下的四分之一加1/4条
//  第四次卖出余下的五分之一加1/5条
//  最后卖出剩余的11条
//  原来有多少条
//largerthanlife
//21/03/2018
#include<iostream>
#define N 5
#define LEFT 11
int main()
{
	int sum = LEFT;
	for(int i = N; i > 1; i--)
		sum = (sum + 1.0/i) * i / (i-1);
	printf("sum = %d\n", sum);

	return 0;
}


//2.6 求车速
//一辆以固定速度行驶的汽车，司机在上午 10 点看到里程表上的读数是一个对称数，为 95859，
//两小时后里程表上出现了一个新的对称数，该数仍为五位数，
//问该车的速度是多少，新的对称数是多少
//95959?????????
//largerthanlife
//22/03/2018
#include<stdio.h>
int main()
{
	int num[5] = {0};
	for(int i = 95859; i < 100000; i++)
	{
		num[4] = (i % 10) / 1;
		num[3] = (i % 100) / 10;
		num[2] = (i % 1000) / 100;
		num[1] = (i % 10000) / 1000;
		num[0] = (i % 100000) / 10000;
		if(num[0] == num[4] && num[3] == num[1])
		{
			printf("new numer:");
			for(int j = 0; j < 5; j++)
				printf("%d",num[j]);
			printf("\n");
			printf("its speed is %f km/h\n", (i - 95859)/ 2.0);
		}
	}
	return 0;
}


//2.7 爱因斯坦的数学题
//描述：爱因斯坦出了一道这样的数学题
// 有一条长阶梯，若每步跨 2 阶，则最后剩一阶，
// 若每步跨 3 阶，则最后剩 2 阶，
// 若每步跨 5 阶，则最后剩 4 阶，
// 若每步跨 6 阶，则最后剩 5 阶。
// 只有每次跨 7 阶， 最后才正好一阶不剩
// 请问在 1~N 内， 有多少个数能满足？
//largerthanlife
//23/03/2018
#include<stdio.h>
#define N 600
int main()
{
	int sum = 0;
	int i = 0;
	for(sum = 1; sum < N; sum+=2) // step = 2,肯定是奇数
		if( (sum % 2 == 1) && (sum % 3 == 2) && (sum % 5 == 4) && (sum % 6 == 5) && (sum % 7 == 0))
		{
			i++;
			printf("%d : %d\n", i, sum);
		}
	printf("between 1 ~ %d, %d number(s) is qualified\n", N, i);
	return 0;
}


// 2.8猜牌术
// 描述：魔术师利用一副牌中的 13 张黑桃，预先将它们排好后迭在一起，并使牌面朝下
// 然后他对观众说 我不看牌，只要数数就可以猜到每张牌是什么，我大声数数，你们听，不信？
// 你们就看，魔术师将最上面的那张牌数为 1 ， 把它翻过来正好是黑桃 A ，他将黑桃 A 放在桌子上
// 然后按顺序从上到下数手中的余牌，第二次数 1 、 2，将第一张牌放在这迭牌的下面，将第二张牌翻过来，正好是黑桃 2 ，
// 也将它放在桌子上， 第三次数 1 2 3 ，将前面两张依次放在这迭牌的下面，再翻第三张正好是黑桃 3，
// 这样依次进行， 将 13 张牌全部翻出来， 准确无误，
// 问魔术师手中的牌原始次序是怎样安排的？
// WTF is this



// 2.9 舍罕王的失算
//描述：国际象棋盘 64x64格，第一格一粒，之后 2 倍增长，依次放完
//共需多少
//largerthanlife
//24/03/2018
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 64
int main()
{
	double sum = 0;
	for(int i = 0; i < N; i++)
		sum += pow(2,i);
	printf("%.0lf\n", sum);
	return 0;
}


//2.10 马克思手稿中的数学题
//描述：马克思手稿中有一道趣味数学题：
//有 30 个人，其中有男人、女人和小孩，他们在同一家饭店吃饭 总共花了50先令
//已知每个男人需要 3 先令，女人 2 ，小孩 1,
//请求出男人女人小孩各有几人
//largerthanlife
//24/03/2018
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int numman, numwoman, numchild;
	for(numman = 1; numman <= 17; numman ++)
		for(numwoman = 1; numwoman <= 25; numwoman++)
			{
				numchild = 30 - numman - numwoman;
				if(numman * 3 + numwoman * 2 + numchild == 50)
					printf("man: %d\nwoman: %d\nchild: %d\n", numman, numwoman, numchild);
			}
	return 0;
}


//2.11换分币
//描述：将 5 元的人民币兑换成1 元、 5 角和 1 角的硬币，共有多少种不同的兑换方法
//题意不清，是否至少各一张？
//anyway it's easy
//largerthanlife
//24/03/2018
 #include <stdio.h>
#include <stdlib.h>
int main()
{
	int num1yuan;
	int num5jiao;
	int num1jiao;
	int count = 0;
	for(num1yuan = 0; num1yuan <= 5; num1yuan ++)
		for(num5jiao = 0; num5jiao <= 10; num5jiao++)
			for(num1jiao = 0; num1jiao <= 50; num1jiao++)
				if(num1yuan * 10 + num5jiao * 5 + num1jiao == 50)
				{
					count++;
					printf("%d:\n1 yuan: %d\n5 jiao: %d\n1 jiao: %d\n", count, num1yuan, num5jiao, num1jiao);

				}
	return 0;
}


//3.1完数
//描述：求某一范围内完数的个数
//如果一个数等于它的因子之和， 则称该数为“完数”
//范围是什么
//largerthanlife
//30/03/2018
#include <stdio.h>
#include <stdlib.h>
int main()
{
	bool find(int);
	int num;
	scanf("%d", &num);
	for(int i = 0; i <= num; i++)
		if(find(i))
			printf("%d is qualified\n", i);
	return 0;
}

bool find(int num)
{
	int sum = 1; // 1 肯定是因数之一
	for(int i = 2; i < num/2 + 1; i++) // i 直接从2开始 效率高啊  上限到 num 的一半就行
		if(num % i == 0)
			sum += i;
	return sum == num;
}


//3.2亲密数
//描述：如果整数 A 的全部因子（包括1，不包括 A 本身），之和等于 B，且 整数 B 的全部因子之和等于 A ，则将 A B 称为亲密数，求 3000 以内的全部亲密数
//会有这种事啊
//largerthanlife
//30/03/2018
//警告：这程序要跑将近一分钟
#include <stdio.h>
#include <stdlib.h>
#define MAX 3000
int main()
{
	bool find(int, int);
	for(int i = 1; i < MAX; i++)
		for(int j = 1; j < MAX; j++)
			if(find(i, j) && find(j, i))
				printf("%d and %d is qualified\n", i, j);
	return 0;
}

bool find(int num, int test)
{
	int sum = 1; // 1 肯定是因数之一
	for(int i = 2; i < num/2 + 1; i++) // i 直接从2开始 效率高啊  上限到 num 的一半就行
		if(num % i == 0)
			sum += i;
	return sum == test;
}


//3.3自守数
//描述：自守数是指一个数的平方的尾数等于该数自身的自然数
//如： 5^2 = 25, 25^2 = 625, 76^2 = 5776, 9376^2 = 87909376
// 求 100000 以内的自守数
//largerthanlife
//30/03/2018
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100000
int main()
{
	bool istail(long, int);
	for(int i = 0; i < MAX; i++)
		if(istail(i*i, i))
			printf("%d is qualified\n", i);
	return 0;
}

int count(long num)
{
	int i;
	for(i = 1; num; i++)
		num /= pow(10, i);
	return i;
}

bool istail(long num, int find)
{
	int bit = count(num);
	for(; bit; bit--, num %= (int)(pow(10,bit)))
		if(num == find)
			return true;
	return false;
}


//answer version
//largerthanlife
//30/03/2018
// 6哦朋友
#include <stdio.h>
#include <stdlib.h>
int main()
{
	long mul, number, k, a, b;
	for(number = 0; number < 100000; number++)
	{
		for(mul=number, k = 1;(mul/=10)>0; k*=10);

		a = k*10;
		mul = 0;
		b = 10;
		while(k > 0)
		{
			mul = (mul+(number%(k*10))*(number%b - number%(b/10))) % a;
			k /= 10;
			b *= 10;
		}
		if(number == mul)
			printf("%ld	", number);
	}
	return 0;
}


//3.4回文数
//打印所有不超过 n（ n<256 ），的其平方具有对称性质的数
//largerthanlife
//30/03/2018
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 256
int main()
{
	bool find(int);
	for(int i = 1; i < MAX; i++)
		if(find(i*i))
			printf("%d is qualified(%d * %d = %d)\n", i, i, i, i*i);
	return 0;
}

bool find(int num)
{
	bool countbit(int);
	bool judge(int*, int length);
	
	int bit = countbit(num);
	//int *s = (int*)malloc(bit);
	int s[6] = {0};
	for(int i = bit - 1; i >= 0; num %= (int)pow(10, i), i--)
	{
		s[i] = num / (int)pow(10, i);
	}
	return judge(s, bit);
}

int countbit(int num)
{
	int i = 1;
	for(; num / 10; i++, num /= 10);
	return i;
}

bool judge(int *s , int length)
{
	for(int i = 0; i < length/2; i++)
		if(s[i] != s[length -1 -i])
		{
			return false;
		}
	return true;
}
*/

//3.５　水仙花数
//描述：输出所有的水仙花数， 即指一个三位数 其各位数字的立方和等于该数本身
//largerthanlife
//30/03/2018
#include <stdio.h>
#include <stdlib.h>
int main()
{
	for(int i = 100; i < 999; i++)
	{
		int num = i;
		int a = num/100;
		num %= 100;
		int b = num/10;
		num %= 10;
		int c = num;
		if(a*a*a + b*b*b + c*c*c == i)
			printf("%d is qualified\n", i);
	}
	return 0;
}
