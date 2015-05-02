#pragma once

#include<Windows.h>

class Engine
{
public:
	Engine();
	~Engine();

	bool Initialize();
	void Run();
	void Shutdown();

private:
	void InitializeWin(unsigned short width, unsigned short height);

private:
	LPCWSTR appName;
	HINSTANCE hInstance;
	HWND hwnd;
	bool running;
	unsigned short widthScreen;
	unsigned short heightScreen;
};

static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);