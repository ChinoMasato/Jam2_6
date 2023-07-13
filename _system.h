#pragma once

enum SCENE
{
	null, title, play, end, re
};

class parts
{
public:
	int pic;
	double x, y;
	bool live;
};

extern SCENE scene;