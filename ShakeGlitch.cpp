#include <windows.h>
#include <stdio.h>

int main (void)
{
HDC hdc = GetDC(NULL);
int w = GetSystemMetrics (0);
int h = GetSystemMetrics (1);
int x =SM_CXSCREEN;
int y= SM_CYSCREEN;

for (;;)
{
BitBlt (hdc,rand()%10,rand()%10,w,h,hdc,rand()%10,rand()%10,0x9999999);
Sleep(10);
}

return 0 ;
}
