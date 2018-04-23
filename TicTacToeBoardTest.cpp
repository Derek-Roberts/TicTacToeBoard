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

TEST(TicTacToeBoardTest, getWinner)
{
	TicTacToeBoard obj;
	ASSERT_TRUE( obj.getWinner() );
}

TEST(TicTacToeBoardTest, getPieceTest)
{
	TicTacToeBoard obj;
	ASSERT_TRUE( obj.getPiece(0,0) );
}