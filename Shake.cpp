#include <iostream>
#include <windows.h>

int main()
{
    while (1) {
        HDC hdc = GetDC(0);
        int x = SM_CXSCREEN;
        int y = SM_CYSCREEN;
        int w = GetSystemMetrics(0);
        int h = GetSystemMetrics(1);
        BitBlt(hdc, rand() % 10, rand() % 10, w, h, hdc, rand() % 10, rand() % 10, SRCCOPY);//Shakes You Display A hell lot 
        Sleep(10);
        ReleaseDC(0, hdc);
    }
}
