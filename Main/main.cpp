#include "Game.h"
#include "DxlibIO.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	SetOutApplicationLogValidFlag(false);	// ログを出力しない
	// TODO: Viewは解像度に依存すべき
	SetGraphMode(640, 480, 16);			// 解像度
	ChangeWindowMode(true);				// ウィンドウモード
	SetBackgroundColor(255, 255, 255);	// 背景色
	if (DxLib_Init() == -1) { return -1; }
	SetDrawScreen(DX_SCREEN_BACK); // 描画先画面を裏画面にセット

	int ticks = 0;
	LSystem model("");
	DxlibIO io;
	LSystemView view(&io, &model);
	Game controller(&io, &view, &model);

	// TODO: controllerで設定すべき？
	model.SetInitialString("F").AddRule("F", "FF-[-F+F+F]+[+F-F-F]").SetAngle(22.5);
	view.SetInitX(320).SetInitY(480);
	ticks = 4;

	// model.SetInitialString("X").AddRule("X", "F-[[X]+X]+F[+FX]-X").AddRule("F", "FF");
	// view.SetInitX(320).SetInitY(480).SetAngle(22.5).SetStepSize(12);
	// ticks = 5;

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		controller.Update();
		ClearDrawScreen();
		view.Draw(ticks);
		ScreenFlip();
	}

	DxLib_End();
	return 0;
}