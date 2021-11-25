#include <iostream>
#include "House.h"

House::House() : 
    numWindows(8), 
    livingRoomSize(31.8f), 
    roomHeight(2.8f), 
    numBathRooms(3), 
    totalFloorSize(155.2f), 
    roomsToClean(0), 
    name("house")
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
