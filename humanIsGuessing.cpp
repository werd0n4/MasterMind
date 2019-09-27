#include "headers/humanIsGuessing.h"

void humanIsGuessing()
{
    srand(time(NULL));
    std::string secretCode = "",secretCodeCopy, humanGuess, computerOutput;
    int round = 0;
    for(int i = 0;i<4;i++)
    {
        secretCode += char(65 + rand()%6);
    }
    std::cout << secretCode << std::endl;
    while (true)
    {
        round++;
        computerOutput = "";
        secretCodeCopy = secretCode;
        std::cout << round << ". Your guess: ";
        std::cin >> humanGuess;

        for(int i = 0; i<4;i++)
        {
            if(secretCode[i] == humanGuess[i]){
                computerOutput += 'x';
                humanGuess[i] = '*';
                secretCodeCopy[i] = '*';
            }
        }

        for(int i = 0; i<4;i++)
        {
            if(humanGuess[i] != '*'){
                for(int j = 0;j<4;j++){
                    if(humanGuess[i] == secretCodeCopy[j]){
                        computerOutput += 'o';
                        humanGuess[i] = '*';
                        secretCodeCopy[j] = '*';
                        break;
                    }
                }
            }
        }

        std::cout << computerOutput <<std::endl;
        if(computerOutput == "xxxx"){
            std::cout << std::endl;
            std::cout << "Secret code: " << secretCode << std::endl;
            break;
        }
    }

    std::cout << "Zgadles po " << round << " rundach" << std::endl << std::endl; 
}