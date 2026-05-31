#include "Areas.h"
Areas::Areas() {
	nextArea = nullptr;
	AreaLanes = new LanesList;
	servedNormal = 0;
	servedVIP = 0;
}
Areas::Areas(int NoLanes, int AreaNum) {
	AreaLanes = new LanesList;
	nextArea = nullptr;
	AreaNO = AreaNum;
	servedNormal = 0;
	servedVIP = 0;
}
Areas::~Areas() {
	delete Distances;
	delete AreaLanes;
}
void Areas::setDistances(int* dist,int size) {
	Distances = new int[size];
	for (int i = 0; i < size; i++) {
		Distances[i] = dist[i];
	}
}
int Areas::getNoLanes() {
	return AreaLanes->getCount();
}
int Areas::getServedNormal() {
	return servedNormal;
}
int Areas::getServedVip() {
	return servedVIP;
}
int Areas::getDistance(int otherAreaNo) {
	return Distances[otherAreaNo-1];
}
void Areas::setNext(Areas* next) {
	nextArea = next;
}
bool Areas::checkLane(int time,int type) {
  return AreaLanes->isAvailable(time,type);
}
bool Areas::ScheduleLane(int time, int duration, int type) {
	if (type == 0)
		servedNormal++;
	else if(type==1)
		servedVIP++;
	return AreaLanes->book(time, duration, type);
	
}
Areas* Areas::getNext() {
	return nextArea;
}
int Areas::getAreaNo() {
	return AreaNO;
}
void Areas::setLane(Lanes* L ){
	AreaLanes->InsertLane(L);
}