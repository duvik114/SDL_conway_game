/*
	This is just a Conway's life game
*/
#include <stdio.h>
#include "Game.hpp"
#define FPS 44

int main()
{	
	Game game;
	game.InitGame();
	SDL_Event event;

	bool mouseDownFlag = false;
	char framesCounter = 0;
	const int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frameTime;

	while (game.is_playable)
	{
		frameStart = SDL_GetTicks();

		while (SDL_PollEvent(&event) != 0)
		{
			if (event.type == SDL_QUIT)
				game.is_playable = false;
			else if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
				mouseDownFlag = true;
			else if (event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT)
				mouseDownFlag = false;
		}

		if (!mouseDownFlag)
		{
			if (framesCounter >= 1.0f * FPS / 44.0f)
			{
				framesCounter = 0;
				game.Update();
			}
		}
		else
		{
			game.CreateLiveSpon(event.button.x, event.button.y);
			// printf("%d %d\n", event.button.x, event.button.y); 
		}
		game.RenderFrames();

		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime)
			SDL_Delay(frameDelay - frameTime);

		framesCounter++;
	}

	game.EndGame();

	return 0;
}
