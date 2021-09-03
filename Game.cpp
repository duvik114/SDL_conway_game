#include "Game.hpp"

void Game::InitGame(void)
{
	SDL_SetMainReady();
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("Bonjour", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH * CELL_WIDTH, HEIGHT * CELL_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, 0u);
	/*board.InitBoard(1, 1);
	board.InitBoard(1, 2);
	board.InitBoard(1, 3);
	board.InitBoard(2, 2);*/
	is_playable = true; 
}

void Game::CreateLiveSpon(Sint32 posx, Sint32 posy)
{
	board.InitBoard(posx / CELL_WIDTH + 1, posy / CELL_HEIGHT + 1);
}

void Game::RenderFrames(void)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	bool flag = true, flag2 = true;
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			if (!board.GetSasElement(i + 1, j + 1))
			{
				flag = false;
				continue;
			}
			flag2 = false;
			rect = {j * CELL_WIDTH, i * CELL_HEIGHT, CELL_WIDTH, CELL_HEIGHT};
			SDL_RenderFillRect(renderer, &rect);
		}
	}

	/*if (flag)
		is_playable = false;*/
	/*if (flag2)
		board.InitBoard(1, 1);*/

	SDL_RenderPresent(renderer);
}

void Game::Update()
{
	board.UpdateBoard();
}

void Game::EndGame(void)
{
	// SDL_Delay(4444); 
	SDL_Quit();
}
