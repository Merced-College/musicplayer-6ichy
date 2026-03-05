#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include <Arduino.h>
#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

// Required Enum
enum class PlayerState { STOPPED, PLAYING, PAUSED, ERROR };

class AudioPlayer {
private:
    // Required variables
    PlayerState currentState = PlayerState::STOPPED;
    int currentVolume = 15;
    int currentTrack = -1; // -1 means no track selected

    // Hardware objects
    SoftwareSerial* mySerial; 
    DFRobotDFPlayerMini myDFPlayer;

    // Helper to print state whenever it changes
    void setState(PlayerState newState);

public:
    // Constructor: Takes the RX/TX pins for SoftwareSerial
    AudioPlayer(int rx, int tx);

    void init(); // Setup DFPlayer
    
    // Required Control Functions
    void playTrack(int trackNumber);
    void pause();
    void stop();
    void nextTrack();
    void previousTrack();
    void setVolume(int level);
};

#endif