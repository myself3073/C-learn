#include<stdio.h>

void a(void);
void b(void);

int g_i;

void a(void){
	g_i++;
	printf("in functio:g_i is %d\n",g_i);
}

void b(void){
	int g_i;
	g_i = 520;
	printf("in b function is %d\n",g_i);
}

int main( int argc,char *argv[]){

	a();
	b();
	printf("in main function is %d\n",g_i);
	return 0;
}
