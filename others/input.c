#include <stdio.h>
#include <stdlib.h>
// #include <fcntl.h>
#include <unistd.h>
int main(){
	int d;
	char c;
	scanf("%d:%c",&d,&c);
	printf("Howdy%d:%c\n",d,c);
	char str[200];
	// scanf("%s",str);
	// read(0,str,15);
	printf("%s",str);
	return 0;
}