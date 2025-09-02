#include <iostream>
#include <stdio.h>
#include <cstdio>
#include "header.h"

//using namespace std;

int main() {
    printf("helloworld\n"); //c언어 출력방법 
    printf("김수진");
    printf("02년생입니다.\n"); //"\n한줄띄기"
    std::cout << "Hello world first"; //c++ 출력방법 //c언어에 + 객체지향

    int number = 0;
    scanf("%d", &number); //숫자를 하나 입력 받고
    printf("입력한 숫자는(c++) : %d\n", number);

    std::cin >> number;
    printf("입력한 숫자는(c++) : %d\n", number);

    return 0;
}
