#include "Game.h"
#include "DxlibIO.h"

#ifdef __ANDROID__
int android_main(void)
#else
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
#endif
{
	SetOutApplicationLogValidFlag(false);	// ���O���o�͂��Ȃ�
	// TODO: View�͉𑜓x�Ɉˑ����ׂ�
	SetGraphMode(640, 480, 16);			// �𑜓x
#ifndef __ANDROID__
	ChangeWindowMode(true);				// �E�B���h�E���[�h
#endif
	SetBackgroundColor(255, 255, 255);	// �w�i�F
	if (DxLib_Init() == -1) { return -1; }
	SetDrawScreen(DX_SCREEN_BACK); // �`����ʂ𗠉�ʂɃZ�b�g

	int ticks = 0;
	LSystem model("");
	DxlibIO io;
	LSystemView view(&io, &model);
	Game controller(&io, &view, &model);

	// TODO: controller�Őݒ肷�ׂ��H
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