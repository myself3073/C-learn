#include<stdio.h>

char *getstring(char str){

	//不要返回局部变量的指针
	char ret[] = "不要返回局部变量的指针";

	switch(str){
		case 'A': return "AA";
		case 'B': return "BB";
		case 'C': return "CC";
		case 'D': return ret;
		default: return "None";
	}
}

int add(int,int);
int sub(int,int);
int calc(int (*)(int,int),int,int);
//int (*select(char))(int,int);

typedef int (*PTR_TO_FUN)(int,int);
PTR_TO_FUN select(char);

int add(int num1,int num2){
	return num1+num2;
}

int sub(int num1,int num2){
	return num1-num2;
}

int calc(int (*fp)(int num1,int num2),int num1,int num2){
	return (*fp)(num1,num2);
}

int (*select(char op))(int,int){//后两个int这样写就行
       switch(op){
	case '+': return add;
	case '-': return sub;
	default: return 0;
       }	
}

int main(int argc,char *argv[]){

	/*
	char input;
	scanf("%s",&input);
	
	printf("Return string is %s\n",getstring(input));
	*/


	/*
	//指针函数 => 返回类型 *函数名(参数列表);
	//函数指针 => 返回类型 (*指针变量名)();eg:int (*p_func)(int,int)意思定义一个指针变量p_func,该指针变量指向一个带有两个int类        // 型的参数,且返回值类型是int的函数
	//
	int (*fp)(int,int);//定义一个函数指针(指针变量)

	fp = add;//指针(指针变量)指向机器给add这个函数分配内存的首地址

	printf("add:%d\n",(*fp)(1,9));//指针函数执行
	*/

	/*
	**函数指针作为参数(重要)

	printf("calc result is:%d\n",calc(add,1,99));
	printf("calc result is:%d\n",calc(&add,1,99));//两行对比可知,函数名跟数组名一样,名即首地址
	printf("calc result is:%d\n",calc(sub,100,1));

	*/

	//函数指针作为返回值
	int a,b;
	char op;
	int (*fp)(int,int);
	printf("input fmt:1+2\n");
	scanf("%d%c%d",&a,&op,&b);
	fp = select(op);
//	printf("%d %c %d = %d\n",a,op,b,(*fp)(a,b));
	
	printf("%d %c %d = %d\n",a,op,b,(*((*select)(op)))(a,b));//select是一个函数指针,执行后也返回一个函数指针(带有两个参数)



	/*突发奇想的,不用管	
	int *p = NULL;
	int a = 9;
	p = &a;
	printf("Address:p => %p and &p => %p\n",p,&p);
	*/


	return 0;
}
