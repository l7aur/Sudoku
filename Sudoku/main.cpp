#include <iostream>
#include <fstream>
#include "Sudoku.h"

void test() {
	std::ifstream fin("test.txt");
	int noTests = 0;
	fin >> noTests;
	Sudoku* sudoku = new Sudoku();
	for (int i = 0; i < noTests; i++) {
		sudoku->read(fin);

		printf("Sudoku #%d to be solved:\n", i);
		sudoku->print();

		printf("Solved Sudoku #%d:\n", i);
		sudoku->solveByBruteForce();
		sudoku->print();
		sudoku->clear();
	}
	delete sudoku;
	fin.close();
}

void test_one() {
	std::ifstream fin("input.txt");

	Sudoku* sudoku = new Sudoku();
	sudoku->read(fin);
	fin.close();

	printf("Sudoku to be solved:\n");
	sudoku->print();

	printf("Solved Sudoku:\n");
	sudoku->solveByBruteForce();
	sudoku->print();
	delete sudoku;
}

int main()
{
	//test_one();
	test();
	return 0;
}
