#include "Board.hpp"

void Board::InitBoard(int posx, int posy)
{
	if (posx > 0 && posx <= WIDTH && posy > 0 && posy <= HEIGHT)
		sas[posy][posx] = true;
}

void Board::UpdateBoard()
{
	std::vector<std::vector<bool>> sas_copy = sas; // ?
	for (size_t i = 1; i <= HEIGHT; i++)
	{
		for (size_t j = 1; j <= WIDTH; j++)
		{
			int alive_count = 0;

			alive_count += sas_copy[i - 1][j - 1] ? 1 : 0;
			alive_count += sas_copy[i - 1][j] ? 1 : 0;
			alive_count += sas_copy[i - 1][j + 1] ? 1 : 0;
			alive_count += sas_copy[i][j - 1] ? 1 : 0;
			     /* себя проверять не будем; */
			alive_count += sas_copy[i][j + 1] ? 1 : 0;
			alive_count += sas_copy[i + 1][j - 1] ? 1 : 0;
			alive_count += sas_copy[i + 1][j] ? 1 : 0;
			alive_count += sas_copy[i + 1][j + 1] ? 1 : 0;

			if (alive_count < 2 || alive_count > 3)
				sas[i][j] = false;
			if (alive_count == 3)
				sas[i][j] = true;

			/* RIP */
		}
	}
}
