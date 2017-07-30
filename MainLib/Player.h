#pragma once

class Player
{
private:
	int x_, y_;
public:
	Player(int x, int y);
	void move(int key);
	int getx();
	int gety();
};