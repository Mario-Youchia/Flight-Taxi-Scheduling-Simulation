#include "Lanes.h"
Lanes::Lanes() {
	LaneArea = nullptr;
}
Lanes::Lanes(Areas* Area, int avail, int maint, int maintNO) {
	LaneArea = Area;
	AvailableT = avail;
	MaintenanceT = maint;
	MaintenanceFlights = maintNO;
	servedFlights = 0;
}
void Lanes::setNext(Lanes* next) {
	nextLane = next;
}
Lanes* Lanes::getNext() {
	return nextLane;
}
void Lanes::setLaneType(Specialization x)
{
	LaneType = x;
}
Specialization Lanes::getLaneType()
{
	return LaneType;
}
void Lanes::setFlight(int addTime) {
	AvailableT += addTime;
}
bool Lanes::IsAvailable(int Time) {
	if (Time < AvailableT)
		return false;
	return true;
}