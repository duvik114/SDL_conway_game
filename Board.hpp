#include <vector>
#include <random>
#pragma once 
#define WIDTH 120
#define HEIGHT 60
#define CELL_WIDTH 10
#define CELL_HEIGHT 10

class Board
{
public:
	Board() { sas = std::vector<std::vector<bool>>(HEIGHT + 2, std::vector<bool>(WIDTH + 2, false)); } // 40x40 square + extra rows & columns!
	~Board() {}
	void InitBoard(int posx, int posy);
	void UpdateBoard();
	bool GetSasElement(size_t i, size_t j) { return sas[i][j]; }
	void SetSasElement(size_t i, size_t j, bool value) { sas[i][j] = value; }
private:
	std::vector<std::vector<bool>> sas; // 12x15 squareS
};