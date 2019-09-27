#include "headers/makeSet.h"

void makeSet(std::string* set){
    int code, rest;
    for(int i=0;i<1296;i++){
        set[i] = "";
        code = i;
        for(int j=0;j<4;j++){
            rest = code%6;
            code = code/6;
            set[i] += char(65 + rest);
        }
    }
}