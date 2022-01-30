#include "pch.h"
#include "Boeing.h"

IMPLEMENT_SERIAL(Boeing, CObject, 1)
int Boeing::isType()
{
	return 3;
}
int Boeing::GetEngines()
{
	return this->engines;
}
int Boeing::PassPlanes = 0;
void  Boeing::Serialize(CArchive& ar)
{
	CObArray::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << engines;
		
	}
	else // Loading, not storing
	{
		ar >> engines;
		
	}
}

