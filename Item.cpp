#include "Item.h"
#include <iostream>
#include "Player.h"
#include "GameManager.h"
#include <stdlib.h>

void ItemEffect(Player1& p1, Player2& p2, bool p1Turn)
{
    srand(time(NULL));
    int ItemRan = rand() % 6; //0-6

    switch(ItemRan)
    {
        case ZombieDamage:
            p2.PowerDown();
            printf("\n[아이템] 공격력 감소 발동! 좀비 공격력 감소\n");
            break;
        case ZombiePower:
            p2.PowerBuff();
            printf("\n[아이템] 공격력 증가 발동! 좀비 공격력 증가\n");

            break;

        case PlayerHit:
            p1.TakeDamage(); //HP 다운
            printf("\n[아이템] 감염 함정 발동! 생존자 HP 감소\n");
            break;

        case PlayerHeal:
            p1.Heal();
            printf("\n[아이템] 생존자 HP 회복\n");
            break;

        //스킵아이템
        case SkipTurn:
            if (p1Turn)
                printf("\n[아이템] 생존자가 아이템을 밟음 → 좀비는 다음 턴 스킵!\n");
            else
                printf("\n[아이템] 좀비가 아이템을 밟음 → 생존자는 다음 턴 스킵!\n");
            // 여기에 isp1Turn에 따라 skipTurn flag를 설정하면 됨
            break;

        //시작포인트이동 아이템
        case StartPoint:
            if (p1Turn)
            {
                p1.x1 = 1;
                p1.y1 = 1;
                printf("\n[아이템] 생존자가 시작점으로 이동!\n");
            }
            else
            {
                p2.x2 = 13; // 예: 시작위치
                p2.y2 = 33;
                printf("\n[아이템] 좀비가 시작점으로 이동!\n");
            }
            break;
    }

    }
