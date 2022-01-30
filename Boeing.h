#pragma once
#include "SoloPlane.h"
#include "Plane.h"
class Boeing : public SoloPlane
{
public:
	Boeing(int eng = 4) { this->engines = eng; }
	void Serialize(CArchive& ar);
	int GetEngines();
	int isType();
	static int PassPlanes;
private:
	DECLARE_SERIAL(Boeing)
	int engines;

};

