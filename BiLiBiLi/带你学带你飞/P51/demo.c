#include<stdio.h>

union Node
{
	int one;
	double two;
	char thr[5];
};

int main( int argc,char *argv[]){

	union Node node;

	node.one = 520;

	node.thr[5] = "abc";

	node.two = 123.123;

	printf("Address:node.one=>%p\n",&node.one);
	printf("Address:node.two=>%p\n",&node.two);
	printf("Address:node.thr=>%p\n",&node.thr);

	//只有最后面附值,才不会被覆盖
	printf("Value:node.one=>%d\n",node.one);
	printf("Value:node.two=>%f\n",node.two);
	printf("Value:node.thr=>%s\n",node.thr);

	return 0;
}
