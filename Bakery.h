#pragma once

#include "LeakedObjectDetector.h"

struct Bakery
{
    Bakery();
    ~Bakery();
    double flourAmount;
    int numCake;
    int numBread;
    float numMoney;
    int maxOvenTemp;
    int minutesLeft;
    std::string name;

    struct RyeBread
    {
        RyeBread();
        ~RyeBread();
        int bakingTime = 45;
        float bakingTemp = 350.0f;
        float numPumpkinSeeds = 5.5f;
        float numLinseed = 2.3f;
        bool bioIngredients = 1;

        void mixIngredients();
        float getWeight(float flourUsed, float numPumpkinSeeds, float numLinseed);
        bool burn(int bakingTime);
        JUCE_LEAK_DETECTOR(RyeBread)
    };

    void bakeBread(const RyeBread& brd);
    float sellCake(std::string cakeName);
    void smellGreat();
    int createTimer(int timeAmount);

    RyeBread breadToSell;

    void sellAndGetNumMoney();
    JUCE_LEAK_DETECTOR(Bakery)
};
