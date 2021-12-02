#include<stdio.h>

enum Day
{
	SUN,
	MON,
	THU,
	THR,
	TUE,
	FRI,
	SAT
}day1;

int main( int argc,char *argv[]){

	enum Day day2;
	printf("day2 => %d\n",day2);//0
	
	//枚举变量可这样用 且支持++ 自加运算
	for(day2 = SUN;day2 < SAT;day2++){
		printf("days of is %d\n",day2);
	}

	printf("after for day2 of is %d\n",day2);

	day2=123;
	
	printf("after:day2=123 => %d\n",day2);

	day2 = SUN;
	printf("after:day2=SUN => %d\n",day2);

	return 0;
}
