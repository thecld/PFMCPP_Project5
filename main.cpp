/*
Project 5: Part 2 / 4
 video: Chapter 3 Part 1

Create a branch named Part2

 The 'this' keyword
 
 The purpose of this project part is to show you how accessing member variables of objects INSIDE member functions is very similar to accessing member variables of objects OUTSIDE of member functions, via 'this->' and via the '.' operator.
 This project part will break the D.R.Y. rule, but that is fine for the purpose of this project part.
 
 
 1) if you don't have any std::cout statements in main() that access member variables of your U.D.Ts
         write some.
    You can copy some from your Project3's main() if needed.
 
 2) For each std::cout statement in main() that accessed member variables of your types or printed out the results of your member function calls,
        a) write a member function that prints the same thing out, but uses the proper techniques inside the member functions to access the same member variables/functions.
        b) be explicit with your use of 'this->' in those member functions so we see how you're accessing/calling those member variables and functions *inside*
        c) call that member function after your std::cout statement in main.
        d) you should see 2 (almost) identical messages in the program output for each member function you add:
            one for the std::cout line, and one for the member function's output
 
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 */

/*
 example:
 */
#include <iostream>
namespace Example
{
    //a User-Defined Type
    struct MyFoo
    {
        MyFoo() { std::cout << "creating MyFoo" << std::endl; }
        ~MyFoo() { std::cout << "destroying MyFoo" << std::endl; }
        
		// 2a) the member function whose function body is almost identical to the std::cout statement in main.
        // even though I chose the name 'memberFunc' for this function, you should NAME THINGS WHAT THEY ARE OR WHAT THEY DO.
        void memberFunc() 
        { 
            // 2b) explicitly using 'this' inside this member function.
            std::cout << "MyFoo returnValue(): " << this->returnValue() << " and MyFoo memberVariable: " << this->memberVariable << std::endl; 
        }  
        
        int returnValue() { return 3; }
        float memberVariable = 3.14f;

        /*
        note: the example functions are implemented in-class, and the ctor/dtor show the curly braces on the same line as the function declaration.
        Do not do this.  Follow the instructions and coding style for the course.
        */
    };
    
    int main()
    {
        //an instance of the User-Defined Type named mf
        MyFoo mf;
        
        // 1) a std::cout statement that uses mf's member variables
        std::cout << "mf returnValue(): " << mf.returnValue() << " and mf memberVariable: " << mf.memberVariable << std::endl; 
        
        // 2c) calling mf's member function.  the member function's body is almost identical to the cout statement above.
        mf.memberFunc();
        return 0;
    }
}

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
    };

    void bakeBread(RyeBread brd);
    float sellCake(std::string cakeName);
    void smellGreat();
    int createTimer(int timeAmount);

    RyeBread breadToSell;

    void sCNB();
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

void Bakery::sCNB()
{
    std::cout << "Bakery sellCake(): " << this->sellCake("Sweet Cake") << " Bakery numBread: " << this->numBread << "\n";
}

void Bakery::bakeBread(RyeBread brd)
{
    std::cout << "Flour used: " << flourAmount << std::endl << "Timer set to: " << brd.bakingTime << std::endl << "Oven set to: " << maxOvenTemp << std::endl;
}

float Bakery::sellCake(std::string cakeName)
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
    };

    void provideShelter();
    void provideRest(float sleepQuality);
    bool getDirty(int numPeople, int numAnimals);
    int cleanHouse(int numDirtyRooms, int secondsPerRoom);

    Bathroom bathroomA;

    void tFSGD();
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

void House::tFSGD()
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

    void changePowerState(Compressor a);
    void changeEffectPosition(Compressor a, Compressor b);

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

void CompressorRack::changePowerState(Compressor a)
{
    std::cout << a.name << " -> switching power state.\n";
}

void CompressorRack::changeEffectPosition(Compressor a, Compressor b)
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

    void activateSprinklers(House);
    void deliverBread(House);
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

void Neighborhood::activateSprinklers(House a)
{
    std::cout << a.name << " -> Turning on grass sprinklers for 15 minutes!\n";
}

void Neighborhood::deliverBread(House a)
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
    bakedBakery.sellCake("That cake over there");
    bakedBakery.smellGreat();
    bakedBakery.createTimer(13);

    std::cout << "\n";

    smallHouse.totalFloorSize = 80.2f;
    smallHouse.provideShelter();
    smallHouse.provideRest(3.58f);
    smallHouse.getDirty(2, 0);
    smallHouse.cleanHouse(2,28);

    std::cout << "\n";

    bigHouse.totalFloorSize = 280.5f;
    bigHouse.provideShelter();
    bigHouse.provideRest(4.58f);
    bigHouse.getDirty(5, 2);
    bigHouse.cleanHouse(3,9);

    std::cout << "\n";

    CompressorRack rackA;
    rackA.peakComp.threshold = -3.0;
    rackA.rmsComp.threshold = -5.0;
    Neighborhood neighborhoodA;

    std::cout << "\n";

    rackA.changePowerState(rackA.peakComp);
    rackA.changePowerState(rackA.rmsComp);
    rackA.changeEffectPosition(rackA.peakComp, rackA.rmsComp);

    std::cout << "\n";

    neighborhoodA.activateSprinklers(neighborhoodA.house1A);
    neighborhoodA.deliverBread(neighborhoodA.house1B);

    std::cout << "\n";

    std::cout << "bakedBakery.sellCake(): " << bakedBakery.sellCake("Sweet Cake") << " bakedBakery.numBread: " << bakedBakery.numBread << "\n";
    bakedBakery.sCNB();

    std::cout << "\n";

    std::cout << "smallHouse.totalFlootSize: " << smallHouse.totalFloorSize << " smallHouse.getDirty(): " << smallHouse.getDirty(10,25) << "\n";
    smallHouse.tFSGD();

    std::cout << "\n";

    std::cout << "good to go!" << std::endl;

    std::cout << "\n";
}
