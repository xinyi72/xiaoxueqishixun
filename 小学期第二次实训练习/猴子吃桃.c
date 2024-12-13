#include "stdio.h"
long long peach_num(int days);
int main(){
    int n;
    printf("请输入猴子吃了多少天桃子:");
    scanf("%d",&n);
    printf("猴子第一天一共摘了%d个桃子。",peach_num(n));
    return 0;
}

long long peach_num(int days){
    if(days==1) return 1;
    else{
        return (peach_num(days-1)+1)*2;
    }
}
