#include "Glow.h"

extern CHackProcess fProcess; // Same object thats in OneshotsGlowHack.cpp but we access it in here.
Offsets O; // Accessing the Offsets tru this object.
Offsets::GlowStruct EntGlow; // GlowStruct 

void Glow::Run()
{
	ReadInfo();
	
	for (int i = 0; i < 200; i++) // current glowcount and max glowcount have been removed? thats why i just put 200
	{
		ReadEntity(i);
		GlowEntitys(i);
	}
}

void Glow::ReadInfo(){ 
	
	ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(fProcess.__dwordClient + O.m_dwLocalPlayer), &LocalPlayer, sizeof(int), NULL); // Gets LocalPlayer
	ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(fProcess.__dwordClient + O.m_dwGlowObject), &GlowObject, sizeof(int), NULL); // Gets GlowObject
	ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(LocalPlayer + O.m_iTeamNum), &LocalTeam, sizeof(int), NULL);} // Gets My team from LocalPlayer

void Glow::ReadEntity(int Entnum){ // Reads our Entity information

	ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(GlowObject + 0x38 * Entnum), &Entity, sizeof(int), NULL); // First Adress in Glowobject is the Pointer to the entity its glowing.

	ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(Entity + 0x8), &ClassID, sizeof(int), NULL); // Multilevel Pointer Reading ClassID
	ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(ClassID + 0x8), &ClassID, sizeof(int), NULL);
	ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(ClassID + 0x1), &ClassID, sizeof(int), NULL);
	ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(ClassID + 0x14), &ClassID, sizeof(int), NULL);

	ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(Entity + O.m_iTeamNum), &TeamNum, sizeof(int), NULL);// Getting the entitys Team Number
	ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(Entity + O.m_iHealth), &Health, sizeof(int), NULL); } // Getting the entitys Team Number

void Glow::GlowEntity(int Entnum){ // Glows our entity
	if (Entity && LocalPlayer)
		WriteProcessMemory(fProcess.__HandleProcess, (PBYTE*)(GlowObject + 0x38 * Entnum + 0x4), &EntGlow, sizeof(EntGlow), NULL);} // Writes a struct with WPM
	
