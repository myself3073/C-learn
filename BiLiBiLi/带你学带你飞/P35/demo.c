#include<stdio.h>

int g_count = 0;
void hanoi(int n,char x,char y,char z);

void hanoi(int n,char x,char y,char z){
	if( 1 == n){
		printf("[%d]盘%d:%c ==> %c\n",__LINE__,n,x,z);
	}else{
		hanoi(n-1,x,z,y);
		printf("[%d]盘%d:%c ==> %c\n",__LINE__,n,x,z);
		hanoi(n-1,y,x,z);
	}
	g_count++;
	return;
}

int main( int argc,char *argv[]){

	int num = 3;
	hanoi(num,'X','Y','Z');
	printf("count = %d\n",g_count);
	return 0;
}
