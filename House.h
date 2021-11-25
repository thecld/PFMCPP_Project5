#include "LeakedObjectDetector.h"

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
