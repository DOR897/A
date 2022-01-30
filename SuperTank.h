#pragma once
#include "Plane.h"
class SuperTank : public Plane
{
public:
	SuperTank(int n = 500) { this->WaterAmt = n; }
	void SetWater(int n);
	int GetWater(int n);
	static int Supers;
	int isType();
	void Serialize(CArchive& ar);

private:
	int WaterAmt;
	DECLARE_SERIAL(SuperTank)
	
	

};

