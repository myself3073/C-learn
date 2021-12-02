#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
void printLibrary(struct Book *library);
struct Book *searchBook(struct Book **library,char *searchInfo);
void printBook(struct Book *book);

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

	static struct Book *tail;//记录每次调用addBook结束后链表的尾部节点

	book = (struct Book *)malloc(sizeof(struct Book));
	if(NULL == book){
		printf("分配内存失败...\n");
		exit(1);
	}

	toInputInfo(book);
	
	if(NULL == *library){//空链表
		*library = book;
		book->next = NULL;
		
	}else{
	
		tail->next = book;
		book->next = NULL;
		}
	tail = book;
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

struct Book *searchBook(struct Book **library,char *searchInfo)
{
	struct Book *targetBook;
	targetBook = *library;
	while(NULL != targetBook)
	{
		//找到,break退出循环
		if(!strcmp(targetBook->title,searchInfo) ||!strcmp(targetBook->author,searchInfo) )
		{
			break;
		}
		//没找着,继续循环
		targetBook = targetBook->next;
	}
	return targetBook;
}

//问题:结构体成员遍历输出有没有好方法?

void printBook(struct Book *book)
{
	printf("书名:%s\n",book->title);
	printf("作者:%s\n",book->author);
	printf("售价:%6.2f\n",book->price);
}

int main( int argc,char *argv[]){

	struct Book *library = NULL;
	struct Book *book;
	char ch,searchInfo[128];

	
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

	printf("请输入要查找的书名或者作者:\n");
	scanf("%s",searchInfo);
	
	//查找
	book = searchBook(&library,searchInfo);

	if(NULL == book){
		printf("根据你输入的信息,没找到相关的书籍...\n");
		//这里可以在调用一个函数,再次进入搜索的
	}else{
		printf("根据你输入的信息,找到如下相关的书籍:\n");
		//library里有可能有 重名 的
		do
		{
			printBook(book);
		}while(((book = searchBook(&book->next,searchInfo)) != NULL));	//
	}

	//释放
	releaseLibrary(&library);
	
	return 0;
}
