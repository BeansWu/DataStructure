#pragma once
#ifndef MYSTACK_H
#define MYSTACK_h

#include <iostream>

template <typename T>
class MyStack {
public:
	MyStack(int size);
	~MyStack();
	bool stackEmpty();
	bool stackFull();
	void clearStack();
	int stackLength();
	bool push(T elem);
	bool pop(T &elem);
	void stackTraverse(bool isFromButton);

private:
	T *m_iBuffer;
	int m_iTop;
	int m_iSize;
};

template <typename T>
MyStack<T>::MyStack(int size) {
	m_iSize = size;
	m_iBuffer = new T[m_iSize];
	m_iTop = 0;
};

template <typename T>
MyStack<T>::~MyStack() {
	delete[]m_iBuffer;
};

template <typename T>
bool MyStack<T>::stackEmpty() {
	if (0 == m_iTop) {
		return true;
	}
	return false;
}

template <typename T>
bool MyStack<T>::stackFull() {
	if (m_iSize == m_iTop) {
		return true;
	}
	return false;
}

template <typename T>
void MyStack<T>::clearStack() {
	m_iTop = 0;
}

template <typename T>
int MyStack<T>::stackLength() {
	return m_iTop;
}

template <typename T>
bool MyStack<T>::push(T elem) {
	if (stackFull()) {
		return false;
	}
	m_iBuffer[m_iTop] = elem;
	m_iTop++;
	return true;
}

template <typename T>
bool MyStack<T>::pop(T &elem) {
	if (stackEmpty()) {
		return false;
	}
	m_iTop--;
	elem = m_iBuffer[m_iTop];
	return true;
}

template <typename T>
void MyStack<T>::stackTraverse(bool isFromButton) {
	if (isFromButton) {
		for (int i = 0; i < m_iTop; i++) {
			cout << m_iBuffer[i];
		}
	}
	else {
		for (int i = m_iTop - 1; i >= 0; i++) {
			cout << m_iBuffer[i];
		}
	}
}
#endif
