#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void){
	
	//int a, b[3] = {1,22,33};
	//printf("Address:a => %p  b => %p and %d\n ",&a,b,b);
	
	int *p1 = NULL;

	p1 = (int *)malloc(sizeof(int) * 5);

	printf("malloc分配的动态内存首地址p1:%p\n",p1);

	printf("指针这个东西的地址&p1:%p\n",&p1);

	p1 = (int *)realloc(p1,10);

	printf("realloc分配的动态内存首地址p1:%p\n",p1);

	printf("指针这个东西的地址&p1:%p\n",&p1);

	char str[] = "ahuga";
	printf("%c\n",*(str+2));//*str <==> str[0]

	return 0;
}
