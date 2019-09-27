
#include "headers/computerIsGuessing.h"

void computerIsGuessing()
{
    int amountOfCodes = 1296, round = 0, i1, i2;
    std::string set[amountOfCodes], currentComputerCode, humanCode, compareCode, currentComputerCodeCopy, setCodeCopy;

    srand(time(NULL));
    
    makeSet(set);
    
    while(true){
        if(amountOfCodes == 0){
            std::cout << "Cos poszlo nie tak, albo sie pomyliles albo oszukiwales celowo :P" << std::endl;
            break;
        }
        round++;
        int numb = rand()%amountOfCodes;
        currentComputerCode = set[numb];
        for(i2 = numb;i2<amountOfCodes-1;i2++){
            set[i2] = set[i2+1];
        }
        amountOfCodes--;
        std::cout << round << ". Czy to ten kod? " << currentComputerCode << " : Pozostalo " << amountOfCodes << std::endl;
        std::getline(std::cin, humanCode);
        if(humanCode == "xxxx")
            break;
        for(i1 = i2 =0;i1<amountOfCodes;i1++){
            compareCode = "";
            currentComputerCodeCopy = currentComputerCode;
            setCodeCopy = set[i1];
            for(int j=0;j<4;j++){
                if(currentComputerCode[j] == setCodeCopy[j]){
                    compareCode += 'x';
                    currentComputerCodeCopy[j] = '*';
                    setCodeCopy[j] = '*';
                }
            }
            for(int j=0;j<4;j++){
                if(setCodeCopy[j] != '*'){
                    for(int z = 0;z<4;z++){
                        if(setCodeCopy[j] ==  currentComputerCodeCopy[z]){
                            compareCode += 'o';
                            currentComputerCodeCopy[z] = '*';
                            break;
                        }
                    }
                }
            }
            if(humanCode == compareCode){
                set[i2] = set[i1];
                i2++;
            }
        }
        amountOfCodes = i2;
    }

    if(humanCode == "xxxx")
        std::cout << "Odgadlem kod w " << round << " rund" << std::endl << std::endl;
}