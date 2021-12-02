#include<stdio.h>
#include<stdlib.h>
struct Date
{
	unsigned int year;
	unsigned int month;
	unsigned int day;
};

struct Book
{
	char title[124];
	char author[24];
	struct Date date;
	float price;
	//unsigned float price;//unsigned 不修饰float and double
};

void toInputInfo(struct Book *book);
void printBookInfo(struct Book *book);

void toInputInfo(struct Book *book)
{
	printf("书名:\n");
	scanf("%s",book->title);
	printf("作者:\n");
	scanf("%s",book->author);
	printf("出版日期:\n");
	scanf("%d-%d-%d",&book->date.year,&book->date.month,&book->date.day);
	printf("售价:\n");
	scanf("%f",&book->price);

}

void printBookInfo(struct Book *book)
{
	printf("书名:%s\n",book->title);
	printf("作者:%s\n",book->author);
	printf("出版日期:%u-%u-%u\n",book->date.year,book->date.month,book->date.day);
	printf("售价:%.2f\n",book->price);

	return;
}

int main( int argc,char *argv[]){

	struct Book b1,b2;

	struct Book *pb = NULL;

	pb = (struct Book *)calloc(1,sizeof(struct Book));

	//pb = (struct Book *)malloc(sizeof(struct Book));

	if(NULL == pb){
		printf("calloc fail...\n");
		exit(1);
	}

	printf("请入录书籍的信息:\n");


	toInputInfo(pb);

	printf("入录书籍的信息为:\n");

	//printBookInfo(b1);
	
	printBookInfo(pb);

	free(pb);
	pb = NULL;

	return 0;
}
