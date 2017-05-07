#undef FOR_RELEASE

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Game.h"
#include "Chess.h"
#include "Prompts.h"
#include "Terminal.h"


using namespace std;


// Make a move on the board. Return an int, with < 0 being failure
int ChessGame::makeMove(Position start, Position end) {
    // Possibly implement chess-specific move logic here
    //
    // We call Board's makeMove to handle any general move logic
    // Feel free to use this or change it as you see fit
    int retCode = Board::makeMove(start, end);
    return retCode;
}

// Setup the chess board with its initial pieces
void ChessGame::setupBoard() {
    std::vector<int> pieces {
        ROOK_ENUM, KNIGHT_ENUM, BISHOP_ENUM, QUEEN_ENUM,
        KING_ENUM, BISHOP_ENUM, KNIGHT_ENUM, ROOK_ENUM
    };
    for (size_t i = 0; i < pieces.size(); ++i) {
        initPiece(PAWN_ENUM, WHITE, Position(i, 1));
        initPiece(pieces[i], WHITE, Position(i, 0));
        initPiece(pieces[i], BLACK, Position(i, 7));
        initPiece(PAWN_ENUM, BLACK, Position(i, 6));

    }
}


// displays the board //CHANGECHANGECHANGECHANGECHANGECHANGECHANGECHANGECHANGECHANGE
void ChessGame::printBoard() {
    int row = 8;
    for (unsigned int i = 0; i < height(); i++) {
        cout << row << " ";
        row--;
        for (unsigned int j = 0; j < width(); j++) {
            Piece* current = getPiece(Position(j, height()-i-1));
            if ((i + j) % 2 == 0) {
                Terminal::colorBg(Terminal::BLACK);
            } else {
                Terminal::colorBg(Terminal::RED);
            }
            Terminal::colorFg(true, Terminal::WHITE);
            if (current == NULL) {
                std::cout << "   ";
            }
            else {
                int person = current->owner();
                int value = current->id();
                // black pieces
                if (person == 1 && value == 0) { // black pawn
                    cout << " \u265F" << " ";
                }
                if (person == 1 && value == 1) { // black rook
                    cout << " \u265C" << " ";  
                }
                if (person == 1 && value == 2) { // black knight
                    cout << " \u265E" << " ";
                }
                if (person == 1 && value == 3) { // black bishop
                    cout << " \u265D" << " ";
                }
                if (person == 1 && value == 4) { // black queen
                    cout << " \u265B" << " ";
                }
                if (person == 1 && value == 5) { // black king
                    cout << " \u265A" << " ";
                }
                // white pieces
                if (person == 0 && value == 0) { // white pawn
                    cout << " \u2659" << " ";
                }
                if (person == 0 && value == 1) { // white rook
                    cout << " \u2656" << " ";
                }
                if (person == 0 && value == 2) { // white knight
                    cout << " \u2658" << " ";
                }
                if (person == 0 && value == 3) { // white bishop
                    cout << " \u2657" << " ";
                }
                if (person == 0 && value == 4) { // white queen
                    cout << " \u2655" << " ";
                }
                if (person == 0 && value == 5) { // white king
                    cout << " \u2654"<< " ";
                }
            }
            Terminal::set_default();
        }
        cout<<endl;
    }
    cout << "   a  b  c  d  e  f  g  h" << endl;
}
