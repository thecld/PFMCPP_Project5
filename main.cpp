/*
 Project 5: Part 3 / 4
 video: Chapter 3 Part 4: 

Create a branch named Part3

 the 'new' keyword

 1) add #include "LeakedObjectDetector.h" to main
 
 2) Add 'JUCE_LEAK_DETECTOR(OwnerClass)' at the end of your UDTs.
 
 3) write the name of your class where it says "OwnerClass"
 
 4) write wrapper classes for each type similar to how it was shown in the video
 
 5) update main() 
      replace your objects with your wrapper classes, which have your UDTs as pointer member variables.
      
    This means if you had something like the following in your main() previously: 
*/
#if false
 Axe axe;
 std::cout << "axe sharpness: " << axe.sharpness << "\n";
 #endif
 /*
    you would update that to use your wrappers:
    
 */

#if false
AxeWrapper axWrapper( new Axe() );
std::cout << "axe sharpness: " << axWrapper.axPtr->sharpness << "\n";
#endif
/*
notice that the object name has changed from 'axe' to 'axWrapper'
You don't have to do this, you can keep your current object name and just change its type to your Wrapper class

6) If you have a class that has a nested class in it, and an instantiation of that nested class as a member variable, 
    - you do not need to write a Wrapper for that nested class
    - you do not need to replace that nested instance with a wrapped instance.
    If you want an explanation, message me in Slack

7) If you were using any UDTs as function arguments like this:
*/
#if false
void someMemberFunction(Axe axe);
#endif
/*
  Pass-By-Reference now that you know what references are (Project 6 Part 2).
*/
#if false
void someMemberFunction(Axe& axe);
#endif
/*
If you aren't modifying the passed-in object inside the function, pass by const reference.
*/
#if false
void someMemberFunction(const Axe& axe);
#endif
/*
 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 see here for an example: https://repl.it/@matkatmusic/ch3p04example

 you can safely ignore any warnings about exit-time-destructors.
 if you would like to suppress them, add -Wno-exit-time-destructors to the .replit file 
   with the other warning suppression flags
 */




#include <iostream>
#include <cmath>
#include "LeakedObjectDetector.h"
/*
 copied UDT 1:
 */

struct Compressor
{
    Compressor();
    ~Compressor();
    double threshold { -10.5 };
    float ratio { 4.5f };
    float outputGain { -1.5f };
    float inputGain { -11.0f };
    int compType { 2 };
    std::string name { "compressor" };


    struct Saturator
    {
        Saturator();
        ~Saturator();
        int satType = 0;
        double gain = -10.5;
        float inputFilter = 10000.0f;
        float outputFilter = 1600.5f;
        float mix = 77.7f;

        void changeType(int satType);
        bool checkClipping();
        void oversample(bool oversampling);
        JUCE_LEAK_DETECTOR(Saturator)
    };

    void compress(double audioIn);
    void volumeMakeUp();
    void saturateInput(const Saturator& sat);
    double rampThreshold(double desiredThreshold);

    Saturator satA;
    JUCE_LEAK_DETECTOR(Compressor)
};

struct CompresssorWrapper
{
    CompresssorWrapper(Compressor* comp) : compPtr(comp) {}
    ~CompresssorWrapper()
    {
        delete compPtr;
    }

    Compressor* compPtr = nullptr;
};

Compressor::Compressor()
{
    std::cout << "Compressor constructed." << "\n";
}

Compressor::~Compressor()
{
    std::cout << "Compressor destructed." << "\n";
}

Compressor::Saturator::Saturator()
{
    std::cout << "Nested type Saturator constructed." << "\n";
}

Compressor::Saturator::~Saturator()
{
    std::cout << "Nested type Saturator destructed." << "\n";
}

void Compressor::compress(double audioIn)
{
    if (audioIn > threshold)
    {
        if (compType == 0)
            std::cout << "Compressing with ratio of: " << ratio << " using Peak algorithm." << std::endl << "Threshold is set to: " << threshold << std::endl << "Output gain is set to: " << outputGain << std::endl;
        else
            std::cout << "Compressing with ratio of: " << ratio << " using RMS algorithm." << std::endl << "Threshold is set to: " << threshold << std::endl << "Output gain is set to: " << outputGain << std::endl;
    }
}

