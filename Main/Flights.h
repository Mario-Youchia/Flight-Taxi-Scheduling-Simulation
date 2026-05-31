#ifndef FLIGHT_H
#define FLIGHT_H
#include<iostream>
#include"Helper.h"
#include"Areas.h"
using namespace std;

class Flights
{
	int ID;//special integer for each flight
	Specialization FlightType;//a flight can be VIP or Normal
	Areas* Departure;//the departure area
	Areas* Arrival;//the arrival area
	FlightStatus Status;//whether it is waiting,flying,conveyed
	Flights* next;
	int passengers;
	int BookingTimestamp;
	int actualTravelTime;
	int timesDelayed;
	int WaitingTime;
	int ServiceTime;
	int FinishTime;
	int TakeOffT, LandingT, PBoarding, POffBoarding;
public:
	Flights();
	Flights(int flightID, int pass, int flightBookTime, Areas* dep, Areas* arr);
	void setFlightConstants(int one, int two, int three, int four);
	bool isThis(int ID);//checks whether this flight has the same ID
	void setNext(Flights*);
	void updateInfo(int newTime);
	void increamentTimesDelayed();
	int getTimesDelayed();
	int getPassengers();
	int getFinishTime();
	int getBookingTime();
	bool CanFly();
	void Fly();
	Flights* getNext();
	int getID();
	int getPriority();
	int getTime();
	void setFlightType(Specialization x);
	void setPriority(Specialization);//same as set flight type
	Specialization getFlightType();
	int getServieceTime();
};
#endif
