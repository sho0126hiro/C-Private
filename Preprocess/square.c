//http://coskx.webcrow.jp/mrr/for_students/CIntro/preprocess.html
#include <stdio.h>

#define SQUARE(x) ((x)*(x))

int main()
{
    double x,y;
    x=4.0;
    y=SQUARE(x++);
    printf("x=%f y=%f\n",x,y);
    return 0;
}
//x=6.000000 y=20.000000
/*
x=5 y=16を期待していたが，x=6になってしまった。
    y=SQUARE(x++);
の単純な文字の置き換えになるので
    y=((x++)*(x++));
になってしまう。
yは期待したとおりだが，
xは2回インクリメントされるので，期待とは違ってしまった。
*/