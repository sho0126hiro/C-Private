#include <stdio.h>

//�z��̗v�f�����擾�imain���}�N���錾���L���j

/*
�z��̗v�f��=�z��S�̂̑傫��/�z��̗v�f����̑傫��
sizeof(array):�z��S�̂̃������T�C�Y
sizeof(array[x]):�z�����̃������T�C�Y
�v�f��N=sizeof(array)/sizeof(array[0]);
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

/*���s����

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
