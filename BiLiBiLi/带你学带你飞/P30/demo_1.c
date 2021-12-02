#include<stdio.h>

int add(int,int);
int sub(int,int);
int calc(int (*)(int,int),int,int);

int add(int num1,int num2){
	return num1+num2;
}
int sub(int num1,int num2){
	return num1-num2;
}

int calc(int (*fp)(int num1,int num2),int num1,int num2)
{
	return (*fp)(num1,num2);
}

int main(int argc,char *argv[]){

	int a,b;
	scanf("%d%d",&a,&b);

	printf("calc result is: ret => %d a => %d b => %d\n",calc(add,a,b));

	return 0;
}
