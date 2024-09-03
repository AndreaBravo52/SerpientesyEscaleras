#ifndef PLAYER_H
#define PLAYER_H
class Player{
    public:
    Player();
    Player(int);
    void setTile(int);
    int getTile() const;
    int getNum() const;
    private:
    int num;
    int tile;
};
Player::Player(){
    num=0;
    tile=1;
}
Player::Player(int n){
    num=n;
    tile=1;
}

void Player::setTile(int t){
    tile=t;
}
int Player::getTile() const{
    return tile;
}
int Player::getNum() const{
    return num;
}

#endif //PLAYER_H