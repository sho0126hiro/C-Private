#include <stdio.h>
#include <string.h>

int main(void){
	char ss[]="Abd";
	char *p1,*p2;
	p1=(char *)malloc(sizeof(char[4]));
	p2=(char *)malloc(sizeof(char[4]));
	strcpy(p1,ss);
	strcpy(p2,ss);
	//p1,p2‚Éss‚ğƒRƒs[
	printf("‡@:");
	printf("%c\n",*(p1+2));
	
	printf("‡A:");
	printf("%s\n",p1+1);
	
	printf("‡B:");
	printf("%c\n",*p1+1);

	*p2=*(p1+1)+1;
	*(p1+2)=*p2;
	printf("‡C:");
	printf("%s\n",p2);
	
	printf("‡D:");
	printf("%s\n",p1);
	
	return 0;
	
}

/*
‡@:d
‡A:bd
‡B:B
‡C:cbd
‡D:Abc
*/
