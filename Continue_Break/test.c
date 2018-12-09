#include <stdio.h>
// break : ループを抜け出す
// continue : ループの先頭へ
int main(){
    for (int i=0;i<4;i++){
        printf("i = %d\n",i);
        if(i<3){
            printf("hello");
            if(i<2){
                printf(" == kon nichi");
                continue;
            }
            printf(" == hello == ");
            continue;
        }
        printf("wa\n");
    }
    return 0;
}
/*
i = 0
hello == kon nichii = 1
hello == kon nichii = 2
hello == hello == i = 3
wa
*/