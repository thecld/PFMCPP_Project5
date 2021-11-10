/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12

 Create a branch named Part1

Purpose:  This project continues developing Project3.
       you will learn how to take code from existing projects and migrate only what you need to new projects
       you will learn how to write code that doesn't leak as well as how to refactor. 

 Destructors
        
 
 
 1) Copy 3 of your user-defined types (the ones with constructors and for()/while() loops from Project 3) here
    Choose the classes that contained nested classes.  Include the nested classes when you copy them over.

 2) move all of your implementations of all functions to OUTSIDE of the class.

 3) add destructors
        make the destructors do something like print out the name of the class.

 4) add 2 new UDTs that use only the types you copied above as member variables.

 5) add 2 member functions that use your member variables to each of these new UDTs

 6) Add constructors and destructors to these 2 new types that do stuff.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 7) copy over your main() from the end of Project3 
        get it to compile with the types you copied over.
        remove any code in main() that uses types you didn't copy over.
 
 8) Instantiate your 2 UDT's from step 4) in the main() function at the bottom.
       call their member functions.
 
 9) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.

 you can resolve any [-Wdeprecated] warnings by adding -Wno-deprecated to list of compiler arguments in the .replit file. all of the "-Wno" in that file are compiler arguments.

 */
#include <iostream>
#include <cmath>
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
    int compType = 2;

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
    };

    void compress(double audioIn);
    void volumeMakeUp();
    void saturateInput(Saturator sat);
    double rampThreshold(double desiredThreshold);

    Saturator satA;
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

void Compressor::saturateInput(Saturator sat)
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
    };

    void bakeBread(RyeBread brd);
    float cakeSell(std::string cakeName);
    void smellGreat();
    int minuteTimer(int timeAmount);

    RyeBread breadToSell;
};

Bakery::Bakery() : flourAmount(22.7), numCake(10), numBread(38), numMoney(8392.21f), maxOvenTemp(350), minutesLeft(0)
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

void Bakery::bakeBread(RyeBread brd)
{
    std::cout << "Flour used: " << flourAmount << std::endl << "Timer set to: " << brd.bakingTime << std::endl << "Oven set to: " << maxOvenTemp << std::endl;
}

float Bakery::cakeSell(std::string cakeName)
{
    if (cakeName == "Sweet Cake")
    {
        std::cout << "Product sold: " << cakeName << std::endl;
        return 9430.f;
    }

    std::cout << "Product unavailable" << std::endl;
    return 0.f;
}

void Bakery::smellGreat()
{
    std::cout << "Smelling great!" << std::endl;
}

int Bakery::minuteTimer(int timeAmount)
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
        bool towelsState();
    };

    void provideShelter();
    void provideRest(float sleepQuality);
    bool getDirty(int numPeople, int numAnimals);
    int cleaningProcedure(int numDirtyRooms, int secondsPerRoom);

    Bathroom bathroomA;
};

House::House() : numWindows(8), livingRoomSize(31.8f), roomHeight(2.8f), numBathRooms(3), totalFloorSize(155.2f), roomsToClean(0)
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

int House::cleaningProcedure(int numDirtyRooms, int secondsPerRoom)
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

    void effectPowerSwitch(Compressor a);
    void changeEffectPosition(Compressor a, Compressor b);

};

CompressorRack::CompressorRack()
{
    std::cout << "CompressorRack constructed!\n"; 
}

CompressorRack::~CompressorRack()
{
    std::cout << "Starting destruction procedure, reseting thresholds.\n";
    peakComp.rampThreshold(0.0);
    rmsComp.rampThreshold(0.0);
    std::cout << "CompressorRack destructed!\n"; 
}

void CompressorRack::effectPowerSwitch(Compressor a)
{
    std::cout << a << " -> switching power state.\n";
}

void CompressorRack::changeEffectPosition(Compressor a, Compressor b)
{
    std::cout << "Moving " << a << " to temporary slot. Moving " << b << " to slot slot A. Moving " << a << " to slot B.\n";
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

    void grassSprinklers(House);
    void deliverBread(House);
};

Neighborhood::Neighborhood()
{
    std::cout << "Neighborhood constructed!\n";
}

Neighborhood::~Neighborhood()
{
    std::cout << "Let's clean the houses before destructing the neighborhood!\n";
    house1A.cleaningProcedure(5, 3);
    house1B.cleaningProcedure(3, 6);
    std::cout << "Neighborhood destructed!\n";
}

void Neighborhood::grassSprinklers(House a)
{
    std::cout << a << " -> Turning on grass sprinklers for 15 minutes!\n";
}

void Neighborhood::deliverBread(House a)
{
    std::cout << bioBakery << "will deliver freash bread to " << a << " soon!\n";
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
    Compressor compA;
    Bakery bakedBakery;
    House smallHouse;
    House bigHouse;

    std::cout << "\n";
    
    compA.compress(-4.56);
    compA.volumeMakeUp();
    compA.saturateInput(compA.satA);
    compA.rampThreshold(-7.0);
    compA.rampThreshold(-1.3);
    
    std::cout << "\n";

    bakedBakery.bakeBread(bakedBakery.breadToSell);
    bakedBakery.cakeSell("That cake over there");
    bakedBakery.smellGreat();
    bakedBakery.minuteTimer(13);

    std::cout << "\n";

    smallHouse.totalFloorSize = 80.2f;
    smallHouse.provideShelter();
    smallHouse.provideRest(3.58f);
    smallHouse.getDirty(2, 0);
    smallHouse.cleaningProcedure(2,28);

    std::cout << "\n";

    bigHouse.totalFloorSize = 280.5f;
    bigHouse.provideShelter();
    bigHouse.provideRest(4.58f);
    bigHouse.getDirty(5, 2);
    bigHouse.cleaningProcedure(3,9);

    std::cout << "\n";

    CompressorRack rackA;
    rackA.peakComp.threshold = -3.0;
    rackA.rmsComp.threshold = -5.0;
    Neighborhood neighborhoodA;

    /*rackA.effectPowerSwitch(peakComp);
    rackA.effectPowerSwitch(rmsComp);
    rackA.changeEffectPosition(peakComp, rmsComp);*/

    std::cout << "\n";

    std::cout << "good to go!" << std::endl;

    std::cout << "\n";
}
