//＊＊＊H30年度・DSP1-4・番号42＊＊＊

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DATASIZE 701 //data size

//file読み込み
void FileRead(char filename[],double data[]){
	FILE *fp;
	//printf("| function : %s | filename:%s |\n",__FUNCTION__,filename);
	fp=fopen(filename,"r");
	if(fp==NULL){
		printf("can't open a file\n");
		//exit(1);
		return;
	}
	int i=0;
	while(fscanf(fp,"%lf",&data[i])!= EOF)i++;
	fclose(fp);
}
//File書き込み
void FileWrite(char filename[],double data[]){
	FILE *fp;
	printf("| function : %s | filename:%s |\n",__FUNCTION__,filename);
	fp=fopen(filename,"w");
	if(fp==NULL){
		printf("can't open a file\n");
		//exit(1);
		return;
	}
	for(int i=0;i<DATASIZE-1;i++){
		fprintf(fp,"%f\n",data[i]);
	}
	fclose(fp);
}
//内積
double InnerProduct(double a[],double b[],int N){
	//二本のベクトルと要素数を入力して内積を出力
	double c=0;
	double sum=0;
	for(int i=0;i<N;i++){
		c=a[i]*b[i];
		//printf("c=%f a[i]=%f b[i]=%f\n",c,a[i],b[i]);
		sum=sum+c;
		//printf("sum=%f\n",sum);
	}
	return sum;
}
//配列内のデータをずらす関数
void ShiftArray(double a[],double b[] ,int m){	
	//aの配列をmこ右にずらし、0を代入する。
	int i;
	for(i=0;i<DATASIZE-m;i++)b[i]=a[i+m];
	for(i=0;i<m;i++){
		b[DATASIZE-i]=0.0;
	}
}
//相互相関係数の算出
void Calculation(double data1[],double data2[],double Rxy[]){
	int i;
	double data2_m[DATASIZE]={0}; //mだけずらした配列
	for(i=0;i<DATASIZE-1;i++){
		ShiftArray(data2,data2_m,i); //data2_mにiずらした配列が代入される
		Rxy[i]=InnerProduct(data1,data2_m,DATASIZE); //XとYi+mの内積を求める
        Rxy[i]/=DATASIZE;
	}
	//printf("| LINE : %d | function : %s |",__LINE__,__FUNCTION__);
}

int main(){
	//人口データ格納配列
	double data1[DATASIZE]={0};//a.txt
	double data2[DATASIZE]={0};//b.txt
	//読み込みファイル名
	char fname1[]="a.txt";
	char fname2[]="b.txt";
	//ファイルの中身読み込み、dataに格納
	FileRead(fname1,data1);
	FileRead(fname2,data2);
	double Rxy[DATASIZE-1]={0};//Xi,Yi+mの内積結果格納配列
	Calculation(data1,data2,Rxy);
	//fileへの書き込み
	char fname3[]="c.txt"; //出力ファイル名
	return 0;
}