void Compressor::volumeMakeUp()
{
    float difference = inputGain - outputGain;
    std::cout << "Adjusting the volume by " << difference << std::endl;
}

void Compressor::saturateInput(const Saturator& sat)
{
    std::cout << "Saturation engaged! Saturator type: " << sat.satType << std::endl << "Mix parameter is set to: " << sat.mix << std::endl;
}

double Compressor::rampThreshold(double desiredThreshold)
{
    if (desiredThreshold < threshold)
    {
        while (threshold >= desiredThreshold)
        {
            std::cout << "Desired threshold is smaller, ramping down threshold: " << threshold << "\n"; 
            threshold -= 0.1;

            if (threshold <= desiredThreshold)
            {
                std::cout << "Procedure completed.\n";
                return threshold;
            }
        }
    }
    else
    {
        while (threshold <= desiredThreshold)
        {
            std::cout << "Desired threshold is bigger, ramping up threshold: " << threshold << "\n";
            threshold += 0.1;

            if (threshold >= desiredThreshold)
            {
                std::cout << "Procedure completed.\n";
                return threshold;   
            }
        }
    }
    std::cout << "Desired threshold is the same as initial threshold." << "\n";
    return threshold;
}

/*
 copied UDT 2:
 */

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

struct BakeryWrapper
{
    BakeryWrapper(Bakery* bakery) : bakeryPtr(bakery) {}
    ~BakeryWrapper()
    {
        delete bakeryPtr;
    }
    Bakery* bakeryPtr = nullptr;
};

Bakery::Bakery() : flourAmount(22.7), numCake(10), numBread(38), numMoney(8392.21f), maxOvenTemp(350), minutesLeft(0), name("bakery")
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

/*
 copied UDT 3:
 */

struct House
{
    House();
    ~House();
    int numWindows;
    float livingRoomSize;
    float roomHeight;
    int numBathRooms;
    float totalFloorSize;
    int roomsToClean;
    std::string name;

    struct Bathroom
    {
        Bathroom();
        ~Bathroom();
        bool shower = true;
        bool bathtub = false;
        int numWindows = 1;
        float mirrorSurface = 1.5f;
        int numTowels = 3;

        void getSteamy();
        void turnWaterOn();
        bool getTowelsState();
        JUCE_LEAK_DETECTOR(Bathroom)
    };

    void provideShelter();
    void provideRest(float sleepQuality);
    bool getDirty(int numPeople, int numAnimals);
    int cleanHouse(int numDirtyRooms, int secondsPerRoom);

    Bathroom bathroomA;

    void printFloorSizeAndDirtnessLevel();
    JUCE_LEAK_DETECTOR(House)
};

struct HouseWrapper
{
    HouseWrapper(House* house) : housePtr(house) {}
    ~HouseWrapper()
    {
        delete housePtr;
    }
    House* housePtr = nullptr;
};

House::House() : numWindows(8), livingRoomSize(31.8f), roomHeight(2.8f), numBathRooms(3), totalFloorSize(155.2f), roomsToClean(0), name("house")
{
    std::cout << "House constructed." << "\n";
}

House::~House()
{
    std::cout << "House destructed." << "\n";
}

House::Bathroom::Bathroom()
{
    std::cout << "Nested type Bathroom constructed." << "\n";
}

House::Bathroom::~Bathroom()
{
    std::cout << "Nested type Bathroom destructed." << "\n";
}

void House::printFloorSizeAndDirtnessLevel()
{
    std::cout << "House totalFlootSize: " << this->totalFloorSize << " House getDirty(): " << this->getDirty(10,25) << "\n";
}

int House::cleanHouse(int numDirtyRooms, int secondsPerRoom)
{
    if (secondsPerRoom > -1)
    {
        int cleaningTimer;
        roomsToClean = numDirtyRooms;
        while (roomsToClean >= 0)
        {
            cleaningTimer = secondsPerRoom;
            while (cleaningTimer > 0 && roomsToClean > 0)
            {
                std::cout << "Cleaning. Rooms left: " << roomsToClean << " | Time left: " << (roomsToClean*secondsPerRoom) - (secondsPerRoom-cleaningTimer) << "s. \n";
                --cleaningTimer;
            }
            if (roomsToClean == 0)
            {
                std::cout << "Cleaning completed. There's " << roomsToClean << " rooms left to clean.\n";
                return roomsToClean;
            }
            --roomsToClean;
        }
    }

    std::cout << "Negative values aren't allowed. Please enter correct value.\n";
    return roomsToClean = 0;
}

