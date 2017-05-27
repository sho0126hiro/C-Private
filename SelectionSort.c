#include <stdio.h>
#include <stdlib.h>

#define NUMBER 100 //要素数NUMBERは100

//関数宣言
void exchange(int d[],int i, int j);
void exchange2(int *x, int *y);
void Selection(int data[]);
void Selection2(int data[]);

//表示
void Display(int number[],int pattern){
  if(pattern==1){
    for(int i=0;i<100;i++){
        printf("%3d",number[i]);
        if(i!=0 && i%10==0)	printf("\n");
    }
  }else if(pattern==2){
    for(int i=100-1;i>=0;i--){
        printf("%3d",number[i]);
        if(i!=0 && i%10==0)	printf("\n");
    }
  }
}
//main
int main(){
	int number[NUMBER];
	for(int i=0;i<NUMBER;i++) number[i]=rand()%100;

	Selection(number);
	printf("小さい順\n");
	Display(number,1);
	printf("\n大きい順\n");
	Display(number,2);
	return 0;
}
//交換(配列)
void exchange(int d[],int i, int j){
	int tmp;
	tmp =d[i];
	d[i]=d[j];
	d[j]=tmp;

}
//交換（ポインタ)
void exchange2(int *x, int *y){
	int tmp;
	tmp =*x;
	*x  =*y;
	*y  =tmp;
}
/*
void exchange2(int *x, int *y){
	int *tmp;
	*tmp =*x;
	*x  =*y;
	*y  =tmp;
}
*/
//小さい順
void Selection(int data[]){
	int min;
	for(int i=NUMBER;0<i;i--){
		min=0;
		for(int j=0;j<i;j++){
			if(data[min]<data[j]){
			//大きい順にするときはif内の＜を＞にする
				min=j;
			}
		}
		//exchange(data,min,i-1);	//配列
		exchange2(&data[min],&data[i-1]);	//ポインタ
	}
}
