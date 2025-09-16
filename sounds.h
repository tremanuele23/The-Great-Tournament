#ifndef SOUNDS_H_INCLUDED
#define SOUNDS_H_INCLUDED
#include <windows.h>
#include <mmsystem.h>
#include <iostream>
#include <string>
#pragma comment(lib, "winmm.h");

using namespace std;


wstring getExeDir() {
    wchar_t buffer[MAX_PATH];
    GetModuleFileNameW(NULL, buffer, MAX_PATH);

    wstring fullPath = buffer;
    size_t pos = fullPath.find_last_of(L"\\/"); // trova ultima barra
    return fullPath.substr(0, pos);             // prende solo la cartella
}
wstring exeDir = getExeDir();

//SPLAT
void playSplat() {
    wstring splatAudioPath = exeDir + L"\\splat.mp3";
    wstring splatCommand = L"open \""+splatAudioPath+L"\" type mpegvideo alias splat";
    mciSendStringW(splatCommand.c_str(), NULL, 0, NULL);
    mciSendString("play splat from 0", NULL, 0, NULL);
}

//itemUsed
void playItemUsed() {
    wstring itemUsdAudioPath = exeDir + L"\\itemUsed.mp3";
    wstring itemUsdCommand = L"open \""+itemUsdAudioPath+L"\" type mpegvideo alias itemUsed";
    mciSendStringW(itemUsdCommand.c_str(), NULL, 0, NULL);
    mciSendString("play itemUsed from 0", NULL, 0, NULL);
}

#endif // SOUNDS_H_INCLUDED
