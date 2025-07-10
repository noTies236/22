#include <iostream>
#include "SDL2/SDL.h"
#include "GLAD/glad.h"

// globals
int gScreenWidth = 540;
int gScreenHight = 480;

SDL_Window* gGraphicsApplicationWindow = nullptr;
SDL_GLContext gOpenGLContext = nullptr;

bool gQuit = false;

void GetOpenGlVersionInfo();
void GetOpenGlVersionInfo() {
	std::cout << "vendor: " << glGetString(GL_VENDOR) << "\n";
	std::cout << "GL_RENDERER: " << glGetString(GL_RENDERER) << "\n";
	std::cout << "GL_VERSION: " << glGetString(GL_VERSION) << "\n";
	std::cout << "GL_SHADING_LANGUAGE_VERSION: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << "\n";
}

#if 1
void InitializeProgram();
void MainLoop();
void MainLoop();
void CleanUp();

void InitializeProgram()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL has not started!" << "\n";
		exit(1);
	} else {
		std::cout << "SDL has started!" << "\n";
	}

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

	gGraphicsApplicationWindow = SDL_CreateWindow("OpenGL window", 0, 0, gScreenWidth, gScreenHight, SDL_WINDOW_OPENGL);

	if (gGraphicsApplicationWindow == nullptr) {
		std::cout << "window has not starded!";
	}

	gOpenGLContext = SDL_GL_CreateContext(gGraphicsApplicationWindow);

	if (!gladLoadGLLoader(SDL_GL_GetProcAddress)) {
		std::cout << "Glad was not initialized!" << "\n";
	}

	if (gOpenGLContext == nullptr) {
		std::cout << "openGl context has not been created" << "\n";
	}
}

void Input() {
	SDL_Event e;

	while (SDL_PollEvent(&e) != 0) {
		if (e.type == SDL_QUIT) {
			std::cout << "Goodbye!" << "\n";
			gQuit = true;
		}
	}
}

void PreDraw() {

}

void Draw() {

}

void MainLoop()
{
	GetOpenGlVersionInfo();

	while (!gQuit) {
		Input();

		PreDraw();
			
		Draw();

		SDL_GL_SwapWindow(gGraphicsApplicationWindow);
	}
}

void CleanUp()
{
	SDL_DestroyWindow(gGraphicsApplicationWindow);

	SDL_Quit();
}
#endif

int main(int argc, char* argv[])
{
	InitializeProgram(); 

	MainLoop();
	
	CleanUp();
	return 0;
}