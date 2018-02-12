/* 2���T���؂ɂ��T�� */

#include <stdio.h>
#include <stdlib.h> /*malloc*/
#include <string.h> /*strcmp*/

#define KEY_SIZE	8

struct tree{
	struct tree *left;
	int no;
	struct tree *right;
};

/* ���l�̓��͗p�֐� */
int get_num(void) {
	int  i;
	int  d = 0;
	int  c = 0;
	rewind(stdin);
	for( i = 0; i < 5 && c != '\n' ; i++ ){ /* 5�P�^�܂� */
	 c = getchar();
	 if ( c == '\n' ) break;
	 d = d * 10 + c - '0';
	}
	rewind(stdin);
	return d;
}

/* �m�[�h�̒ǉ� */
struct tree *add_node(int num) {
	 struct tree *p;
	 p = (struct tree *)malloc(sizeof(struct tree));
	 p->left = NULL;
	 p->no = num;
	 p->right = NULL;
	 return p;
}

/* �c���[�̍쐬 */
struct tree *make_tree(struct tree *node, int num) {
	 if( node == NULL ){
		 node = add_node(num);
		 return node;
	 }
	 if ( num > node->no )
		 node->left = make_tree(node->left,num);
	 if ( num < node->no )
		 node->right = make_tree(node->right,num);
	  return node;
}

/* �c���[�̕\�� */
void print_tree(struct tree *node) {
	 int i;
	 static int depth = 0;
	  if( node->left != NULL ){
		 depth ++;
		 print_tree(node->left);
		 depth --;
	 }
	  for( i = 0; i < depth; i++ )
		 printf("\t");
	 printf("[%2d]\n",node->no);
	  if( node->right != NULL){
		 depth ++;
		 print_tree(node->right);
		 depth --;
	 }
}


/* �c���[�̒T���֐� search ������ */
/*�T���Ώۂ�����������0�A������Ȃ�������-1��Ԃ�*/
int search(int target,struct tree *node){
	printf("[%d]->",node->no);
	if(node -> no == target)return 0;
	else if(node -> left == NULL && node ->right == NULL)return -1;
	if(node -> no < target && node -> left   != NULL)return search(target,node->left);
	if(node -> no > target && node -> right != NULL)return search(target,node->right);
	return 0;
}

int main(void) {
	struct tree *root;
	int i, num;	
	int target;	  /*�T���L�[*/
	char c[] = "";/*yes or no ���͗p*/
	int check=0;
	root=0;
	for( i = 0; i < KEY_SIZE; i++ ){
		printf("%d> ",i+1);
		num = get_num();
		if( i == 0 ){
			root = make_tree(NULL,num);
		}
		else{
			make_tree(root,num);
		}
	}
	print_tree(root);
	
	/* �L�[���͂ɂ����s����~�����܂ŁA�T���L�[��
	 * ���͂ƒT���A���ʂ̕\�����J��Ԃ�
	 */
	printf("key>");
	target = get_num();
	check = search(target,root);
	if(check== -1)printf("NotFound.\n");
	else          printf("Found.\n");
	
	while(1){
		printf("Do you wanna continue(yes/no)?");
		gets(c);
		/*strcmp:��v�����0�A��v���Ȃ����0�ȊO��Ԃ��B*/
		if(! strcmp(c,"yes")){
			printf("key>");
			target = get_num();
			check = search(target,root);
			if(check== -1)printf("NotFound.\n");
			else          printf("Found.\n");
		} else {
			break;
		}
	}
	return 0;
}

