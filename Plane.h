#pragma once
class Plane : public CObArray
{
public:
	Plane(int a = 0, int b = 0);
	 int isType();
	 void Serialize(CArchive& ar);
private:
	int fuel;
	int weight;
	DECLARE_SERIAL(Plane)
};
