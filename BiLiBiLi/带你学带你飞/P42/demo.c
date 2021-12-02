#include<stdio.h>

struct Ab
{
	char a;
	int b;
	char c;
}ab = {'q',520,'w'};

struct Ac
{
	char a;
	char c;
	int b;
}ac={'q',520,'w'};

int main( int argc,char *argv[]){

	//ab为结构体变量

	//结构体 对齐和填充
	printf("size of ab is :%d\n",sizeof(ab));
	printf("size of ac is :%d\n",sizeof(ac));

	int a,b;
	a = 123;
	b = a;
	printf("Address:a => %p  b => %p\n",&a,&b);

	return 0;
}
