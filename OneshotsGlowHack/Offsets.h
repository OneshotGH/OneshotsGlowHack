#pragma once
#include "OneshotsGlowHack.h"

class Offsets // Offset class to store all of our Offsets
{
public:

	struct Glow
	{
		float red = 1; 
		float green = 0; 
		float blue = 0;
		float alpha = 1.0;
		byte dick[8]; // just padding
		float buffer3 = 1;
		int buffer4 = 0;
		bool on = true;
	}EntGlow;

	DWORD m_dwLocalPlayer = 0xAACBAC;
	DWORD m_iHealth = 0xFC;
	DWORD m_bDormant = 0xE9;
	DWORD m_iTeamNum = 0xF0;
	DWORD m_dwGlowObject = 0x4FA6620;
	DWORD m_dwEntityList = 0x4A89C7C;
	DWORD m_iGlowIndex = 0xA300;
};

