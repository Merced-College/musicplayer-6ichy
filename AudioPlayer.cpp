#include "AudioPlayer.h"

AudioPlayer::AudioPlayer(int rx, int tx) {
    mySerial = new SoftwareSerial(rx, tx);
}

void AudioPlayer::init() {
    mySerial->begin(9600);
    if (!myDFPlayer.begin(*mySerial)) {
        Serial.println(F("DFPlayer Error: Check wiring/SD card."));
        setState(PlayerState::ERROR);
        return;
    }
    myDFPlayer.volume(currentVolume);
    setState(PlayerState::STOPPED);
    Serial.println(F("DFPlayer Ready."));
}

void AudioPlayer::setState(PlayerState newState) {
    if (currentState == newState) return;
    currentState = newState;
    
    Serial.print(F(">> Player State changed to: "));
    switch (currentState) {
        case PlayerState::STOPPED: Serial.println(F("STOPPED")); break;
        case PlayerState::PLAYING: Serial.println(F("PLAYING")); break;
        case PlayerState::PAUSED:  Serial.println(F("PAUSED"));  break;
        case PlayerState::ERROR:   Serial.println(F("ERROR"));   break;
    }
}

void AudioPlayer::playTrack(int trackNumber) {
    if (trackNumber < 1 || trackNumber > 30) { // Safety check
        Serial.println(F("Error: Invalid track number."));
        setState(PlayerState::ERROR);
        return;
    }
    myDFPlayer.play(trackNumber);
    currentTrack = trackNumber;
    setState(PlayerState::PLAYING);
}

void AudioPlayer::pause() {
    // REQUIRED LOGIC: Cannot pause if stopped
    if (currentState == PlayerState::STOPPED) {
        Serial.println(F("Invalid Action: Cannot pause when stopped."));
        return;
    }

    if (currentState == PlayerState::PLAYING) {
        myDFPlayer.pause();
        setState(PlayerState::PAUSED);
    } else if (currentState == PlayerState::PAUSED) {
        myDFPlayer.start(); // Resume
        setState(PlayerState::PLAYING);
    }
}

void AudioPlayer::stop() {
    myDFPlayer.stop();
    setState(PlayerState::STOPPED);
}

void AudioPlayer::nextTrack() {
    if (currentTrack == -1) {
        Serial.println(F("Error: Select a track first."));
        return;
    }
    playTrack(++currentTrack);
}

void AudioPlayer::previousTrack() {
    if (currentTrack <= 1) {
        Serial.println(F("Error: No previous track."));
        return;
    }
    playTrack(--currentTrack);
}

void AudioPlayer::setVolume(int level) {
    if (level < 0 || level > 30) {
        Serial.println(F("Error: Volume must be 0-30."));
        return;
    }
    currentVolume = level;
    myDFPlayer.volume(currentVolume);
    Serial.print(F("Volume: ")); Serial.println(currentVolume);
}