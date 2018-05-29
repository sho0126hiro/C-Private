#include <stdio.h>

//配列の要素数を取得（main内マクロ宣言が有効）

/*
配列の要素数=配列全体の大きさ/配列の要素一つ分の大きさ
sizeof(array):配列全体のメモリサイズ
sizeof(array[x]):配列一つ分のメモリサイズ
要素数N=sizeof(array)/sizeof(array[0]);
*/

#define length(data) (sizeof(data)/sizeof(data[0]))

void PrintData(int data[]){
	for(int i=0;i<10;i++){
		printf(" %d",data[i]);
	}
	printf("\nfunc in  N = %2d\n",length(data));
	
}
int lengthfunc(int data[]){
	return sizeof(data)/sizeof(data[0]);
}
int main(){
	//data[10]
	int data[10]={3,4,3,2,4,0,0,0,0,0};
	printf("data       = ");
	PrintData(data);
	int N;
	N=sizeof(data)/sizeof(data[0]);
	printf("main     N = %2d\n",N);
	N=length(data);
	printf("define   N = %2d\n",N);
	N=lengthfunc(data);
	printf("func out N = %2d\n",N);
	
	//data[]
	int data2[]={3,3,4};
	printf("data2      = ");
	PrintData(data2);
	N=sizeof(data2)/sizeof(data2[0]);
	printf("main     N = %2d\n",N);
	N=length(data2);
	printf("define   N = %2d\n",N);
	N=lengthfunc(data2);
	printf("func out N = %2d\n",N);
	return 0;
}

/*実行結果

	data       =  3 4 3 2 4 0 0 0 0 0
	func in  N =  1
	main     N = 10
	define   N = 10
	func out N =  1
	
	data2      =  3 3 4 1237637841 35257988 19076696 1 15303744 15331080 0
	func in  N =  1
	main     N =  3
	define   N =  3
	func out N =  1
*/
