/* �O���t�\���̐[���D��T�� */

#include<stdio.h>
#include <stdlib.h>
#define TRUE      1
#define FALSE     0
#define MAX_SIZE 11

typedef struct character{
	int  no;                        /* �L�[ */
	char name;                      /* ���O */
	struct character *next_addr;    /* ���̃f�[�^�̃A�h���X */
}CELL;

/*�񎟌��z��i�|�C���^�j*/
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

CELL *adjacent[MAX_SIZE]; /* �אڃ��X�g */
int visited[MAX_SIZE];
int path[MAX_SIZE];

/* ���X�g�\���ŕ���ł���l�q��\������ */
void disp(void) {
	int i = 0;
	CELL *current_addr;
	printf("�אڃ��X�g:\n");
	for( i = 0; i < MAX_SIZE; i++ ){
		if( adjacent[i] != NULL ){
			current_addr = adjacent[i];
			do{
				printf("-|%c|-",current_addr->name);
				current_addr = current_addr->next_addr;
			}while( current_addr != NULL );
		}
		printf("\n");
	}
}

/* �f�[�^�̒ǉ� */
void add(int parent, int child) {
	/*adjacent[0]->child->child->NULL
	  adjacent[1]->child->NULL
	  �i�ȉ����j
	  ��L�̐��`���X�g������Ă���*/
	CELL *p;
	CELL *q;
	p = (CELL *)malloc(sizeof(CELL));
	p->no = child;
	p->name = 'A' + child;
	p->next_addr = NULL;
	q = adjacent[parent];
	while ( q->next_addr != NULL ) {
		q = q->next_addr;
	}
	q->next_addr = p;
}

/* �O���t�̏����� */
void init_graph(void) {
	CELL *p;
	int i,j,l;
	for (i = 0; i < MAX_SIZE; i++){
		visited[i]=FALSE;
	}
	/*adjacent������*/
	for(i=0;i<MAX_SIZE;i++){
		p = (CELL *)malloc(sizeof(CELL));
		p->no=i;
		p->name='A'+i;
		p->next_addr=NULL;
		adjacent[i]=p;
	}
	//[TATE][YOKO]
	for(i=0;i<MAX_SIZE;i++){
		for(j=0;graph_data[i][j] != '\0';j++){
			/*add�𗘗p*/
			l=graph_data[i][j]-'A';
			add(i,l);
		}
	}
}
/* �o�H�̕\�� */
void print_path(int num) {
	int i;
	for( i = 0; i <= num; i++ ){
		 printf("%c ", path[i] + 'A' );
	}
	printf("\n");
}

/* �o�H�̒T���i�[���D��T���j */
void search(int num, int now, int end) {
	/*
		num : �T���萔
		now : ���݂̒��_�̈ʒu
		end : �S�[���̈ʒu
	*/
	CELL *p;
	visited[now]=TRUE;/*�K�ꂽ���Ƃ��L��*/
	path[num]=now;/*���݈ʒu���Z�b�g*/
	if(now==end){
		print_path(num);
	}else{
		p=adjacent[now];
		while(p != NULL){
			if(visited[p->no]==FALSE){
				search(num+1,p->no,end);
			}
			p=p->next_addr;
		}
	}
	visited[now]=FALSE;
	//printf("%d:adjacent[name]:%c[LAST]\n",__LINE__,now+'A');
}

/* ���C���֐� */
int main(void) {
	init_graph();
	disp();
	search( 0, 0, 10 );		/* A(0) ���� K(10) �̌o�H */
	return 0;
}
