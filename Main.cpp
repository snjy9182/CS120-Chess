#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <cctype>
#include <iostream>
#include "Game.h"
#include "Chess.h"
#include "Prompts.h"


using namespace std;

int main() {
    ChessGame chess;
    chess.setupBoard();
    chess.printBoard();
    Piece* current = chess.getPiece(Position(0, 7));
    int person = current->owner();
    int value = current->id();

    cout << person << value << endl;
	cout << "#########" << endl;

	Prompts::menu();

	cin >> ch;
	while(input != 1 || input != 2){
		cout << "Enter 1 or 2 as input." << endl;
		cin.get(input);
		input = (int)ch;
	}


}
