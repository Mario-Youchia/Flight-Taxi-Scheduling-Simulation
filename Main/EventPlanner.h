#ifndef EVENT_H
#define EVENT_H
#include"Flights.h"
#include"Queue.h"
#include"NormalQueue.h"
class EventPlanner
{
	int currentTime;//the time reference
	Queue<Flights>* FlightList;//the list that contains all the flights that are going to be booked
	NormalQueue<Flights>* FinsinedFlightList;//the list that contains all the flights that are assigned
	int ProLimit;//promotion limit
	int FlightsPromoted,ServedFlights;
	int TakeOffT, LandingT, PBoarding, POffBoarding;//constants set at startup
public:
	EventPlanner();
	~EventPlanner();
	void Simulate();
	int get(Variables);
	NormalQueue<Flights>* DeliverInfo();
	void setConstants(int one, int two, int three, int four);
	void bookFlight(Specialization type,int time,int ID,int Pass,Areas* dep,Areas* arr);//books a new flight
	void CancelFlight(int time, int ID);//cancels flight, needs adjustment
	void PromoteFlight(int time, int ID);//promots flight, needs adjustment
	void setProLimit(int Pro);
};
#endif // !EVENT_H
