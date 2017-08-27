#pragma once
#ifndef TREE_H
#define TREE_H

#include <iostream>

using namespace std;

class Tree {
public:
	Tree(int size, int *pRoot);
	~Tree();
	int *getNode(int index);
	bool addNode(int index, int direction, int *pNode);
	bool delNode(int index, int *pNode);
	void traverse();

private:
	int *m_pTree;
	int m_iSize;
};

Tree::Tree(int size, int *pRoot) {
	m_pTree = new int[size];
	m_iSize = size;
	for (int i = 0; i < m_iSize; i++) {
		m_pTree[i] = 0;
	}
	m_pTree[0] = *pRoot;
};

Tree::~Tree() {
	delete[]m_pTree;
	m_pTree = NULL;
	m_iSize = 0;
}

int *Tree::getNode(int index) {
	if (index < 0 || index > m_iSize) {
		return NULL;
	}
	if (m_pTree[index] == 0) {
		return NULL;
	}

	return &m_pTree[index];
}

bool Tree::addNode(int index, int direction, int *pNode) {
	if (index < 0 || index >= m_iSize) {
		return false;
	}
	if (m_pTree[index] == 0) {
		return false;
	}
	if (2 * index + direction >= m_iSize || m_pTree[2 * index + direction] != 0) {
		return false;
	}
	m_pTree[2 * index + direction] = *pNode;

	return true;
}

bool Tree::delNode(int index, int *pNode) {
	if (index < 0 || index >= m_iSize) {
		return false;
	}
	if (m_pTree[index] != 0) {
		return false;
	}

	*pNode = m_pTree[index];
	m_pTree[index] = 0;

	return true;
}

void Tree::traverse() {
	for (int i = 0; i < m_iSize; i++) {
		cout << m_pTree[i] << " ";
	}
}

#endif // !TREE_H
