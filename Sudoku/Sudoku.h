#ifndef SUDOKU_H
#define SUDOKU_H

#include "Set.h"
#include "fstream"

class Sudoku {
public:
	Sudoku();
	void read(std::ifstream& in);
	int compute_square(const int x, const int y) const;
	void solveByBruteForce();
	void print() const;
	bool isSolved() const;
	void printLines() const;
	void printColumns() const;
	void printSquares() const;
	void clear();
	void generate();
private:
	Set* squares[9];
	Set* lines[9];
	Set* columns[9];
	int matrix[9][9]{ 0 };
};

#endif