struct CompresssorWrapper
{
    CompresssorWrapper(Compressor* comp) : compPtr(comp) {}
    ~CompresssorWrapper()
    {
        delete compPtr;
    }

    Compressor* compPtr = nullptr;
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

struct HouseWrapper
{
    HouseWrapper(House* house) : housePtr(house) {}
    ~HouseWrapper()
    {
        delete housePtr;
    }
    House* housePtr = nullptr;
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

struct NeighborhoodWrapper
{
    NeighborhoodWrapper(Neighborhood* nh) : neighborhoodPtr(nh) {}
    ~NeighborhoodWrapper()
    {
        delete neighborhoodPtr;
    }
    Neighborhood* neighborhoodPtr = nullptr;
};
