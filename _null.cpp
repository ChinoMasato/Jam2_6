#include "DxLib.h"
#include "parts.h"

void init();
void draw();

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);
	SetGraphMode(800, 600, 32);

	if (DxLib_Init() == -1)
	{
		return -1;
	}
	SetDrawScreen(DX_SCREEN_BACK);
	
	init();

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {

		draw();

		ScreenFlip();
		ClearDrawScreen();
	}


	DxLib_End();

	return 0;
}

void init()
{
	init_parts();
}

void draw()
{
	draw_parts();
}