#pragma once
#include "OneshotsGlowHack.h"

class Offsets // Offset class to store all of our Offsets
{
public:

	struct GlowStruct // The glowstruct that we are gonna write to the GlowObjectArray
	{
		float red = 1.f; 
		float green = 0.f;
		float blue = 0.f;
		float alpha = 1.f;
		byte Padd[8]; // just padding
		float buffer3 = 1.f;
		int buffer4 = 0 ;
		bool on = true;
		
	};
	//-----------Offsets-------------
	DWORD m_dwLocalPlayer = 0xAACBFC;
	DWORD m_iHealth = 0xFC;
	DWORD m_iTeamNum = 0xF0;
	DWORD m_dwGlowObject = 0x4FA6870;
	DWORD m_dwEntityList = 0x4A89E5C;
	//-------------------------------
};

