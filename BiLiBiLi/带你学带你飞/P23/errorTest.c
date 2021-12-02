#include<stdio.h>

int main(int argc,char *agrv[]){

	int i = 0;
	int (*p_array)[3] = {123,234,345};

	for(i=0;i<3;i++){
		
		printf("%d\n",*(p_array+i));//能打印但是结果不是我们想要

	}

}
