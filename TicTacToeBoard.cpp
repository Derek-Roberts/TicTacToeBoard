#include "TicTacToeBoard.h"
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
  turn = X;
  for(int i=0; i<BOARDSIZE; i++)
    for(int j=0; j<BOARDSIZE; j++)
      board[i][j] = Blank;
}

/**
 * Switches turn member variable to represent whether it's X's or O's turn
 * and returns whose turn it is
**/
Piece TicTacToeBoard::toggleTurn()
{
	switch(turn) {
		case X: turn = O; return turn;
		case O: turn = X; return turn;
		default: break;
	}
	return Invalid;
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does 
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location. 
 * Out of bounds coordinates return the Piece Invalid value. When the game
 * is over, no more pieces can be placed so attempting to place a piece
 * should neither change the board nor change whose turn it is.
**/ 
Piece TicTacToeBoard::placePiece(int row, int column)
{
	// If the space is blank
	if (board[row][column] == Blank) {
		Piece newPiece = turn;
		board[row][column] = newPiece;
		toggleTurn();
		return newPiece;
	}
	// If the space is not blank
	else if (board[row][column] == X || board[row][column] == O) {
		return board[row][column];
	}
	// If the space is neither blank or not blank: an error has occured
	else {
		return Invalid;
	}
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
	if ((row < 0 || row > BOARDSIZE) || (column < 0 || column > BOARDSIZE)) {
		return Invalid;
	}
	else if (board[row][column] == Blank) {
		return Blank;
	}
	else if (board[row][column] == X || board[row][column] == O) {
		return board[row][column];
	}
	else {
		return Invalid;
	}
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{
	// Check for row winner
	for(int i=0; i<BOARDSIZE; i++)
		if (getPiece(i,0) == getPiece(i,1) && getPiece(i,1) == getPiece(i,2) && getPiece(i,0) != Blank)
			return (turn);
	
	// Check for column winner
	for(int i=0; i<BOARDSIZE; i++)
		if (getPiece(0,i) == getPiece(1,i) && getPiece(1,i) == getPiece(2,i) && getPiece(0,i) != Blank)
			return (turn);
	
	// Check for diagonal winner
	if (getPiece(0,0) == getPiece(1,1) && getPiece(1,1) == getPiece(2,2) && getPiece(0,0) != Blank)
        return(turn);
         
  if (getPiece(0,2) == getPiece(1,1) && getPiece(1,1) == getPiece(2,0) && getPiece(0,2) != Blank)
        return(turn);
	
  return Invalid;
}