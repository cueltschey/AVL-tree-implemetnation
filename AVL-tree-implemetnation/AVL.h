#pragma once
#include "Node.h"
#include <iostream>
using namespace std;
class AVL
{
private:
	Node* root;
	bool insert(Node*& node, int data);
	bool remove(Node*& node, int data);
	bool find(Node* node, int data);
	void inOrder(Node* node, ostream& os);
	void preOrder(Node* node, ostream& os);
	void postOrder(Node* node, ostream& os);
public:
	AVL() : root(nullptr) {}
	~AVL();
	bool insert(int data);
	bool remove(int data);
	bool find(int data);
	void inOrder(ostream& os);
	void preOrder(ostream& os);
	void postOrder(ostream& os);
};

