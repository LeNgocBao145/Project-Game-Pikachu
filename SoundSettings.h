#pragma once
#include "function.h"

//Phat nhac hieu ung khi chien thang
void playWonEffect(bool soundEffect);

void playLoseEffect(bool soundEffect);

//Phat nhac nen
void playMusicBackground(bool soundBackground);

void playMusicRound(bool soundBackground);

void editSoundEffect(bool& sound);

void editMusicBackground(bool& sound);

void editSoundSettings(bool& soundBackground, bool& soundEffect);

int showSoundSettings();