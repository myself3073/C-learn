#include<stdio.h>
#include<stdlib.h>

//用途一:类型的别名,而不是简单的宏替换.可以用作同时声明指针类的多个对象
typedef int INT;
typedef int* PINT;

typedef struct Date
{
	int year;
	int month;
	int day;
}DATA;

int main( int argc,char *argv[]){

	/*
	int* pa,pb;//这多数不符合我们的意图，它只声明了一个指向字符变量的指针, 和一个字符变量
	int a = 520;

	pa = &a;

	pb = pa;
	
	printf("Value:*pa=>%d\n",*pa);
	printf("Value:*pb=>%d\n",*pb);
	*/
	
	PINT pa,pb;
	int a = 520;

	pa = &a;

	pb = pa;

	printf("Address:pa=>%p  pb=>%p\n",pa,pb);

	DATA data,*pdata;

	pdata = (DATA *)malloc(sizeof(DATA));

	return 0;
}
