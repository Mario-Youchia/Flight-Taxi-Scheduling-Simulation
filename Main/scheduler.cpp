#include "scheduler.h"
#include "iostream"
#include <fstream>
#include <string>
using namespace std;
//////////////////////////
class LinkedListNode
{
private:
	int data = 0;
	LinkedListNode* Next = nullptr;
public:
	LinkedListNode(int value);
	void setNodeValue(int value);
	int getNodeValue() const;
	void setNextPtr(LinkedListNode* Ptr);
	LinkedListNode* getNextPtr() const;
	~LinkedListNode();
};
LinkedListNode::LinkedListNode(int value)
{
	data = value;
}
void LinkedListNode::setNodeValue(int value)
{
	data = value;
}
int LinkedListNode::getNodeValue() const
{
	return data;
}
void LinkedListNode::setNextPtr(LinkedListNode* Ptr)
{
	Next = Ptr;
}
LinkedListNode* LinkedListNode::getNextPtr() const
{
	return Next;
}
LinkedListNode::~LinkedListNode() {};
class LinkedList
{
private:
	LinkedListNode* Head = nullptr;
	Specialization flightType = NORMAL;
	LinkedList* Next = nullptr;
	int count = 0;
public:
	LinkedList(int arr[], int size);
	void PrintLinkedList(ofstream& output) const;
	LinkedListNode* GetPtrToNodeAt(int index) const;
	void AdjustNodeAt(int index, int CorrectValue);
	int GetNodeValueAt(int index) const;
	void setFlightType(Specialization FlightType);
	Specialization GetFlightType() const;
	LinkedList* GetNextPtr() const;
	void SetNextPtr(LinkedList* next);
	~LinkedList();
};
LinkedList::LinkedList(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (!Head)
			Head = new LinkedListNode(arr[i]);
		else
		{
			LinkedListNode* Ptr = nullptr;
			Ptr = Head;
			while (Ptr->getNextPtr())
				Ptr = Ptr->getNextPtr();
			Ptr->setNextPtr(new LinkedListNode(arr[i]));
		}
		count++;
	}
}
void LinkedList::PrintLinkedList(ofstream& output) const
{
	LinkedListNode* Ptr = Head;
	while (Ptr)
	{
		output << Ptr->getNodeValue() << "\t";
		Ptr = Ptr->getNextPtr();
	}
	output << endl;
}
LinkedListNode* LinkedList::GetPtrToNodeAt(int index) const
{
	LinkedListNode* Ptr = Head;
	int Count = 0;
	while (Ptr && index < count)
	{
		if (Count == index) return Ptr;
		Count++;
		Ptr = Ptr->getNextPtr();
	}
}
void LinkedList::AdjustNodeAt(int index, int CorrectValue)
{
	GetPtrToNodeAt(index)->setNodeValue(CorrectValue);
}
int LinkedList::GetNodeValueAt(int index) const
{
	return GetPtrToNodeAt(index)->getNodeValue();
}
void LinkedList::setFlightType(Specialization FlightType)
{
	flightType = FlightType;
}
Specialization LinkedList::GetFlightType() const
{
	return flightType;
}
LinkedList* LinkedList::GetNextPtr() const
{
	return Next;
}
void LinkedList::SetNextPtr(LinkedList* next)
{
	Next = next;
}
LinkedList::~LinkedList() {};
class LinkedList_2
{
private:
	LinkedList* Head = nullptr;
	int count = 0;
public:
	LinkedList_2();
	void InsertList(LinkedList* Linked_List);
	void PrintList(ofstream& output) const;
	void Average(int Time, ofstream& output) const;
};

LinkedList_2::LinkedList_2()
{
	Head = 0;
	count = 0;
}