void House::provideShelter()
{
    std::cout << "Home sweet home!" << std::endl;
}

void House::provideRest(float sleepQuality)
{
    if (sleepQuality > 3)
        std::cout << "Conratulations, you managed to get rest!" << std::endl;
    else
        std::cout << "Sorry buddy, you'll be sleepy for the rest of the day." << std::endl;
}

bool House::getDirty(int numPeople, int numAnimals)
{
    if (totalFloorSize / (numPeople + numAnimals) < (totalFloorSize * 0.4f))
    {
        std::cout << "There's " << numPeople << " people and " << numAnimals << " animals living on " << totalFloorSize << " square meters. House needs some cleaning!" << "\n";
        return true;
    }

    std::cout << "There's " << numPeople << " people and " << numAnimals << " animals living on " << totalFloorSize << " square meters. House is clean, sweet!" << "\n";
    return false;
}

/*
 new UDT 4:
 with 2 member functions
 */

struct CompressorRack
{
    CompressorRack();
    ~CompressorRack();
    Compressor peakComp;
    Compressor rmsComp;

    void changePowerState(Compressor& a);
    void changeEffectPosition(Compressor& a, Compressor& b);

    JUCE_LEAK_DETECTOR(CompressorRack)
};

struct CompressorRackWrapper
{
    CompressorRackWrapper(CompressorRack* cr) : compRackPtr(cr) {}
    ~CompressorRackWrapper()
    {
        delete compRackPtr;
    }
    CompressorRack* compRackPtr = nullptr;
};

CompressorRack::CompressorRack()
{
    peakComp.name = "Peak compressor";
    rmsComp.name = "RMS compressor";
    std::cout << "CompressorRack constructed!\n"; 
}

CompressorRack::~CompressorRack()
{
    std::cout << "Starting destruction procedure, reseting thresholds.\n";
    peakComp.rampThreshold(0.0);
    rmsComp.rampThreshold(0.0);
    std::cout << "CompressorRack destructed!\n"; 
}

void CompressorRack::changePowerState(Compressor& a)
{
    std::cout << a.name << " -> switching power state.\n";
}

void CompressorRack::changeEffectPosition(Compressor& a, Compressor& b)
{
    std::cout << "Moving " << a.name << " to temporary slot. Moving " << b.name << " to slot slot A. Moving " << a.name << " to slot B.\n";
}

/*
 new UDT 5:
 with 2 member functions
 */

struct Neighborhood
{
    Neighborhood();
    ~Neighborhood();
    House house1A;
    House house1B;
    Bakery bioBakery;

    void activateSprinklers(House&);
    void deliverBread(House&);

    JUCE_LEAK_DETECTOR(Neighborhood)
};

struct NeighborhoodWrapper
{
    NeighborhoodWrapper(Neighborhood* nh) : neighborhoodPtr(nh) {}
    ~NeighborhoodWrapper()
    {
        delete neighborhoodPtr;
    }
    Neighborhood* neighborhoodPtr = nullptr;
};

Neighborhood::Neighborhood()
{
    house1A.name = "First house";
    house1B.name = "Second house";
    bioBakery.name = "Bio bakery";
    std::cout << "Neighborhood constructed!\n";
}

Neighborhood::~Neighborhood()
{
    std::cout << "Let's clean the houses before destructing the neighborhood!\n";
    house1A.cleanHouse(5, 3);
    house1B.cleanHouse(3, 6);
    std::cout << "Neighborhood destructed!\n";
}

void Neighborhood::activateSprinklers(House& a)
{
    std::cout << a.name << " -> Turning on grass sprinklers for 15 minutes!\n";
}

void Neighborhood::deliverBread(House& a)
{
    std::cout << bioBakery.name << " will deliver fresh bread to " << a.name << " soon!\n";
}

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

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
