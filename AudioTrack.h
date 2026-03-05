#ifndef AUDIOTRACK_H
#define AUDIOTRACK_H

#include <Arduino.h>

class AudioTrack {
public:
    int trackNumber;
    String title;

    // Default constructor (needed for arrays)
    AudioTrack() : trackNumber(0), title("Unknown") {}

    // Constructor to set data
    AudioTrack(int num, String t) : trackNumber(num), title(t) {}
};

#endif