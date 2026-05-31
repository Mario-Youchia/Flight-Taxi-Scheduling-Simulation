#ifndef AREA_H
#define AREA_H
#include"LanesList.h"
class Areas
{
	int AreaNO;//area number
	int* Distances;//array containing the distances to every other area, note that Distances[this area number]=0
	LanesList* AreaLanes;//the list that contains Lanes that are assigned to this area
	Areas* nextArea;//pointer to the next area
	int servedVIP, servedNormal;
public:
	Areas();
	~Areas();
	Areas(int NoLanes, int AreaNum);//constructs area with the number of lanes and the area number
	int getNoLanes();
	int getServedNormal();
	int getServedVip();
	void setDistances(int*, int);//takes the distances array, supposedly from scheduler class after reading the file
	void setNext(Areas* next);
	bool checkLane(int time,int type);
	bool ScheduleLane(int time, int duration, int type);
	int getDistance(int OtherAreaNo);
	Areas* getNext();
	int getAreaNo();//return the area number
	void setLane(Lanes* L);//adds a new lane to the area
};
#endif
