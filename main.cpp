/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.
 
 7) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
 */

//#include <iostream>
//#include <cmath>
//#include "LeakedObjectDetector.h"
#include "CompressorRack.h"
#include "Neighborhood.h"
#include "Wrappers.h"

int main()
{
    CompresssorWrapper compWrapper(new Compressor());
    BakeryWrapper bakeryWrapper(new Bakery());
    HouseWrapper smallHouseWrapper(new House());
    HouseWrapper bigHouseWrapper(new House());


    std::cout << "\n";
    
    compWrapper.compPtr->compress(-4.56);
    compWrapper.compPtr->volumeMakeUp();
    compWrapper.compPtr->saturateInput(compWrapper.compPtr->satA);
    compWrapper.compPtr->rampThreshold(-7.0);
    compWrapper.compPtr->rampThreshold(-1.3);
    
    std::cout << "\n";

    bakeryWrapper.bakeryPtr->bakeBread(bakeryWrapper.bakeryPtr->breadToSell);
    bakeryWrapper.bakeryPtr->sellCake("That cake over there");
    bakeryWrapper.bakeryPtr->smellGreat();
    bakeryWrapper.bakeryPtr->createTimer(13);

    std::cout << "\n";

    smallHouseWrapper.housePtr->totalFloorSize = 80.2f;
    smallHouseWrapper.housePtr->provideShelter();
    smallHouseWrapper.housePtr->provideRest(3.58f);
    smallHouseWrapper.housePtr->getDirty(2, 0);
    smallHouseWrapper.housePtr->cleanHouse(2,28);

    std::cout << "\n";

    bigHouseWrapper.housePtr->totalFloorSize = 280.5f;
    bigHouseWrapper.housePtr->provideShelter();
    bigHouseWrapper.housePtr->provideRest(4.58f);
    bigHouseWrapper.housePtr->getDirty(5, 2);
    bigHouseWrapper.housePtr->cleanHouse(3,9);

    std::cout << "\n";

    CompressorRackWrapper compRackWrapper(new CompressorRack);
    compRackWrapper.compRackPtr->peakComp.threshold = -3.0;
    compRackWrapper.compRackPtr->rmsComp.threshold = -5.0;
    NeighborhoodWrapper neighborhoodWrapper(new Neighborhood);

    std::cout << "\n";

    compRackWrapper.compRackPtr->changePowerState(compRackWrapper.compRackPtr->peakComp);
    compRackWrapper.compRackPtr->changePowerState(compRackWrapper.compRackPtr->rmsComp);
    compRackWrapper.compRackPtr->changeEffectPosition(compRackWrapper.compRackPtr->peakComp, compRackWrapper.compRackPtr->rmsComp);

    std::cout << "\n";

    neighborhoodWrapper.neighborhoodPtr->activateSprinklers(neighborhoodWrapper.neighborhoodPtr->house1A);
    neighborhoodWrapper.neighborhoodPtr->deliverBread(neighborhoodWrapper.neighborhoodPtr->house1B);

    std::cout << "\n";

    std::cout << "bakedBakery.sellCake(): " << bakeryWrapper.bakeryPtr->sellCake("Sweet Cake") << " bakedBakery.numMoney: " << bakeryWrapper.bakeryPtr->numMoney << "\n";
    bakeryWrapper.bakeryPtr->numMoney = 8392.21f;
    bakeryWrapper.bakeryPtr->sellAndGetNumMoney();

    std::cout << "\n";

    std::cout << "smallHouse.totalFlootSize: " << smallHouseWrapper.housePtr->totalFloorSize << " smallHouse.getDirty(): " << smallHouseWrapper.housePtr->getDirty(10,25) << "\n";
    smallHouseWrapper.housePtr->printFloorSizeAndDirtnessLevel();

    std::cout << "\n";

    std::cout << "good to go!" << std::endl;

    std::cout << "\n";
}
