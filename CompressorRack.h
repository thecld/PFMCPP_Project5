#pragma once
#include "LeakedObjectDetector.h"
#include "Compressor.h"

struct CompressorRack
{
    CompressorRack();
    ~CompressorRack();
    Compressor peakComp;
    Compressor rmsComp;

    void changePowerState(Compressor& a);
    void changeEffectPosition(Compressor& a, Compressor& b);

    JUCE_LEAK_DETECTOR(CompressorRack)
};
