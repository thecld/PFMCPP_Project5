#include <iostream>
#include "Compressor.h"

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

void Compressor::saturateInput(const Saturator& sat)
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
