#include "stdafx.h"
#include "App.h"
#include "GL\glew.h"

namespace App
{
	App::App()
		: window_(nullptr)
		, renderer_(nullptr)
		, context_(nullptr)
	{
		if (InitSDL() != 0)
		{
			SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Unable to initialize SDL: %s\n", SDL_GetError());
		}
		CreateWindow();
		CreateRenderer();
		CreateContext();
	}

	App::~App()
	{
		SDL_DestroyWindow(window_);
		SDL_Quit();
	}

	bool App::Update()
	{
		bool isExiting = false;

		SDL_Event event;

		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_KEYDOWN)
				isExiting = true;
		}

		Render();

		return isExiting;
	}

	void App::Render()
	{
		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glDrawBuffer(GL_COLOR_ATTACHMENT0);
		SDL_GL_SwapWindow(window_);
	}

	int App::InitSDL()
	{
		return SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	}

	void App::CreateWindow()
	{
		window_ = SDL_CreateWindow("First Window", 0, 0, 640, 320, SDL_WINDOW_OPENGL);

		if (!window_)
			SDL_Log("Unable to create window: %s\n", SDL_GetError());
	}

	void App::CreateRenderer()
	{
		renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);

		if (!renderer_)
			SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Unable to create the renderer: %s\n", SDL_GetError());
	}

	void App::CreateContext()
	{
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

		context_ = SDL_GL_CreateContext(window_);

		if (!context_)
			SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Unable to create the renderer: %s\n", SDL_GetError());

		// gl extension wrangler
		glewExperimental = GL_TRUE;
		GLenum glError = glewInit();
		//glGetFrameBufferSize()
		glViewport(0, 0, 640, 320);

		if (SDL_GL_SetSwapInterval(1) < 0)
			SDL_LogError(SDL_LOG_CATEGORY_RENDER, "Unable to set swap interval to vsync time: %s\n", SDL_GetError());

		//GLuint program = glCreateProgram();
		//GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	}
}
