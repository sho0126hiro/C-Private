/* �O���t�\���̕��D��T�� */

#include<stdio.h>

#define TRUE            1
#define FALSE           0
#define MAX_SIZE        11

int adjacent[MAX_SIZE][MAX_SIZE]; /* �אڍs�� */
int visited[MAX_SIZE];
int open_list[MAX_SIZE]; /* �L���[ */
int count;/**/
	
char *graph_data[] = {
	"CI",           /* A : C I */
	"DGH",          /* B : D G H */
	"ADG",          /* C : A D G */
	"BCHIJ",        /* D : B C H I J */
	"FHJ",          /* E : F H J */
	"EGK",          /* F : E G K */
	"BCF",          /* G : B C F */
	"BDEJ",         /* H : B D E J */
	"AD",           /* I : A D */
	"DEHK",         /* J : D E H K */
	"FJ"            /* K : F J */
};

/*�אڍs��̕\��*/
void disp(){
	int i,j;
	printf("�אڍs��F\n");
	for(j=0;j<MAX_SIZE;j++){
		for(i=0;i<MAX_SIZE;i++){
			printf("%d ",adjacent[j][i]);
		}
		printf("\n");
	}
}

/* �O���t�̏����� */
void init_graph(void)
{
	int i,j;
	/*visit������*/
	for(j=0;j<MAX_SIZE;j++){
		visited[j]=FALSE;
	}
	/*adjacent������*/
	for(j=0;j<MAX_SIZE;j++){
		for(i=0;i<MAX_SIZE;i++){
			adjacent[j][i]=0;
		}
	}
	//[TATE][YOKO]
	for(j=0;j<MAX_SIZE;j++){
		for(i=0;graph_data[j][i] != '\0' ;i++){
			adjacent[j][graph_data[j][i]-'A']=1;
		}
	}
	disp();
}


/* �L���[�̏����� */
void init_queue(int *q)
{
	int i;
	for( i = 0; i < MAX_SIZE; i++ ){
		q[i] = -1;
	}
}

/* �L���[�̕\�� */
void print_queue(int *q)
{
	int i;
	printf("{");
	for( i = 0; i < MAX_SIZE; i++ )
		if( q[i] != -1 )
			printf("%c",q[i]+'A');
	printf("}\n");
}

/* �L���[�̒��Ƀf�[�^d�����݂��Ă��邩�ǂ������`�F�b�N */
int check_queue(int *q,int d)
{
	int i;
	for( i = 0; i < MAX_SIZE;i++ )
		if( q[i] == d ) return TRUE;
	return FALSE;
}

/* �L���[�Ƀf�[�^������ */
void enqueue(int *q, int d)
{	
	int count=0;
	while(q[count]!=-1)count++;
	q[count]=d;
}

/* �L���[����f�[�^�����o�� */
int dequeue(int *q)
{
	int x,i=0;
	
	if(q[0]==-1)return -1;//����Ȃ��H
	else x=q[0];
	/*slide*/
	while(q[i]!=-1){
		q[i]=q[i+1];
		i++;
	}
	q[i-1]=-1;
	return x;
}

/* �o�H�̒T���i���D��T���j */
/*searching.. �̏ꏊ��print_queue�̏ꏊ*/
void search(int now, int end)
{
	int i;
	init_queue(open_list);/*�L���[�̏�����*/
	enqueue(open_list,now);/*�ŏ��̃f�[�^(now)���L���[�ɓ����*/
	visited[now]=TRUE;/*�K�ꂽ���Ƃ��L��*/
	printf("searching ... %c\n",(now +'A'));
	printf("open_list =");
	print_queue(open_list);
	/*�L���[�Ƀf�[�^���Ȃ��Ȃ�܂ŌJ��Ԃ�*/
	while(open_list[0]!=-1){
		now=dequeue(open_list);/*�L���[����f�[�^�����o����now�ɃZ�b�g*/
		visited[now]=TRUE;/*visited[now]��TRUE���Z�b�g���K�ꂽ���Ƃ��L��*/
		if(now==end){/*���݈ʒu���S�[���ł����*/
			printf("Found.\n");
		}else{/*���ݒn���S�[���łȂ���*/	
			for(i=0;i<MAX_SIZE;i++){/*�S�Ă̒��_������*/
				if(adjacent[now][i]==1 && visited[i]!=TRUE){/*�אڂ��Ă��鎞�ł��A�܂��K��Ă��Ȃ���*/
					if(check_queue(open_list,i)!=TRUE){/*�L���[�̒��ɑ��݂��Ȃ����_��I��*/
						enqueue(open_list,i);
						printf("searching ... %c\n",(i +'A'));
						printf("open_list =");
						print_queue(open_list);
					}
				}
			}
		}
	}	
}

/* ���C���֐� */
int main(void)
{
	init_graph();
	search(0, 10 );         /* A ���� K �̌o�H */
	return 0;
}
