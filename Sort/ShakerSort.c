#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100
/*関数宣言*********************************************************************/
void Shaker(int number[]);
void Shaker2(int number[]);
void Display(int number[]);
void Exchange(int number[],int i,int j);
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
	Shaker(number);
	Display(number);
	printf("\n大きい順\n");
	Shaker2(number);
	Display(number);
	return 0;
}
/*シェイカーソート****************************************************************************/
void Shaker(int number[]){
	int left=0,right=N-1,i,j,k,tmp;
	while(right>left){
		for(j=left;j<right;j++){
		//left=>right
			if(number[j]>number[j+1]){
				Exchange(number,j,j+1);
				k=j;
			}
		}
		right=k;
		for(j=right;j>left;j--){
		//right=>left
			if(number[j]<number[j-1]){
				Exchange(number,j,j-1);
				k=j;
			}
		}
		left=k;
	}
}

void Shaker2(int number[N]){
	int left=0,right=N-1,i,j,k,tmp;
	while(right>left){
		for(j=left;j<right;j++){
		//left=>right
			if(number[j]<number[j+1]){
				Exchange(number,j,j+1);
				k=j;
			}
		}
		right=k;
		for(j=right;j>left;j--){
		//right=>left
			if(number[j]>number[j-1]){
				Exchange(number,j,j-1);
				k=j;
			}
		}
		left=k;
	}
}
/*交換****************************************************************************/
void Exchange(int number[N],int i,int j){
	int tmp;
	tmp      =number[i];
	number[i]=number[j];
	number[j]=tmp;
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
