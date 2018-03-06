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
*/

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
