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
        BitBlt(hdc, rand() % 50, rand() % 50, w, h, hdc, rand() % 50, rand() % 50, SRCCOPY);//JUST ALTER THE RASTER OPERATIONS FOR MORE FUN :0
        Sleep(10);
        ReleaseDC(0, hdc);
    }
}
