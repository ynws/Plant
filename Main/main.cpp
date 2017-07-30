#include "Game.h"
#include "DxlibIO.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	SetOutApplicationLogValidFlag(false);	// ログを出力しない
	SetGraphMode(640, 480, 16);			// 解像度
	ChangeWindowMode(true);				// ウィンドウモード
	SetBackgroundColor(255, 255, 255);	// 背景色
	if (DxLib_Init() == -1) { return -1; }
	SetDrawScreen(DX_SCREEN_BACK); // 描画先画面を裏画面にセット

	int ticks = 0;
	LSystem model("");
	DxlibIO io;
	LSystemView view(&io, &model);
	Game controller(&view, &model);

	// コッホ曲線
	// model.SetInitialString("-F").AddRule("F", "F+F-F-F+F");
	// view.SetInitX(40).SetInitY(350).SetStepSize(7);
	// ticks = 3;
	// コッホ島
	// model.SetInitialString("F-F-F-F").AddRule("F", "F+FF-FF-F-F+F+FF-F-F+F+FF+FF-F");
	// view.SetInitX(440);
	// ticks = 2;
	// 派生1
	// model.SetInitialString("F-F-F-F").AddRule("F", "FF-F-F-F-F-F+F");
	// view.SetInitX(440).SetInitY(200);
	// ticks = 3;
	// ドラゴン曲線
	model.SetInitialString("A").AddRule("A", "A+B+").AddRule("B", "-A-B");
	view.SetInitX(340).SetInitY(150).SetStepSize(4);
	ticks = 12;
	// シェルピンスキーのギャスケット
	// model.SetInitialString("B").AddRule("A", "B+A+B").AddRule("B", "A-B-A");
	// view.SetInitX(240).SetInitY(350).SetStepSize(6).SetAngle(60);
	// ticks = 2;

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