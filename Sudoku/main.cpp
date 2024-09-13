#include <iostream>
#include <fstream>
#include "Sudoku.h"

int main()
{
	std::ifstream fin("input.txt");
	
	Sudoku* sudoku = new Sudoku();
	sudoku->read(fin);
	sudoku->print();
	fin.close();
	return 0;
}
