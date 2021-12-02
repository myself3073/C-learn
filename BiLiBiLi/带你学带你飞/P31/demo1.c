#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main(void){

	char *cp = "192.168.1.1";
	if(-1 == inet_addr(cp)){
		printf("change is fail...\n");
	}
	printf("change is %s\n",cp);
	printf("change is %x\n",cp);
}
