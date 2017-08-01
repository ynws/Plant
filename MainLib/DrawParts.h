#pragma once
#include "IOBase.h"

// L-System画面描写パーツ
class DrawParts
{
protected:
	double posx_, posy_;	// 描写基準位置の相対値(1.0刻み。Viewのスケールで拡大)
public:
	DrawParts(double posx, double posy) : posx_(posx), posy_(posy) {}
	virtual ~DrawParts() {};
	// TODO: このクラスはView相当だが、Modelが生成する。おかしいので構成見直すべき
	virtual void Draw(IOBase *io, int initx, int inity, int scale) = 0;
};

