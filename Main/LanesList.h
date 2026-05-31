#ifndef LANESLIST_H
#define LANESLIST_H
#include"Lanes.h"
class LanesList
{
private:
	Lanes* Head;
	int count;
public:
	LanesList();
	~LanesList();
	int getCount();
	bool book(int time,int duration,int type);
	bool isAvailable(int time, int type);
	void InsertLane(Lanes*);
	void DeleteAll();
};

#endif // !1



