#pragma once
#include "Plane.h"
class SoloPlane : public Plane
{
public:
	SoloPlane(int cap = 2, int speed = 300) { this->capacity = cap; this->maxSpeed = speed; }
	void Serialize(CArchive& ar);
	int GetCap();
	int GetSpeed();
	int isType();
	static int Solos;
private:
	DECLARE_SERIAL(SoloPlane)
	int capacity;
	int maxSpeed;
	

};



