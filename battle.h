#ifndef BATTLE
#define BATTLE
#include "entity.h"


class battle{
    private:
        int playerCount;
        int enemyCount;

        entity * player;

        entity * enemy;

        int actionSelect();

        int targetSelect();

    public:

        void addPlayer(entity * newPlayer);

        void addEnemy(entity * newEnemy);

        int round();

        void strike(entity * attacker, entity * defender);

        bool ready();

};

#endif
