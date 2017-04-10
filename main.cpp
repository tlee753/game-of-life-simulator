#include <iostream>
#include <array>
#include <random>
#include <cstdlib>
#include <time.h>
// #include "gameOfLife.h"

using namespace std;

#define boardCols 20
#define boardRows 20
#define boundsToggle 0
#define evolutions 100
#define gameSimulations 100.0

void randInitBoard(array<array<int, boardCols>, boardRows> &board);
void zeroInitBoard(array<array<int, boardCols>, boardRows> &board);
void printBoard(array<array<int, boardCols>, boardRows> board);
void nextState(array<array<int, boardCols>, boardRows> &board, int withBounds);
int surviveSimulation(int rounds);
float percentageGameSurvival(float games);

int main () {
	cout << "Game of Life starting...\n";

	srand(time(NULL));

	percentageGameSurvival(gameSimulations);

	return 0;
}

void randInitBoard(array<array<int, boardCols>, boardRows> &board) {
	// cout << "\nInitializing Board\n";
	for (int i = 0; i < boardRows; i++) {
		for (int j = 0; j < boardCols; j++) {
			board[i][j] = rand() % 2;
		}
	}
}

void zeroInitBoard(array<array<int, boardCols>, boardRows> &board) {
	for (int i = 0; i < boardRows; i++) {
		for (int j = 0; j < boardCols; j++) {
			board[i][j] = 0;
		}
	}
}

void printBoard(array<array<int, boardCols>, boardRows> board) {
	cout << "\n\n\nBoard State\n";

	for (int i = 0; i < boardRows; i++) {
		for (int j = 0; j < boardCols; j++) {
			cout << board[i][j];
		}
		cout << endl;
	}
}

void nextState(array<array<int, boardCols>, boardRows> &board, int withBounds) {
	// cout << "\nSurvival State\n";

	array<array<int, boardCols>, boardRows> temp;
	zeroInitBoard(temp);

	int survivalCount = 0;
	int rowEdge = boardRows - 1;
	int colEdge = boardCols - 1;

	if (withBounds) {
		for (int i = 0; i < boardRows; i++) {
			for (int j = 0; j < boardCols; j++) {
				survivalCount = 0;

				if ((i > 0) && (i < rowEdge) && (j > 0) && (j < colEdge)) {
					// center piece
					if (board[i-1][j-1]) survivalCount++;
					if (board[i-1][j]) survivalCount++;
					if (board[i-1][j+1]) survivalCount++;
					if (board[i][j-1]) survivalCount++;
					if (board[i][j+1]) survivalCount++;
					if (board[i+1][j-1]) survivalCount++;
					if (board[i+1][j]) survivalCount++;
					if (board[i+1][j+1]) survivalCount++;
				}
				// cout << survivalCount << "\t";
				if (survivalCount >= 3 && survivalCount <= 4) {
					temp[i][j] = 1;
				} else {
					temp[i][j] = 0;
				}
			}
			// cout << endl;
		}
	} else {
		for (int i = 0; i < boardRows; i++) {
			for (int j = 0; j < boardCols; j++) {
				survivalCount = 0;

				if ((i > 0) && (i < rowEdge) && (j > 0) && (j < colEdge)) {
					// center piece
					if (board[i-1][j-1]) survivalCount++;
					if (board[i-1][j]) survivalCount++;
					if (board[i-1][j+1]) survivalCount++;
					if (board[i][j-1]) survivalCount++;
					if (board[i][j+1]) survivalCount++;
					if (board[i+1][j-1]) survivalCount++;
					if (board[i+1][j]) survivalCount++;
					if (board[i+1][j+1]) survivalCount++;
				} else if ((i == 0) && (i < rowEdge) && (j > 0) && (j < colEdge)) {
					// upper edge
					// cout << "u";
					if (board[i][j-1]) survivalCount++;
					if (board[i][j+1]) survivalCount++;
					if (board[i+1][j-1]) survivalCount++;
					if (board[i+1][j]) survivalCount++;
					if (board[i+1][j+1]) survivalCount++;
				} else if ((i > 0) && (i < rowEdge) && (j == 0) && (j < colEdge)) {
					// left edge
					// cout << "l";
					if (board[i-1][j]) survivalCount++;
					if (board[i-1][j+1]) survivalCount++;
					if (board[i][j+1]) survivalCount++;
					if (board[i+1][j]) survivalCount++;
					if (board[i+1][j+1]) survivalCount++;
				} else if ((i > 0) && (i == rowEdge) && (j > 0) && (j < colEdge)) {
					// bottom edge
					// cout << "b";
					if (board[i-1][j-1]) survivalCount++;
					if (board[i-1][j]) survivalCount++;
					if (board[i-1][j+1]) survivalCount++;
					if (board[i][j-1]) survivalCount++;
					if (board[i][j+1]) survivalCount++;
				} else if ((i > 0) && (i < rowEdge) && (j > 0) && (j == colEdge)) {
					// right edge
					// cout << "r";
					if (board[i-1][j-1]) survivalCount++;
					if (board[i-1][j]) survivalCount++;
					if (board[i][j-1]) survivalCount++;
					if (board[i+1][j-1]) survivalCount++;
					if (board[i+1][j]) survivalCount++;
				} else if ((i == 0) && (i < rowEdge) && (j == 0) && (j < colEdge)) {
					// upper left corner
					// cout << "ul";
					if (board[i][j+1]) survivalCount++;
					if (board[i+1][j]) survivalCount++;
					if (board[i+1][j+1]) survivalCount++;
				} else if ((i == 0) && (i < rowEdge) && (j > 0) && (j == colEdge)) {
					// upper right corner
					// cout << "ur";
					if (board[i][j-1]) survivalCount++;
					if (board[i+1][j-1]) survivalCount++;
					if (board[i+1][j]) survivalCount++;
				} else if ((i > 0) && (i == rowEdge) && (j == 0) && (j < colEdge)) {
					// lower left corner
					// cout << "ll";
					if (board[i-1][j]) survivalCount++;
					if (board[i-1][j+1]) survivalCount++;
					if (board[i][j+1]) survivalCount++;
				} else if ((i > 0) && (i == rowEdge) && (j > 0) && (j == colEdge)) {
					// lower right corner
					// cout << "lr";
					if (board[i-1][j-1]) survivalCount++;
					if (board[i-1][j]) survivalCount++;
					if (board[i][j-1]) survivalCount++;
				} else {
					cout << "error: is this a one x one board?" << endl;
				}
				// cout << survivalCount << "\t";
				if (survivalCount == 3 /*&& survivalCount <= 3*/) {
					temp[i][j] = 1;
				} else {
					temp[i][j] = 0;
				}
			}
			// cout << endl;
		}
	}

	board = temp;
}

int surviveSimulation(int rounds) {
	array<array<int, boardCols>, boardRows> board;
	randInitBoard(board);
	int survived = 0;

	for (int i = 0; i < rounds; i++) {
		nextState(board, boundsToggle);
		// printBoard(board);
	}

	printBoard(board);

	for (int i = 0; i < boardRows; i++) {
		for (int j = 0; j < boardCols; j++) {
			if (board[i][j] == 1) {
				survived = 1;
				return survived;
			}
		}
	}

	return survived;
}

float percentageGameSurvival(float games) {
	int sum = 0;
	float percentage = 0.0;

	for (int i = 0; i < games; i++) {
		sum += surviveSimulation(evolutions);
	}

	cout << "\nGames survived: " << sum << " / Games: " << games << endl;
	percentage = sum / games;
	cout << "Survival Rate: " << percentage << endl;
	return percentage;
}
