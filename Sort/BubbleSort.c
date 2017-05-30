#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100
/*�֐��錾*********************************************************************/
void Bubble(int number[]);
void Bubble2(int number[]);
void Display(int number[]);
void Exchange(int number[],int i,int j);
/*main****************************************************************************/
int main(){
	int i,j;
	int number[N]={0};
	time_t t;
	srand((unsigned)time(&t));//rand������
	for(i=0;i<N;i++){
		number[i]=rand()%100;
	}
	printf("=========�o�u���\�[�g=========\n");
	printf("�\�[�g�O\n");
	Display(number);
	printf("\n��������\n");
	Bubble(number);
	Display(number);
	printf("\n�傫����\n");
	Bubble2(number);
	Display(number);
	return 0;
}
/*�o�u���\�[�g****************************************************************************/
void Bubble(int number[N]){
	int i,j;
	for(i=N;i>0;i--){
		for(j=0;j<i-1;j++){
			if(number[j]>number[j+1]){
				Exchange(number,j,j+1);
			}
		}
	}
}
void Bubble2(int number[N]){
	int i,j;
	for(i=N;i>0;i--){
		for(j=0;j<i-1;j++){
			if(number[j]<number[j+1]){
				Exchange(number,j,j+1);
			}
		}
	}
}
/*����****************************************************************************/
void Exchange(int number[],int i,int j){
	int tmp;
	tmp=      number[i];
	number[i]=number[j];
	number[j]=tmp;
}
/*�\��*****************************************************************/
void Display(int number[]){
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			printf("%3d",number[10*i+j]);
		}
		printf("\n");
	}
}
