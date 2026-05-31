#ifndef SCHED_H
#define SCHED_H
#include"AreaList.h"
#include "Flights.h"
#include "Lanes.h"
#include"EventPlanner.h"
#include"VeryNormalQueue.h"
using namespace std;
class scheduler
{
	
	AreaList* AList; //list of available areas
	EventPlanner* Event;//used to assign all the event read from the file
	int** distances;//a matrix that contains the distances from each area to the other, then each row of the matrix is given to the area of interest
	NormalQueue<Flights>* Finished;
public:
	scheduler();
	~scheduler();
	void Finish(ofstream& output);
	void Run();
	void setDistances(int** dist,int size);
	void readData(ifstream& file, string name);
	void saveData();
};
#endif
