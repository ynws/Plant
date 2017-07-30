#include "Game.h"

Game::Game(IOBase *io, LSystemView *lsystemview, LSystem *lsystem) :
	io_(io), view_(lsystemview), lsystem_(lsystem)
{
}

void Game::Update()
{
	// �g��k��
	int wheel = io_->GetMouseWheelRotVol();
	if (wheel > 0) {
		view_->SetStepSize((int)(view_->GetStepSize() * 1.5));
	}
	else if (wheel < 0) {
		view_->SetStepSize((int)(view_->GetStepSize() * 0.5));
	}

	// �`��ʒu�̒���
	// TODO: �}�E�X�Ǘ��N���X�쐬
}
