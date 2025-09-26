#include "GameManager.h"
#include "Player.h"
#include "MapManager.h"
#include "Item.cpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

// 미로 탈출 게임 만들기
// 2차원 배열을 활용하여 텍스트 기반 미로 탈출 게임을 구현.
// 미로의 구성
// 10행 20열의 2차원 배열
// 저장 방식

void Text()
{
    printf("===== 좀비를 피해 탈출하라 ====\n");
    printf("생존자는 좀비를 피해 생존키트 3개를 획득하여 탈출하여라\n");
    printf("좀비는 탈출하는 생존자를 감염시켜라\n");
    printf("생존자[P], 좀비[Z], 탈출구[⏏︎], 아이템[I], 키트[k]\n");
    printf("승리에 도움을 주는 아이템[I]을 활용하라\n");
    printf("생존자 : w(↑) s(↓) a(←) d(→)\n");
    printf("좀비 : i(↑) k(↓) j(←) l(→)\n");
}

//주사위 길이 검증하기
bool RandomDice(int& Dice, const std::string& moveInput)
{
    if(moveInput.length() != Dice)
    {
    printf("\n입력한 방향 개수가 맞지않습니다! 다시 입력해주세요\n");
    return false;
    }
    return true;

}



//게임 종료 조건검사 
bool WinLose(Player1& p1)
{
    //1. 생존자 HP 0 이하
    //생존자 패배 조건 //좀비 승리
    if(p1.HP <= 0.0f) 
    {
        printf("\n생존자의 HP가 0입니다.\n축하합니다 ! 좀비가 승리했습니다!\n");
        return true;
    }

    //2. 생존자 키트3개 모아 탈출구 이동
    if(p1.SaveKitCount() >= 3 && Maze[p1.x1][p1.y1] == 3) 
    {
        printf("\n생존자가 생존키트 3개를 모아 탈출구에 도착했습니다.\n축하합니다! 생존자가 승리했니다.\n");
        return true;
    }

    return false;

}


void Player()
{

    std::string AllMove1; //생존자
    std::string AllMove2; //좀비

    Player1 p1;
    Player2 p2;

    Text(); //텍스트 보여주기
    
    //승리함수가 True 할떄까지 돌리기 
    while(WinLose(p1) != true)
    {
        //생존자 턴 //벽에 부딛혔을때
        while(true)
        {
            printf("\n");

            printf("[미로 화면 출력]\n");
            PrintMaze(p1,p2); //한번 보여주기 
            printf("\n[생존자 턴]");
            p1.PlayerPrint();
            
            //주사위 랜덤
            srand(time(NULL));
            int Dice = rand() % 6 + 1; //1-6랜덤
            printf("🎲 주사위를 굴렸습니다. %d칸 이동 가능\n", Dice);

            while(true)
            {
            printf("이동할 방향을 선택하세요 (w, s, a, d): ");
            std::cin >> AllMove1; //입력받기

            //주사위 이동길이 확인
            //입력수와 이동수 동일 확인
            if(!RandomDice(Dice, AllMove1)) continue;

            int prevX1 = p1.x1; //이동전 위치x
            int prevY1 = p1.y1; //이동전 위치y

            bool HitWall = false; //아직 벽 안부딛힘


            for(int i = 0; i<AllMove1.length(); i++)
            {      
                char Move1 = AllMove1[i];
                p1.Move1(Move1); //하나씩 이동시키기


                    if(Maze[p1.x1][p1.y1] == 1) //벽에 부딛힐때
                    {  
                        printf("\n벽에 부딛혔습니다!! 다시 입력해주세요\n");

                        p1.x1 = prevX1; //되돌리기
                        p1.y1 = prevY1;
                         
                        HitWall = true;
                        break;

                    }
            }
            if(HitWall) continue; //다시 입력
                    
            break; //안쪽 while//벽 없 //잘 이동
            }

            break; //생존자 턴 While 종료 //좀비 턴
        }

            //아이템 검사
            if(Maze[p1.x1][p1.y1] == 4)
            {
                ItemEffect(p1, p2, true);   //생존자 아이템 획득
                Maze[p1.x1][p1.y1] = 0; //아이템 사라짐
            }
            else if(Maze[p1.x1][p1.y1] == 5)
            {
            
                p1.CollectSavekit(); //SaveKit++  //3개 되면 종료
                Maze[p1.x1][p1.y1] = 0;
            }

        // 좀비랑 만나면 피해
            if (p1.x1 == p2.x2 && p1.y1 == p2.y2)
            {
                p1.TakeDamage();
            }

        //좀비턴 전에 승리
        if (WinLose(p1)) break;

    // 좀비 턴 //벽만났을떄
    while(true)
    {
        printf("\n");
        printf("[미로 화면 출력]\n\n");
        PrintMaze(p1,p2);
        printf("\n[좀비 턴]");
        p2.ZombiePrint();

        //주사위 랜덤
        srand(time(NULL));
        int Dice = rand() % 6 + 1; //1-6랜덤
        printf("🎲 주사위를 굴렸습니다. %d칸 이동 가능\n", Dice);

        while(true)
        {
        printf("이동할 방향을 선택하세요 (w, s, a, d): ");
        std::cin >> AllMove2; //입력받기

        //주사위 이동길이 확인
        //입력수와 이동수 동일 확인
        if(!RandomDice(Dice, AllMove2)) continue;

        int prevX2 = p2.x2; //이동전 위치x
        int prevY2 = p2.y2; //이동전 위치y


        bool HitWall = false; //아직 벽 안부딛힘


            for(int i = 0; i<AllMove2.length(); i++)
            {      
                char Move2 = AllMove2[i];
                p2.Move2(Move2); //하나씩 이동시키기

               if (Maze[p2.x2][p2.y2] == 1)
                {
                printf("\n벽입니다! 다시 입력해주세요\n");

                p2.x2 = prevX2; //되돌리기
                p2.y2 = prevY2;


                    HitWall = true;
                    break;
                }
            }
            if(HitWall) continue; //다시 입력
            break; //안쪽 while//벽 없 //잘 이동
        }
        break; //좀비 턴 While 종료 //좀비 턴
    }

            if (Maze[p2.x2][p2.y2] == 4)
            {
                ItemEffect(p1, p2, false); // 좀비가 아이템 위
                Maze[p2.x2][p2.y2] = 0;
            }



        //생존자와 만났을떄 
            if (p1.x1 == p2.x2 && p1.y1 == p2.y2)
            {
                p1.TakeDamage();
            }

        if (WinLose(p1)) break;

    }

    
    printf("======게임종료=======");
}
