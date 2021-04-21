#include <tchar.h>
#include <windows.h>
#include <iostream>

using namespace std;

int width = 0;
int height = 0;

bool mouse_move(int x, int y)
{
	INPUT input;
	input.type = INPUT_MOUSE;
	input.mi.mouseData = 0;
	input.mi.time = 0;
	input.mi.dx = x * (65536 / GetSystemMetrics(SM_CXSCREEN));//x being coord in pixels
	input.mi.dy = y * (65536 / GetSystemMetrics(SM_CYSCREEN));//y being coord in pixels
	input.mi.dwFlags = MOUSEEVENTF_MOVE;//MOUSEEVENTF_ABSOLUTE
	SendInput(1, &input, sizeof(input));
	return true;
}

void plant(int x, int y, int layers)
{
	int num;
	for (num = 0; num <= 440; num += 16) {
		
		Sleep(1);
		mouse_move(x + num, y - layers);
		SetCursorPos(x + num, y - layers);
		mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
		mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
	}
	
}

int main()
{
	// set window size and location
	HWND hProcess;
	hProcess = FindWindow(NULL, _T("Roblox"));
	SetWindowPos(hProcess, HWND_TOPMOST, 800, 0, 720, 320, NULL);
	
	// Get window dimensions
	RECT rect;
	GetWindowRect(hProcess, &rect);
	int width = rect.right - rect.left + 180;
	int height = rect.bottom - rect.top - 130;

	
	while (true) {

		// Switch to sickle
		keybd_event(0x32, 0x03, KEYEVENTF_KEYUP, 0);
		keybd_event(0x32, 0x03, KEYEVENTF_EXTENDEDKEY, 0);
		mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
		Sleep(5000);

		// Switch to seeds
		keybd_event(0x31, 0x02, KEYEVENTF_KEYUP, 0);
		keybd_event(0x31, 0x02, KEYEVENTF_EXTENDEDKEY, 0);
		
		//Planting laters
		plant(width, height, 0); //1
		plant(width, height, 60); //2
		plant(width, height, 120); //3
		plant(width, height, 170); //4
		plant(width, height, 220); //5
		plant(width, height, 230); //6
		plant(width, height, 280); //7
		plant(width, height, 320); //8
		plant(width, height, 370); //9

		// Move next
		keybd_event(0x44, 0x20, KEYEVENTF_EXTENDEDKEY, 0); // D
		Sleep(1200);
		keybd_event(0x44, 0x20, KEYEVENTF_KEYUP, 0);  // D
		keybd_event(0x57, 0x11, KEYEVENTF_EXTENDEDKEY, 0); // W
		Sleep(300);
		keybd_event(0x57, 0x11, KEYEVENTF_KEYUP, 0); // W
	}
	

	return 0;
}