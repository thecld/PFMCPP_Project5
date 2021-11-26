#include <iostream>
#include "Neighborhood.h"

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
