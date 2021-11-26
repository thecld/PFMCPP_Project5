#pragma once
#include "Compressor.h"
#include "Bakery.h"
#include "House.h"
#include "CompressorRack.h"
#include "Neighborhood.h"

struct Compressor;

struct CompresssorWrapper
{
    CompresssorWrapper(Compressor* comp);
    ~CompresssorWrapper();
    Compressor* compPtr = nullptr;
};

struct BakeryWrapper
{
    BakeryWrapper(Bakery* bakery);
    ~BakeryWrapper();
    Bakery* bakeryPtr = nullptr;
};

struct HouseWrapper
{
    HouseWrapper(House* house);
    ~HouseWrapper();
    House* housePtr = nullptr;
};

struct CompressorRackWrapper
{
    CompressorRackWrapper(CompressorRack* cr);
    ~CompressorRackWrapper();
    CompressorRack* compRackPtr = nullptr;
};

struct NeighborhoodWrapper
{
    NeighborhoodWrapper(Neighborhood* nh);
    ~NeighborhoodWrapper();
    Neighborhood* neighborhoodPtr = nullptr;
};
