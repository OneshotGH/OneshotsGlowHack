#include "Glow.h"
#include <iostream>
extern CHackProcess fProcess; // Same object thats in OneshotsGlowHack.cpp but we access it in here.
Offsets O; // Accessing the Offsets tru this object.



void Glow::Run()
{
	ReadInfo();
	
	for (int i = 0; i < 200; i++)
	{

		
		ReadEntity(i);
		Dick(i);

	}


}

void Glow::ReadInfo()
{
	ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(fProcess.__dwordClient + O.m_dwGlowObject), &GlowObject, sizeof(int), NULL);
	ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(fProcess.__dwordClient + O.m_dwLocalPlayer), &LocalPlayer, sizeof(int), NULL);
	ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(fProcess.__dwordClient + O.m_dwGlowObject), &GlowObject, sizeof(int), NULL);
	ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(LocalPlayer + O.m_iTeamNum), &LocalTeam, sizeof(int), NULL);

}
void Glow::ReadEntity(int Entnum)
{
	ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(GlowObject + 0x38 * Entnum), &Entity, sizeof(int), NULL);
	DWORD gBuffer = NULL;
	ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(Entity + 0x8), &gBuffer, sizeof(int), NULL);
	ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(gBuffer + 0x8), &gBuffer, sizeof(int), NULL);
	ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(gBuffer + 0x1), &gBuffer, sizeof(int), NULL);
	ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(gBuffer + 0x14), &ClassID, sizeof(int), NULL);
	ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(Entity + O.m_iTeamNum), &TeamNum, sizeof(int), NULL);
}
void Glow::GlowEntity(int Entnum)
{

	WriteProcessMemory(fProcess.__HandleProcess, (PBYTE*)(GlowObject + 0x38 * Entnum + 0x4), &O.EntGlow, sizeof(O.EntGlow), NULL);
}
void Glow::Dick(int i)
{

	switch (i) // to do make this 
	{
	default:
		break;
	}

	if (ClassID == 35)// base granade
	{
		if (LocalTeam != TeamNum)
		{
			O.EntGlow.red = 1;
			O.EntGlow.green = 0;
			O.EntGlow.blue = 0;
			O.EntGlow.alpha = 1;
			GlowEntity(i);
			return;
		}
		else
		{
			O.EntGlow.red = 0;
			O.EntGlow.green = 1;
			O.EntGlow.blue = 0;
			O.EntGlow.alpha = 1;
			GlowEntity(i);
			return;
		}
		
	}

	if (ClassID == 9)// base granade
	{
		O.EntGlow.red = 1;
		O.EntGlow.green = 0;
		O.EntGlow.blue = 0;
		O.EntGlow.alpha = 1;
		GlowEntity(i);
	}
	if (ClassID == 9)// base granade
	{
		O.EntGlow.red = 1;
		O.EntGlow.green = 0;
		O.EntGlow.blue = 0;
		O.EntGlow.alpha = 1;
		GlowEntity(i);
	}
	if (ClassID == 1) // ak47
	{
		O.EntGlow.red = 1;
		O.EntGlow.green = 0.3;
		O.EntGlow.blue = 0;
		O.EntGlow.alpha = 1;
		GlowEntity(i);
	}
	if (ClassID == 107)// plantad c4
	{
		O.EntGlow.red = 1;
		O.EntGlow.green = 0;
		O.EntGlow.blue = 1;
		O.EntGlow.alpha = 1;
		GlowEntity(i);
	}
	if (ClassID == 29)//c4
	{
		O.EntGlow.red = 0;
		O.EntGlow.green = 0;
		O.EntGlow.blue = 1;
		O.EntGlow.alpha = 1;
		GlowEntity(i);
	}
	if (ClassID == 233) // scar20
	{
		O.EntGlow.red = 0.3;
		O.EntGlow.green = 1;
		O.EntGlow.blue = 1;
		O.EntGlow.alpha = 1;
		GlowEntity(i);
	}
	if (ClassID == 204)// aug
	{
		O.EntGlow.red = 0;
		O.EntGlow.green = 1;
		O.EntGlow.blue = 0.1;
		O.EntGlow.alpha = 0.6;
		GlowEntity(i);
	}
	if (ClassID == 205)// awp
	{
		O.EntGlow.red = 0;
		O.EntGlow.green = 1;
		O.EntGlow.blue = 0;
		O.EntGlow.alpha = 1;
		GlowEntity(i);
	}
	if (ClassID == 207)// ppbizon
	{
		O.EntGlow.red = 1;
		O.EntGlow.green = 0;
		O.EntGlow.blue = 0;
		O.EntGlow.alpha = 0.6;
		GlowEntity(i);
	}
	if (ClassID == 2011)// elites
	{
		O.EntGlow.red = 0;
		O.EntGlow.green = 1;
		O.EntGlow.blue = 0;
		O.EntGlow.alpha = 0.6;
		GlowEntity(i);
	}
	if (ClassID == 212)// famas
	{
		O.EntGlow.red = 1;
		O.EntGlow.green = 0;
		O.EntGlow.blue = 0;
		O.EntGlow.alpha = 0.6;
		GlowEntity(i);
	}
	if (ClassID == 213)// fiveseven
	{
		O.EntGlow.red = 1;
		O.EntGlow.green = 0;
		O.EntGlow.blue = 0;
		O.EntGlow.alpha = 0.6;
		GlowEntity(i);
	}
	if (ClassID == 214)//G3SG1
	{
		O.EntGlow.red = 0.5;
		O.EntGlow.green = 1;
		O.EntGlow.blue = 1;
		O.EntGlow.alpha = 1;
		GlowEntity(i);
	}
	if (ClassID == 216)// gallil
	{
		O.EntGlow.red = 1;
		O.EntGlow.green = 0;
		O.EntGlow.blue = 0;
		O.EntGlow.alpha = 0.6;
		GlowEntity(i);
	}
	if (ClassID == 217) // glock
	{
		O.EntGlow.red = 1;
		O.EntGlow.green = 0;
		O.EntGlow.blue = 0;
		O.EntGlow.alpha = 0.6;
		GlowEntity(i);
	}
	if (ClassID == 218)// p2000
	{
		O.EntGlow.red = 1;
		O.EntGlow.green = 0;
		O.EntGlow.blue = 0;
		O.EntGlow.alpha = 0.6;
		GlowEntity(i);
	}
	if (ClassID == 219)//M249
	{
		O.EntGlow.red = 1;
		O.EntGlow.green = 0;
		O.EntGlow.blue = 0;
		O.EntGlow.alpha = 0.6;
		GlowEntity(i);
	}
	if (ClassID == 221)//M4A1
	{
		O.EntGlow.red = 1;
		O.EntGlow.green = 1;
		O.EntGlow.blue = 0;
		O.EntGlow.alpha = 1;
		GlowEntity(i);
	}
	if (ClassID == 222)//mac10
	{
		O.EntGlow.red = 1;
		O.EntGlow.green = 0;
		O.EntGlow.blue = 0;
		O.EntGlow.alpha = 0.6;
		GlowEntity(i);
	}
	if (ClassID == 223)//mag7
	{
		O.EntGlow.red = 1;
		O.EntGlow.green = 0;
		O.EntGlow.blue = 0;
		O.EntGlow.alpha = 0.6;
		GlowEntity(i);
	}
	if (ClassID == 225)//mp7
	{
		O.EntGlow.red = 1;
		O.EntGlow.green = 0;
		O.EntGlow.blue = 0;
		O.EntGlow.alpha = 0.6;
		GlowEntity(i);
	}
	if (ClassID == 226)//mp9
	{
		O.EntGlow.red = 1;
		O.EntGlow.green = 0;
		O.EntGlow.blue = 0;
		O.EntGlow.alpha = 0.6;
		GlowEntity(i);
	}
	if (ClassID == 227)//negev
	{
		O.EntGlow.red = 0.3;
		O.EntGlow.green = 0.3;
		O.EntGlow.blue = 1;
		O.EntGlow.alpha = 0.6;
		GlowEntity(i);
	}
	if (ClassID == 228)//nova
	{
		O.EntGlow.red = 1;
		O.EntGlow.green = 0;
		O.EntGlow.blue = 0;
		O.EntGlow.alpha = 0.6;
		GlowEntity(i);
	}
	if (ClassID == 230)//p250
	{
		O.EntGlow.red = 1;
		O.EntGlow.green = 0;
		O.EntGlow.blue = 0;
		O.EntGlow.alpha = 0.6;
		GlowEntity(i);
	}
	if (ClassID == 231)//p90
	{
		O.EntGlow.red = 1;
		O.EntGlow.green = 0;
		O.EntGlow.blue = 0;
		O.EntGlow.alpha = 0.6;
		GlowEntity(i);
	}
	if (ClassID == 232)//sawdoff
	{
		O.EntGlow.red = 1;
		O.EntGlow.green = 0;
		O.EntGlow.blue = 0;
		O.EntGlow.alpha = 0.6;
		GlowEntity(i);
	}
	if (ClassID == 238)//scout
	{
		O.EntGlow.red = 0;
		O.EntGlow.green = 1;
		O.EntGlow.blue = 1;
		O.EntGlow.alpha = 0.6;
		GlowEntity(i);
	}
	if (ClassID == 237)//sg556
	{
		O.EntGlow.red = 0;
		O.EntGlow.green = 1;
		O.EntGlow.blue = 0;
		O.EntGlow.alpha = 0.6;
		GlowEntity(i);
	}
	if (ClassID == 237)//tazer
	{
		O.EntGlow.red = 1;
		O.EntGlow.green = 0;
		O.EntGlow.blue = 0;
		O.EntGlow.alpha = 0.6;
		GlowEntity(i);
	}
	if (ClassID == 238)//tec9
	{
		O.EntGlow.red = 1;
		O.EntGlow.green = 0;
		O.EntGlow.blue = 0;
		O.EntGlow.alpha = 0.6;
		GlowEntity(i);
	}
	if (ClassID == 240)//ump
	{
		O.EntGlow.red = 1;
		O.EntGlow.green = 0;
		O.EntGlow.blue = 0;
		O.EntGlow.alpha = 0.6;
		GlowEntity(i);
	}
	if (ClassID == 242)//XM1014
	{
		O.EntGlow.red = 1;
		O.EntGlow.green = 0;
		O.EntGlow.blue = 0;
		O.EntGlow.alpha = 0.6;
		GlowEntity(i);
	}
	if (ClassID == 39)//desert eagle
	{
		O.EntGlow.red = 0;
		O.EntGlow.green = 1;
		O.EntGlow.blue = 0;
		O.EntGlow.alpha = 1;
		GlowEntity(i);
	}
	if (ClassID == 107)// plantad c4
	{
		O.EntGlow.red = 1;
		O.EntGlow.green = 0;
		O.EntGlow.blue = 1;
		O.EntGlow.alpha = 1;
		GlowEntity(i);
	}
	if (ClassID == 66)// flashbang
	{
		O.EntGlow.red = 0;
		O.EntGlow.green = 1;
		O.EntGlow.blue = 1;
		O.EntGlow.alpha = 1;
		GlowEntity(i);
	}
	if (ClassID == 84)// he
	{
		O.EntGlow.red = 1;
		O.EntGlow.green = 0;
		O.EntGlow.blue = 1;
		O.EntGlow.alpha = 1;
		GlowEntity(i);
	}
	if (ClassID == 96)// molotov ground
	{
		O.EntGlow.red = 1;
		O.EntGlow.green = 1;
		O.EntGlow.blue = 0;
		O.EntGlow.alpha = 1;
		GlowEntity(i);
	}
	if (ClassID == 97)// molotov air
	{
		O.EntGlow.red = 1;
		O.EntGlow.green = 1;
		O.EntGlow.blue = 0;
		O.EntGlow.alpha = 1;
		GlowEntity(i);
	}
	if (ClassID == 87)// insindiary
	{
		O.EntGlow.red = 1;
		O.EntGlow.green = 1;
		O.EntGlow.blue = 0;
		O.EntGlow.alpha = 1;
		GlowEntity(i); return;
	}
	if (ClassID == 40)// decoy
	{
		O.EntGlow.red = 1;
		O.EntGlow.green = 1;
		O.EntGlow.blue = 1;
		O.EntGlow.alpha = 1;
		GlowEntity(i); return;
	}
	if (ClassID == 41)// decoy air
	{
		O.EntGlow.red = 1;
		O.EntGlow.green = 1;
		O.EntGlow.blue = 1;
		O.EntGlow.alpha = 1;
		GlowEntity(i); return;
	}
}