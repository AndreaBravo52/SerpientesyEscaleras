#ifndef TILE_H
#define TILE_H
class Tile{
    public:
    Tile();
    char getTileType() const;
    void setTileType(char);
    virtual int findSpot();
    private:
    char tileType;
};
Tile::Tile(){
    tileType='N';
}
char Tile::getTileType() const{
    return tileType;
}
void Tile::setTileType (char t){
    tileType=t;
}
int Tile::findSpot(){
    return 0;
}

#endif //TILE_H