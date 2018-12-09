#include <stdio.h>
int count=0;
void foge(){
    printf("foge in %d \n",count);
}
void hoga(){
    count=3;
    printf("hoga in %d \n",count);
}
int main(){
    printf("main %d\n",count);
    count=1;
    foge();
    printf("main %d\n",count);
    count=2;
    hoga();
    printf("main %d\n",count);
    return 0;
}
/*
void foge(){
    print("foge in %d \n",count);
}
*/