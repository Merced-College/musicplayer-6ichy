#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "AudioTrack.h"

class Playlist {
private:
    AudioTrack tracks[10]; // Minimum 8 required
    int count = 0;

public:
    Playlist();
    void addTrack(int num, String title);
    void listTracks();
    
    // Required Algorithms
    void linearSearch(String keyword);
    void manualSort(); // Implementation: Selection Sort by title
    
    // Helper to populate the list in setup
    void initializeTracks(); 
};

#endif