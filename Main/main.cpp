#include "DxLib.h"
#include "Player.h"
#include "DxlibIO.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	SetOutApplicationLogValidFlag(false);	// ���O���o�͂��Ȃ�
	SetGraphMode(640, 480, 16);			// �𑜓x
	ChangeWindowMode(true);				// �E�B���h�E���[�h
	SetBackgroundColor(255, 255, 255);	// �w�i�F
	if (DxLib_Init() == -1) { return -1; }
	SetDrawScreen(DX_SCREEN_BACK); // �`����ʂ𗠉�ʂɃZ�b�g

	DxlibIO io;
	Player player(10, 10);

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		int key = io.GetCursorInput(DX_INPUT_KEY_PAD1);
		player.move(key);

		ClearDrawScreen();

		io.DrawCircle(player.getx() * 3, player.gety() * 3, 10, GetColor(255,255,255), TRUE);

		ScreenFlip();
	}

	DxLib_End();
	return 0;
}