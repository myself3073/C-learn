#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
	int value;
	struct Node *next;
};

void insetNode(struct Node **head,int value);
void printNode(struct Node **head);

void insetNode(struct Node **head,int value)
{
	struct Node *previous,*current,*new;

	current = *head;
	previous = NULL;

	new = (struct Node *)malloc(sizeof(struct Node));
	if(NULL == new){
		printf("分配内存失败...\n");
		exit(1);
	}

	new->value = value;

	if(*head == NULL){
		*head = new;
		new->next = current;
		return;
	}

	//定位到要插入的位置
	while(current != NULL && current->value < value)
	{
		previous = current;
		current = current->next;
	}
	//插入
	previous->next = new;
	new->next = current;

	return;
}

void printNode(struct Node **head)
{
	struct Node *current;
	current = *head;
	while(current != NULL)
	{
		printf("%d ",current->value);
		current = current->next;
	}
		putchar('\n');
	return;
}
int main( int argc,char *argv[]){

	struct Node *head = NULL;
	int input;

	while(1)
	{
		printf("请输入一个要录入的整数(-1结束输入):\n");
		scanf("%d",&input);
		if(input == -1){
			break;
		}
		insetNode(&head,input);
	}
	printf("打印:\n");
	printNode(&head);

	return 0;
}
