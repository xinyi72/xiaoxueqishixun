#include "stdio.h"
#include "time.h"
#include "stdlib.h"
//骰子游戏：电脑玩家和游戏玩家依次投掷骰子，最后统计谁的分数多谁就获胜。游戏不结束规则：玩家，电脑玩家的分数都小于30分
int touzi();
int main(){
    int times=1;//第几轮
    srand(time(NULL));
    int player_score=0;//玩家的得分统计
    int computer_score=0;//电脑的得分统计
    int num=1;
    printf("欢迎你来到这个游戏！\n");
    printf("游戏规则：玩家和电脑轮流投骰子，每次投掷的点数就是本轮的得分!\n");
    while(player_score<30&&computer_score<30){

        printf("现在是第%d轮\n",times);
        if(num==1){
            int a;
            a=touzi();
            printf("玩家投掷出了%d点\n",a);
            player_score+=a;
            num=2;//更换投的人

        }
        else{
            int b=touzi();
            printf("电脑投掷出了%d点\n",b);
            computer_score+=b;
            num=1;
        }
        times+=1;
    }
    printf("玩家得分是%d\n",player_score);
    printf("电脑得分是%d\n",computer_score);
    if(player_score>computer_score)printf("恭喜玩家获胜！\n");
    else printf("恭喜电脑获胜！");
    return 0;

}
int touzi(){
    return rand() %6+1;
}
