#include<stdio.h>

int main(int argc,char *argv[]){
	
	int a =123;
	char *p;

	p = &a;

	printf("*p=%d\n",*p);
	printf("sizeof:%d\n",sizeof(p));
	printf("address:%p\n",p);
	return 0;
}
