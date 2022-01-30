#include "pch.h"
#include "F16.h"

IMPLEMENT_SERIAL(F16,CObArray, 1)
void F16::SetRockets(int n)
{
	this->rockets = n;
}
int F16::GetRockets()
{
	return this->rockets;
}

int F16::isType()
{
	return 4;
}
int F16::Fighters = 0;


	

void F16::Serialize(CArchive& ar)
{
	CObArray::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << rockets;
	}
	else // Loading, not storing
	{
		ar >> rockets;

	}

}

