// MotionTriggeredAntiPeekAutoShoot.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "iostream"
#include "Windows.h"
#include "vector" 

using namespace std;

int screenWidth = GetSystemMetrics(SM_CXSCREEN);
int screenHeight = GetSystemMetrics(SM_CYSCREEN);
int width = 6;
int height = 6;
bool enabled = true;

void slideAttack() {
	INPUT _VK_NUMPAD1_keyDown;
	_VK_NUMPAD1_keyDown.type = INPUT_KEYBOARD;
	_VK_NUMPAD1_keyDown.ki.wScan = MapVirtualKey(VK_NUMPAD1, MAPVK_VK_TO_VSC); // hardware scan code
	_VK_NUMPAD1_keyDown.ki.time = 0;
	_VK_NUMPAD1_keyDown.ki.wVk = VK_NUMPAD1; // virtual-key code
	_VK_NUMPAD1_keyDown.ki.dwExtraInfo = 0;
	_VK_NUMPAD1_keyDown.ki.dwFlags = 0; // 0 for key down
	INPUT _VK_NUMPAD1_keyUp = _VK_NUMPAD1_keyDown;
	_VK_NUMPAD1_keyUp.ki.dwFlags = KEYEVENTF_KEYUP;

	INPUT _VK_NUMPAD2_keyDown = _VK_NUMPAD1_keyDown;
	_VK_NUMPAD2_keyDown.ki.wScan = MapVirtualKey(VK_NUMPAD2, MAPVK_VK_TO_VSC); // hardware scan code
	_VK_NUMPAD2_keyDown.ki.wVk = VK_NUMPAD2; // virtual-key code
	INPUT _VK_NUMPAD2_keyUp = _VK_NUMPAD2_keyDown;
	_VK_NUMPAD2_keyUp.ki.dwFlags = KEYEVENTF_KEYUP;

	INPUT _VK_NUMPAD3_keyDown = _VK_NUMPAD1_keyDown;
	_VK_NUMPAD3_keyDown.ki.wScan = MapVirtualKey(VK_NUMPAD3, MAPVK_VK_TO_VSC); // hardware scan code
	_VK_NUMPAD3_keyDown.ki.wVk = VK_NUMPAD3; // virtual-key code
	INPUT _VK_NUMPAD3_keyUp = _VK_NUMPAD3_keyDown;
	_VK_NUMPAD3_keyUp.ki.dwFlags = KEYEVENTF_KEYUP;

	INPUT _VK_NUMPAD4_keyDown = _VK_NUMPAD1_keyDown;
	_VK_NUMPAD4_keyDown.ki.wScan = MapVirtualKey(VK_NUMPAD4, MAPVK_VK_TO_VSC); // hardware scan code
	_VK_NUMPAD4_keyDown.ki.wVk = VK_NUMPAD4; // virtual-key code
	INPUT _VK_NUMPAD4_keyUp = _VK_NUMPAD4_keyDown;
	_VK_NUMPAD4_keyUp.ki.dwFlags = KEYEVENTF_KEYUP;

	while (1) {
		if (((GetKeyState(0x33) & 0x100) != 0) && enabled) {

			SendInput(1, &_VK_NUMPAD1_keyDown, sizeof(INPUT));
			Sleep(5);
			SendInput(1, &_VK_NUMPAD2_keyDown, sizeof(INPUT));
			Sleep(10);
			SendInput(1, &_VK_NUMPAD3_keyDown, sizeof(INPUT));
			Sleep(20);
			SendInput(1, &_VK_NUMPAD4_keyDown, sizeof(INPUT));
			Sleep(15);
			SendInput(1, &_VK_NUMPAD4_keyUp, sizeof(INPUT));
			Sleep(10);
			SendInput(1, &_VK_NUMPAD3_keyUp, sizeof(INPUT));
			Sleep(10);
			SendInput(1, &_VK_NUMPAD2_keyUp, sizeof(INPUT));
			Sleep(5);
			SendInput(1, &_VK_NUMPAD1_keyUp, sizeof(INPUT));
		}

		Sleep(1);
	}
}


void trackEnabled() {
	while (1) {
		if ((GetKeyState(VK_F1) & 0x100) != 0) {
			enabled = !enabled;
			cout << "F1" << endl;
			Sleep(500);
		}
		Sleep(1);
	}
}

void trackResolution() {
	while (1) {
		screenWidth = GetSystemMetrics(SM_CXSCREEN);
		screenHeight = GetSystemMetrics(SM_CYSCREEN);
		if (screenWidth == 2048 && screenHeight == 1152) {
			screenWidth = 2560;
			screenHeight = 1440;
		}
		Sleep(10000);
	}
}

void recoilInput() {
	while (1) {
		cout << "Enter int to change value";
		cin >> enabled;
		Sleep(1000);
	}
}

int main() {
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)slideAttack, 0, 0, 0);
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)trackEnabled, 0, 0, 0);
	//CreateThread(0, 0, (LPTHREAD_START_ROUTINE)trackResolution, 0, 0, 0);
	//CreateThread(0, 0, (LPTHREAD_START_ROUTINE)recoilInput, 0, 0, 0);
	while (1) {
		Sleep(1000);
	}
	return 0;
}
