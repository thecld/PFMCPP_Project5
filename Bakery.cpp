#include <iostream>
#include "Bakery.h"

Bakery::Bakery() : 
    flourAmount(22.7), 
    numCake(10), 
    numBread(38), 
    numMoney(8392.21f), 
    maxOvenTemp(350), 
    minutesLeft(0), 
    name("bakery")
{
    std::cout << "Bakery constructed." << "\n";
}

Bakery::~Bakery()
{
    std::cout << "Bakery destructed." << "\n";
}

Bakery::RyeBread::RyeBread()
{
    std::cout << "Nested type RyeBread constructed." << "\n";
}

Bakery::RyeBread::~RyeBread()
{
    std::cout << "Nested type RyeBread destructed." << "\n";
}

void Bakery::sellAndGetNumMoney()
{
    std::cout << "Bakery sellCake(): " << this->sellCake("Sweet Cake") << " Bakery numMoney: " << this->numMoney << "\n";
}

void Bakery::bakeBread(const RyeBread& brd)
{
    std::cout << "Flour used: " << flourAmount << std::endl << "Timer set to: " << brd.bakingTime << std::endl << "Oven set to: " << maxOvenTemp << std::endl;
}

float Bakery::sellCake(std::string cakeName)
{
    if (cakeName == "Sweet Cake")
    {
        std::cout << "Product sold: " << cakeName << std::endl;
        this->numMoney += 9430.f;
        return 9430.f;
    }

    std::cout << "Product unavailable" << std::endl;
    return 0.f;
}

void Bakery::smellGreat()
{
    std::cout << "Smelling great!" << std::endl;
}

int Bakery::createTimer(int timeAmount)
{
    minutesLeft = timeAmount;
    while (minutesLeft >= 0)
    {
        if (minutesLeft > 1)
        {
            std::cout << "Baking, time left: " << minutesLeft << " minutes.\n";
        }
        else
        {
            if (minutesLeft > 0)
            {
                std::cout << "Baking, time left: " << minutesLeft << " minute.\n";
            }
            else
            {
                std::cout << "Time left: " << minutesLeft << " minutes. Baking completed.\n";
                return minutesLeft;
            }
        }
        --minutesLeft;        
    }
    std::cout << "Invalid input, please insert positive value. Setting timer to 0.\n";
    return minutesLeft = 0;
}
