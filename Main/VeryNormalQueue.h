#ifndef VERYNORM_H
#define VERYNORM_H




template <typename T>
class VeryNormalQueue
{
private :
	
	T* backPtr;
	T* frontPtr;
public :
	VeryNormalQueue();
	bool isEmpty() const ;
	bool enqueue(T*);
	T* dequeue();  
	bool peekFront(T& frntEntry)  const;	
	~VeryNormalQueue();
};
/////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
VeryNormalQueue<T>::VeryNormalQueue()
{
	backPtr=nullptr;
	frontPtr=nullptr;

}
/////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
bool VeryNormalQueue<T>::isEmpty() const
{
	if(frontPtr==nullptr)
		return true;
	else
		return false;
}

/////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
bool VeryNormalQueue<T>::enqueue(T* newNodePtr)
{
	
	if (isEmpty())
		frontPtr = newNodePtr; // The queue is empty
	else
		backPtr->setNext(newNodePtr); // The queue was not empty
	backPtr = newNodePtr; // New node is at back
	return true ;
} // end enqueue


/////////////////////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
T* VeryNormalQueue<T>:: dequeue()
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


template <typename T>
bool VeryNormalQueue<T>:: peekFront(T& frntEntry) const
{
	if(isEmpty())
		return false;

	frntEntry = frontPtr->getItem();
	return true;

}
///////////////////////////////////////////////////////////////////////////////////

template <typename T>
VeryNormalQueue<T>::~VeryNormalQueue()
{
	T item;
	while(dequeue(item)){}
}
#endif // !1