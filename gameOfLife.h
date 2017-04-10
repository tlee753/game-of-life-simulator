/*
* Game of Life class file
* 
* Author: Tyler Lee
*/

using namespace std;

class gameOfLife {
	public: 
		gameOfLife();
		void nextState();
		void printBoard();
	private:
		array<array<int, 3>, 3> board = {};
};