#include "Engine.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pSCmdLine, int iCmdShow)
{
	bool result;

	//Create the engine object
	Engine* engine;
	engine = new Engine();

	if (!engine)
		return 0;

	//Initialize and check it then run
	result = engine->Initialize();

	if (result)
	{
		engine->Run();
	}

	return 0;
}
