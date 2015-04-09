#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
#include "entity.h"
#include "battle.h"
#include "assorted.h"

using std::cin;
using std::cout;
using std::vector;
using std::string;

int main(){

    string playerInput;
    int inputInt;

    cout<< "select your class\n";
    cout<< "1. warrior\n";

    std::getline (cin,playerInput);

    while(!checkRange(playerInput,1,1)){
        cout<< "invalid selection \n";
        std::getline (cin,playerInput);
    }

    inputInt = str_toInt(playerInput);

    entity player(inputInt);

    entity enemy(2);

    battle encounter;

    encounter.addPlayer(&player);

    encounter.addEnemy(&enemy);

    while (encounter.ready()){

        cout << player.printFulStats() << "\n";
        cout << enemy.printFulStats() << "\n";
        cout <<"\n";

        encounter.round();
    }

        cout << player.printBatStats() << "\n";
        cout << enemy.printBatStats() << "\n";
/*
    1. attack
    2. defend
    3. magic/skill
    4. item
    5. run*/

    return 1;
};