void Glow::GlowEntitys(int i){ // Glows all the entitys with custom color based on ClassID.
	
	switch (ClassID) 
	{
	case AK47:
		SetColor(1.f, 0.3f, 0.f, 1.f);
		GlowEntity(i);
		break;
	case BaseCSGrenade:
		SetColor(1.f, 0.0f, 0.f, 1.f);
		GlowEntity(i);
		break;
	case BaseCSGrenadeProjectile:
		SetColor(1.f, 0.0f, 0.f, 1.f);
		GlowEntity(i);
		break;
	case Player: //
		if (LocalTeam != TeamNum || GetKeyState(VK_F1) == 1){
			SetColor( (1.f - (Health * 0.01f)), Health * 0.01f, 0.f, 0.8f);
			GlowEntity(i);			}
		else {
			SetColor(0.f, 0.f, 1.f, 0.8f);
			GlowEntity(i);}
		break;
	case C4:
		SetColor(1.f, 0.0f, 0.f, 1.f);
		GlowEntity(i);
		break;
	case Eagle:
		SetColor(0.f, 1.0f, 0.f, 1.f);
		GlowEntity(i);
		break;
	case Decoy:
		SetColor(1.f, 1.0f, 1.f, 1.f);
		GlowEntity(i);
		break;
	case DecoyProjectile:
		SetColor(1.f, 1.0f, 1.f, 1.f);
		GlowEntity(i);
		break;
	case Flashbang:
		SetColor(1.f, 0.f, 1.f, 1.f);
		GlowEntity(i);
		break;
	case CHEGrenade:
		SetColor(1.f, 0.f, 0.f, 1.f);
		GlowEntity(i);
		break;
	case Hostage:
		SetColor(0.f, 0.0f, 1.f, 1.f);
		GlowEntity(i);
		break;
	case HostageCarriableProp:
		SetColor(0.f, 0.0f, 1.f, 1.f);
		GlowEntity(i);
		break;
	case IncendiaryGrenade:
		SetColor(1.f, 1.0f, 0.f, 1.f);
		GlowEntity(i);
		break;
	case Item_Healthshot:
		SetColor(0.f, 1.f, 1.f, 1.f);
		GlowEntity(i);
		break;
	case MolotovGrenade:
		SetColor(1.f, 1.f, 0.f, 1.f);
		GlowEntity(i);
		break;
	case MolotovProjectile:
		SetColor(1.f, 1.f, 0.f, 1.f);
		GlowEntity(i);
		break;
	case PlantedC4:
		SetColor(0.f, 1.0f, 1.f, 1.f);
		GlowEntity(i);
		break;
	case SensorGrenade:
		SetColor(0.f, 1.f, 1.f, 1.f);
		GlowEntity(i);
		break;
	case SensorGrenadeProjectile:
		SetColor(0.f, 1.f, 1.f, 1.f);
		GlowEntity(i);
		break;
	case SmokeGrenade:
		SetColor(0.f, 1.0f, 0.f, 1.f);
		GlowEntity(i);
		break;
	case SmokeGrenadeProjectile:
		SetColor(0.f, 1.0f, 0.f, 1.f);
		GlowEntity(i);
		break;
	case WeaponAug:
		SetColor(0.f, 1.f, 0.f, 1.f);
		GlowEntity(i);
		break;
	case WeaponAWP:
		SetColor(0.f, 1.0f, 0.2f, 1.f);
		GlowEntity(i);
		break;
	case WeaponBizon:
		SetColor(0.f, 0.0f, 1.f, 1.f);
		GlowEntity(i);
		break;
	case WeaponElite:
		SetColor(0.f, 0.0f, 1.f, 1.f);
		GlowEntity(i);
		break;
	case WeaponFamas:
		SetColor(0.f, 0.0f, 1.f, 1.f);
		GlowEntity(i);
		break;
	case WeaponFiveSeven:
		SetColor(0.f, 1.0f, 0.f, 1.f);
		GlowEntity(i);
		break;
	case WeaponG3SG1:
		SetColor(1.f, 0.3f, 1.f, 1.f);
		GlowEntity(i);
		break;
	case WeaponGalilAR:
		SetColor(0.f, 0.0f, 1.f, 1.f);
		GlowEntity(i);
		break;
	case WeaponGlock:
		SetColor(0.f, 0.0f, 1.f, 1.f);
		GlowEntity(i);
		break;
	case WeaponHKP2000:
		SetColor(0.f, 0.0f, 1.f, 1.f);
		GlowEntity(i);
		break;
	case WeaponM249:
		SetColor(0.f, 0.0f, 1.f, 1.f);
		GlowEntity(i);
		break;
	case WeaponM4A1:
		SetColor(1.f, 1.0f, 0.f, 1.f);
		GlowEntity(i);
		break;
	case WeaponMAC10:
		SetColor(0.f, 0.0f, 1.f, 1.f);
		GlowEntity(i);
		break;
	case WeaponMag7:
		SetColor(0.f, 0.0f, 1.f, 1.f);
		GlowEntity(i);
		break;
	case WeaponMP7:
		SetColor(1.f, 1.0f, 0.f, 1.f);
		GlowEntity(i);
		break;
	case WeaponMP9:
		SetColor(0.f, 0.0f, 1.f, 1.f);
		GlowEntity(i);
		break;
	case WeaponNegev:
		SetColor(0.f, 0.0f, 1.f, 1.f);
		GlowEntity(i);
		break;
	case WeaponNOVA:
		SetColor(0.f, 0.0f, 1.f, 1.f);
		GlowEntity(i);
		break;
	case WeaponP250:
		SetColor(0.f, 0.0f, 1.f, 1.f);
		GlowEntity(i);
		break;
	case WeaponP90:
		SetColor(1.f, 1.f, 0.f, 1.f);
		GlowEntity(i);
		break;
	case WeaponSawedoff:
		SetColor(0.f, 0.0f, 1.f, 1.f);
		GlowEntity(i);
		break;
	case WeaponSCAR20:
		SetColor(1.f, 0.3f, 1.f, 1.f);
		GlowEntity(i);
		break;
	case WeaponSG556:
		SetColor(0.f, 1.f, 0.f, 1.f);
		GlowEntity(i);
		break;
	case WeaponSSG08:
		SetColor(1.f, 0.3f, 1.f, 1.f);
		GlowEntity(i);
		break;
	case WeaponTaser:
		SetColor(1.f, 1.f, 1.f, 1.f);
		GlowEntity(i);
		break;
	case WeaponTec9:
		SetColor(0.f, 0.0f, 1.f, 1.f);
		GlowEntity(i);
		break;
	case WeaponUMP45:
		SetColor(0.f, 0.0f, 1.f, 1.f);
		GlowEntity(i);
		break;
	case WeaponUSP:
		SetColor(0.f, 0.0f, 1.f, 1.f);
		GlowEntity(i);
		break;
	case WeaponXM1014:
		SetColor(0.f, 0.0f, 1.f, 1.f);
		GlowEntity(i);
		break;
	default:
		break;
	}
}

void Glow::SetColor(float r, float g, float b, float a){ // setting the glow color
	EntGlow.red = r; EntGlow.green = g; EntGlow.blue = b; EntGlow.alpha = a;
}