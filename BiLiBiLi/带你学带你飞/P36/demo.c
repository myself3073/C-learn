#include<stdio.h>

void quick_sort(int arr[],int,int);

void quick_sort(int arr[],int l,int r){
	int tmp,pivot,i,j;
	//上一个数组,分两个数,开始排序
	pivot = arr[(l + r )/2];
	i = l;
	j = r ;
	while(i <= j){
		//从左往右找,找出所有大于基准数的元素
		while(arr[i] < pivot){
			i++;
		}
		//从右往左找,找出所有小于基准数的元素
		while(arr[j] > pivot){
			j--;
		}
		if(i <= j){
			//找出后,互换
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			//各自往前推
			i++;
			j--;
		}
	}
	//一趟下来:比基准小的元素都在左边,比基准大的元素都在右边.剩下的就交给递归了
	for (int k = 0; k < 10; k++)
	{
		printf("%d ",arr[k]);
	}
	putchar('\n');
	if(i < r){
		quick_sort(arr,i,r);
	}
	if(j > l){
		quick_sort(arr,l,j);
	}
	
}

int main( int argc,char *argv[]){

	int arr[] = {21,56,30,40,60,44,10,20,50,80,80};
	int length = sizeof(arr)/sizeof(arr[0]);
	quick_sort(arr,0,length - 1);
	printf("快速排序结束:\n");
	for(int i = 0;i < length;i++){
		printf("%d ",arr[i]);
	}
	putchar('\n');
	return 0;
}
