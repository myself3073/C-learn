#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int global_var;

int global_var_1 = 520;

int main( int argc,char *argv[]){

	static int static_var;
	static int static_var_1 = 123;
	
	int var = 123;

	char *pst1 = "I like the world...";
	char *pst2 = "This is beef...";

	int *p = NULL;

	p = (int *)malloc(sizeof(int));


	printf("Adress:global_var:%p\n",&global_var);

	printf("Adress:global_var_1:%p\n",&global_var_1);

	
	printf("Adress:static_var:%p\n",&static_var);


	printf("Adress:static_var_1:%p\n",&static_var_1);


	printf("Adress:var:%p\n",&var);


	printf("Adress:pst1:%p\n",pst1);


	printf("Adress:p:%p\n",p);


	return 0;
}
