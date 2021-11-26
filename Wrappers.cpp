#include <iostream>
#include "Wrappers.h"


CompresssorWrapper::CompresssorWrapper(Compressor* comp) : compPtr(comp) {}
CompresssorWrapper::~CompresssorWrapper()
{
    delete compPtr;
}

BakeryWrapper::BakeryWrapper(Bakery* bakery) : bakeryPtr(bakery) {}
BakeryWrapper::~BakeryWrapper()
{
    delete bakeryPtr;
}

HouseWrapper::HouseWrapper(House* house) : housePtr(house) {}
HouseWrapper::~HouseWrapper()
{
    delete housePtr;
}

CompressorRackWrapper::CompressorRackWrapper(CompressorRack* cr) : compRackPtr(cr) {}
CompressorRackWrapper::~CompressorRackWrapper()
{
    delete compRackPtr;
}

NeighborhoodWrapper::NeighborhoodWrapper(Neighborhood* nh) : neighborhoodPtr(nh) {}
NeighborhoodWrapper::~NeighborhoodWrapper()
{
    delete neighborhoodPtr;
}
