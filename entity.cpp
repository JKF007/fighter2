
#include "entity.h"
#include "assorted.h"
#include <string>
#include <iostream>

using std::endl;
using std::cout;

    entity::entity(){
        className = "";
        characterName = "";
        hp = 0;
        mp = 0;
        phyAttk = 0;
        phyDef = 0;


    };
    entity::entity(const string& newName, int newHp, int newMp, int newPAttk, int newPDef){
        className = newName;
        characterName ="john";
        hp = newHp;
        mp = newMp;
        phyAttk = newPAttk;
        phyDef = newPDef;
        tempPDef = phyDef;

    };

    entity::entity(int code ){
       if (code == 1){
        makeWarrior();
       }
       else if (code == 2){
        makeGoblin();
       }
       else{
        makeCiv();
       }


    };

    entity::entity(const string& fileName){
        readFile (fileName);

    };

    int entity::readFile(const string& fileName){
        std::ifstream fileStream (fileName);

        if(fileStream.is_open() && fileStream.good()){

            string fileInput;
            getline(fileStream, fileInput );

            className = fileInput;

            getline(fileStream, fileInput );
            characterName = fileInput;

            getline(fileStream, fileInput );
            hp = atoi(fileInput.c_str());

            getline(fileStream, fileInput );
            mp = atoi(fileInput.c_str());

            getline(fileStream, fileInput );
            phyAttk = atoi(fileInput.c_str());

            getline(fileStream, fileInput );
            phyDef =  atoi(fileInput.c_str());

            tempPDef = phyDef;
        }
        else{
            cout<< "character file not found, creating default character \n";
            makeCiv();
        }
        fileStream.close();
        return 1;

    };

    bool entity::isDead(){

        return ( hp <= 0);

    };

    int entity::resolveDamage(const int& attackingPower){
        int damage = attackingPower - tempPDef;
        if (damage > 0){
            hp = hp - damage;
        }
        return damage;
    };

    void entity::startRound(){

        if(defendDuration >0){
            defendDuration --;
            if(defendDuration ==0){
                cout << getCharName() <<" has stop defending\n\n";
                tempPDef = phyDef;
            }
        }


    };
    void entity::defend(){
        tempPDef = phyDef + (phyDef/4);
        defendDuration ++;
        cout << getCharName()<<" enter into a defensive position, raising his physical defensive by 25%\n\n";
    };

    string entity::getCharName(){
        return characterName;
    };
    string entity::getClassName(){
        return className;
    };
    int entity::getHp(){
        return hp;
    };

    int entity::getMp(){
        return mp;
    };

    int entity::getPhyAttk(){
        return phyAttk;
    };

    int entity::getPhyDef(){
        return phyDef;
    };

    string entity::printFulStats(){
        return  "Name: "+ characterName
                +" Class: "+ className
                +" HP: " + int_toStr(hp)
                +" MP: " + int_toStr(mp)
                +" phyAttk: " + int_toStr(phyAttk)
                +" phyDef: " + int_toStr(phyDef) ;

    };

    string entity::printBatStats(){
        return  "Name: "+ characterName
                +" Class: "+ className
                +" HP: " + int_toStr(hp)
                +" MP: " + int_toStr(mp);
    };



    void entity::makeWarrior(){
        className = "Warrior";
        characterName = "Bob";
        hp = 100;
        mp = 25;
        phyAttk = 10;
        phyDef = 5;
        tempPDef = phyDef;

    };

    void entity::makeGoblin(){
        className = "Goblin";
        characterName = "Dakka";
        hp = 20;
        mp = 0;
        phyAttk = 6;
        phyDef = 0;
        tempPDef = phyDef;
    };

    void entity::makeCiv(){
        className = "Civilian";
        characterName = "john";
        hp = 5;
        mp = 0;
        phyAttk = 1;
        phyDef = 0;
        tempPDef = phyDef;
    };
