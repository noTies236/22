#include "window.h"
//#include "SDL2/SDL.h"

SDL_Window* WindowApplication::g_window = nullptr; 
bool WindowApplication::shouldNotCloseWindow = false;

void WindowApplication::setupWindow()
{
	//      x          x      
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL has not started" << "\n";
		return;
	}

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

	//                                                x  x                  x
	WindowApplication::g_window = SDL_CreateWindow("noties", 0, 0, 640, 480, SDL_WINDOW_OPENGL);

	if (g_window == nullptr) {
		std::cout << "window has not been inicializACaded" << "\n";
		return;
	}

	SDL_GL_CreateContext(g_window);

	WindowApplication::setupGlad();  
}

void WindowApplication::setupGlad() 
{
	//           x                  x
	if (!gladLoadGLLoader(SDL_GL_GetProcAddress)) {
		std::cout << "GLAD was not setup" << "\n";
	}
}

void WindowApplication::eventWindow()
{
	SDL_Event e;

	while (SDL_PollEvent(&e) != 0) {
		if (e.type == SDL_QUIT) {
			WindowApplication::shouldNotCloseWindow = true;
		}
	}
}

void WindowApplication::initWindow()
{
	
	WindowApplication::setupWindow();
	
	while (!WindowApplication::shouldNotCloseWindow) {
		glClearColor(0.1f, 0.2f, 0.2f, 0.7f);
		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

		WindowApplication::eventWindow();

		//          x
		SDL_GL_SwapWindow(g_window); 
	}
}