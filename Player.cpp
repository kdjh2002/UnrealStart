#include "Player.h"
#include "MapManager.h"


// -----------------------------------------
// Player1 = 생존자 함수 정의

//입력받은 Move로 좌표 이동하기 
void Player1::Move1(char Player1Move)
{
    //처음위치 1,1
        if(Player1Move == 'a')
        {
            y1--;
        }
        else if(Player1Move == 'd')
        {
            y1++;
        }
        else if(Player1Move == 'w')
        {
            x1--;
        }
        else if(Player1Move == 's')
        {
            x1++;
        }
}

// 생존자 데미지 받음
void Player1::TakeDamage()
{
    HP -= 2.0f;
    if (HP < 0.0f) HP = 0.0f;

    printf("\n[생존자] 좀비와 접촉! HP -2 \n현재 HP: %0.f\n", HP);
}

// 생존자 회복
void Player1::Heal()
{
    HP += 1.0f;
    if (HP > 5.0f) HP = 5.0f;

    printf("\n[생존자] 체력 회복! HP +1\n 현재 HP: %0.f\n", HP);
}

// 생존키트 획득
void Player1::CollectSavekit()
{
    SavekitCounting++;
    printf("\n[생존자] 생존 키트 획득! \n획득 키트 개수: %d\n", SavekitCounting);
}

// 생존키트 개수 반환
int Player1::SaveKitCount()
{
    return SavekitCounting;
}

//턴 돌아올떄마다 프린트되기
void Player1::PlayerPrint()
{
    printf("\n현재 HP : %.0f, 획득 키트 개수: %d\n" , HP, SavekitCounting);
}
// ---------------------------------
  
// Player2 = 좀비 함수 정의

//입력받은 Move로 좌표 이동하기 
void Player2::Move2(char Player2Move)
{
    //처음위치 1,1
        if(Player2Move == 'j')
        {
            y2--;
        }
        else if(Player2Move == 'l')
        {
            y2++;
        }
        else if(Player2Move == 'i')
        {
            x2--;
        }
        else if(Player2Move == 'k')
        {
            x2++;
        }
}

// 좀비 공격력 증가
void Player2::PowerBuff()
{
    Power += 1.0f;
    printf("\n[좀비] 공격력 증가! \nPower: %0.f\n", Power);
}

// 좀비 공격력 감소
void Player2::PowerDown()
{
    Power -= 1.0f;
    if (Power < 1.0f) Power = 1.0f;  // 최소 공격력 제한
    printf("\n[좀비] 공격력 감소! \nPower: %0.f\n", Power);
}

// 좀비 공격
float Player2::Attack()
{
    printf("\n[좀비] 공격! \n현재 공격력: %0.f\n", Power);
    return Power;
}

//턴 돌아올떄마다 프린트되기
void Player2::ZombiePrint()
{
    printf("\n현재 공격력 : %.0f\n" , Power);
}

