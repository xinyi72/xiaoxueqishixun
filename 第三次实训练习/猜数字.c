#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void guess(int inputnum[]);
void judge(int a[], int b[], int c[]);
int main(){
    int a[4];//随机生成的四个数字
    int c[2], b[4] = {0};//一个是存储对了几个的一个是存储用户输入的；
    int n, i;
    srand(time(NULL));
    do{
        a[0] = rand() % 10;
        a[1] = rand() % 10;
        a[2] = rand() % 10;
        a[3] = rand() % 10;
    }while (a[0] == a[1] || a[0] == a[2] || a[0] == a[3] || a[1] == a[2] || a[1] == a[3] || a[2] == a[3]);
    for(int j =0;j<4;j++){
    	printf("%d",a[j]);
	}
	printf("请输入你想玩几次：");
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        c[0] = 0;
        c[1] = 0;
        printf("请输入猜测的数字(一位一位的输入):");
        for (int i = 0; i < 4; i++) {
            scanf("%d", &b[i]);
        }

        //guess(b);
        judge(a, b, c );
        if (c[0] == 4) {
            printf("恭喜你猜对了!");
            break;
        } else if (c[0] != 4)
            printf("%dA%dB\n", c[0], c[1]);
        if (i == n) {
            printf(" 很遗憾,你没有猜对正确的数字!\n");
            printf("这个数字是:");
            for (int j = 0; j < 4; j++)
                printf("%d", a[j]);
        }
    }
}

//void guess(int b[]) {
//    printf("请输入猜测的数字(一位一位的输入):");
//    for (int i = 0; i < 4; i++) {
//        scanf("%d", &b[i]);
//    }
//}

void judge(int a[], int b[], int c[]) {

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (a[i] == b[j] && i == j)
                c[0]++;
            else if (a[i] == b[j] && i != j)
                c[1]++;
        }
    }
}
