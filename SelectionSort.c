#include <stdio.h>

#define NUMBER 100 //要素数NUMBERは100

//関数宣言
void exchange(int d[],int i, int j);
void exchange2(int *x, int *y);
void Selection(int data[]);
void Selection2(int data[]);
void Display(int number[]);

//main
int main(){

	FILE *fp;
	int number[NUMBER];
	char filename[200];
	char file[200];
	char extension[200];
	//ファイルの読み込み
	fp=fopen("sample.txt","r");
	if (fp==NULL){
		printf("can't open a file\n");
		exit(1);
	}
	for(int i=0;i<NUMBER;i++)fscanf(fp,"%d",&number[i]);
	fclose(fp);
	
	//読み込み終わり
	
	Selection(number);
	printf("小さい順\n");
	Display(number);
	Selection2(number);
	printf("\n大きい順\n");	
	Display(number);
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
これはダメ
(tmp をポインタにしている)
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
//大きい順
void Selection2(int data[]){
	int min;
	for(int i=NUMBER;0<i;i--){
		min=0;
		for(int j=0;j<i;j++){
			if(data[min]>data[j]){
			//大きい順にするときはif内の＞を＜にする
				min=j;
			}
		}
		//exchange(data,min,i-1);	//配列
		exchange2(&data[min],&data[i-1]);	//ポインタ
	}
}
//表示
void Display(int number[]){
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			printf("%3d",number[10*i+j]);
		}
		printf("\n");
	}
}

