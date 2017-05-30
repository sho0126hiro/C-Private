#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100
/*関数宣言*********************************************************************/
void Insertion(int number[]);
void Insertion2(int number[]);
void Display(int number[]);
/*main****************************************************************************/
int main(){
	int i,j;
	int number[N]={0};
	time_t t;
	srand((unsigned)time(&t));//rand初期化
	for(i=0;i<N;i++){
		number[i]=rand()%100;
	}
	printf("==========選択ソート==========\n");
	printf("ソート前\n");
	Display(number);
	printf("\n小さい順\n");
	Insertion(number);
	Display(number);
	printf("\n大きい順\n");
	Insertion2(number);
	Display(number);
	return 0;
}
/*挿入ソート****************************************************************************/
void Insertion(int number[]){
	int i,j,next;
	for(i=1;i<N;i++){
		next=number[i];
		j=i;
		while(j>=1 && number[j-1] > next){
			number[j]=number[j-1];
			j--;
		}
		number[j]=next;
	}
}
void Insertion2(int number[N]){
	int i,j,next;
	for(i=0;i<N;i++){
		next=number[i];
		j=i;
		while(j>=1 && number[j-1] < next){
			number[j]=number[j-1];
			j--;
		}
		number[j]=next;
	}
}
/*表示*****************************************************************/
void Display(int number[]){
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			printf("%3d",number[10*i+j]);
		}
		printf("\n");
	}
}
