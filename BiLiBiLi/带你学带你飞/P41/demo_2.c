#include<stdio.h>

/*
 *#和##是两个预处理运算符
 *在带参数的宏定义中,#运算符后面应跟一个参数,预处理会把这个参数转换为一个字符串
 *##运算符被称为记号连接运算符,比如我们可以使用##运算符连接两个参数
 *
 * 注意:
 *1.当宏参数是另一个宏的时候,参数里的宏不生效http://www.elecfans.com/d/1404579.html
 * */

/*
#define toSTR(s) (#s)
#define toSTR1(w) (# w)

#define TOGET(a,b) (a##b)
#define TOGET1(x,y)  (x ## y)
*/

//解决注意1:多加一层中间转换宏,把所有宏的参数在这层里全部展开 
#define _toSTR(s) (#s)
#define _toSTR1(w) (# w)

#define _TOGET(a,b) (a##b)
#define _TOGET1(x,y)  (x ## y)

#define toSTR(s) _toSTR(s)
#define toSTR1(w) _toSTR1(w)

#define TOGET(a,b) _TOGET(a,b)
#define TOGET1(x,y)  _TOGET1(x,y)

#define MM 250




int main( int argc,char *argv[]){

	//\t换成空格(无论多少个都不打印),换成逗号,编译就出错.
	//printf(STR(Hello\t));
	//printf(STR1(World\n));

	//printf("%d\n",TOGET(5,20));

	//这是错误的
	//printf("%s\n",TOGET("abc","qwe"));
	//printf("%c\n",TOGET('a','b'));
	
//	printf(toSTR(MM));//输出字符串 MM 而不是250
//	printf("%s\n",TOGET(MM,MM));//语法错误,由错误可知:这里被展开为:printf("%s\n",MMMM);MMMM未被定义

	//解决注意1:多加一层中间转换宏,把所有宏的参数在这层里全部展开 
	printf("%s\n",toSTR(MM));
	printf("%d\n",TOGET(MM,MM));

	return 0;
}
