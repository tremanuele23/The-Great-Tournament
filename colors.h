#ifndef COLORS_H_INCLUDED
#define COLORS_H_INCLUDED
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <unistd.h>

void color (int x) {
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon, x);
}
#endif // COLORS_H_INCLUDED
