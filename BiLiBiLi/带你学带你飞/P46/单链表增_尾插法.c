#include<stdio.h>
#include<stdlib.h>
struct Book
{
	char title[128];
	char author[24];
	float price;
	struct Book *next;
};

void addBook(struct Book **library);
void toInputInfo(struct Book *book);
void releaseLibrary(struct Book **library);

void toInputInfo(struct Book *book){

	if(NULL == book){
		printf("there is no book to in...\n");
		return;
	}
	printf("书名:\n");
	scanf("%s",book->title);
	printf("作者:\n");
	scanf("%s",book->author);
	printf("售价:\n");
	scanf("%f",&book->price);
	return;
}

void addBook(struct Book **library){//注意点:**library 第一层解引用可以理解为*library <==>hea头指针

	struct Book *book,*tmp;
	book = (struct Book *)malloc(sizeof(struct Book));
	if(NULL == book){
		printf("分配内存失败...\n");
		exit(1);
	}

	toInputInfo(book);
	
	/* 头叉法
	if(NULL == *library){ //空链表
		*library = book;
		book->next = NULL;
		
	}else{
		tmp = *library;
		*library = book;
		book->next = tmp;
	}
	*/

	if(NULL == *library){//空链表
		*library = book;
		book->next = NULL;
		
	}else{
		
		//定位链表尾部
		while(NULL != (*library)->next)
		{
			*library = (*library)->next;
		}
		//插入
		(*library)->next = book;
		book->next = NULL;

	
		/*
		//尾叉法
		tmp = *library;
		//定位链表尾部
		while(NULL != tmp->next)
			{
			tmp =  tmp->next;
			}
		//插入
		tmp->next = book;
		book->next = NULL;
		*/
		}
	return;
}

void printLibrary(struct Book *library){
		
	struct Book *book;
	int bookCount = 1;
	book = library;
	while(NULL != book)
	{	
		printf("第%d本书的信息:\n",bookCount);
		printf("书名:%s\n",book->title);
		printf("作者:%s\n",book->author);
		printf("售价:%6.2f\n",book->price);
		bookCount++;
		book = book->next;//注意点
	}
	return;
}

void releaseLibrary(struct Book **library) //传入头指针head
{
	struct Book *tmp;
	while(NULL != *library)
	{
		tmp = *library;
		*library = (*library)->next;//注意点:这里()不能去掉,因为->优先级比*高
		free(tmp);
		tmp = NULL;
	}
}

int main( int argc,char *argv[]){

	struct Book *library = NULL;
	char ch;
	
	while(1){
		printf("是否录入书籍信息:(Y/N)");
		do
		{
			ch = getchar();
		}while(ch != 'Y' && ch != 'N');
		if(ch == 'Y'){
			addBook(&library);
		}else{
			break;
		}
	
	}
	printf("是否打印书籍信息:(Y/N)");
	do
	{
		ch = getchar();
	}while(ch != 'Y' && ch != 'N');
	if(ch == 'Y'){
		printLibrary(library);
	}

	//释放
	releaseLibrary(&library);
	
	return 0;
}
