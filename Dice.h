#ifndef DICE_H
#define DICE_H
#include <vector>
#include <stdlib.h>
class Dice {
    public:
    Dice();
    int roll() const;
    private:
    std::vector <int> numberOpt;
};
Dice::Dice(){
    numberOpt={1,2,3,4,5,6};
}
int Dice::roll() const{
    int i;
    i=rand()% 6;
    return numberOpt[i];
}

#endif //DICE_H