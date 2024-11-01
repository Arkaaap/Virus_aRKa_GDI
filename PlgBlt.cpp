#include <Windows.h>


int main()
{
	FreeConsole();
	HDC hWindow;
	HDC hDsktp;
	HWND hWnd;
	RECT wRect;
	int dX = 0, dY = 0, dW, dH;
    POINT wPt[3];
    
    wPt[0].x = 0;
    wPt[0].y = 0;
    wPt[1].x = 0;
    wPt[1].y = 0;
    wPt[2].x = 0;
    wPt[2].y = 0;
    int i;
    for (i = 0 ;i<100;i++)
    {
    	hWnd = GetForegroundWindow();
    	hWindow = GetWindowDC(hWnd);
    	hDsktp = GetDC(0);
    	GetWindowRect(hWnd, &wRect);
    	
    	dW = GetSystemMetrics(SM_CXSCREEN); // = GetDeviceCaps(hWindow, HORZRES)
    	dH = GetSystemMetrics(SM_CYSCREEN); // = GetDeviceCaps(hWindow, VERTRES)
    	
    	wPt[0].x = wRect.left - 10;
    	wPt[0].y = wRect.top - 10;
    	wPt[1].x = wRect.right + 10;
    	wPt[1].y = wRect.top;
    	wPt[2].x = wRect.left - 10;
    	wPt[2].y = wRect.bottom + 10;
    	StretchBlt(hDsktp,0,dY,dX,-dY,hDsktp,0,0,dX,dY,NOTSRCCOPY);
    	PlgBlt(hDsktp, wPt, hDsktp, wRect.left, wRect.top, wRect.right - wRect.left, wRect.bottom - wRect.top, 0, 0, 0);
    	Sleep(10);
	}
}
