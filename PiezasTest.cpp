/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(PiezasTest, create_board)
{
	Piezas game;
	ASSERT_EQ(game.pieceAt(0,0), Blank);
}

TEST(PiezasTest, drop_piece_x)
{
	Piezas game;
	ASSERT_EQ(game.dropPiece(0), X);
}

TEST(PiezasTest, drop_piece_o)
{
	Piezas game;
	game.dropPiece(0);
	ASSERT_EQ(game.dropPiece(0), O);
}

TEST(PiezasTest, drop_piece_lower_bounds)
{
	Piezas game;
	ASSERT_EQ(game.dropPiece(-1), Invalid);
}

TEST(PiezasTest, drop_piece_higher_bounds)
{
	Piezas game;
	ASSERT_EQ(game.dropPiece(99), Invalid);
}

TEST(PiezasTest, drop_piece_full)
{
	Piezas game;
	game.dropPiece(0);
	game.dropPiece(0);
	game.dropPiece(0);
	ASSERT_EQ(game.dropPiece(0), Blank);
}

TEST(PiezasTest, piece_at_x)
{
	Piezas game;
	game.dropPiece(0);	
	ASSERT_EQ(game.pieceAt(0,0), X);
}

TEST(PiezasTest, piece_at_y)
{
	Piezas game;
	game.dropPiece(0);	
	game.dropPiece(0);	
	ASSERT_EQ(game.pieceAt(0,1), O);
}

TEST(PiezasTest, piece_at_outside_bounds)
{
	Piezas game;
	ASSERT_EQ(game.pieceAt(-1,-1), Invalid);
}

/*
TEST(PiezasTest, piece_at_outside_bounds)
{
	Piezas game;
	ASSERT_EQ(game.pieceAt(-1,-1), Invalid);
}
*/
