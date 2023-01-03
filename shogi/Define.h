#ifndef DEFINE_H
#define DEFINE_H

#include<time.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#define chessB(piece)"\033[1;34m"#piece"\033[0m"//藍棋
#define chessR(piece)"\033[1;31m"#piece"\033[0m"//紅棋
#define coordin(piece)"\033[32m"#piece"\033[0m"//棋盤座標
#define coordinn(piece)"\033[33m"#piece"\033[0m"//駒台座標
#define line(piece)"\033[37m"#piece"\033[0m"//格線
#define cell(piece)"\033[8;30;40m"#piece"\033[0m"//空格
#define welcome(word)"\033[4;30;43m"#word"\033[0m"
#define min(i, j) (((i) < (j)) ? (i) : (j))//小的
#define max(i, j) (((i) > (j)) ? (i) : (j))//大的
#include <ev.h>
//定義變數
char input;
int xi,yi;//棋子
int xj,yj;//位置
int turn = -1;
bool chessSign = 1;
bool loadingsign = 1;
bool isStandard = 1;
bool GameOverSign = 1;
bool restart = 0;
bool skip = 0;
char tophandfile[1000];
char boardfile[1500];
char bothandfile[1000];
ev_timer time_watcher;
ev_io io_watcher;
time_t t1 = 0, t2 = 0;
char *board[10][10];
char *tophand[3][14];
char *bothand[3][14];
char *record = "我是大便";
char *record2 = "[紅]違反遊戲規則請重新輸入";
char *record3 = "[藍]違反遊戲規則請重新輸入";
int num1 = 0;

struct board_save{     //儲存  
    //把棋盤和駒台存起來
    char *saved_tophand[3][14];
    char *saved_board[10][10];
    char *saved_bothand[3][14];
    //輪轉紀錄
    int saved_red_or_blue;
    //左右指標
    struct board_save *left, *right;    
};
typedef struct board_save board_save;
board_save *list;
//函式
void boardbuilding();
void printboard();
int red_or_blue(int x,int y);
int tophandchek(int x,int y);
int bothandchek(int x,int y);
int blueMove(FILE *fptr);
int redMove(FILE *fptr);
int upgrade();
int captive(int x,int y);
int Turn_blueenemies_into_friends();
int Turn_redenemies_into_friends();
void rules_of_chesspieces();
void is_Gameover();
void LoadingLine();
board_save *Back(board_save *list, int turn);
board_save *Next(board_save *list, int turn);
void SavedBoard(board_save *list, int turn);
board_save *CreateSavedBoard(board_save *list);
char Turn_to_Symbol_bothand(int i,int j);
char Turn_to_Symbol_tophand(int i,int j);
char Turn_to_Symbol_board(int i,int j);
char *Turn_to_word_tophand(char tophandfile);
char *Turn_to_word_bothand(char bothandfile);
char *Turn_to_word_board(char boardfile);

static void timer_cb(EV_P_ ev_timer *w, int revents);
static void io_cb(EV_P_ ev_io *w, int revents);
void timemain();

#endif