#pragma once
#include <iostream>
void Position(); //입력받은 move로 좌표 이동하기


// //생존자
// int x1 = 1;
// int y1 = 1;

// //좀비
// int x2 = 23;
// int y2 = 28;

//생존자 클래스 
class Player1
{

public : 

    //속성
    std::string Name = "생존자"; //이름
    float HP = 5.0f; //체력
    int x1 = 1;
    int y1 = 1;

    void Move1(char Player1Move); //이동함수
    void BackMove1(char Player1Move); //벽만났을때 

    
    void TakeDamage(); //좀비접촉 : HP -2 //아이템 : HP -1
    void Heal();    //생존키트 획득 : HP +2 //아이템 : HP +1
    void CollectSavekit(); //생존키트 획득
    int SaveKitCount(); //생존키트 3개 카운팅

    void PlayerPrint(); //현재 생명력 프린트

    int SavekitCounting = 0;
};

class Player2
{
public :
    //속성 
    std::string Name = "좀비";
    float Power = 2.0f;
    int x2 = 8;
    int y2 = 18;
    // int x2 = 1;
    // int y2 = 2; //확인용

    void Move2(char Player2Move); //이동함수
    void BackMove2(char Player2Move); //벽만났을때 


    void PowerBuff(); //아이템 먹으면 +- 1.0f
    void PowerDown(); //아이템 먹으면 - 1.0f
    void ZombiePrint();  //현재공격력 보여주기

    float Attack(); //생존자 접촉하면 -2.0f
};


extern Player1 p1;
extern Player2 p2;