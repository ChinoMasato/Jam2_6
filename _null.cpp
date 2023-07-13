#include "DxLib.h"
#include "parts.h"
#include "scene.h"
#include "_system.h"

void init();
void update();
void draw();
SCENE scene = title;

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
	PlayMusic("bgmハープ.mp3", DX_PLAYTYPE_LOOP);

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {

		if (scene == re)
		{
			init();
			scene = title;
		}

		update();

		draw();

		ScreenFlip();
		ClearDrawScreen();
	}


	DxLib_End();

	return 0;
}

void init()
{
	init_scene();
	init_parts();
}

void update()
{
	up_scene();
	up_parts();
}

void draw()
{
	DrawGraph(0, 0, pa[11].pic, true);
	draw_parts();
	draw_scene();
}