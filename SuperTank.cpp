#include "pch.h"
#include "SuperTank.h"
IMPLEMENT_SERIAL(SuperTank, CObArray, 1)

void SuperTank::SetWater(int n)
{
	this->WaterAmt = n;
}

int SuperTank::GetWater(int n)
{
	return this->WaterAmt;
}

int SuperTank::Supers = 0;

int SuperTank::isType()
{
	return 1;
}
void SuperTank::Serialize(CArchive& ar)
{
	CObArray::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << WaterAmt;
		
	}
	else
	{
		ar >> WaterAmt;
	
	}
}


