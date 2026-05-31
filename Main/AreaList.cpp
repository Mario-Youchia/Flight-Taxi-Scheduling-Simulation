#include "AreaList.h"
AreaList::AreaList() {
	Head = nullptr;
	count = 0;
}
AreaList::~AreaList() {
	DeleteAll();
}
void AreaList::InsertArea(int NoLanes, int AreaNum) {
	Areas* newArea = new Areas(NoLanes, AreaNum);
	InsertArea(newArea);
}
void AreaList::InsertArea(Areas* newArea) {
	if (Head == nullptr) {
		Head = newArea;
		count++;
		return;
	}
	else {
		Areas* A1 = Head;
		while (A1->getNext() != nullptr) {
			A1 = A1->getNext();
		}
		A1->setNext(newArea);
	}
	count++;
}
int AreaList::getCount() {
	return count;
}
VeryNormalQueue<Areas>* AreaList::getQueue() {
	Areas* Arr = new Areas;
	VeryNormalQueue<Areas>* qu = new VeryNormalQueue<Areas>;
	Arr = Head;
	while (Arr != nullptr) {
		qu->enqueue(Arr);
		Arr = Arr->getNext();
	}
	return qu;
}
void AreaList::DeleteAll()
{
	Areas* A = Head;
	while (Head != nullptr)
	{
		A = Head->getNext();
		delete Head;
		Head = A;
	}
}
Areas* AreaList::findArea(int AreaNo) {
	Areas* A = Head;
	while (A->getAreaNo() != AreaNo)
		A = A->getNext();
	if (A->getAreaNo() != AreaNo)
		return nullptr;
	return A;
}

