#include "DxLib.h"
#include "Game.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	SetOutApplicationLogValidFlag(false);	// ログを出力しない
	SetGraphMode(640, 480, 16);			// 解像度
	ChangeWindowMode(true);				// ウィンドウモード
	SetBackgroundColor(255, 255, 255);	// 背景色
	if (DxLib_Init() == -1) { return -1; }
	SetDrawScreen(DX_SCREEN_BACK); // 描画先画面を裏画面にセット

	LSystem model("F-F-F-F", "F", "F-F+F+FF-F-F+F");
	LSystemView view(&model);
	Game controller(&view, &model);

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		controller.Update();
		ClearDrawScreen();
		view.Draw();
		ScreenFlip();
	}

	DxLib_End();
	return 0;
}