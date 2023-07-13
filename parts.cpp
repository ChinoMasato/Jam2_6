#include "DxLib.h"
#include "parts.h"

parts pa[10];

void init_parts()
{
	pa[0].pic = LoadGraph("me_migi.png");
	pa[1].pic = LoadGraph("me_hidari.png");
	pa[2].pic = LoadGraph("hana.png");
	pa[3].pic = LoadGraph("kuti.png");
	pa[4].pic = LoadGraph("mimi_migi.png");
	pa[5].pic = LoadGraph("mimi_hidari.png");
	pa[6].pic = LoadGraph("te_migi.png");
	pa[7].pic = LoadGraph("te_hidari.png");
	pa[8].pic = LoadGraph("asi_migi.png");
	pa[9].pic = LoadGraph("asi_hidari.png");

	for (int i = 0; i < 10; i++)
	{
		pa[i].x = 0;
		pa[i].y = 0;
		pa[i].live = true;
	}
}

void draw_parts()
{
	for (int i = 0; i < 10; i++)
	{
		DrawGraph(pa[i].x, pa[i].y, pa[i].pic, pa[i].live);
	}
}