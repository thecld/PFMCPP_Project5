#pragma once
#include "LeakedObjectDetector.h"
#include "Bakery.h"
#include "House.h"

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