void LinkedList_2::InsertList(LinkedList* Linked_List)
{
	if (!Head) Head = Linked_List;
	else
	{
		LinkedList* Ptr = nullptr;
		Ptr = Head;
		while (Ptr->GetNextPtr())
			Ptr = Ptr->GetNextPtr();
		Ptr->SetNextPtr(Linked_List);
	}
	count++;
}
void LinkedList_2::PrintList(ofstream& output) const
{
	LinkedList* Ptr = Head;
	while (Ptr)
	{
		Ptr->PrintLinkedList(output);
		Ptr = Ptr->GetNextPtr();
	}
}
void LinkedList_2::Average(int Time, ofstream& output) const
{
	if (Time == 4 || Time == 5)
	{
		LinkedList* Ptr = Head;
		double Average = 0;
		double sum = 0;
		while (Ptr)
		{
			sum += Ptr->GetNodeValueAt(Time - 1);
			Ptr = Ptr->GetNextPtr();
		}
		Average = sum / count;
		output << Average;
	}
	else
	{
		cout << "Enter WT, or ST";
		return;
	}
}
void Areas_Lanes_Statistics(int** Arr, int NumOfRows, ofstream& output,int flynum)
{
	int sumOfNormFlights = 0;
	for (int i = 0; i < NumOfRows; i++)
		sumOfNormFlights += Arr[i][1];
	int sumOfVIPFlights = 0;
	for (int i = 0; i < NumOfRows; i++)
		sumOfVIPFlights += Arr[i][2];
	output << "Flights: " << flynum << " [Norm:" << sumOfNormFlights
		<< ", VIP:" << sumOfVIPFlights << "]" << endl;
	output << "Areas: " << NumOfRows << endl;
	for (int i = 0; i < NumOfRows; i++)
		output << "Area " << i + 1 << ": Lanes: " << Arr[i][0] << " [Norm:" << Arr[i][1]
		<< ", VIP : " << Arr[i][2] << "]" << endl;
}
void AutoPromoted(int Auto_Promoted, ofstream& output)
{
	output << "Auto-promoted: " << Auto_Promoted;
}
void Output_Function(ofstream& output, int** T_Matrix, int NumOfRowsInT_Matrix, int** Arr, int NumOfRows,int AverageWT, int AverageST, int Auto_promoted)
{
	output << "FT\tID\tBT\tWT\tST" << endl;
	LinkedList_2* Linked_List_20 = new LinkedList_2;
	for (int i = 0; i < NumOfRowsInT_Matrix; i++)
	{
		LinkedList* Linked_List = new LinkedList(T_Matrix[i], 5);
		Linked_List_20->InsertList(Linked_List);
	}
	Linked_List_20->PrintList(output);
	Areas_Lanes_Statistics(Arr, NumOfRows, output, NumOfRowsInT_Matrix);
	output << "Avg Wait = "<< AverageWT;
	output << ", Avg Serv = " << AverageST << endl;
	AutoPromoted(Auto_promoted, output);
}
/// <summary>
/// //////////////////////////////////////////////////////
/// </summary>
scheduler::scheduler() {
	AList = new AreaList;
	Event = new EventPlanner;
	Finished = new NormalQueue<Flights>;
}

scheduler::~scheduler() {
	delete AList;
	delete Event;
	delete distances;
}
void scheduler::Finish(ofstream& output) {
	//void Output_Function(ofstream & output, int T_Matrix[][5], int NumOfRowsInT_Matrix, int Arr[][3], int NumOfRows,
	//	int AverageWT, int AverageST, int Auto_promoted)
	int FlightNums = Event->get(SERVEDFLIGHTS);
	int Promoted = Event->get(PROMOTEDFLIGHTS);
	int** Arr=new int*[FlightNums];
	Flights* tempFlight=new Flights;
	int WTsum, STsum;
	WTsum = 0;
	STsum = 0;

	for (int i = 0; i < FlightNums; i++) {
		Arr[i] = new int[5];
		if (!Finished->isEmpty()) {
			tempFlight = Finished->dequeue();
			Arr[i][0] = tempFlight->getFinishTime();
			Arr[i][1] = tempFlight->getID();
			Arr[i][2] = tempFlight->getBookingTime();
			Arr[i][3] = tempFlight->getTime() - tempFlight->getBookingTime();
			Arr[i][4] = tempFlight->getServieceTime();
			WTsum+= tempFlight->getTime() - tempFlight->getBookingTime();
			STsum += tempFlight->getServieceTime();
		}
	}
	int AreasNum = AList->getCount();
	Areas* Area1 = new Areas;
	VeryNormalQueue<Areas>* Q1 = new VeryNormalQueue<Areas>;
	Q1 = AList->getQueue();
	int** Arr2 = new int* [AreasNum];
	for (int i = 0; i < AreasNum; i++) {
		Area1 = Q1->dequeue();
		Arr2[i] = new int[3];
		Arr2[i][0] = Area1->getNoLanes();
		Arr2[i][1] = Area1->getServedNormal();
		Arr2[i][2] = Area1->getServedVip();
	}

	Output_Function(output, Arr, FlightNums, Arr2, AreasNum, WTsum / FlightNums, STsum / FlightNums, Event->get(PROMOTEDFLIGHTS));
}
void scheduler::Run() {
	Event->Simulate();
	Finished = Event->DeliverInfo();
}

