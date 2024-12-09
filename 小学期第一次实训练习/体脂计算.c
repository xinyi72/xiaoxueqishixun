
/*
 *任务描述：
 从用户输入中获取身高和体重。然后，我们计算用户的BMI（身体质量指数）, 如果BMI小于18.5 输出“您的体型偏瘦”。如果BMI在18.5到24.9之间，则输出“您的体型正常”；如果BMI在24.9到29.9之间，则输出“您的体型超重”；否则，输出“您的体型肥胖”。
 */

#include <stdio.h>

int main(){
    double height,weight,bmi;
    printf("请输入身高(米)和体重(千克)");
    scanf("%lf%lf",&height,&weight);
    bmi = weight / (height * height);
    if (bmi < 18.5) printf("您的体型偏瘦\n");
    else if (bmi >= 18.5 && bmi < 24.9) printf("您的体型正常\n");
    else if (bmi >= 24.9 && bmi < 29.9)printf("您的体型超重\n");
    else printf("您的体型肥胖\n");
    return 0;

}
