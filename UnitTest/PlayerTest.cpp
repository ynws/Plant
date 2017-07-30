#include <gtest/gtest.h>
#include "Player.h"
#include "IOStatus.h"

TEST(Player, init) {
	Player p(1, 3);
	EXPECT_EQ(p.getx(), 1);
	EXPECT_EQ(p.gety(), 3);
}

TEST(Player, move) {
	Player p(1, 3);
	p.move(eCursor::UP);
	EXPECT_EQ(p.getx(), 1);
	EXPECT_EQ(p.gety(), 2);
	p.move(eCursor::RIGHT);
	EXPECT_EQ(p.getx(), 2);
	EXPECT_EQ(p.gety(), 2);
	p.move(eCursor::DOWN);
	EXPECT_EQ(p.getx(), 2);
	EXPECT_EQ(p.gety(), 3);
	p.move(eCursor::LEFT);
	EXPECT_EQ(p.getx(), 1);
	EXPECT_EQ(p.gety(), 3);
	p.move(eCursor::NONE);
	EXPECT_EQ(p.getx(), 1);
	EXPECT_EQ(p.gety(), 3);
}