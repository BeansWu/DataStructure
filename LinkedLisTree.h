#pragma once
#ifndef TREE_BY_LINKED_LIST_H
#define TREE_BY_LINKED_LIST_H

#include <iostream>
#include <stdio.h>

using namespace std;

class Node {
public:
	Node(int nIndex, int nData);
	Node *search(int nIndex);
	void delNode();
	void preorderTraversal();
	void orderTraversal();
	void posteriorTraversal();

	int getData();
	void setData(int nData);
	int getIndex();
	Node *getPLChild();
	void setPLChild(Node *pNode);
	Node *getPRChild();
	void setPRChild(Node *pNode);
	Node *getParent();
	void setParent(Node *pNode);

private:
	int index;
	int data;
	Node *pLChild;
	Node *pRChild;
	Node *pParent;
};

Node::Node(int nIndex, int nData) {
	index = nIndex;
	data = nData;
	pLChild = NULL;
	pRChild = NULL;
	pParent = NULL;
};

Node *Node::search(int nIndex) {
	if (index == nIndex) {
		return this;
	}

	Node *temp = NULL;

	if (pLChild != NULL) {
		if (pLChild->index == nIndex) {
			return pLChild;
		}
		else {
			temp = pLChild->search(nIndex);
			if (temp != NULL) {
				return temp;
			}
		}
	}

	if (pRChild != NULL) {
		if (pRChild->index == nIndex) {
			return pRChild;
		}
		else {
			temp = pRChild->search(nIndex);
			return temp;
		}
	}

	return NULL;
};

void Node::delNode() {
	if (pLChild != NULL) {
		pLChild->delNode();
	}

	if (pRChild != NULL) {
		pRChild->delNode();
	}

	if (pParent != NULL) {
		if (pParent->pLChild == this) {
			pParent->pLChild = NULL;
		}
		if (pParent->pRChild == this) {
			pParent->pRChild = NULL;
		}
	}

	delete this;
}

void Node::preorderTraversal() {
	cout << index << " " << data << endl;

	if (pLChild != NULL) {
		pLChild->preorderTraversal();
	}

	if (pRChild != NULL) {
		pRChild->preorderTraversal();
	}
}

void Node::orderTraversal() {
	if (pLChild != NULL) {
		pLChild->orderTraversal();
	}

	cout << index << " " << data << endl;

	if (pRChild != NULL) {
		pRChild->orderTraversal();
	}
}

void Node::posteriorTraversal() {
	if (pLChild != NULL) {
		pLChild->posteriorTraversal();
	}

	if (pRChild != NULL) {
		pRChild->posteriorTraversal();
	}

	cout << index << " " << data << endl;
}

int Node::getData() {
	return data;
}

void Node::setData(int nData) {
	data = nData;
}

int Node::getIndex() {
	return index;
}

Node *Node::getPLChild() {
	return pLChild;
}

Node *Node::getPRChild() {
	return pRChild;
}

Node *Node::getParent() {
	return pParent;
}

void Node::setPLChild(Node *pNode) {
	pLChild = pNode;
}

void Node::setPRChild(Node *pNode) {
	pRChild = pNode;
}

void Node::setParent(Node *pNode) {
	pParent = pNode;
}

class Tree {
public:
	Tree();
	~Tree();
	Node *search(int nIndex);
	bool addNode(int nIndex, int direction, Node *pNode);
	bool delNode(int nIndex, Node *pNode);
	void preorderTraversal();
	void orderTraversal();
	void posteriorTraversal();

private:
	Node *pTreeRoot;
};

Tree::Tree() {
	pTreeRoot = new Node(0, 0);
}

Tree::~Tree() {
	pTreeRoot->delNode();
}

Node *Tree::search(int nIndex) {
	return pTreeRoot->search(nIndex);
}

bool Tree::addNode(int nIndex, int direction, Node *pNode) {
	Node *temp = pTreeRoot->search(nIndex);
	if (temp == NULL) {
		return false;
	}

	Node *node = new Node(pNode->getIndex(), pNode->getData());
	node->setParent(temp);
	if (node == NULL) {
		return false;
	}

	if (direction == 0) {
		if (temp->getPLChild() != NULL) {
			return false;
		}

		temp->setPLChild(node);
	}

	if (direction == 1) {
		if (temp->getPRChild() != NULL) {
			return false;
		}

		temp->setPRChild(node);
	}

	return true;
}

bool Tree::delNode(int nIndex, Node *pNode) {
	Node *temp = pTreeRoot->search(nIndex);

	if (temp == NULL) {
		return false;
	}

	if (pNode != NULL) {
		pNode->setData(temp->getData());
	}

	temp->delNode();

	return true;
}

void Tree::preorderTraversal() {
	pTreeRoot->preorderTraversal();
}

void Tree::orderTraversal() {
	pTreeRoot->orderTraversal();
}

void Tree::posteriorTraversal() {
	pTreeRoot->posteriorTraversal();
}

#endif // !TREE_BY_LINKED_LIST_H
