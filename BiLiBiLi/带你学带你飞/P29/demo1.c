#include<stdio.h>
#include<stdarg.h>
//stdarg.h 可编写参数列表可变的函数
//传值
void swap_val(int x,int y){
	int tmp;
	printf("In swap_val 前:a=%d b=%d\n",x,y);
	tmp = x;
	x = y;
	y =tmp;
	printf("In swap_val 后:a=%d b=%d\n",x,y);

	return;
}
//传址
void swap_addr(int *x,int *y){
	int tmp;
	
	printf("In swap_addr 前:a=%d b=%d\n",*x,*y);
	tmp = *x;
	*x = *y;
	*y = tmp;
	printf("In swap_addr 后:a=%d b=%d\n",*x,*y);
}

int main( int argc,char *argv[]){

	/*
	int a;
	printf("Address: a=> %p\n",&a);
	a=1;
	printf("Address: a=> %p\n",&a);
	*/
	
	int a = 3,b = 4;

	printf("In main 前:a=%d b=%d\n",a,b);
//	swap_val(a,b);
	swap_addr(&a,&b);
	printf("In main 后:a=%d b=%d\n",a,b);

	return 0;
}
