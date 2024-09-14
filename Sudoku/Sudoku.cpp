#include "Sudoku.h"
#include <stack>

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
		return 0;
	if (x < 3 && y < 6)
		return 1;
	if (x < 3 && y < 9)
		return 2;
	if (x < 6 && y < 3)
		return 3;
	if (x < 6 && y < 6)
		return 4;
	if (x < 6 && y < 9)
		return 5;
	if (y < 3)
		return 6;
	if (y < 6)
		return 7;
	return 8;
}

void Sudoku::solveByBruteForce()
{
	std::stack<std::pair<std::pair<int, int>, int>> S; //(i, j) in matrix + value
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			int digit = 1;
			while (matrix[i][j] == 0) //undefined number in that spot
			{
				bool isDigitOK = true;
				if (lines[i]->getData()[digit] ||
					columns[j]->getData()[digit] ||
					squares[this->compute_square(i, j)]->getData()[digit]) {
					//printf("%d [%d, %d]\n", digit, i, j);
					digit++;
				}
				else {
					//printf("\t%d [%d, %d]\n", digit, i, j);
					matrix[i][j] = digit;
					S.push({ {i, j}, digit });
					lines[i]->insert(digit);
					columns[j]->insert(digit);
					squares[this->compute_square(i, j)]->insert(digit);
				}
				while (digit > 9) {
					if (S.empty()) {
						printf("ERROR1!\n");
						return;
					}
					//go back one spot
					digit = S.top().second;
					i = S.top().first.first;
					j = S.top().first.second;
					matrix[i][j] = 0;
					lines[i]->remove(digit);
					columns[j]->remove(digit);
					squares[this->compute_square(i, j)]->remove(digit);
					S.pop();
					digit++;
					//printf("new pos %d, %d\n", i, j);
				}
			}
		}
	}
	while (!S.empty()) S.pop();
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

bool Sudoku::isSolved() const
{
	for (int i = 0; i < 9; i++)
		if (!lines[i]->isFull() ||
			!columns[i]->isFull() ||
			!squares[i]->isFull())
			return false;
	return true;
}

void Sudoku::printLines() const
{
	for (int i = 0; i < 9; i++)
	{
		printf("Line %d: ", i + 1);
		for (int j = 1; j < 10; j++)
			if (lines[i]->getData()[j])
				printf("%d ", j);
		printf("\n");
	}
}

void Sudoku::printColumns() const
{
	for (int i = 0; i < 9; i++)
	{
		printf("Column %d: ", i + 1);
		for (int j = 1; j < 10; j++)
			if (columns[i]->getData()[j])
				printf("%d ", j);
		printf("\n");
	}
}

void Sudoku::printSquares() const
{
	for (int i = 0; i < 9; i++)
	{
		printf("Square %d: ", i + 1);
		for (int j = 1; j < 10; j++)
			if (squares[i]->getData()[j])
				printf("%d ", j);
		printf("\n");
	}
}

void Sudoku::clear()
{
	for (int i = 0; i < 9; i++) {
		lines[i]->clear();
		columns[i]->clear();
		squares[i]->clear();
	}
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			matrix[i][j] = 0;
}

void Sudoku::generate()
{
}
