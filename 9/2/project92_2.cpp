#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <ctime> //실시간 초 얻기위해 time_t

int main(){
    // //1.printf문 이용하여 *찍어보기
    // printf("  *  \n");
    // printf(" *** \n");
    // printf("*****\n");

    // printf("-----------------\n");

    // //2.printf문 이용하여 미로 찍어보기
    // printf("□□□□□□□□\n");
    // printf("□ □□ □ □\n");
    // printf("□   □  □\n");
    // printf("□□□□□□□□\n");

    // printf("-----------------\n");

    // //3.두 수를 입력받아 스왑하기
    // printf("두 숫자를 입력하세요: ");
    // int a = 0;
    // int b = 0;
    // std::cin >> a;
    // std::cin >> b;

    // int c = a + b;
    // printf("%d, ", a);
    // printf("%d\n", b);

    // printf("-----------------\n");  

    // //4. 사형의 가로, 세로를 입력받아 넓이 출력하기
    // printf("사형의 가로,세로를 입력해 넓이를 알아보기\n");
    // int d = 0;
    // int e = 0;
    // printf("가로를 입력하세요 : ");
    // std::cin >> d;
    // printf("세로를 입력하세요 : ");
    // std::cin >> e;

    // int f = d*e;
    // printf("사형의 넓이는 %d 입니다.\n", f);
    
    // printf("-----------------\n");

    // //5. 두 수를 입력 받아 나머지를 출력하기(%연산자 사용 금지)
    // printf("두 수를 입력 받아 나머지를 출력하기\n");
    // int x = 0;
    // int y = 0;
    // printf("두 수를 입력하세요 : ");
    // std::cin >> x;
    // std::cin >> y;

    // int z = x/y;
    // int w = x-(z*y);
    // printf("나머지는");
    // printf("%d입니다.\n", w);

    // printf("-----------------\n");
    

//     5. 시간 계산기
// - 초를 입력 받아 시분초 출력하기
//1분 = 60초
//1시간 = 60분
    int sec = 0;
    printf("초를 입력하세요 : \n");
    std::cin >> sec;
    int h = sec/3600;
    int hs = (sec%3600);
    int m = hs/60;
    int s = hs%60;
    printf("%d시 %d분 %d초 입니다 \n", h,m,s);

    printf("-----------------\n");

// 6. 동전 개수 계산하기
// - 금액을 입력받아 500원, 100원, 50원, 10원 동전이 각각 몇 개 필요한지 계산하는 프로그램.
// - 금액이 큰 동전을 최대한 많이 받아야 한다.
    printf("돈을 입력하세요\n");
    int money = 0;
    std::cin >> money;
    int m500 = money/500;
    int m100 = (money%500)/100; 
    int m50 = (money%500%100)/50;
    int m10 = (money%500%100%50) /10;

        printf("500원은 %d 개\n", m500);
        printf("100원은 %d 개\n", m100);
        printf("50원은 %d 개\n", m50);
        printf("10원은 %d 개\n", m10);

    printf("-----------------\n");
// 7. 자리수 분리하기(입력은 항상 세자리라고 가정)
// - 수를 입력받고 100의 자리, 10의 자리, 1의 자리를 각각 출력하기
// - 각 자리의 수를 합해서 출력하기

    printf("세자리수를 입력해 자리수를 분리하세요\n");
    int num3 = 0;
    std::cin >> num3;
    int n100 = num3/100;
    int n10 = (num3%100)/10; 
    int n1 = (num3%100%10)/1;

        printf("100의 자리는 %d\n", n100);
        printf("10원은 %d\n", n10);
        printf("1원은 %d\n", n1);







}