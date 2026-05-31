#ifndef HELPER_H
#define HELPER_H
struct time0 {
	int hours;
	int minutes;
};
enum Specialization {
	NORMAL,
	VIP
};
enum FlightStatus {
	WaitingFlight,
	FlyingFlight,
	ConveyedFlight
};
enum Variables {
	PROMOTEDFLIGHTS,
	SERVEDFLIGHTS
};
#endif // !HELPER_H

