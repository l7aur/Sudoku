#include "Sudoku.h"

Sudoku::Sudoku()
{
	for (int i = 0; i < 9; i++) {
		squares[i] = new Set(9);
		lines[i] = new Set(9);
		columns[i] = new Set(9);
	}
}

void Sudoku::read(std::ifstream& in)
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++) {
			int x;
			in >> x;
			matrix[i][j] = x;
			columns[j]->insert(x);
			lines[i]->insert(x);
			squares[this->compute_square(i, j)]->insert(x);
		}
}

int Sudoku::compute_square(const int x, const int y) const
{
	if (x < 3 && y < 3)
		return 1;
	else if (x < 3 && y < 6)
		return 2;
	else if (x < 3 && y < 9)
		return 3;
	else if (x < 6 && y < 3)
		return 4;
	else if (x < 6 && y < 6)
		return 5;
	else if (x < 6 && y < 9)
		return 6;
	else if (y < 3)
		return 7;
	else if (y < 6)
		return 8;
	return 9;
}

int Sudoku::solve()
{
	bool addedDigit = false;
	do{
		int freeSpaces = 0;
		for (int i = 0; i < 9; i++)
			if ((freeSpaces = lines[i]->getFree())) {
				//add element
				int digit = lines[i]->GetFirstFree();

				//
				addedDigit = true;
				continue;
			}
		for (int i = 0; i < 9; i++)
			if ((freeSpaces = columns[i]->getFree())) {
				//add element
				addedDigit = true;
				continue;
			}
		for (int i = 0; i < 9; i++)
			if ((freeSpaces = squares[i]->getFree())) {
				//add element
				addedDigit = true;
				continue;
			}
	} while (addedDigit);
	return 0;
}

void Sudoku::print() const
{
	for (int i = 0; i < 9; i++, printf("\n")) {
		for (int j = 0; j < 9; j++) {
			printf("%d ", matrix[i][j]);
			if ((j + 1) % 3 == 0)
				printf("\t");
		}
		if ((i + 1) % 3 == 0)
			printf("\n");
	}
}
