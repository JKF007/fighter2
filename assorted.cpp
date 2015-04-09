#include "assorted.h"
#include <sstream>

    string int_toStr(int input){
        std::ostringstream intConverter;

        intConverter <<input;

        return intConverter.str();
    };

    int str_toInt(const string& input){
        std::istringstream stringConverter (input);

        int result;

        stringConverter >>result;

        return result;
    };

    bool isNumeric(const string& input){
        if( input.size() ==0){
            return false;
        }

        for (const char& oneChar : input){

            if (!isdigit(oneChar)){
                return false;
            }
        }
        return true;
    };

    bool checkRange(const string& input, int min, int max){

        if(isNumeric(input)){
            int inputAsInt = str_toInt(input);
            if(min <= inputAsInt && inputAsInt <=max){
                return true;
            }

        }
        return false;
    };
