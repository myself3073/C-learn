#include<stdio.h>

int main(int argc,char *argv[]){

	int array[2][3] = {0};
	int i,j,k=0;
	for(i=0;i<2;i++){
	
		for(j=0;j<3;j++){
			k++;
			array[i][j] = k;
		}
	}

	printf("Address:array =>%p\n",array);
	printf("Address:array[0][0] =>%p\n",array);
	printf("Address:*(array+1) =>%p\n",*(array+1));
	printf("Adress:array[1][0] =>%p\n",array[1][0]);

	printf("Value:**(array+1) =>%d\n",**(array+1));
	printf("Value:array[1][0] => %d\n",array[1][0]);
	return 0;
}
