#include "LanesList.h"
LanesList::LanesList() {
	Head = nullptr;
	count = 0;
}
LanesList::~LanesList() {
	DeleteAll();
}
int LanesList::getCount() {
	return count;
}

bool LanesList::book(int time,int duration,int type) {
	Lanes* lane = Head;
	while (lane != nullptr) {
		if (lane->IsAvailable(time)&&type==lane->getLaneType()) {
			lane->setFlight(duration);
			return true;
		}
		else
			lane = lane->getNext();

	}
	lane = Head;
		while (lane != nullptr) {
			if (lane->IsAvailable(time)) {
				lane->setFlight(duration);
				return true;
			}
			else
				lane = lane->getNext();
		
	}
	return false;
}
bool LanesList::isAvailable(int time, int type) {
	Lanes* lane = Head;
	while (lane != nullptr) {
		if (lane->IsAvailable(time) && type == lane->getLaneType()) {
			return true;
		}
		else
			lane = lane->getNext();

	}
	lane = Head;
	while (lane != nullptr) {
		if (lane->IsAvailable(time)) {
			return true;
		}
		else
			lane = lane->getNext();

	}
	return false;
}
void LanesList::InsertLane(Lanes* newLane){
	if (Head == nullptr) {
		Head = newLane;
		count++;
		return;
	}
	else {
		Lanes* A1 = Head;
		while (A1->getNext() != nullptr) {
			A1 = A1->getNext();
		}
		A1->setNext(newLane);
	}
	count++;
}
void LanesList::DeleteAll()
{
	Lanes* A = Head;
	while (Head != nullptr)
	{
		A = Head->getNext();
		delete Head;
		Head = A;
	}
}

