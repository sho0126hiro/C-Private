#include <stdio.h>
// break : ループを抜け出す
// continue : ループの先頭へ
int main(){
    int j=5;
    for (int i=0;i<4;i++){
        //i : 0,1,2,3
        switch(i){
            case 1:
                printf("hello");
                break;
            case 2:
                if(j<2)continue;
                printf("world");
                continue;
            default:
                printf("!");
        }
        printf("[foge]");
    }
    return 0;
}
/*
j<2
![foge]hello[foge]![foge]
]>2
![foge]hello[foge]world![foge]
*/