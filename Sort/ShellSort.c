#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100
/*�֐��錾*********************************************************************/
void Shell(int number[]);
void Shell2(int number[]);
void Display(int number[]);
void Exchange(int number[],int i,int j);
/*main****************************************************************************/
int main(){
	int i,j,h;
	int number[N]={0};
	time_t t;
	srand((unsigned)time(&t));//rand������
	for(i=0;i<N;i++){
		number[i]=rand()%100;
	}
	printf("==========�V�F���\�[�g==========\n");
	printf("�\�[�g�O\n");
	Display(number);
	printf("\n��������\n");
	Shell(number);
	Display(number);
	printf("\n�傫����\n");
	Shell2(number);
	Display(number);
	return 0;
}
/*�V�F���\�[�g****************************************************************************/
void Shell(int number[]){
	int i,j,k,h= 1,next;
	while(h<=N)h=h*3+1;
	h=h/3;
	while(h>=1){
		for(i=0;i<h;i++){
			for(j=h+i;j<N;j=j+h){
				next=number[j];
				for(k=j;h<=k && number[k-h] > next;k=k-h){
					number[k]=number[k-h];
				}
				number[k]=next;
			}

		}
		h=h/3;
	}
}

void Shell2(int number[N]){
	int i,j,k,h= 1,next;
	while(h<=N)h=h*3+1;
	h=h/3;
	while(h>=1){
		for(i=0;i<h;i++){
			for(j=h+i;j<N;j=j+h){
				next=number[j];
				for(k=j;h<=k && number[k-h] < next;k=k-h){
					number[k]=number[k-h];
				}
				number[k]=next;
			}
		}
		h=h/3;
	}
}
/*����****************************************************************************/
void Exchange(int number[N],int i,int j){
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
