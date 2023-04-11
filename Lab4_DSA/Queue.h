#ifndef QUEUE_H
#define QUEUE_H
#include"Process.h"
template <typename T>
class Queue
{
	int rear;
	int front;
	int capacity;
	int noOfElements;
	T* data;
	void reSize(int newCap);
public:
	Queue(int i=0);
	~Queue();
	Queue(const Queue<T>& q);
	Queue<T> operator = (const Queue<T>& q);
	void enqueue(T element);
	T dequeue();
	T getElementAtFront();
	bool isEmpty();
	bool isFull();
	int getCapacity();
	int getNoOfElements();
	void print();

};
template class Queue<Process>;

#endif // !QUEUE_H
