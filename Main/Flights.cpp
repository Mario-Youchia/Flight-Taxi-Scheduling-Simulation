#include "Flights.h"
Flights::Flights() {
	next = nullptr;
	passengers = 0;
}
Flights::Flights(int flightID, int pass, int flightBookTime, Areas* dep, Areas* arr) {
	next = nullptr;
	ID = flightID;
	passengers = pass;
	BookingTimestamp = flightBookTime;
	actualTravelTime = BookingTimestamp;
	Departure = dep;
	Arrival = arr;
}
void Flights::setFlightConstants(int one, int two, int three, int four) {
	TakeOffT = one;
	LandingT = two;
	PBoarding = three;
	POffBoarding=four;
}

void Flights::updateInfo(int newTime) {
	actualTravelTime = newTime;
	WaitingTime = actualTravelTime - BookingTimestamp;
	FinishTime = actualTravelTime+Departure->getDistance(Arrival->getAreaNo())+ TakeOffT+LandingT+PBoarding+POffBoarding; //plus utilities that will be added later.
	ServiceTime = TakeOffT + PBoarding * passengers + LandingT + POffBoarding * passengers;
}
bool Flights::isThis(int flyID) {
	if (ID == flyID)
		return true;
	return false;
}


void Flights::setNext(Flights* n) {
	next = n;
}
int Flights::getID() {
	return ID;
}

Flights* Flights::getNext() {
	return next;
}
void Flights::setFlightType(Specialization x)
{
	FlightType = x;
}
Specialization Flights::getFlightType()
{
	return FlightType;
}
int Flights::getPriority() {
	return FlightType;
}
int Flights::getTime() {
	return actualTravelTime;
}
void Flights::increamentTimesDelayed() {
	timesDelayed++;
}
int Flights::getTimesDelayed() {
	return timesDelayed;
}
int Flights::getPassengers() {
	return passengers;
}
int Flights::getFinishTime() {
	return FinishTime;
}
int Flights::getBookingTime() {
	return BookingTimestamp;
}
bool Flights::CanFly() {
	if (Departure->checkLane(actualTravelTime, FlightType))
		return Arrival->checkLane(actualTravelTime+ Departure->getDistance(Arrival->getAreaNo()) + TakeOffT + PBoarding*passengers, FlightType);
	return false;

}
void Flights::Fly() {
	if (CanFly()) {
		Departure->ScheduleLane(actualTravelTime,TakeOffT+PBoarding * passengers, FlightType);
		Arrival->ScheduleLane(actualTravelTime+Departure->getDistance(Arrival->getAreaNo()) + TakeOffT + PBoarding * passengers, LandingT+POffBoarding * passengers, FlightType);
	}
}
void Flights::setPriority(Specialization pr) {
	FlightType = pr;
}
int Flights::getServieceTime()
{
	return ServiceTime;
}


