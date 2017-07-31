#include "Game.h"

Game::Game(IOBase *io, LSystemView *lsystemview, LSystem *lsystem) :
	io_(io), view_(lsystemview), lsystem_(lsystem), mouse_(io)
{
}

void Game::Update()
{
	mouse_.Update();
	// Šg‘åk¬
	if (mouse_.GetWheel() > 0) {
		view_->SetStepSize((int)(view_->GetStepSize() * 1.5));
	}
	else if (mouse_.GetWheel() < 0) {
		view_->SetStepSize((int)(view_->GetStepSize() * 0.5));
	}

	// •`‰æˆÊ’u‚Ì’²®
	if (mouse_.IsLeftPressed()) {
		view_->SetInitX(view_->GetInitX() + mouse_.GetDx());
		view_->SetInitY(view_->GetInitY() + mouse_.GetDy());
	}
}
