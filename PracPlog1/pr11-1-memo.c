#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MAX_SIZE 13
#define TRUE     1
#define FALSE    0
#define IMAX     10000 /* �z�肵����ő�R�X�g�����傫���l��ݒ� */

#define min(a,b) ((a)<(b) ? (a):(b))

 /* �f�[�^�i�אڍs��j */
int adjacent[MAX_SIZE][MAX_SIZE] = {
        {   0,  30,IMAX,  40,IMAX,IMAX,IMAX,IMAX,IMAX,IMAX,IMAX,IMAX,IMAX},     //  0: ����
        {  30,   0,  90,  60, 140,  80,IMAX,IMAX,IMAX,IMAX,IMAX,IMAX,IMAX},     //  1: ���
        {IMAX,  90,   0,IMAX,IMAX, 110, 330,240,IMAX,IMAX,IMAX,IMAX,IMAX},      //  2: �Q�n
        {  40,  60,IMAX,   0, 130,IMAX,IMAX,IMAX,IMAX,IMAX,IMAX,IMAX,IMAX},     //  3: ��t
        {IMAX, 140,IMAX, 130,   0, 100, 260,IMAX,IMAX,IMAX,IMAX,IMAX,IMAX},     //  4: ���
        {IMAX,  80, 110,IMAX, 100,   0, 170,IMAX,IMAX,IMAX,IMAX,IMAX,IMAX},     //  5: �Ȗ�
        {IMAX,IMAX, 330,IMAX, 260, 170,   0, 550,  80,  90,IMAX,IMAX,IMAX},     //  6: ����
        {IMAX,IMAX, 240,IMAX,IMAX,IMAX, 550,   0, 630,IMAX,IMAX,IMAX,IMAX},     //  7: �V��
        {IMAX,IMAX,IMAX,IMAX,IMAX,IMAX,  80, 630,   0,  60, 190,IMAX,IMAX},     //  8: �R�`
        {IMAX,IMAX,IMAX,IMAX,IMAX,IMAX,  90,IMAX,  60,   0, 290, 180,IMAX},     //  9: �{��
        {IMAX,IMAX,IMAX,IMAX,IMAX,IMAX,IMAX,IMAX, 190, 290,   0, 110, 300},     // 10: �H�c
        {IMAX,IMAX,IMAX,IMAX,IMAX,IMAX,IMAX,IMAX,IMAX, 180, 110,   0, 190},     // 11: ���
        {IMAX,IMAX,IMAX,IMAX,IMAX,IMAX,IMAX,IMAX,IMAX,IMAX, 300, 190,   0}      // 12: �X
};

char *graph_data[] = {  // ��L�אڍs���0~12�Ԗڂ̊e�v�f�ɑΉ�
        "Tokyo",
        "Saitama",
        "Gunma",
        "Chiba",
        "Ibaraki",
        "Tochigi",
        "Fukushima",
        "Niigata",
        "Yamagata",
        "Miyagi",
        "Akita",
        "Iwate",
        "Aomori"
};


int d[MAX_SIZE][MAX_SIZE];           /* ���_�Ԃ̍ŏ��R�X�g */
int pre_vertex[MAX_SIZE][MAX_SIZE];  /* �ŒZ�o�H */

/* d��pre_vertex�������� */
void init(void)
{
	//d[i][j]=adjacent[i][j]
	int i,j;
	for(i=0;i<MAX_SIZE;i++){
		for(j=0;j<MAX_SIZE;j++){
			d[i][j]=adjacent[i][j];//adjacent������
			pre_vertex[i][j] = i;//pre_vertex������
		}
	}
}

