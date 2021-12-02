#include<stdio.h>
/*
 *    可变参数 
 *    #define SHOWLIST(...) printf(#__VA_ARGS__)
 *    __VA_ARGS__在预处理中被实际的参数集所替换
 * */

#define SHOWLIST(...) printf(#__VA_ARGS__)

#define PRINT(format,...) printf(#format,##__VA_ARGS__)

#define MM 789

int main( int argc,char *argv[]){


	//SHOWLIST(abc,250,MM,\n);

	int num = 123;
	char *p = "abcd";

	PRINT(num = %d str = %s\n,num,p);

	return 0;
}
