#include "Game.h"

Game::Game(IOBase *io, LSystemView *lsystemview, LSystem *lsystem) :
	io_(io), view_(lsystemview), lsystem_(lsystem)
{
}

void Game::Update()
{
	// 拡大縮小
	int wheel = io_->GetMouseWheelRotVol();
	if (wheel > 0) {
		view_->SetStepSize((int)(view_->GetStepSize() * 1.5));
	}
	else if (wheel < 0) {
		view_->SetStepSize((int)(view_->GetStepSize() * 0.5));
	}

	// 描画位置の調整
	// TODO: マウス管理クラス作成
}
