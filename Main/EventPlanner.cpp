#include"EventPlanner.h"
EventPlanner::EventPlanner() {
	currentTime = 0;
	FlightList = new Queue<Flights>;
	FinsinedFlightList = new NormalQueue<Flights>;
	ProLimit = 0;
	FlightsPromoted = 0;
	ServedFlights = 0;
	TakeOffT = 0;
	LandingT = 0;
	PBoarding = 0;
	POffBoarding = 0;
}
EventPlanner::~EventPlanner() {
	delete FlightList;
	delete FinsinedFlightList;
}
void EventPlanner::setConstants(int one, int two, int three, int four) {
	TakeOffT = one;
	LandingT = two;
	PBoarding = three;
	POffBoarding = four;
}
int EventPlanner::get(Variables T) {
	if (T == 0)
		return FlightsPromoted;
	else if (T == 1)
		return ServedFlights;
	return 0;
}
NormalQueue<Flights>* EventPlanner::DeliverInfo() {
	return FinsinedFlightList;
}

void EventPlanner::Simulate() {
	Flights* tempflight = new Flights;
	while (!FlightList->isEmpty()) {
		while (FlightList->candequeue(currentTime)) {
			tempflight = FlightList->dequeue();
			if (tempflight->CanFly()) {
				tempflight->Fly();
				tempflight->updateInfo(currentTime);
				FinsinedFlightList->enqueue(tempflight, tempflight->getFinishTime());
				ServedFlights++;
			}
			else {
				tempflight->increamentTimesDelayed();
				tempflight->updateInfo(tempflight->getTime() + 1);
				if (tempflight->getTimesDelayed() == ProLimit) {
					tempflight->setFlightType(VIP);
					FlightsPromoted++;
				}
				FlightList->enqueue(tempflight, tempflight->getTime(), tempflight->getFlightType());
			}
		}
		currentTime++;
	}
}
void EventPlanner::bookFlight(Specialization type, int time, int ID, int Pass, Areas* dep, Areas* arr) {
	Flights* newflight = new Flights(ID, Pass, time, dep, arr);
	newflight->setFlightConstants(TakeOffT, LandingT, PBoarding, POffBoarding);
	newflight->setPriority(type);
	FlightList->enqueue(newflight, time, type);
}
void EventPlanner::CancelFlight(int time, int ID) {
	Queue<Flights>* tempList = new Queue<Flights>;
	Flights* tempflight = new Flights;
	tempflight = FlightList->dequeue();
	while (tempflight) {
		if (tempflight->isThis(ID)) {
			delete tempflight;
			tempflight = nullptr;
		}
		else {
			tempList->enqueue(tempflight, tempflight->getTime(), tempflight->getFlightType());
		}
		tempflight = FlightList->dequeue();

	}
	tempflight = FlightList->dequeue();
	while (tempflight) {
		FlightList->enqueue(tempflight, tempflight->getPriority(), tempflight->getFlightType());
		tempflight = FlightList->dequeue();
	}
	delete tempList;
}
void EventPlanner::PromoteFlight(int time, int ID) {
	Queue<Flights>* tempList = new Queue<Flights>;
	Flights* tempflight = new Flights;
	tempflight = FlightList->dequeue();
	while (tempflight) {
		if (tempflight->isThis(ID)) {
			tempflight->setPriority(VIP);
		}
		tempList->enqueue(tempflight, tempflight->getPriority(), tempflight->getFlightType());
	}
	delete tempList;
	tempflight = FlightList->dequeue();
}
void EventPlanner::setProLimit(int Pro) {
	ProLimit = Pro;
}