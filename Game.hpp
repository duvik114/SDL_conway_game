#define SDL_MAIN_HANDLED
#include "Board.hpp"
#include "SDL.h"
#pragma once

class Game
{
public:
	void InitGame(void); // Initialize SDL2
	void CreateLiveSpon(Sint32 posx, Sint32 posy);
	void RenderFrames(void); // Render frames)
	void Update(); // Update frames
	void EndGame(void); // Ends the game)

private:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	SDL_Rect rect;
	Board board;

public:
	bool is_playable;

};