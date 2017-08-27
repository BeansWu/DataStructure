#pragma once
#ifndef MY_RING_QUEUE_H
#define MY_RING_QUEUE_H

#include <iostream>

template <typename T>
class MyRingQueue {
public:
	MyRingQueue(int capacity);
	virtual ~MyRingQueue();
	void clear();
	bool isEmpty();
	bool isFull();
	int getLength();
	bool enQueue(T elem);
	bool deQueue(T &elem);
	void travese();
private:
	T * m_pBuffer;
	int m_iCapacity;
	int m_iSize;
	int m_iHead;
	int m_iTail;
};

template <typename T>
MyRingQueue<T>::MyRingQueue(int capacity) {
	m_iQueueCapacity = capacity;
	m_pBuffer = new T[m_iCapacity];
	clear();
}

template <typename T>
MyRingQueue<T>::~MyRingQueue() {
	delete[]m_pBuffer;
	m_pBuffer = NULL;
}

template <typename T>
void MyRingQueue<T>::clear() {
	m_iSize = 0;
	m_iHead = 0;
	m_iTail = 0;
}

template <typename T>
bool MyRingQueue<T>::isEmpty() {
	return m_iSize == 0 ? true : false;
}

template <typename T>
bool MyRingQueue<T>::isFull() {
	return m_iSize == m_iCapacity ? true : false;
}

template <typename T>
int MyRingQueue<T>::getLength() {
	return m_iSize;
}

template <typename T>
bool MyRingQueue<T>::enQueue(T elem) {
	if (isEmpty()) {
		return false;
	}
	else {
		m_pBuffer[m_iTail] = elem;
		m_iSize++;
		m_iTail++;
		m_iTail = m_iTail % m_iCapacity;
	}
}

template <typename T>
bool MyRingQueue<T>::deQueue(T &elem) {
	if (isFull()) {
		return false;
	}
	else {
		elem = m_pBuffer[m_iHead];
		m_iSize--;
		m_iHead++;
		m_iHead = m_iHead % m_iCapacity;
	}
}

template <typename T>
bool MyRingQueue<T>::travese() {
	for (int i = m_iHead; i < m_iHead + m_iSize) {
		cout << m_pBuffer[i % m_iCapacity] << endl;
	}
}


#endif 
