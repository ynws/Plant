#pragma once
#include "IOBase.h"

// L-System��ʕ`�ʃp�[�c
class DrawParts
{
protected:
	double posx_, posy_;	// �`�ʊ�ʒu�̑��Βl(1.0���݁BView�̃X�P�[���Ŋg��)
public:
	DrawParts(double posx, double posy) : posx_(posx), posy_(posy) {}
	virtual ~DrawParts() {};
	// TODO: ���̃N���X��View���������AModel����������B���������̂ō\���������ׂ�
	virtual void Draw(IOBase *io, int initx, int inity, int scale) = 0;
};

