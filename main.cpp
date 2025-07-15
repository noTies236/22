#include <iostream>
#include "SDL2/SDL.h"
#include "GLAD/glad.h"
#include "vector"

// globals
int gScreenWidth = 740;
int gScreenHight = 680;

SDL_Window* gGraphicsApplicationWindow = nullptr;
SDL_GLContext gOpenGLContext = nullptr;

bool gQuit = false;

//VAO
GLuint gVertexArrayObject = 0;
GLuint gVertexBufferObject = 0;
GLuint gGraphicsPipelineShaderProgram = 0;

const std::string gVertexShaderSource =
	"#version 410 core\n"
	"in vec3 position;\n"
	"void main()\n"
	"{\n"
	"	gl_Position = vec4(position.x, position.y, position.z, 1.0f);\n"
	"}\n";

const std::string gFragmentShaderSource =
	"#version 410 core\n"
	"out vec4 color;\n"
	"void main()\n"
	"{\n"
	"	color = vec4(0.6f, 0.5f, 1.8f, 0.7f);\n"
	"}\n";

GLuint CompileShader(GLuint type, const std::string& source) {
	GLuint shaderObject{};

	if (type == GL_VERTEX_SHADER) {
		shaderObject = glCreateShader(GL_VERTEX_SHADER);
	}
	else if (type == GL_FRAGMENT_SHADER) {
		shaderObject = glCreateShader(GL_FRAGMENT_SHADER);
	}
	else {
		std::cout << "error!! CompileShader()" << "\n";
	}
	const char* src = source.c_str();
		std::cout << type << src << "\n";

	glShaderSource(shaderObject, 1, &src, nullptr);
	glCompileShader(shaderObject);

	return shaderObject;
}

GLuint CreateShaderProgram(const std::string& vertexShaderSource, const std::string& fragmentShaderSource) {
	GLuint programObject = glCreateProgram();

	GLuint myVertexShader = CompileShader(GL_VERTEX_SHADER, vertexShaderSource);
	GLuint myFragmentShader = CompileShader(GL_FRAGMENT_SHADER, fragmentShaderSource);

	glAttachShader(programObject, myVertexShader);
	glAttachShader(programObject, myFragmentShader);
	glLinkProgram(programObject);

	glValidateProgram(programObject);

	return programObject;
}

void CreateGraphicsPipeline() {
	gGraphicsPipelineShaderProgram = CreateShaderProgram(gVertexShaderSource, gFragmentShaderSource);
}

void GetOpenGlVersionInfo();
void GetOpenGlVersionInfo() {
	std::cout << "vendor: " << glGetString(GL_VENDOR) << "\n";
	std::cout << "GL_RENDERER: " << glGetString(GL_RENDERER) << "\n";
	std::cout << "GL_VERSION: " << glGetString(GL_VERSION) << "\n";
	std::cout << "GL_SHADING_LANGUAGE_VERSION: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << "\n";
}

void VertexSpecification();
void VertexSpecification() {
	std::vector<GLfloat> vertexPosition{
		-0.8f, -0.8f, 0.0f,
		 0.8f, -0.8f, 0.0f,
		 0.0f,  0.8f, 0.0f,
	};

	glCreateVertexArrays(1, &gVertexArrayObject);
	glBindVertexArray(gVertexArrayObject);
	
	glCreateBuffers(1, &gVertexBufferObject);
	glBindBuffer(GL_ARRAY_BUFFER, gVertexBufferObject);
	
	glBufferData(GL_ARRAY_BUFFER, 
			     vertexPosition.size() * sizeof(GLfloat), 
			     vertexPosition.data(), 
			     GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0,
						  3,
						  GL_FLOAT,	
						  GL_FALSE,
						  0,
						  (void*)0);

	glBindVertexArray(0);
	glDisableVertexAttribArray(0);
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
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);
	glViewport(0,0, gScreenWidth, gScreenHight);
	//glClearColor(1.0f, 0.2f, 1.0f, 1.0f);

	glUseProgram(gGraphicsPipelineShaderProgram);
}

void Draw() {
	glBindVertexArray(gVertexArrayObject); 
	glBindBuffer(GL_ARRAY_BUFFER, gVertexBufferObject);
	glDrawArrays(GL_TRIANGLES, 0, 3);
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

	VertexSpecification();

	CreateGraphicsPipeline();

	MainLoop();
	
	CleanUp();
	return 0;
}