#include <iostream>

#include "headers/humanIsGuessing.h"
#include "headers/computerIsGuessing.h"

int main()
{
    int choice;

    while(true)
    {
        std::cout << "Kto bedzie zgadywal kod?" << std::endl;
        std::cout << "1. Komputer" << std::endl;
        std::cout << "2. Czlowiek\n-> ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cin.clear();
            fflush(stdin);
            computerIsGuessing();
            break;

        case 2:
            std::cin.clear();
            fflush(stdin);
            humanIsGuessing();
        }

        std::cout << "Koniec gry. Co teraz ?" << std::endl;
        std::cout << "1. Jeszcze raz" << std::endl;
        std::cout << "2. Koniec gry\n:";
        std::cin >> choice;

        if(choice == 2)
            break;
    }
    
    return 0;
}