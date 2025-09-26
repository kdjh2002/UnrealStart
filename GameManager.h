#pragma once


//전체 게임 흐름관리

//게임초기화
//메인 게임 루프 실행
//한 명의 턴 처리
//게임 종료 조건 검사
//승리/패배 결과 출력
char Move1; //생존자
char Move2; //좀비

void Text();
void Player(); //게임 진행
bool WinLose(); //게임 종료 조건 검사
