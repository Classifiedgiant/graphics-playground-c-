#ifndef GRAPHICS_PLAYGROUND_APP_H_
#define GRAPHICS_PLAYGROUND_APP_H_

#include <memory>

#define SDL_MAIN_HANDLED
#include "SDL.h"

namespace App
{
	class App
	{
	public:
		App();
		~App();
		App(const App& rhs) = delete;
		App& operator=(const App&) = delete;

		App(App&&) = delete;
		App& operator=(App&&) = delete;

		const bool Update();

	private:
		int InitSDL();
		void CreateWindow();

		SDL_Window* window_;
	};
}
#endif //GRAPHICS_PLAYGROUND_APP_H_
