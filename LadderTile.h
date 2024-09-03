#ifndef LADDERTILE_H
#define LADDERTILE_H
#include "Tile.h"
class LadderTile: public Tile{
    public:
    LadderTile();
    LadderTile(int);
    int getReward() const;
    int findSpot() override;
    private:
    int reward;
};
LadderTile::LadderTile(){
    setTileType('L');
    reward=3;
}
LadderTile::LadderTile(int r){
    setTileType('L');
    reward=r;
}
int LadderTile::getReward() const{
    return reward;
}
int LadderTile::findSpot() {
    int spot=reward;
    return spot;
}

#endif //LADDERTILE_H