#include<stdio.h>

struct Date
{
	unsigned int year;
	unsigned int months;
	unsigned int day;
};

struct Book
{
	char title[124];
	char author[24];
	struct Date date;
	float prices;
}book1 = {
	"世界真大",
	"HHZ",
	{
		2021,
		11,
		25
	},
	199.99
};

int main( int argc,char *argv[]){


	printf("title:%s\n",book1.title);
	printf("author:%s\n",book1.author);
	printf("date:%u-%u-%u\n",book1.date.year,book1.date.months,book1.date.day);
	printf("prices:%6.2f\n",book1.prices);

	struct Book book2,*pst=NULL;

	book2 = book1;

	pst = &book1;

	printf("title:%s\n",book2.title);
	printf("author:%s\n",book2.author);
	printf("date:%u-%u-%u\n",book2.date.year,book2.date.months,book2.date.day);
	printf("prices:%6.2f\n",book2.prices);

	printf("title:%s\n",(*pst).title);
	printf("author:%s\n",(*pst).author);
	printf("date:%u-%u-%u\n",(*pst).date.year,(*pst).date.months,(*pst).date.day);
	printf("prices:%6.2f\n",(*pst).prices);

	printf("title:%s\n",book1.title);
	printf("author:%s\n",book1.author);
	printf("date:%u-%u-%u\n",book1.date.year,book1.date.months,book1.date.day);
	printf("prices:%6.2f\n",book1.prices);

	return 0;
}
