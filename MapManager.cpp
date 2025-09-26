#include "MapManager.h"
#include "GameManager.h"
#include "Player.h"
#include <iostream>

Player1 p1;
Player2 p2;


// 길(0): '. '으로 표시
// 벽(1): '# '으로 표시
// 시작점(2): 'S '로 표시
// 출구(3): 'E '로 표시

//미로 프린트 함수 
void PrintMaze(Player1& p1,Player2& p2)
{
    for(int i=0; i < MazeHeight; i++)
    {
        for(int j=0; j < MazeWidth; j++)
        {
            if(i == p1.x1 && j == p1.y1 && i == p2.x2 && j == p2.y2)
            {
                printf("!"); //둘이 겹쳤을떄 
            }
            else if(i == p1.x1 && j == p1.y1)
            {
                printf("P"); //생존자 
            }
            else if(i == p2.x2 && j == p2.y2)
            {
                printf("Z"); //좀비
            }
            else if(Maze[i][j] == 5)
            {
                printf("k"); //생존 키트 //생존자 3개 획득해야함
            }
            else if(Maze[i][j] == 4)
            {
                printf("I"); //아이템
            }
            else if(Maze[i][j] == 3)
            {
                printf("⏏︎"); //탈출구 
            }
            else if(Maze[i][j] == 2)
            {
                printf("S"); //시작점
            }
            else if(Maze[i][j] == 1)
            {
                printf("#"); //벽
            }
            else if(Maze[i][j] == 0)
            {
                printf("."); //길
            }
        }
        printf("\n");
    }
};
