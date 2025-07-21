#pragma once
#include "iostream"
#include "SDL2/SDL.h"
#include "GLAD/glad.h"

namespace WindowApplication {
	//          x
	extern SDL_Window* g_window;
	extern bool shouldNotCloseWindow;
	void setupWindow();
	void setupGlad();
	void initWindow();
	void eventWindow();
}