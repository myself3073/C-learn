#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Persion
{
	char name[64];
	char phone[24];
	struct Persion *next;
};

void getInput(struct Persion *persion);
void printPesion(struct Persion *persion);
void addPersion(struct Persion **contacts);
void changePersion(struct Persion **contacts);
void _changePersion(struct Persion *onePersion);
void _delPersion(struct Persion **contact,struct Persion *onePersion);
void delPersion(struct Persion **contacts);
void findPersion(struct Persion **contacts);
struct Persion *_findPersion(struct Persion *onePersion,char *searchInfo);
void displayContacts(struct Persion *contacts);
void releaseContacts(struct Persion **contacts);

void getInput(struct Persion *persion)
{
	printf("联系人:\n");
	scanf("%s",persion->name);
	printf("号码:\n");
	scanf("%s",persion->phone);
	return;
}

void addPersion(struct Persion **contact)
{
	struct Persion *persion,*tmp;

	static struct Persion *tail;

	persion = (struct Persion *)malloc(sizeof(struct Persion));
	if(NULL == persion){
		printf("分配内存失败...\n");
		exit(1);
	}

	getInput(persion);

	if(NULL == *contact)
	{
		*contact = persion;
		persion->next = NULL;
	}else{
		tail->next = persion;
		persion->next = NULL;
	}

	tail = persion;

	return;
}

void printPersion(struct Persion *persion)
{
	printf("联系人:%s\n",persion->name);
	printf("号码:%s\n",persion->phone);
}

void printContact(struct Persion **contact)
{
	struct Persion *persion;
	persion = *contact;
	if(NULL == persion){
		printf("电话本是空的,请先添加联系人...\n");
		return;
	}
	while(NULL != persion)
	{
		printPersion(persion);
		persion = persion->next;
	}
	return;
}

struct Persion *_findPersion(struct Persion *onePersion,char *searchInfo)
{
	struct Persion *persion;
	persion  = onePersion;

	while(NULL != persion)
	{
		if(!strcmp(persion->name,searchInfo)||!strcmp(persion->phone,searchInfo))
		{
			break;
		}
		persion = persion->next;
	}
	return persion;
}

void findPersion(struct Persion **contacts)
{
	struct Persion *persion;
	char name_Or_phone[64];

	printf("请输入查找条件:(姓名或者号码)\n");
	scanf("%s",name_Or_phone);
	while(name_Or_phone == NULL)
	{
		printf("您输入的信息为空,请重新输入...\n");
		scanf("%s",name_Or_phone);
	}
	printf("查找结果:\n");
	persion = _findPersion(*contacts,name_Or_phone);
	do
	{
		if(NULL == persion){
			printf("找不到匹配的联系人...\n");
			return;
		}else{
			printPersion(persion);
		}
	}while((persion = _findPersion(persion->next,name_Or_phone)) != NULL);
}

void _changePersion(struct Persion *onePersion)
{
	char changeName[64],changePhone[64];
	
	printf("输入修改的信息,输入-1则保持不变...\n");
	printf("联系人:\n");
	scanf("%s",changeName);
	printf("号码:\n");
	scanf("%s",changePhone);

	if(NULL != changeName && !strcmp(onePersion->name,"-1")){
		strcpy(onePersion->name,changeName);
	}
	
	if(NULL != changePhone && !strcmp(onePersion->phone,"-1")){
		strcpy(onePersion->phone,changePhone);
	}
	return;
}

void changePersion(struct Persion **contacts)
{
	struct Persion *persion;
	char searchInfo[64],option;
	int findNum = 0;

	printf("请输入要修改的联系人(姓名或者号码):\n");
	scanf("%s",searchInfo);
	while(searchInfo == NULL)
	{
		printf("您输入的信息为空,请重新输入...\n");
		scanf("%s",searchInfo);
	}
	persion = _findPersion(*contacts,searchInfo);
	do
	{
		if(persion == NULL){
			printf("查无此人!!!\n");
			return;
		}else{
			printf("根据条件,匹配到该联系人:\n");
			printPersion(persion);
			printf("是否修改此联系人?(Y/N)\n");
			//scanf("%c",option);
			option = getchar();
			while( option != 'Y' && option != 'N')
			{
				printf("您输入的信息有误,请重新输入...\n");
				//scanf("%c",option);
				option = getchar();
			}
			if(option == 'Y')
			{
					_changePersion(persion);
					printf("修改结果:\n");
					printPersion(persion);
			}else{
					break;
			}
		}
	}while((persion = _findPersion(persion->next,searchInfo))!= NULL);
}

void _delPersion(struct Persion **contacts,struct Persion *onePersion)
{
	struct Persion *previous,*current;
		
	printf("3Value:%p\n",&contacts);
	current = *contacts;
	printf("@########%s  %s\n",current->name,onePersion->name);
	previous = NULL;
	
	while((current != NULL && !strcmp(current->name,onePersion->name)) || (current != NULL && !strcmp(current->phone,onePersion->phone)))
	{
		previous = current;
		current = current->next;
	}

	if(previous == NULL){
		//空链表或者第一个就匹配的情况
		*contacts = NULL;
	}else{
		//一般情况
		previous->next = current->next;
	}

	printf("@########%s\n",current->name);
	printf("4Value:%p\n",&contacts);
	free(current);
	return;
}

void delPersion(struct Persion **contacts)
{
	struct Persion *persion;
	char searchInfo[64],option;

	printf("1Value:%p\n",&contacts);
	persion = *contacts;
	printf("请输入要删除的联系人(姓名或者号码):\n");
	scanf("%s",searchInfo);

	while(searchInfo == NULL)
	{
		printf("您输入的信息为空,请重新输入...\n");
		scanf("%s",searchInfo);
	}
	persion = _findPersion(*contacts,searchInfo);
	do
	{	printf("do:%s\n",(*contacts)->name);
		if(persion == NULL){
			printf("查无此人!!!\n");
			return;
		}else{
			printf("根据条件,匹配到该联系人:\n");
			printPersion(persion);
			printf("是否删除此联系人?(Y/N)\n");
			//scanf("%c",option);
			option = getchar();
			while( option != 'Y' && option != 'N')
			{
				printf("您输入的信息有误,请重新输入...\n");
				//scanf("%c",option);
				option = getchar();
			}
			if(option == 'Y')
			{
					printf("2Value:%p\n",&contacts);
					printf("dodo:%s\n",(*contacts)->name);
					_delPersion(contacts,persion);
					printf("5Value:%p\n",&contacts);
					printf("删除成功!!!!\n");
			}else{
					break;
			}
		}
	}while((persion = _findPersion(persion->next,searchInfo))!= NULL);
}

int main( int argc,char *argv[]){

	struct Persion *head_contacts;
	
	head_contacts = NULL;

	int option;

	while(1)
	{
		printf("选择下列功能:\n");
		printf("########1.插########\n");
		printf("########2.查########\n");
		printf("########3.改########\n");
		printf("########4.删########\n");
		printf("########5.显########\n");
		printf("########6.退########\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1: addPersion(&head_contacts);break;
			case 2: findPersion(&head_contacts);break; 
			case 3:	changePersion(&head_contacts);break;
			case 4: delPersion(&head_contacts);break;
			case 5: printContact(&head_contacts);break;
			case 6:;
		}
	}


	return 0;
}
