#include<stdio.h>

int main(int argc,char *agrv[]){

	int arr[5] = {0};
	int array[4][5] = {0};

	/*
	printf("Sizeof int:%d\n",sizeof(int));
	//抽象:array是指向4行5列这整个二维数组的,同理array+1是指向第二行整行的
	printf("Address:array => %p and array[0][0] => %p and array+1 => %p\n",array,&array[0][0],array+1);
	*/


	//*(array+1) 表示是啥?
	//*(array+i) == array[i]  而array[i]就是指向第i行第一个元素地址(把array[i]看作是一个数组名,数组名就是数组首元素的地址)
	
	int i,j,k=0;
	for(i = 0; i < 4; i++){
		for(j=0;j<5;j++){
			array[i][j] = k++;
		}
	}
	k=0;
	for(i=0;i<5;i++){
		k+=9;
		arr[i] = k;
	}

	/*
	//zarray+i == *(array+i)==array[i]  还是个地址变量
	printf("Address:array+1 => %p and *(array+1) => %p and &array[1][0] => %p\n",array+1,*(array+1),&array[1][0]);
	printf("Address:array+2 => %p and *(array+2) => %p\n",array+2,*(array+2));
	// 一维数组 arr+i 是地址变量,*(arr+i)是取值操作
	printf("Address:arr+1 => %p and *(arr+1) => %p and Value:*(arr+1) => %d\n",arr+1,*(arr+1),*(arr+1));

	printf("Value:&array[1][0] => %d  and **(array+1) => %d\n",array[1][0],**(array+1));
	*/


	//*(array+i)+j == &array[i][j]

	return 0;
}
