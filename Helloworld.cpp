    /*
    연산자 operator
    계산을 하기 위한 기호

    -대입 연산자
    == 같다
    = 오른쪽에 있는 값을 왼쪽에 넣어라
    a = b; //b에 있는 값을 a에 넣어라

    -산술 연산자 : 사칙연산
    + - * /(몫+나머지) %(나머지)

    -복한 대입연산자 : 줄여쓰기용
    a += b; 
    a = a+b; //위와 같은코드

    -증감 연산자
    a++;  a가 하나씩 늘어남
    */

#include <iostream> //입출력 관련(cout)
#include <stdio.h> // stdio.h에 네임스페이스 추가한 래퍼
#include <cstdio> 
#include "header.h"

//using namespace std;

 int main() {
//     printf("helloworld\n"); //c언어 출력방법 
//     printf("김수진");
//     printf("02년생입니다.\n"); //"\n한줄띄기"
//     std::cout << "Hello world first"; //c++ 출력방법 //c언어에 + 객체지향

//     int number; //number이라는 이름을 가진 int 변수를 선언하고 거기에 0을 대입
//     number = 0; //변수에 값을 대입 

//     //int : 정수형(소수점 없는 숫자, 5, 20, -3 ...)
//     number = 5.3; //number에는 5가 저장된다
//     number = 5 / 2; //-> 2.뒤 버림

//     scanf("%d", &number); //숫자를 하나 입력 받기(c)
//     printf("입력한 숫자는(c++) : %d\n", number);

//     std::cin >> number; //숫자를 하나 입력 받기(c++)
//     printf("입력한 숫자는(c++) : %d\n", number);

    int number1 = 0;
    int number2 = 0;
    printf("숫자 1을 입력하시오 : ");
    std::cin >> number1;
    printf("숫자 2을 입력하시오 : ");
    std::cin >> number2;

    int number3 = number1+number2;
    printf("두 숫자의 합은 %d입니다.", number3);

    return 0;
}
