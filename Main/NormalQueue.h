#pragma once
#ifndef LOWQUEUE_H
#define	LOWQUEUE_H
#include "Flights.h"
template <typename T>
class NormalQueue
{
private:

	T* backPtr;
	T* frontPtr;
public:
	NormalQueue();
	bool isEmpty() const;
	bool enqueue(T* newEntry, int pr);
	T* dequeue();
	bool peekFront(T* frntEntry)  const;
	void deleteAll();
	~NormalQueue();
};
template <typename T>
NormalQueue<T>::NormalQueue()
{
	backPtr = nullptr;
	frontPtr = nullptr;

}
/////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
bool NormalQueue<T>::isEmpty() const
{
	if (frontPtr == nullptr)
		return true;
	else
		return false;
}

/////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
bool NormalQueue<T>::enqueue(T* newEntry, int pr)
{
	newEntry->setNext(nullptr);
	T* front = frontPtr;
	if (isEmpty())
		frontPtr = newEntry;
	else if (pr <= frontPtr->getFinishTime()) {
		if (frontPtr->getNext() == nullptr) {
			backPtr = frontPtr;
			newEntry->setNext(frontPtr);
			frontPtr = newEntry;
		}
		else {
			newEntry->setNext(frontPtr);
			frontPtr = newEntry;
		}
	}
	else {
		while (front->getNext() != nullptr) {
			if (pr > front->getNext()->getFinishTime()) {
				front = front->getNext();
			}
			else {
				break;
			}

		}
		if (front->getNext() != nullptr) {
			newEntry->setNext(front->getNext());
			front->setNext(newEntry);
		}
		else {//least important node
			front->setNext(newEntry);
			backPtr = newEntry;
		}
	}
	return true;
} // end enNormalQueue


/////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
T* NormalQueue<T>::dequeue()
{
	T* frntEntry = new T;
	if (isEmpty())
		frntEntry = nullptr;

	T* nodeToDeletePtr = frontPtr;
	frntEntry = frontPtr;
	frontPtr = frontPtr->getNext();
	// Queue is not empty; remove front
	if (nodeToDeletePtr == backPtr)	 // Special case: one node in queue
		backPtr = nullptr;

	// Free memory reserved by the dequeued node
	return frntEntry;

}



/////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
bool NormalQueue<T>::peekFront(T* frntEntry) const
{
	if (isEmpty())
		return false;

	frntEntry = frontPtr;
	return true;

}
///////////////////////////////////////////////////////////////////////////////////

template<typename T>
void NormalQueue<T>::deleteAll() {
	while (frontPtr != nullptr) {
		T* nodeToDeletePtr = frontPtr;
		frontPtr = frontPtr->getNext();
		// Queue is not empty; remove front
		if (nodeToDeletePtr == backPtr)	 // Special case: one node in queue
			backPtr = nullptr;
		delete nodeToDeletePtr;
	}
}
template <typename T>
NormalQueue<T>::~NormalQueue()
{
	deleteAll();
}
#endif // !LOWQUEUE_H