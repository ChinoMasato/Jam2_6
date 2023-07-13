#include "DxLib.h"
#include "scene.h"
#include "parts.h"
#include "_system.h"

int c;

void init_scene()
{
	c = LoadSoundMem("Œˆ’è (1).mp3");

	pa[11].pic = LoadGraph("wahu46.png");
	pa[12].pic = LoadGraph("title.png");
	pa[13].pic = LoadGraph("start.png");
	pa[14].pic = LoadGraph("mozi_0.png");
	pa[15].pic = LoadGraph("mozi_1.png");
	pa[16].pic = LoadGraph("mozi_2.png");
	pa[17].pic = LoadGraph("mozi_3.png");
	pa[18].pic = LoadGraph("mozi_4.png");
	pa[19].pic = LoadGraph("wahu46.png");
	pa[20].pic = LoadGraph("mozi_5.png");
	pa[21].pic = LoadGraph("1190417.png");
}

void up_scene()
{
	if(scene == title)
	{
		pa[11].y = 0;
		pa[12].x = 200;
		pa[12].y = 100;
		pa[13].x = 280;
		pa[13].y = 335;

		for (int i = 11; i <= 19; i++)
		{
			pa[i].live = true;
		}

		if (CheckHitKey(KEY_INPUT_SPACE) == 1)
		{
			PlaySoundMem(c, DX_PLAYTYPE_BACK);
			scene = null;
			pa[14].x = 500;
			pa[14].y = -100;
			pa[15].x = 300;
			pa[15].y = 0;
			pa[16].x = 300;
			pa[16].y = 100;
			pa[17].x = 300;
			pa[17].y = 200;
			pa[18].x = 300;
			pa[18].y = 300;
			pa[21].y = -900;
		}
	}

	if (scene == null)
	{
		pa[11].y = pa[11].y - 2;
		pa[12].y = pa[12].y - 2;
		pa[13].y = pa[13].y - 2;

		if (pa[11].y <= -2000)
		{
			for (int i = 11; i <= 19; i++)
			{
				pa[i].y = pa[i].y - 2;
			}

			for (int i = 0; i <= 21; i++)
			{
				pa[i].live = true;
				pa[20].live = false;
			}
		}

		if (pa[18].y <= -1500)
		{
			pa[21].y = pa[21].y + 2;
			if (pa[21].y >= 0)
			{
				pa[21].y = 0;
				for (int i = 0; i < pa_; i++)
				{
					pa[i].live = false;
					pa[0].live = true;
					pa[11].live = true;
					pa[18].live = true;
					pa[21].live = true;
				}
				scene = play;
			}
		}
	}
}

void draw_scene()
{
	DrawGraph(pa[19].x, pa[19].y, pa[19].pic, pa[19].live);
	DrawGraph(pa[14].x, pa[14].y, pa[14].pic, pa[14].live);
	DrawGraph(pa[15].x, pa[15].y, pa[15].pic, pa[15].live);
	DrawGraph(pa[16].x, pa[16].y, pa[16].pic, pa[16].live);
	DrawGraph(pa[17].x, pa[17].y, pa[17].pic, pa[17].live);
	DrawGraph(pa[18].x, pa[18].y, pa[18].pic, pa[18].live);
	DrawGraph(pa[11].x, pa[11].y, pa[11].pic, pa[11].live);
	DrawGraph(pa[12].x, pa[12].y, pa[12].pic, pa[12].live);
	DrawGraph(pa[13].x, pa[13].y, pa[13].pic, pa[13].live);
}