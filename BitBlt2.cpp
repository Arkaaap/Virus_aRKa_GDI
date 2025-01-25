#include <windows.h>

int main(){
		while(1){
		HDC hdc = GetDC(0);
    	int x = GetSystemMetrics(0);
    	int y = GetSystemMetrics(1);
    	StretchBlt(hdc, -10, -10, x + 20, y + 20, hdc, 0, 0, x, y, NOTSRCCOPY);
    	StretchBlt(hdc, 10, 10, x - 20, y - 20, hdc, 0, 0, x, y, SRCCOPY);//COOL 
    	ReleaseDC(0, hdc);
	}
}
