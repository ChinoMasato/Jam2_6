#include "DxLib.h"
#include "parts.h"
#include "_system.h"

parts pa[pa_];
int a = 0;

void init_parts()
{
	pa[0].pic = LoadGraph("karada.png");
	pa[1].pic = LoadGraph("me_migi.png");
	pa[2].pic = LoadGraph("me_hidari.png");
	pa[3].pic = LoadGraph("hana.png");
	pa[4].pic = LoadGraph("kuti.png");
	pa[5].pic = LoadGraph("mimi_migi.png");
	pa[6].pic = LoadGraph("mimi_hidari.png");
	pa[7].pic = LoadGraph("te_migi.png");
	pa[8].pic = LoadGraph("te_hidari.png");
	pa[9].pic = LoadGraph("asi_migi.png");
	pa[10].pic = LoadGraph("asi_hidari.png");

	for (int i = 0; i < pa_; i++)
	{
		pa[i].x = 0;
		pa[i].y = 0;
		pa[i].live = false;
	}
}

void up_parts()
{
	if (scene == play)
	{
		if (CheckHitKey(KEY_INPUT_UP) == 1)
		{
			pa[a].y = pa[a].y - 2;
		}
		if (CheckHitKey(KEY_INPUT_DOWN) == 1)
		{
			pa[a].y = pa[a].y + 2;
		}
		if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
		{
			pa[a].x = pa[a].x + 2;
		}
		if (CheckHitKey(KEY_INPUT_LEFT) == 1)
		{
			pa[a].x = pa[a].x - 2;
		}

		if (CheckHitKey(KEY_INPUT_1) == 1)
		{
			pa[1].x = -300;
			pa[1].y = 400;
			pa[1].live = true;
			a = 1;
		}
		if (CheckHitKey(KEY_INPUT_2) == 1)
		{
			pa[2].x = -310;
			pa[2].y = 400;
			pa[2].live = true;
			a = 2;
		}
		if (CheckHitKey(KEY_INPUT_9) == 1)
		{
			pa[3].x = -330;
			pa[3].y = 390;
			pa[3].live = true;
			a = 3;
		}
		if (CheckHitKey(KEY_INPUT_0) == 1)
		{
			pa[4].x = -330;
			pa[4].y = 380;
			pa[4].live = true;
			a = 4;
		}
		if (CheckHitKey(KEY_INPUT_7) == 1)
		{
			pa[5].x = -185;
			pa[5].y = 440;
			pa[5].live = true;
			a = 5;
		}
		if (CheckHitKey(KEY_INPUT_8) == 1)
		{
			pa[6].x = -430;
			pa[6].y = 440;
			pa[6].live = true;
			a = 6;
		}
		if (CheckHitKey(KEY_INPUT_3) == 1)
		{
			pa[7].x = -300;
			pa[7].y = 200;
			pa[7].live = true;
			a = 7;
		}
		if (CheckHitKey(KEY_INPUT_4) == 1)
		{
			pa[8].x = -310;
			pa[8].y = 200;
			pa[8].live = true;
			a = 8;
		}
		if (CheckHitKey(KEY_INPUT_5) == 1)
		{
			pa[9].x = -300;
			pa[9].y = 100;
			pa[9].live = true;
			a = 9;
		}
		if (CheckHitKey(KEY_INPUT_6) == 1)
		{
			pa[10].x = -310;
			pa[10].y = 100;
			pa[10].live = true;
			a = 10;
		}

		if (CheckHitKey(KEY_INPUT_RETURN) == 1)
		{
			pa[20].live = true;
			pa[20].x = 280;
			pa[20].y = 320;
			scene = end;
		}
	}

	if (scene == end)
	{
		pa[21].y = pa[21].y - 2;

		if (pa[21].y <= -600)
		{
			if (CheckHitKey(KEY_INPUT_RETURN) == 1)
			{
				scene = re;
			}
		}
	}
}

void draw_parts()
{
	for (int i = 0; i <= 21; i++)
	{
		if (pa[i].live == true)
		{
			DrawGraph(pa[i].x, pa[i].y, pa[i].pic, pa[i].live);
		}
	}
}