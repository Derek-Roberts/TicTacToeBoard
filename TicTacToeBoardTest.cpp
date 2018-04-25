/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

// EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, sanityCheck)
{
	TicTacToeBoard obj;
	ASSERT_TRUE(true);
}

TEST(TicTacToeBoardTest, toggleTurnTest)
{
	TicTacToeBoard obj;
	ASSERT_TRUE( obj.toggleTurn() );
}

TEST(TicTacToeBoardTest, placePieceAfterWinTest)
{
	TicTacToeBoard obj;
	obj.placePiece(0,0);
	obj.placePiece(1,1);
	obj.placePiece(0,1);
	obj.placePiece(1,2);
	obj.placePiece(0,2);
	// The winner is 'O' now trying to place a piece
	ASSERT_TRUE( obj.placePiece(0,0) );
}

TEST(TicTacToeBoardTest, placePieceOutOfBoundsTest)
{
	TicTacToeBoard obj;
	ASSERT_TRUE( obj.placePiece(-1,0) == '?');
}

TEST(TicTacToeBoardTest, getWinnerRowTest)
{
	TicTacToeBoard obj;
	obj.placePiece(0,0);
	obj.placePiece(1,1);
	obj.placePiece(0,1);
	obj.placePiece(1,2);
	obj.placePiece(0,2);
	ASSERT_TRUE( obj.getWinner() == 'O' );
}

TEST(TicTacToeBoardTest, getWinnerColumnTest)
{
	TicTacToeBoard obj;
	obj.placePiece(0,0);
	obj.placePiece(1,0);
	obj.placePiece(2,0);
	ASSERT_TRUE( obj.getWinner() );
}

TEST(TicTacToeBoardTest, getWinnerDiagonalTest)
{
	TicTacToeBoard obj;
	obj.placePiece(0,0);
	obj.placePiece(1,1);
	obj.placePiece(2,2);
	ASSERT_TRUE( obj.getWinner() );
}

TEST(TicTacToeBoardTest, getPieceTest)
{
	TicTacToeBoard obj;
	ASSERT_TRUE( obj.getPiece(0,0) );
}