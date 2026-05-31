#ifndef LANES_H
#define LANES_H
#include"Helper.h"
class Areas;
class Lanes
{
	Areas* LaneArea;//the area which this lane is assigned to
	Lanes* nextLane;
	Specialization LaneType;
	int servedFlights;
	int AvailableT;//availability time
	int MaintenanceT;//Maintenance time
	int MaintenanceFlights;//the number of flights after which the lane is maintainced
public:
	Lanes();
	Lanes(Areas* Area , int avail, int maint, int maintNO);
	void setNext(Lanes*);
	Lanes* getNext();
	void setLaneType(Specialization y);
	void setFlight(int addTime);
	bool IsAvailable(int Time);
	Specialization getLaneType();
};

#endif