void scheduler::setDistances(int** dist,int size) {

	distances = new int* [size];
	for (int i = 0; i < size; i++) {
		distances[i] = new int[size];
		for (int j = 0; j < size; j++)
			distances[i][j] = dist[i][j];
	}
}

void scheduler::readData(ifstream& file, string name)
{
	file.open(name);
	if (!(file.fail()))
	{
		int x;
		int NumOfAreas;
		//first input line
		file >> NumOfAreas;
		int* LanesArray = new int [NumOfAreas];
		int TakeOffT, LandingT, PBoarding, POffBoarding;
		file >> TakeOffT;
		file >> LandingT;	
		file >> PBoarding;
		file >> POffBoarding;
		Event->setConstants(TakeOffT, LandingT, PBoarding, POffBoarding);
		/// //////////////////////////////////////////

		int** dists = new int* [NumOfAreas];
		//initializes the 2d array
		for (int i = 0; i < NumOfAreas; i++)
			dists[i] = new int[NumOfAreas];
		//second portion, reads information about each area
		for (int i = 0; i < NumOfAreas; i++) {
			int NumOfLanes;
			file >> NumOfLanes;
			LanesArray[i] = NumOfLanes;
			AList->InsertArea(NumOfLanes, i + 1);
			for (int j = 0; j < NumOfAreas; j++) {
				if (i == j)
					dists[i][j] = 0;
				else
					file >> dists[i][j];
			}
			AList->findArea(i + 1)->setDistances(dists[i], NumOfAreas);
		}
		setDistances(dists, NumOfAreas);
		int LaneCount = 0;
		for (int i = 0; i < NumOfAreas; i++)
		{
			LaneCount = LaneCount + LanesArray[i];
		}
		/// //////////////////////////////////////////////////
		//third portion, read info about each lane
		int LaneArea;
		char specialization;
		int availabilitytime;
		int maintenanceAfter;
		int maintenanceTime;
		int AutoPromotionLimit;
		int NoOfEvents;
		char BookingType;
		int TakeOffArea;
		int LandingArea;
		char Type;
		int TimeStamp;
		int ID;
		int Passengers;

		for (int i = 0; i < LaneCount; i++)
		{
			file >> LaneArea;
			file >> specialization;
			file >> availabilitytime;
			file >> maintenanceAfter;
			file >> maintenanceTime;

			Lanes* L = new Lanes (AList->findArea(LaneArea), availabilitytime, maintenanceAfter, maintenanceTime);
			if (specialization == 'V')
			{
				L->setLaneType(VIP);
			}
			else if (specialization == 'N')
			{
				L->setLaneType(NORMAL);
			}
			AList->findArea(LaneArea)->setLane(L);
		}
		/// ////////////////////////////////////////////

		file >> AutoPromotionLimit;
		Event->setProLimit(AutoPromotionLimit);
		file >> NoOfEvents;
		//info about the scheduled events, booking, cancelling or promoting
		for (int i = 0; i < NoOfEvents; i++)
		{
			file >> BookingType;
			if (BookingType == 'B')
			{
				file >> TakeOffArea;
				file >> LandingArea;
				file >> Type;
				file >> TimeStamp;
				file >> ID;
				file >> Passengers;
				if (Type == 'V')
				{
					Event->bookFlight(VIP, TimeStamp, ID, Passengers, AList->findArea(TakeOffArea), AList->findArea(LandingArea));
				}
				else if (Type == 'N')
				{
					Event->bookFlight(NORMAL, TimeStamp, ID, Passengers, AList->findArea(TakeOffArea), AList->findArea(LandingArea));

				}
			
			}
			else if (BookingType == 'X')
			{
				file >> TimeStamp;
				file >> ID;
				Event->CancelFlight(TimeStamp, ID);
			}
			else if (BookingType == 'P')
			{
				file >> TimeStamp;
				file >> ID;
				Event->PromoteFlight(TimeStamp, ID);
			}
		}
		file.close();
	}
	else
	{
		cerr << "Error Opening the File!" << endl;
		exit(1); 
	}	
}


void scheduler::saveData()
{
	ofstream file;
	file.open("Sample1.txt");
	int FT, ID, BT, WT, ST;



}
///////////////////////////////////////////////////
