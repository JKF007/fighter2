#include "battle.h"
#include "assorted.h"
#include <iostream>
#include <stdlib.h>

using std::cout;
using std::cin;

    void battle::addPlayer(entity * newPlayer){
        player = newPlayer;
    };

    void battle::addEnemy(entity * newEnemy){
        enemy = newEnemy;
    };

    int battle::round(){
        player->startRound();

        int action = actionSelect();

        if(action == 1){
            strike (player, enemy);
            if (enemy->isDead()){
                return 1;
            }
        }
        else if (action ==2){
            player->defend();
        }

        strike (enemy, player);

        if(player->isDead()){
            return -1;
        }
        return 0;

    };

    void battle::strike(entity * attacker, entity * defender){

        int attkStr = attacker->getPhyAttk();
        cout << attacker->getCharName()<<" strike at " << defender->getCharName()<<" the " << defender->getClassName() <<".\n";

        int damageDealt = defender->resolveDamage(attkStr);

        cout << attacker->getCharName() <<" dealt "<<damageDealt<<" damage.\n\n";

    };

    int battle::actionSelect(){
         cout <<"1. attack \n"
              <<"2. defend \n";

        string inputStr ="";
        std::getline (cin,inputStr);

        while (!checkRange(inputStr, 1,2)){
           cout <<"invalid input\n";
           std::getline (cin,inputStr);
        }

        return str_toInt(inputStr);
    };

    int battle::targetSelect(){
        return 0;
    };

    bool battle::ready(){
        if (enemy->isDead()){
            return false;
        }

        if(player->isDead()){
            return false;
        }
        return true;
    };
