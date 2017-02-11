#include "stdafx.h"
#include "App.h"

namespace App
{
	App::App()
		: window_(nullptr)
	{
		if (InitSDL() != 0)
		{
			SDL_Log("Unable to initialize SDL: %s\n", SDL_GetError());
		}
		CreateWindow();
	}

	App::~App()
	{
		SDL_DestroyWindow(window_);
		SDL_Quit();
	}

	const bool App::Update()
	{
		bool isExiting = false;

		SDL_Event event;

		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_KEYDOWN)
				isExiting = true;
		}

		return isExiting;
	}

	int App::InitSDL()
	{
		return SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	}

	void App::CreateWindow()
	{
		SDL_Window* window = SDL_CreateWindow("First Window", 0, 0, 640, 320, SDL_WINDOW_OPENGL);

		if (!window)
			SDL_Log("Unable to create window: %s\n", SDL_GetError());
	}
}
