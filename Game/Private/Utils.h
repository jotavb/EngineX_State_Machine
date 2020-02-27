#pragma once
#include "Engine/Public/EngineInterface.h"

namespace Utils
{
	static exColor* GetColorRGB(int r, int g, int b, int a)
	{
		exColor* c = new exColor();
		c->mColor[0] = r;
		c->mColor[1] = g;
		c->mColor[2] = b;
		c->mColor[3] = a;
		return c;
	}

	static void SetColorRGB(exColor* c, int r, int g, int b, int a)
	{
		c->mColor[0] = r;
		c->mColor[1] = g;
		c->mColor[2] = b;
		c->mColor[3] = a;
	}
}