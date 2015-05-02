#include "Engine.h"

Engine::Engine()
{
	//Read this from ini file in Initialize()
	widthScreen = 1280;
	heightScreen = 720;
	running = true;
}

Engine::~Engine()
{
	
}

bool Engine::Initialize()
{
	this->InitializeWin(widthScreen, heightScreen);
	return true;
}

void Engine::Run()
{
	MSG msg = { 0 };
	while (WM_QUIT != msg.message)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			if (running)
			{
				//Run simulation
			}
		}
	}
}

void Engine::Shutdown()
{
	running = false;
}

void Engine::InitializeWin(unsigned short width, unsigned short height)
{
	WNDCLASS wc;
	
	//Get the instance of this application
	this->hInstance = GetModuleHandle(NULL);

	//Set the Application name.
	appName = L"Engine";

	//Setup the window class wit default settings
	memset(&wc, 0, sizeof(wc));

	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = appName;

	//Register the window class
	RegisterClass(&wc);

	//Create the window with the screen setting and get the handle to it
	hwnd = CreateWindow(appName, TEXT("Engine"), WS_OVERLAPPEDWINDOW,
		0, 0, width, height, nullptr, nullptr, hInstance, nullptr);

	//Bring the window up on the screen and set it as main focus.
	ShowWindow(hwnd, SW_SHOW);
	SetForegroundWindow(hwnd);
	SetFocus(hwnd);
}

// Windows message processing
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	switch (msg)
	{
		// Check if the window is being destroyed.
		case WM_DESTROY:
		{
			PostQuitMessage(0);
			return 0;
		}
		// Check if the window is being closed.
		case WM_CLOSE:
		{
			PostQuitMessage(0);
			return 0;
		}
		// All other message pass to the default message handler.
		default:
		{
			return DefWindowProc(hwnd, msg, wparam, lparam);
		}
		
	}
}