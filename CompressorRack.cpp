#include <iostream>
#include "CompressorRack.h"

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
