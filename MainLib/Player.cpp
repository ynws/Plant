#include "Player.h"
#include "IOStatus.h"

Player::Player(int x, int y) {
	x_ = x;
	y_ = y;
}

void Player::move(int key)
{
	if (key & eCursor::UP) y_--;
	if (key & eCursor::DOWN) y_++;
	if (key & eCursor::RIGHT) x_++;
	if (key & eCursor::LEFT) x_--;
}

int Player::getx() { return x_; }
int Player::gety() { return y_; }
