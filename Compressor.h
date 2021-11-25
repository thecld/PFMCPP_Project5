#include "LeakedObjectDetector.h"

struct Compressor
{
    Compressor();
    ~Compressor();
    double threshold { -10.5 };
    float ratio { 4.5f };
    float outputGain { -1.5f };
    float inputGain { -11.0f };
    int compType { 2 };
    std::string name { "compressor" };


    struct Saturator
    {
        Saturator();
        ~Saturator();
        int satType = 0;
        double gain = -10.5;
        float inputFilter = 10000.0f;
        float outputFilter = 1600.5f;
        float mix = 77.7f;

        void changeType(int satType);
        bool checkClipping();
        void oversample(bool oversampling);
        JUCE_LEAK_DETECTOR(Saturator)
    };

    void compress(double audioIn);
    void volumeMakeUp();
    void saturateInput(const Saturator& sat);
    double rampThreshold(double desiredThreshold);

    Saturator satA;
    JUCE_LEAK_DETECTOR(Compressor)
};
