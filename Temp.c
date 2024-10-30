#include <windows.h>
#include <wingdi.h>
#include <stdio.h>
#include <winuser.h>
//#include <gdiplus.h>

DWORD WINAPI mbr_Flush(LPVOID Lparam);
DWORD WINAPI Small_Rect(LPVOID Lparam)
{
	HDC hdc = GetDC(NULL);
int x= GetSystemMetrics(0);
	
	int y = GetSystemMetrics(0);
	int i,j,k;
	
	
	
	for (i = 0 ;i<500;i++)
	{
		HBRUSH hb = CreateSolidBrush(RGB(rand()%255,0,0));
		SelectObject(hdc,hb);
		StretchBlt(hdc,rand()%x,rand()%y,rand()%x,rand()%y,hdc,0,0,x,y,SRCCOPY);
		PatBlt(hdc,rand()%x,rand()%x,rand()%x,rand()%y,PATCOPY);
		StretchBlt(hdc,50,50,x-100,y-100,hdc,0,0,x,y,SRCCOPY);
//				for (k = 0;k<3;k++)
//				{
//					p[j].x = x1+(rand()%x1);
//					p[j].y = y1+(rand()%y1);
//				}
				
		
	}
	Sleep(50);

return 0x00;
}


DWORD WINAPI SWIRLING_BALLS(LPVOID Lparam)
{
	HDC hdc = GetDC(NULL);
int x= GetSystemMetrics(0);
	
	int y = GetSystemMetrics(0);
	int i,j,k;
	
	
	for (i = 0 ;i<50;i++)
	{
		HBRUSH hb = CreateSolidBrush(RGB(rand()%255,0,0));
		SelectObject(hdc,hb);
		StretchBlt(hdc,rand()%x,rand()%y,rand()%x,rand()%y,hdc,0,0,x,y,SRCCOPY);
		PatBlt(hdc,rand()%x,rand()%x,rand()%x,rand()%y,PATCOPY);
			for (j = 0 ;j<10;j++)
			{
				
			
		StretchBlt(hdc,15,15,x-70,y-9,hdc,0,0,x,y,SRCCOPY);
		
	}
//				for (k = 0;k<3;k++)
//				{
//					p[j].x = x1+(rand()%x1);
//					p[j].y = y1+(rand()%y1);
//				}
				
		
	}
	return 0x00;
}


void Notshowwindow()
{
	HWND hnd ;
	AllocConsole();
	hnd = FindWindowA("ConsoleWindowClass",NULL);
	ShowWindow(hnd,0);
}


void wave ()
{
	HDC hdc = GetDC(NULL);
int x= GetSystemMetrics(0);
	
	int y = GetSystemMetrics(0);
	
	
	int i;
	
	for (i = 0 ;i<400;i++)
	
	{
		HBRUSH hb = CreateSolidBrush(RGB(rand()%255,rand()%255,0));
		SelectObject(hdc,hb);
		BitBlt(hdc,rand()%10-20,rand()%20-10,x,y,hdc,0,0,SRCCOPY);
		StretchBlt(hdc,rand()%x,rand()%x,rand()%x,rand()%x,hdc,0,0,x,y,SRCCOPY);
		PatBlt(hdc,rand()%x,rand()%y,rand()%x,rand()%y,PATINVERT);
	}
	Sleep(10);
}

void wave1 ()
{
	HDC hdc = GetDC(NULL);
int x= GetSystemMetrics(0);
	
	int y = GetSystemMetrics(0);
	
	
	int i;
	
	for (i = 0 ;i<400;i++)
	
	{
		HBRUSH hb = CreateSolidBrush(RGB(rand()%255,rand()%255,0));
		SelectObject(hdc,hb);
		BitBlt(hdc,rand()%10-20,rand()%20-10,x,y,hdc,0,0,SRCCOPY);
		StretchBlt(hdc,rand()%x,rand()%x,rand()%x,rand()%x,hdc,0,0,x,y,SRCCOPY);
		PatBlt(hdc,rand()%x,rand()%y,rand()%x,rand()%y,BLACKNESS);
	}
	Sleep(10);
}


DWORD WINAPI  mouse (LPVOID Lpa)
{
	HDC hdc = GetDC(0);
int icon_x = GetSystemMetrics(SM_CXICON);
int icon_y = GetSystemMetrics(SM_CYICON) ;
POINT cursor;

	while(1){
		FreeConsole();
        GetCursorPos(&cursor);
        DrawIcon(hdc, cursor.x - icon_x, cursor.y - icon_y, LoadIcon(NULL, IDI_ERROR));
	}
	return 0x00;
	
}

DWORD WINAPI mouse2(LPVOID Lparam)
{
	
	POINT cursor = {0};
	int signX = 1;
	int signY = 1;
	int signX1 = 1;
	int signY1 = 1;
	int increamentor  = 10;
	int x = 10 ;
	int y = 10;
	
		while (1)
		{
			HDC hdc = GetDC(HWND_DESKTOP);
			int icon_x = GetSystemMetrics(SM_CXICON);
			int icon_y = GetSystemMetrics(SM_CYICON);
			GetCursorPos(&cursor);
			x+=increamentor*signX;
			y+=increamentor*signY;
			SetCursorPos(x,y);
			DrawIcon(hdc,cursor.x-icon_x,cursor.y-icon_y,LoadCursor(NULL,IDC_ARROW));
			if (y>=GetSystemMetrics(SM_CYSCREEN)){
				signY = -1; 
			}
			if (x>=GetSystemMetrics(SM_CYSCREEN))
			{
				signX= -1;
			}
			if (y == 0)
			{
				signY = 1;
			}
			if (x == 0)
			{
				signX = 1;
			}
			ReleaseDC(0,hdc);
			Sleep(10);
		}
		return 0x01;
}



//DWORD WINAPI Animate(LPVOID Lparam)
//{
//    HWND hnd = (HWND)Lparam; // Cast the parameter to HWND
//    DWORD Dwtime = 2000;
//
//    // Check if the window handle is valid
//    if (hnd != NULL && AnimateWindow(hnd, Dwtime, AW_BLEND))
//    {
//        return 0; // Success
//    }
//    return 1; // Indicate failure
//}


int main (int argc ,char **argv)
{
	MessageBox(NULL,TEXT("Y"),NULL,MB_OK);
	HWND hnd;
	//hnd = CreateThread(0,0,Animate,0,0,0);
//	Sleep(20000);
//	TerminateThread(hnd,0x00);
//	CloseHandle(hnd);
//	//Notshowwindow();
//	HANDLE hnd1 = CreateThread(0,0,Small_Rect,0,0,0);
//	Sleep(30000);
//	TerminateThread(hnd1,0x00);
//	CloseHandle(hnd1);
//	Sleep(100);
//	HANDLE hnd2 = CreateThread(0,0,SWIRLING_BALLS,0,0,0);
//	Sleep(30000);
//	TerminateThread(hnd2,0x00);
	HANDLE hndx = CreateThread(0,0,mouse,0,0,0);
	Sleep(30000);
	wave();
	TerminateThread(hndx,0x00);
	HANDLE hndx1 = CreateThread(0,0,mouse2,0,0,0);
	Sleep(30000);
	wave1();
	TerminateThread(hndx1,0x00);
	CloseHandle(hndx1);
}
