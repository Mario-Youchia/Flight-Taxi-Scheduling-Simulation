#ifndef QUEUE_H
#define QUEUE_H
#include "Flights.h"

template <typename T>
class Queue
{
private :
	
	T* backPtr;
	T* frontPtr;
public :
	Queue();
	bool isEmpty() const ;
	bool enqueue(T* newEntry,int time,int type);//inserts the new node according to its priority, in this case, the VIP priority is 1 and normal priority is 0
	T* dequeue();
	bool candequeue(int time);
	void deleteAll();
	bool peekFront(T* frntEntry)  const;
	~Queue();
};
template <typename T>
Queue<T>::Queue()
{
	backPtr=nullptr;
	frontPtr=nullptr;

}
/////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
bool Queue<T>::isEmpty() const
{
	if(frontPtr==nullptr)
		return true;
	else
		return false;
}

/////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
bool Queue<T>::enqueue(T* newEntry,int time,int type)
{
	newEntry->setNext(nullptr);
	T* FlightsPtr = newEntry;
	T* front = frontPtr;
	if (isEmpty())
		frontPtr = FlightsPtr;
	else if (time<= frontPtr->getTime()) {
		if (type > frontPtr->getPriority()) {
			if (frontPtr->getNext() == nullptr) {
				backPtr = frontPtr;
				FlightsPtr->setNext(frontPtr);
				frontPtr = FlightsPtr;
			}
			else {
				FlightsPtr->setNext(frontPtr);
				frontPtr = FlightsPtr;
			}
		}
		else{
			while (front->getNext() != nullptr) {
				if (type > front->getNext()->getPriority()) {
					front = front->getNext();
				}
				else {
					break;
				}

			}
			if (front->getNext() != nullptr) {
				FlightsPtr->setNext(front->getNext());
				front->setNext(FlightsPtr);
			}
			else {//least important node
				FlightsPtr->setNext(nullptr);
				front->setNext(FlightsPtr);
				backPtr = FlightsPtr;
			}
		}
	}
	else {
		while (front->getNext() != nullptr) {
			if (time > front->getNext()->getTime()) {
				front = front->getNext();
			}
			else {
				break;
			}
		
		}
		if (front->getNext() != nullptr) {
			if (type > front->getPriority()) {
				FlightsPtr->setNext(front->getNext());
				front->setNext(FlightsPtr);
			}
			else {
				while (front->getNext() != nullptr && type <= front->getPriority()) {
					front = front->getNext();
				}
				if (front->getNext() != nullptr) {
					FlightsPtr->setNext(front->getNext());
					front->setNext(FlightsPtr);
				}
				else {
					FlightsPtr->setNext(nullptr);
					front->setNext(FlightsPtr);
					backPtr = FlightsPtr;
				}
			}
		
		}
		else {//least important node
			front->setNext(FlightsPtr);
			backPtr = FlightsPtr;
		}
	}
	return true ;
} // end enqueue


/////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
T* Queue<T>:: dequeue()
{

	T* frntEntry = new T;
	if(isEmpty())
		frntEntry=nullptr;

	T* nodeToDeletePtr = frontPtr;
	frntEntry = frontPtr;
	frontPtr = frontPtr->getNext();
	// Queue is not empty; remove front
	if (nodeToDeletePtr == backPtr)	 // Special case: one node in queue
		backPtr = nullptr ;	
		
	// Free memory reserved by the dequeued node
	return frntEntry;

}
template <typename T>
bool Queue<T>::candequeue(int time) {
	if (isEmpty())
		return false;
	if (frontPtr->getTime() == time)
		return true;
	return false;
}
template<typename T>
void Queue<T>::deleteAll() {
	while (frontPtr != nullptr) {
		T* nodeToDeletePtr = frontPtr;
		frontPtr = frontPtr->getNext();
		// Queue is not empty; remove front
		if (nodeToDeletePtr == backPtr)	 // Special case: one node in queue
			backPtr = nullptr;
		delete nodeToDeletePtr;
	}
}
//template<typename T>
//bool Queue<T>::deleteNode(T* node) {
//	if (isEmpty())
//		return false;
//	T* ptr;
//	peekFront(ptr);
//	if (ptr = node) {
//		dequeue(ptr);
//		delete ptr;
//		return true;
//	}
//	while (ptr->getNext() = T)
//		ptr = ptr->getNext();
//	if
//}




/////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
bool Queue<T>:: peekFront(T* frntEntry) const 
{
	if(isEmpty())
		return false;

	frntEntry = frontPtr;
	return true;

}
///////////////////////////////////////////////////////////////////////////////////

template <typename T>
Queue<T>::~Queue()
{
	deleteAll();
}
#endif