/* ���ׂĂ̒��_�Ԃ̍ŒZ�o�H��T���i�t���C�h�@�j */
void search(void)
{
	int i,j,k;
  for(i=0;i<MAX_SIZE;i++){
		for(j=0;j<MAX_SIZE;j++){
			for(k=0;k<MAX_SIZE;k++){
				if(d[i][j]!=(min(d[i][j],d[i][k]+d[k][j]))){//�X�V����
					d[i][j]=d[i][k]+d[k][j];
					pre_vertex[i][j]=pre_vertex[k][j];
				}
			}
		}
	}
  /*memo
  for(i=0;i<MAX_SIZE;i++){
    for(j=0;j<MAX_SIZE;j++){
      ��̓�s�ŁA���ׂĂ̗אڍs��𑀍�i�w��j���Ă���B
      
      for(k=0;k<MAX_SIZE;k++){
      ����́A���̌o�R���Ă������ق����������𒲂ׂ邽�߂�k���g���Ă���B
      k��0-maxsize�ŌJ��Ԃ����ƂŁA�S�Ă̒��_�ɑ΂��āA�o�R�����ق����������𒲂ׂĂ���

        if��
        i-j�@  ���̃��[�g���A
        i-k-j�@���̃��[�g�̂ǂ������Z�����𒲂ׂ����B

        ���Ȃ݂ɁAmin(a,b)�́Aa��b�Ŕ�ׂď������ق���Ԃ��i���define���Ă�j
        10�s��
        #define min(a,b) ((a)<(b) ? (a):(b))
        ����́A�֐�
        int min(int a,int b){
          if(a>b)return b;  //a��b�Ŕ�ׂ�b������������b��Ԃ�
          else return a;    //a��b�Ŕ�ׂ�a������������a��Ԃ�
        }
        �Ɠ����Ӗ�
        
        min(d[i][j],d[i][k]+d[k][j]))
        ����́Ad[i][j]�ƁAd[i][k]+d[k][j]���ׂĂǂ��������������𒲂ׂāA
        �������ق���\���Ă���B
        

        if(d[i][j]!=(min(d[i][j],d[i][k]+d[k][j]))){//�X�V����
          �Fk���o�R�����ق����������ɁAif(true)�ɂȂ�

        if�̒��g:
          d[i][j]=d[i][k]+d[k][j];
          k���o�R�����ق��������Ȃ�Ak���o�R�������[�g�ɍX�V���悤
          pre_vertex[i][j]=pre_vertex[k][j];
          ����́A�搶�̍u�`�����̒���
          �u�����āAd[i][j]���X�V����ہA pre_vertex[i][j]�ɂ�pre_vertex[k][j]�������܂��B�v
          ���Ă�����Ă������B
          �ihttps://nittc.tokyo-ct.ac.jp/usr/kitakosi/LEE/PracProgI/akiyojissen1/kougi27.html�j
    
    ����ł����܂�
    search�֐��𓮂�������́Ad[i][j]��pre_vertex[i][j]�̏�Ԃ͉��ɓ\���Ă����܂�
    �Ȃɂ��Q�l�ɂȂ邩��
  */
}

/* �o�H��\���i�t���j */
void print_path(int p, int q)
{
    int x = q;
    printf("-|%s|-",graph_data[x]);
    do{
        x = pre_vertex[p][x];
        printf("-|%s|-",graph_data[x]);
    }while(x != p);
}

int main(void)
{
	//int h,begin,end,flag;
	//int i,j;
	char start[10],destination[10];
    /* ������ */
	init();
    /* �T�� */
	search();

	print_path(5, 0);   // ���s�̈�� tochigi-tokyo
    return 0;
}
/*
pre_vertex[i][j]
    0    0    1    0    1    1    5    2    6    6    8    9   11
    1    1    1    1    1    1    5    2    6    6    8    9   11
    1    2    2    1    5    2    5    2    6    6    8    9   11
    3    3    1    3    3    1    5    2    6    6    8    9   11
    1    4    5    4    4    4    4    2    6    6    8    9   11
    1    5    5    1    5    5    5    2    6    6    8    9   11
    1    5    5    1    6    6    6    2    6    6    8    9   11
    1    2    7    1    5    2    5    7    6    6    8    9   11
    1    5    5    1    6    6    8    2    8    8    8    9   11
    1    5    5    1    6    6    9    2    9    9    8    9   11
    1    5    5    1    6    6    8    2   10    8   10   10   10
    1    5    5    1    6    6    9    2    9   11   11   11   11
    1    5    5    1    6    6    9    2    9   11   12   12   12
d[i][j]
    0   30  120   40  170  110  280  360  360  370  550  550  740
   30    0   90   60  140   80  250  330  330  340  520  520  710
  120   90    0  150  210  110  280  240  360  370  550  550  740
   40   60  150    0  130  140  310  390  390  400  580  580  770
  170  140  210  130    0  100  260  450  340  350  530  530  720
  110   80  110  140  100    0  170  350  250  260  440  440  630
  280  250  280  310  260  170    0  520   80   90  270  270  460
  360  330  240  390  450  350  520    0  600  610  790  790  980
  360  330  360  390  340  250   80  600    0   60  190  240  430
  370  340  370  400  350  260   90  610   60    0  250  180  370
  550  520  550  580  530  440  270  790  190  250    0  110  300
  550  520  550  580  530  440  270  790  240  180  110    0  190
  740  710  740  770  720  630  460  980  430  370  300  190    0
*/