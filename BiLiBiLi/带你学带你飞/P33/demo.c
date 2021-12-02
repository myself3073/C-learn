#include<stdio.h>

extern int count;

void func(void);

void func(void){
	static int st_i = 0;//static关键字使得局部变量st_i变为静态局部变量
		st_i ++;
		printf("st_i is %d\n",st_i);
	return;
}

int main( int argc,char *argv[]){

	for( int i = 0;i < 10; i++){
		func();
	}
	printf("count is %d\n",count);
	return 0;
}

count = 520;
