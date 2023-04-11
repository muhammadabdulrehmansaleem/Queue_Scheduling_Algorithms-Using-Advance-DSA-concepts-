#include <iostream>
#include "Queue.h"
using namespace std;
template <typename T>
void Queue<T>::reSize(int newCap)
{
	T* temp;
	if (newCap == 0)
	{
		(*this).~Queue();
		return;
	}
	temp = new T[newCap];
	for (int i = 0, j = front; i < noOfElements; i++, j = (j + 1) % capacity)
	{
		temp[i] = data[j];
	}
	front = 0;
	rear = noOfElements - 1;
	if (data)
		delete[] data;
	data = temp;
	capacity = newCap;
}

template <typename T>
Queue<T>::Queue(int c)
{
	front = 0;
	rear = 0;
	noOfElements = 0;
	capacity = 0;
	data = nullptr;
}

template <typename T>
Queue<T>::~Queue()
{
	front = 0;
	rear = 0;
	noOfElements = 0;
	capacity = 0;
	if (data)
		delete[] data;
	data = nullptr;
}

//Queue<T>::Queue(const Queue<T>& q)
//{
//	if (!q.data)
//		return;
//	data = new T[q.capacity];
//	int j = q.front;
//	for (int i = 0; i < q.noOfElements; i++)
//	{
//		data[j] = q.data[j];
//		j = (j + 1) % capacity;
//	}
//	noOfElements = q.noOfElements;
//	capacity = q.capacity;
//	front = q.front;
//	rear = q.rear;
//}
//
//template <typename T>
//Queue<T> Queue<T>::operator = (const Queue<T>& q)
//{
//	if (!q.data)
//		return *this;
//	data = new T[q.capacity];
//	int j = q.front;
//	for (int i = 0; i < q.noOfElements; i++)
//	{
//		data[j] = q.data[j];
//		j = (j + 1) % q.capacity;
//	}
//	noOfElements = q.noOfElements;
//	capacity = q.capacity;
//	front = q.front;
//	rear = q.rear;
//
//
//	return *this;
//}

template <class T>
void Queue<T>::enqueue(T element)
{
	if (isFull())
	{
		if (capacity == 0)
			reSize(1);
		else
			reSize(capacity * 2);
	}
	rear = (rear + 1) % capacity;
	data[rear] = element;
	noOfElements++;
}

template <typename T>
T Queue<T>::dequeue()
{
	if (isEmpty())
		exit(0);
	T temp = data[front];
	front = (front + 1) % capacity;
	noOfElements--;
	if (noOfElements == capacity / 4)
		reSize(capacity / 4);
	return temp;
}

template <typename T>
T Queue<T>::getElementAtFront()
{
	return data[front];
}

template <typename T>
bool Queue<T>::isEmpty()
{
	if (noOfElements == 0)
		return true;
	return false;
}
template <typename T>
bool Queue<T>::isFull()
{
	if (noOfElements == capacity)
		return true;
	return false;
}

template <typename T>
int Queue<T>::getNoOfElements()
{
	return noOfElements;
}

template <typename T>
int Queue<T>::getCapacity()
{
	return capacity;
}

//template <typename T>
//void Queue<T>::print()
//{
//
//	for (int i = 0, j = front; i < noOfElements; i++, j = (j + 1) % capacity)
//	{
//		cout << data[j] << endl;
//	}
//}