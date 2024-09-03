#ifndef SNAKETILE_H
#define SNAKETILE_H
#include "Tile.h"
class SnakeTile: public Tile{
    public:
    SnakeTile();
    SnakeTile(int);
    int getPenalty() const;
    int findSpot() override;
    private:
    int penalty;
};
SnakeTile::SnakeTile(){
    setTileType('S');
    penalty=3;
}
SnakeTile::SnakeTile(int p){
    setTileType('S');
    penalty=p;
}
int SnakeTile::getPenalty() const{
    return penalty;
}
int SnakeTile::findSpot(){
    int spot=-penalty;
    return spot;
}


#endif //SNKAETILE_H