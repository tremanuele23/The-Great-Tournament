#ifndef COLORS_H_INCLUDED
#define COLORS_H_INCLUDED
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <string>
using namespace std;
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
            Sleep(15);
    }
}
void digita(string sentence, bool value) {
    for(int i = 0; i<sentence.length(); i++) {
        cout<<sentence[i];
        if(sentence[i]=='.'||sentence[i]==','||sentence[i]==';'||sentence[i]==':'||sentence[i]=='?'||sentence[i]=='!')
            Sleep(100);
        else
            Sleep(15);    }
    if(value)
        cout<<endl;
}
#endif // COLORS_H_INCLUDED
