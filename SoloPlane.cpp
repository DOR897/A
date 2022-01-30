#include "pch.h"
#include "SoloPlane.h"
IMPLEMENT_SERIAL(SoloPlane,CObArray, 1)
int SoloPlane::GetCap()
{
	return this->capacity;
}
int SoloPlane::GetSpeed()
{
	return this->maxSpeed;
}
int SoloPlane::Solos = 0;

int SoloPlane::isType()
{
	return 2;
}
void SoloPlane::Serialize(CArchive& ar)
{
	CObArray::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << capacity;
		ar << maxSpeed;
	}
	else 
	{
		ar >> capacity;
		ar >> maxSpeed;
	}
}

