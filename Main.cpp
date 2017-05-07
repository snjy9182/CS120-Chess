#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Game.h"
#include "Chess.h"
#include "Prompts.h"

using namespace std;

int main() {

	//Prompt, ensuring the inputs are 1 or 2.
	int promptValid = 1;
	int input;
	while(promptValid){
		Prompts::menu();
		string str;
		cin >> str;
		input = stoi(str);
		if (input != 1 && input != 2){
			cout << "Enter 1 or 2 as input." << endl;
		} else {
			promptValid = 0;
		}
	}
	if (input == 1){

		//Set up initial board and first turn.
		ChessGame chess;
    	chess.setupBoard();
    	int gameGone = 0;
    	Player p = WHITE;
    	int turn = 1;
    	bool boardToggle = false;

    	//Turns.
    	while(!gameGone){
    		cout << p << " turn " << turn << ": " << endl;
    		string turnInput;
    		if (turn == 1 && !boardToggle){
    			getline(cin, turnInput);
    		}
    		getline(cin, turnInput);
    		if (turnInput[0]== 'q'){
    			cout << "Quitting program..." << endl;
    			break;
    		}
    		if (!turnInput.compare("board")){
				boardToggle = !boardToggle;
    			if (boardToggle){
    				chess.printBoard();
    			}
    			continue;
    		}
    	
			int StartCol = (int)turnInput[0] - 97;
			int StartRow = (int)turnInput[1] - 48;
			int EndCol = (int)turnInput[3] - 97;
			int EndRow = (int)turnInput[4] - 48;

			if (turnInput.length() > 5){
				Prompts::parseError();
			}
			//cout << StartCol << StartRow<< EndRow << EndCol << endl;
			Position *startPosition = new Position(StartCol, StartRow);
			Position *endPosition = new Position(EndCol, EndRow);
			int move = chess.makeMove(*startPosition, *endPosition);
			//chess.initPiece(NULL, WHITE, Position(StartCol, StartRow));
			//Position *startPosition = new Position(StartCol, StartRow);
			//Position *endPosition = new Position(EndCol, EndRow);
			//int move = chess.makeMove(*startPosition, *endPosition);
			delete startPosition;
			delete endPosition;
			if (boardToggle){
    			chess.printBoard();
    		}
    		//Set up for next turn.
    		if (p == 0)
    			p = BLACK;
    		else
    			p = WHITE;
			turn++;
    	}

	}

	return 0;
}
