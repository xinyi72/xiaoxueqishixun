/*
  任务：
  使用 随机 函数初始化随机数生成器，然后使用 输入函数从用户输入中读取交通肇事犯的数量和车牌号，并使用 for 循环逐个模拟抓交通肇事犯的过程。在循环中，程序使用 rand 函数生成一个随机数，如果该随机数除以 10 的余数为 0，则表示抓到了交通肇事犯，输出相应的信息并将抓到的数量加一；否则，表示没有抓到交通肇事犯，输出相应的信息。最后，程序根据抓到的数量输出相应的总结信息。
  */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int i,n,cnt;
    printf("请输入你要抓几个逃犯:");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        printf("请输入第%d个逃犯的车牌号",i);
        char chepai[100];
        scanf("%s",chepai);
        if(rand()%10==0){
            cnt++;
            printf("恭喜你，抓住了第 %d 个交通肇事犯，车牌号为 %s。\n", cnt, chepai);
        }
        else printf("第%d个逃犯逃脱了\n",i);
    }
    if(cnt==0)printf("很遗憾一个逃犯也没有抓到");
    else  printf("恭喜你，共抓住了 %d 个交通肇事犯。\n", cnt);
}
