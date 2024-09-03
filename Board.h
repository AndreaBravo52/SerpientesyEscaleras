#ifndef BOARD_H
#define BOARD_H
#include "SnakeTile.h"
#include "LadderTile.h"
#include <iostream>
#include <stdlib.h>
class Board{
    public:
    Board();
    Board(int, int, int, int, int);
    int operator +(int);
    void findTileType(int);
    int getBoardSize();
    private:
    Tile *board[50];//numero maximo de casillas para el juego
    int numSnakes;
    int numLadders;
    int boardSize;
    
};
Board::Board(){
    numSnakes=3;
    numLadders=3;
    boardSize=30;
    for (int i=0;i<51;i++){
        board[i]=new Tile;
    }
    board[5]=new SnakeTile;
    board[15]=new SnakeTile;
    board[22]=new SnakeTile;
    board[13]=new LadderTile;
    board[19]=new LadderTile;
    board[26]=new LadderTile;
}
Board::Board(int bs, int sn, int p, int ln, int r){
    boardSize=bs;
    numSnakes=sn;
    numLadders=ln;
        for (int i=0;i<51;i++){
        board[i]=new Tile;
    }
    int placeSnake[sn];
    for (int j=0;j<sn;j++){
        for (int a=0;a<sn;a++){
            int k=rand()% bs;
            placeSnake[a]=k;
        }
         board[placeSnake[j]]=new SnakeTile(p);
     }
    int placeLadder[ln];
    for (int j=0;j<ln;j++){
        for (int a=0;a<ln;a++){
            int k=rand()% bs;
            placeLadder[a]=k;
        }
         board[placeLadder[j]]=new LadderTile(r);
     }
}
int Board::operator +(int i){
    return board[i]->findSpot()+i;//sobrecarga de operador +
}
void Board::findTileType(int i){
    std::cout<<board[i]->getTileType();
}
int Board::getBoardSize(){
    return boardSize;
}


#endif //BOARD_H