#include <stdio.h>

/*

真偽判定

if(x)printf("a");
if(x==1)printf("a");
は同じ

if(x)printf("a");
if(x>=1)printf("a");
は同じ

if(!x)printf("b");
if(x==0)prinf("b");
は同じ

*/

int main(){
	int x=0,y=2,z=1;
	int x2=0,y2=2,z2=1;
	
	if(x==1)printf("x\n");
	if(y==0)printf("y\n");
	if(z>=1)printf("z\n");
	
	if(x2)printf("xx\n");
	if(!y2)printf("yy\n");
	if(z2)printf("zz\n");
	
	return 0;
}
