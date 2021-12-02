#include<stdio.h>

/*
 *简化复杂的类型声明
 * */

//int类型的数组指针
typedef int (*PTR_TO_ARRAY)[3];

//返回类型为int,且参数类型为void的指针函数
//typedef int (*PTR_TO_FUN)(void);

//类型三:int *(*array[3])(int) //数组指针,数组每个元素是函数指针的地址,该函数指针返回类型为int,有一个int类型的参数
typedef int *(*PTR_TO_FUN)(int);

//类型四:工作笔记
//https://fishc.com.cn/thread-87591-1-1.html

int g_count = 0;

int *func(void)
{
	printf("520\n");
	return NULL;
}

int *funA(int num)
{
	g_count = num;
	return &g_count;
}

int *funB(int num)
{
	g_count = num;
	return &g_count;
}

int *funC(int num)
{
	g_count = num;
	return &g_count;
}


int main( int argc,char *argv[]){

	/*
	int array[3] = {9,99,999};:q

	PTR_TO_ARRAY ptr_to_array = &array;

	for(int i=0;i<3;i++){
	
		printf("%d\n",(*ptr_to_array)[i]);
	}
	*/

	/*
	int tmp;
	PTR_TO_FUN ptr_to_func = &func;

	tmp = (int *)ptr_to_func();
	*/

	PTR_TO_FUN array[3] = {&funA,&funB,&funC};

	for(int i = 0;i < 3;i++){
		printf("%d函数执行结果:Address:%p  Value:%d\n",i,(*array[i])(i),*((*array[i])(i)));
	}

	return 0;
}
