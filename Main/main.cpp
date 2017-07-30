#include "DxLib.h"
#include "Game.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	SetOutApplicationLogValidFlag(false);	// ���O���o�͂��Ȃ�
	SetGraphMode(640, 480, 16);			// �𑜓x
	ChangeWindowMode(true);				// �E�B���h�E���[�h
	SetBackgroundColor(255, 255, 255);	// �w�i�F
	if (DxLib_Init() == -1) { return -1; }
	SetDrawScreen(DX_SCREEN_BACK); // �`����ʂ𗠉�ʂɃZ�b�g

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