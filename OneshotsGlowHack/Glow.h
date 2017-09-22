#pragma once
#include "OneshotsGlowHack.h"
#include "Offsets.h"

class Glow
{
public:

	void Run();

	void ReadInfo();

	void ReadEntity(int Entnum);

	void GlowEntity(int Entnum);

	void GlowEntitys(int i);

	void SetColor(float r, float g, float b, float a);



private:

	DWORD LocalTeam = 0;
	DWORD GlowObject = 0;
	DWORD LocalPlayer = 0;
	DWORD Entity = 0;
	DWORD EntityList = 0;
	DWORD Health = 0;
	DWORD IsDormant = 0;
	DWORD GlowIndex = 0;
	DWORD TeamNum = 0;
	DWORD ClassID = 0;

	enum ClassIDs: int {
		AK47 = 1,
		BaseCSGrenade = 8,
		BaseCSGrenadeProjectile = 9,
		Player = 35,
		C4 = 29,
		Chicken = 31,
		Eagle = 39,
		Decoy = 40,
		DecoyProjectile = 41,
		Flashbang = 66,
		CHEGrenade = 84,
		Hostage = 85,
		HostageCarriableProp = 86,
		IncendiaryGrenade = 87,
		Item_Healthshot = 91,
		MolotovGrenade = 97,
		MolotovProjectile = 98,
	    PlantedC4 = 108,
		SensorGrenade = 129,
		SensorGrenadeProjectile = 130,
		SmokeGrenade = 133,
		SmokeGrenadeProjectile = 134,
		WeaponAug = 204,
		WeaponAWP = 205,
		WeaponBizon = 207,
		WeaponElite = 211,
		WeaponFamas = 212,
		WeaponFiveSeven = 213,
		WeaponG3SG1 = 214,
		WeaponGalilAR = 216,
		WeaponGlock = 217,
		WeaponHKP2000 = 218,
		WeaponM249 = 219,
		WeaponM4A1 = 221,
		WeaponMAC10 = 222,
		WeaponMag7 = 223,
		WeaponMP7 = 225,
		WeaponMP9 = 226,
		WeaponNegev = 227,
		WeaponNOVA = 228,
		WeaponP250 = 230,
		WeaponP90 = 231,
		WeaponSawedoff = 232,
		WeaponSCAR20 = 233,
		WeaponSG556 = 237,
		WeaponSSG08 = 238,
		WeaponTaser = 239,
		WeaponTec9 = 240,
		WeaponUMP45 = 242,
		WeaponUSP = 243,
		WeaponXM1014 = 244
	};
	
	
	

};
