#include <Windows.h>
int main() {
	HDC desktop = GetDC(NULL);
	int xs = GetSystemMetrics(SM_CXSCREEN);
	int ys = GetSystemMetrics(SM_CYSCREEN);
	while (true) {
		FreeConsole();
		desktop = GetDC(NULL);
		BitBlt(desktop, -1,1, xs, ys, desktop, 2,2, 0x999999);
	}
}
