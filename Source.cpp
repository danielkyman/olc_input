#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

#include <array>
#include <cstdint>
#include <algorithm>

class Example : public olc::PixelGameEngine
{
public:
	Example()
	{

		sAppName = "Example";
	}

	olc::vf2d vPlayerPos;
	float fPlayerSpeed = 100.0f;



public:
	bool OnUserCreate() override
	{
		vPlayerPos = { (float)ScreenWidth() / 2, (float)ScreenHeight() / 2 };

		return true;
	}
	bool OnUserUpdate(float fElapsedTime) override
	{
		if (GetKey(olc::W).bHeld) vPlayerPos.y -= fPlayerSpeed * fElapsedTime;
		if (GetKey(olc::S).bHeld) vPlayerPos.y += fPlayerSpeed * fElapsedTime;
		if (GetKey(olc::A).bHeld) vPlayerPos.x -= fPlayerSpeed * fElapsedTime;
		if (GetKey(olc::D).bHeld) vPlayerPos.x += fPlayerSpeed * fElapsedTime;



		Clear(olc::DARK_RED);

		DrawCircle(vPlayerPos, 8, olc::WHITE);
		
		return true;
	}
};

int main()
{
	Example demo;
	if (demo.Construct(256, 240, 4, 4))
		demo.Start();
	return 0;
}