#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
	int value;
	struct Node *next;
};

void insetNode(struct Node **head,int value);
struct Node *searchNode(**head,int value);
void deleteNode(struct Node **head,int value);
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

	//定位到要插入的位置
	while(current != NULL && current->value < value)
	{
		previous = current;
		current = current->next;
	}
	
	//这个判断解决head==NULL,及输入11再输入1出错的情况,也就是有没有走while这一步
	if(previous == NULL){
		*head = new;//没走
	}else{
		previous->next = new;//走了
	}

	new->next = current;

	return;
}

struct Node *searchNode(struct Node **head,int value)
{
	struct Node *targetNode;
	targetNode = *head;
	while(NULL != targerNode)
	{
		if(targetNode->value == value){
			break;
		}
		targetNode = targetNode->next;
	}
	return targetNode;
}

struct Node *deleteNode(struct Node **head,int value)
{
	struct Node *previous,*current;
	current = *head;
	previous =  NULL;
	
	while(current != NULL && current->value != value)
	{
		previous = current;
		current = current->next;
	}
	if( NULL == current){
		printf("找不到该元素,退出...\n");
		return;
	}
	if(previous == NULL){
		*head = current->next; 
	}else{
		previous->next = current->next;
	}
	
	//free(current);

	return current;
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
	struct Node delNode,*tmp;s
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
	printf("插入后打印:\n");
	printNode(&head);

	//改进点:链表里面有相同的数字,一并删除.get:可以结合上次的单链表查
	while(1)
	{
		printf("请输入一个要删除的整数(-1结束输入):\n");
		scanf("%d",&input);
		if(input == -1){
			break;
		}
		delNode = (struct Node *)deleteNode(&head,input);//调用这个的时候,链表不能为空的了
		do
		{
			tmp = delNode->next;
			free(delNode);
		}while((delNode = deleteNode(&delNode->next,input)) != NULL);
	}
	printf("删除后打印:\n");
	printNode(&head);

	return 0;
}
