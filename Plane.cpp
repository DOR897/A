#include "pch.h"
#include "Plane.h"
IMPLEMENT_SERIAL(Plane, CObArray, 1)
Plane::Plane(int a , int b )
{
	this->fuel = a;
	this->weight = b;
}
int Plane::isType()
{
	return -1;
}


	void Plane::Serialize(CArchive & ar)
	{
		CObArray::Serialize(ar);
		if (ar.IsStoring())
		{
			ar << fuel;
			ar << weight;
		}
		else // Loading, not storing
		{
			ar >> fuel;
			ar >> weight;
		}
	}


	