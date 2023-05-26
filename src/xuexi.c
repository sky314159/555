#include<stdio.h>
int main()
{
    int i;

    printf("你老多大啊 ：");
    scanf("%d",&i);

    if (i >= 18)
    {
        printf("进门左走 ！ \n");
    }

    if (i < 18)
    {
        printf("进门右边 ！ \n");
    }
    return 0;
}