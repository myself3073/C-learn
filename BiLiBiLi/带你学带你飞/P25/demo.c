#include<stdio.h>

int main( int argc,char *argv[]){
	
	int num = 110;
	int *pi = &num;
	char *ps = "abcd";
	void *pv;

	/*
	//注意int char 指针变量区别之一 两者互换会报错
	printf("Value:int: *pi => %d\n",*pi);
	printf("Value:char: ps =>%s\n",ps);
	*/

	pv = pi;
	printf("Address:pv => %p and pi => %p\n",pv,pi);
	//取值操作 结果编译失败
	printf("Value:*pv => %d and *pi => %d\n",pv,*pi);

	printf("Value:*pv => %d and *pi => %d\n",*(int *)pv,*pi);



	pv = ps;
	printf("Address:pv => %p and pi => %p\n",pv,ps);
	//取值操作 成功
	printf("Value:*pv => %s\n",pv);
	printf("Value:*pv => %s\n",(char *)pv);

	return 0;
}
