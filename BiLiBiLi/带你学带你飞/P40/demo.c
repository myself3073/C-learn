#include<stdio.h>

/*
 *无参数宏:#define 标识符 替换列表
 *
 *带参数宏:#define 标识符(参数1,...,参数n) 替换列表
 *
 *删除宏:#undef 标识符
 *
 *http://c.biancheng.net/view/287.html
*/
#define PI 3.141526

#define MAX(x,y) (((x) > (y))? (x):(y))

int main( int argc,char *argv[]){

	printf("%d\n",MAX(2,90));

	return 0;
}
