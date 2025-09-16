#ifndef COLORS_H_INCLUDED
#define COLORS_H_INCLUDED
#include <conio.h>
#include <stdlib.h>
#include <unistd.h>
#include <chrono>
#include <iomanip>
#include <cmath>
#include "sounds.h"


using namespace std::chrono;

string real_tostring(float num) {
    string value = to_string(num);
    int lung = value.length();
    int point;
    for(int i = 0; i<lung; i++) {
        if (value[i]=='.') {point=i; break;}
    }

    value.erase(point+3, lung-point-3);
    return value;
}

void clearInputBuffer() {
    while (_kbhit()) {
        _getch(); // legge e scarta tutti i tasti ancora nel buffer
    }
}

int getclicks() {


    auto start = high_resolution_clock::now();
    int big_shot=0;
    cout<<"Premi ripetutamente un tasto!!\n\t";
    while(true) {
        auto now = high_resolution_clock::now();
        auto elapsed = duration_cast<milliseconds>(now-start).count();
        cout<<"\r"<<"     "<<flush;
        if(_kbhit()) {
            _getch();
            big_shot++;
        }
        if(elapsed>=1250) {break;}
    }
    playSplat();
    cout<<"\n\n";
    if(big_shot==0) cout<<"Missed!\n";

    return big_shot;
}



void color (int x) {
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon, x);
}

void digita(string sentence) {
    for(int i = 0; i<sentence.length(); i++) {
        cout<<sentence[i];
        if(sentence[i]=='.'||sentence[i]==','||sentence[i]==';'||sentence[i]==':'||sentence[i]=='?'||sentence[i]=='!')
            Sleep(100);
        else
            Sleep(20);
    }
}
void digita(string sentence, bool value) {
    for(int i = 0; i<sentence.length(); i++) {
        cout<<sentence[i];
        if(sentence[i]=='.'||sentence[i]==','||sentence[i]==';'||sentence[i]==':'||sentence[i]=='?'||sentence[i]=='!')
            Sleep(100);
        else
            Sleep(20);    }
    if(value)
        cout<<endl;
}
#endif // COLORS_H_INCLUDED
