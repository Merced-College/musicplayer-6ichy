#include "Playlist.h"

Playlist::Playlist() {
    count = 0;
}

void Playlist::initializeTracks() {
    // Hardcode at least 8 tracks (matches SD card naming 0001.mp3, etc.)
    addTrack(1, "Track One");
    addTrack(2, "Track Two");
    addTrack(3, "Track Three");
    addTrack(4, "Track Four");
    addTrack(5, "Track Five");
    addTrack(6, "Track Six");
    addTrack(7, "Track Seven");
    addTrack(8, "Track Eight");
    Serial.println(F("Playlist populated."));
}

void Playlist::addTrack(int num, String title) {
    if (count < 10) {
        tracks[count] = AudioTrack(num, title);
        count++;
    }
}

void Playlist::listTracks() {
    Serial.println(F("\n--- Current Playlist ---"));
    for(int i = 0; i < count; i++) {
        Serial.print(tracks[i].trackNumber);
        Serial.print(F(". "));
        Serial.println(tracks[i].title);
    }
}

void Playlist::linearSearch(String keyword) {
    Serial.print(F("Searching for: "));
    Serial.println(keyword);
    bool found = false;
    keyword.toLowerCase();

    for(int i = 0; i < count; i++) {
        String currentTitle = tracks[i].title;
        currentTitle.toLowerCase();
        
        if(currentTitle.indexOf(keyword) != -1) {
            Serial.print(F("Found: [Track "));
            Serial.print(tracks[i].trackNumber);
            Serial.print(F("] "));
            Serial.println(tracks[i].title);
            found = true;
        }
    }
    if(!found) Serial.println(F("No matches found."));
}

void Playlist::manualSort() {
    Serial.println(F("Sorting playlist by title (Selection Sort)..."));
    // Selection Sort Algorithm
    for (int i = 0; i < count - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < count; j++) {
            // Compare titles alphabetically
            if (tracks[j].title < tracks[minIdx].title) {
                minIdx = j;
            }
        }
        // Swap AudioTrack objects
        AudioTrack temp = tracks[minIdx];
        tracks[minIdx] = tracks[i];
        tracks[i] = temp;
    }
    Serial.println(F("Sort complete. Type 'list' to see results."));
}