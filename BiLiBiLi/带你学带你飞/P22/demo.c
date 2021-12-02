#include<stdio.h>

int main(int argc,char *argv[]){

	int a[3] = {123,290,380};
	float b[3] = {1.1,2.2,3.3};
	double c[3] = {1.1,2.2,3.3};
	char d[] = "OKK";
	
	//:12s/a/b/g 12行用b替换a,g表示全局
	//
	//数组第一个元素地址==数组的首地址,数组名本质就是数组第一个元素的地址
/*	printf("Address:a => %p  a[0] => %p  a[1] => %p\n",a,&a[0],&a[1]);//4 字节
	printf("Address:b => %p  b[0] => %p  b[1] => %p\n",b,&b[0],&b[1]);//4 字节
	printf("Address:c => %p  c[0] => %p  c[1] => %p\n",c,&c[0],&c[1]);//8 字节
	printf("Address:d => %p  d[0] => %p  d[1] => %p\n",d,&d[0],&d[1]);//1 字节

	printf("int 'd' test:a+1 => %d and &a+1 => %d and a+4 => %d and *(a+1) => %d\n",(a+1),&a+1,(a+4),*(a+1));

	printf("int 'p' test:a+1 => %p and &a+1 => %p and (a+1) => %p\n",(a+1),&a+1,(a+4));

*/
	//数组名不是左值,是常量,不可赋值
	//a++;

	//printf("Value:a++ => %d\n",a);
	
	//int i = 0;
	//printf("printf i++ => %d\n",i++);
	//
	//
	//指针和指针变量:https://blog.csdn.net/qq_43775170/article/details/89400390
	//指向数组的指针变量 可加减运算:意义相当于指向距离指针所在位置向前活向后第n个元素
	
	int *p = a;//定义一个指针变量,并把数组第一个元素的地址赋值 eg:int num =3;int *p;p = &num
	//p是一个指针变量,*p是一个值
	printf("Value:*p => %d and *a => %d     *(p+1) => %d and *(a+1) => %d\n",*p,*a,*(p+1),*(a+1));//*(a+1) 指针法运用在数组名上
	printf("Address:p => %p and a => %p\n",p,a);//p打印指针变量这个变量的地址,也说明数组名也是个存放地址的变量,区别之一:
	//数组名不是左值,是地址常量,不可赋值
	
	printf("Address:*p => %p and a => %p\n",*p,*a);

	return 0;
}
