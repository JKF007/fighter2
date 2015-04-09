#ifndef ENTITY
#define ENTITY

#include <string>
#include <fstream>
#include <cstdlib>

using std::string;

class entity{
    protected:
        string className;
        string characterName;
        int defendDuration;
        int hp;
        int mp;
        int phyAttk;
        int phyDef;
        int tempPAttk;
        int tempPDef;

    public:

        entity();

        entity(int code );

        entity(const string& newName, int newHp, int newMp, int newPAttk, int newPDef);

        entity(const string& fileName );

        int readFile(const string& fileName);

        bool isDead();

        int resolveDamage( const int& attackingPower);

        void startRound();

        void defend();

        string getCharName();
        string getClassName();

        int getHp();

        int getMp();

        int getPhyAttk();

        int getPhyDef();

        string printFulStats();

        string printBatStats();

        void makeWarrior();

        void makeGoblin();

        void makeCiv();
};

#endif
