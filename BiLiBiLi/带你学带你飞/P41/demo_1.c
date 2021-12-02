#include<stdio.h>


#define SQUARE(X) ((X)*(X))

int square(int);

int square(int x){
	return x*x;
}

int main( int argc,char *argv[]){

	int i = 1;
	while(i <= 10){
		//分析一下为什么i-1?
		//printf("%d 的平方:%d\n",i,square(i++));

		//printf("%d 的平方:%d\n",i-1,square(i++));

		printf("%d 的平方:%d\n",i-1,SQUARE(i++));//(i++)*(i++)
	}
	return 0;
}
