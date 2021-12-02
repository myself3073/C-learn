#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 1024

struct Persion
{
	char name[64];
	char phone[24];
	struct Persion *next;
};

//内存池 目前一种类型对应于一种池
struct Persion *pool = NULL;
int count;

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
	
	//内存池还有空间,从它拿
	if(NULL != pool)
	{
		persion = pool;
		pool = pool->next;
		count--;//拿一块少一块
		printf("内存池容量:%d\n",count);
	}else{////内存池没有空间,则从堆里拿
		persion = (struct Persion *)malloc(sizeof(struct Persion));
		if(NULL == persion){
			printf("分配内存失败...\n");
			exit(1);
		}
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

	if(NULL != changeName && strcmp(changeName,"-1")){
		strcpy(onePersion->name,changeName);
	}
	
	if(NULL != changePhone && strcmp(changePhone,"-1")){
		strcpy(onePersion->phone,changePhone);
	}
	return;
}

void changePersion(struct Persion **contacts)
{
	struct Persion *persion;
	char searchInfo[64],option;

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
					continue;
			}
		}
	}while((persion = _findPersion(persion->next,searchInfo))!= NULL);
}

void _delPersion(struct Persion **contacts,struct Persion *onePersion)
{
	struct Persion *previous,*current,*men_tmp;
		
	current = *contacts;
	previous = NULL;

	printf("Value:current=>%s  onePersion=>%s\n",current->name,onePersion->name);
	
	while(!((current != NULL && !strcmp(current->name,onePersion->name)) && (current != NULL && !strcmp(current->phone,onePersion->phone))))
	{
		previous = current;
		current = current->next;
	}

	if(previous == NULL){
		//空链表或者第一个就匹配的情况
		*contacts = current->next;
	}else{
		//一般情况
		previous->next = current->next;
	}
	
	if(count < MAX)
	{
		if(NULL == pool)
		{
			pool = current;
			current->next = NULL;
		}else{
			men_tmp = pool;
			pool = current;
			current->next = men_tmp;
		}
		count++;
		printf("内存池容量:%d\n",count);	
	}else{
		free(current);
	}	

	return;
}

void delPersion(struct Persion **contacts)
{
	struct Persion *persion;
	char searchInfo[64],option;

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
	{	
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
					_delPersion(contacts,persion);
					printf("删除成功!!!!\n");
			}else{
					continue;
			}
		}
	}while((persion = _findPersion(persion->next,searchInfo))!= NULL);
	return;
}

void releaseContacts(struct Persion **contacts)
{
	struct Persion *tmp,*men_tmp;
	if(NULL == *contacts)
		return;
	while(NULL != *contacts)
	{
		tmp = *contacts;
		*contacts = (*contacts)->next;
		if(count < MAX)
	{
		if(NULL == pool)
		{
			pool = tmp;
			tmp->next = NULL;
		}else{
			men_tmp = pool;
			pool = tmp;
			tmp->next = men_tmp;
		}
		count++;
		printf("内存池容量:%d\n",count);		
	}else{
		free(tmp);
	}
		tmp = NULL;
	}
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
			case 6: goto exit;
		}
	}

exit:
	printf("正退出系统...\n");
	releaseContacts(&head_contacts);
	exit(0);
	return 0;
}
