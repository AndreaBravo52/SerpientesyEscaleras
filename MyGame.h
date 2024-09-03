#ifndef MYGAME_H
#define MYGAME_H
#include "Player.h"
#include "Board.h"
#include "Dice.h"
#include <iostream>
#include <string>
#include <stdlib.h>

class MyGame{
    public:
    MyGame();
    MyGame(int, int, int, int, int, int, int,char);
    void start();
    int startGame();
    private:
    Dice dice;
    Player p[5];
    int turnNum;
    int maxTurn;
    char gameType;
    Board tablero;
    int numPlayers;
    int turn(int);
    };

MyGame::MyGame(){
    //constructor para un juego con valores default
    Player p1(1); //crea jugador 1
    p[0]=p1; 
    Player p2(2); //crea jugador 2
    p[1]=p2;
    turnNum=1; //inicia en el turno 1
    maxTurn=40; //numero máximo de turnos
    gameType='M'; //juego tipo manual
    numPlayers=2;
}
MyGame::MyGame(int _numPlayers, int numSnake, int penalty, int numLadder, int reward, int boardSize, int turnLim,char gameT){
    //constructor con parametros definidos por usuario
    for (int i=0; i<_numPlayers; i++){ //loop para crear jugadores
    Player px(i+1);
    p[i]=px;
    }
    Board tableroNuevo(boardSize, numSnake, penalty, numLadder, reward);
    tablero=tableroNuevo;
    turnNum=1;
    maxTurn=turnLim;
    gameType=gameT;
    numPlayers=_numPlayers;
}
void MyGame::start(){
    std::cout<<"To play defaulT game press D, to set parameters press P\n";
    std::string a;
    std::cin>>a;
    while (a!= "D" && a!="P"){
        std::cout<<"Invalid option, please press D to play default game or P to set parameters\n";
        std::cin>>a;}
    if (a=="D"){
        startGame();
    }
    else {
        int _numPlayers, numSnake, penalty, numLadder, reward, boardSize, turnLim;
        std::string gameT;
        std::cout<<"Enter number of players (limit is 5): ";
        std::cin >> _numPlayers;
        while (_numPlayers>5){
            std::cout <<"the limit is 5: ";
            std::cin >>_numPlayers;}
        for (int i=0; i<1;i++){
        std::cout<<"Enter board size (limit is 50): ";
        std::cin >> boardSize;
        try{
            if (boardSize<1||boardSize>50){
                std::string mensaje="Board Size cannot exceed 50";
                throw std::invalid_argument(mensaje);
            }
            break;
        }
        catch (std::invalid_argument &ex){
            std::cerr<<ex.what()<<"\nBoard Size set to default (30)\n";
            boardSize=30;
        }
        }
/*         std::cout<<"Enter board size (limit is 50): ";
        std::cin >> boardSize;
        while (boardSize>50){
            std::cout <<"Board size limit is 50: ";
            std::cin>> boardSize;
        }
 */
        std::cout<<"Enter number of snake tiles: ";
        std::cin >> numSnake;
        while (numSnake>boardSize){
            std::cout<<"number of snake tiles cannot exceed board size: ";
            std::cin>>numSnake;
            }
        std::cout<<"Enter penalty for snake tiles: ";
        std::cin >> penalty;
        std::cout<<"Enter number of ladder tiles: ";
        std::cin >> numLadder;
         while (numLadder>boardSize){
            std::cout<<"number of ladder tiles cannot exceed board size: ";
            std::cin>>numLadder;
            }
        std::cout<<"Enter reward for ladder tiles: ";
        std::cin >> reward;
        std::cout<<"Enter max number of turns: ";
        std::cin >> turnLim;
        std::cout<<"Enter game type M for manual and A for automatic: ";
        std::cin >> gameT;
         while (gameT!="M" && gameT!="A"){
            std::cout <<"invalid option, type M for manual and A for automatic: ";
            std::cin >>gameT;}
            char gameType=gameT[0];
        MyGame ng(_numPlayers,numSnake, penalty, numLadder, reward, boardSize, turnLim, gameType);
          ng.startGame();       
    }
}
int MyGame::startGame(){
    if (gameType=='M'){
        std::cout<<"Press C to continue next turn, or E to end the game:";
        std::string a;
        std::cin>>a;
        while (a!= "C" && a!="E"){
            std::cout<<"Invalid option, please press C to continue next turn or E to end the game";
            std::cin>>a;}
        while (a!="E" && turnNum<maxTurn && p[0].getTile()<tablero.getBoardSize() && p[1].getTile()<tablero.getBoardSize() && p[2].getTile()<tablero.getBoardSize() && p[3].getTile()<tablero.getBoardSize() && p[4].getTile()<tablero.getBoardSize()){
            for(int i=0; i<numPlayers; i++){
                int fin;
                fin=turn(i);
                if (fin==0){
                    return 0;}
            std::cin>>a;
            }
            while (a!= "C" && a!="E"){
                std::cout<<"Invalid option, please press C to continue next turn or E to end the game";
                std::cin>>a;}
            if (a=="E"){
                std::cout<<std::endl<<"--GAME OVER--"<<std::endl;
                 std::cout<<"Thanks for playing!!!"<<std::endl;
                return 0;}
        }
        if (a=="E"||turnNum>=maxTurn){
        std::cout<<std::endl<<"--GAME OVER--"<<std::endl;
        if(turnNum>=maxTurn){
            std::cout<<"The maximum number of turns has been reached..."<<std::endl;
        }
        std::cout<<"Thanks for playing!!!"<<std::endl;
        return 0;
        }
        if (p[0].getTile()<tablero.getBoardSize() && p[1].getTile()<tablero.getBoardSize() && p[2].getTile()<tablero.getBoardSize() && p[3].getTile()<tablero.getBoardSize() && p[4].getTile()<tablero.getBoardSize()){
            Player winner;
            for (int i=0; i<numPlayers;i++){
                if (p[i].getTile()>winner.getTile()){
                    winner=p[i];
                }
            }
            std::cout<<"Player "<<winner.getNum()<<"is the winner.";
            return 0;
        }
    }
    else {
        while (turnNum<maxTurn && p[0].getTile()<tablero.getBoardSize() && p[1].getTile()<tablero.getBoardSize() && p[2].getTile()<tablero.getBoardSize() && p[3].getTile()<tablero.getBoardSize() && p[4].getTile()<tablero.getBoardSize()){
            for(int i=0; i<numPlayers; i++){
                int fin;
                fin=turn(i);
                if (fin==0){return 0;}
            }
        }
        if (turnNum>=maxTurn){
        std::cout<<std::endl<<"--GAME OVER--"<<std::endl;
        std::cout<<"The maximum number of turns has been reached..."<<std::endl;
        std::cout<<"Thanks for playing!!!"<<std::endl;
        return 0;
        }
        if (p[0].getTile()<tablero.getBoardSize() && p[1].getTile()<tablero.getBoardSize() && p[2].getTile()<tablero.getBoardSize() && p[3].getTile()<tablero.getBoardSize() && p[4].getTile()<tablero.getBoardSize()){
            Player winner;
            for (int i=0; i<numPlayers;i++){
                if (p[i].getTile()>winner.getTile()){
                    winner=p[i];
                }
            }
            std::cout<<"Player "<<winner.getNum()<<"is the winner";
            return 0;
        }
    }
    return 0;
    }

int MyGame::turn(int i){
    int die=dice.roll();
    int spot=p[i].getTile()+die;
    std::cout << turnNum <<" " << p[i].getNum() << " " << p[i].getTile() << " " << die << " ";
    tablero.findTileType(spot);
    int newSpot=tablero+spot;//usa sobrecarga de operadores
    p[i].setTile(newSpot);
    if (p[i].getTile()>=tablero.getBoardSize()){
        std::cout<< " " << tablero.getBoardSize() << std::endl <<"--GAME OVER--"<<std::endl<<"Player "<<p[i].getNum()<<" is the winner"<<std::endl;
        return 0;
    }
    else {
        std::cout<<" " << p[i].getTile()<<std::endl;
    turnNum++;}
    return 1;
    }

#endif //MYGAME_H