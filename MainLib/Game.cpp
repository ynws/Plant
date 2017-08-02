#include "Game.h"

Game::Game(IOBase *io, LSystemView *lsystemview, LSystem *lsystem) :
	io_(io), view_(lsystemview), lsystem_(lsystem), mouse_(io)
{
}

void Game::Update()
{
	mouse_.Update();
	// �g��k��
	if (mouse_.GetWheel() > 0) {
		view_->SetScale((int)(view_->GetScale() * 1.5));
	}
	else if (mouse_.GetWheel() < 0) {
		view_->SetScale((int)(view_->GetScale() * 0.5));
	}

	// �`��ʒu�̒���
	if (mouse_.IsLeftPressed()) {
		view_->SetInitX(view_->GetInitX() + mouse_.GetDx());
		view_->SetInitY(view_->GetInitY() + mouse_.GetDy());
	}
}
