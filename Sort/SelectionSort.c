#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100
/*�֐��錾*********************************************************************/
void Selection(int number[]);
void Selection2(int number[]);
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
	
	printf("==========�I���\�[�g==========\n");
	printf("�\�[�g�O\n");
	Display(number);
	Selection(number);
	printf("\n��������\n");
	Display(number);
	printf("\n�傫����\n");
	Selection2(number);
	Display(number);
	return 0;
}
/*�I���\�[�g****************************************************************************/
void Selection(int number[N]){
	int min;
	for(int i=N;0<i;i--){
		min=0;
		for(int j=0;j<i;j++){
			if(number[min]<number[j]){
				min=j;
			}
		}
		Exchange(number,min,i-1);
	}
}
void Selection2(int number[N]){
	int max,i,j;
	for(i=N;i>0;i--){
		max=0;
		for(j=0;j<i;j++){
			if(number[max]>number[j]){
				max=j;
			}
		}
		Exchange(number,max,i-1);
	}
}

/*����****************************************************************************/
void Exchange(int number[],int i,int j){
	int tmp;
	tmp      =number[i];
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
