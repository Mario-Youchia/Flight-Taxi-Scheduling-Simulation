#ifndef AREAL_H
#define AREAL_H
#include"Areas.h"
#include"VeryNormalQueue.h"
class AreaList
{
private:
	Areas* Head; //pointer to the first area
	int count;
public:
	AreaList();
	~AreaList();
	int getCount();
	VeryNormalQueue<Areas>* getQueue();
	void InsertArea(int NoLanes, int AreaNum);//makes a new area and uses the other InsertArea function
	void InsertArea(Areas*);//adds new area to the new
	Areas* findArea(int AreaNo);//return the area with the specified Area number, return nullptr if not found
	void DeleteAll();
};
#endif
