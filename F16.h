#pragma once
#include "SoloPlane.h"
#include "Plane.h"
class F16 : public SoloPlane
{
public:
	F16(int n = 4) { this->rockets = n; }
	void Serialize(CArchive& ar);
	void SetRockets(int n = 4);
	int GetRockets();
	int isType();
	static int Fighters;
	
private:
	DECLARE_SERIAL(F16)
	int rockets;

};

