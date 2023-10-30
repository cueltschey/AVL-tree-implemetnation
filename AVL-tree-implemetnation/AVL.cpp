#include "AVL.h"
#include "Node.h"
bool AVL::insert(Node*& node, int data)
{
	if (node == nullptr) {
		node = new Node(data);
		return true;
	}
	if (data < node->data)
		return insert(node->left, data);
	if (data > node->data)
		return insert(node->right, data);
	return false;
}

bool AVL::remove(Node*& node, int data)
{
	if (node == nullptr)
		return false;
	if (data < node->data)
		return remove(node->left, data);
	if (data > node->data)
		return remove(node->right, data);
	int deg = node->degree();
	if (deg == 0)
	{
		delete node;
		node = nullptr;
	}
	else if (deg == 1)
	{
		Node* tmp = node;
		if (node->left != nullptr) {
			node = node->left;
		}
		else {
			node = node->right;
		}
		delete tmp;
	}
	else
	{
		Node* tmp = node->left;
		while (tmp->right != nullptr)
		{
			tmp = tmp->right;
		}
		node->data = tmp->data;
		remove(node->left, tmp->data);
	}
	return true;
}
bool AVL::find(Node* node, int data) {
	if (node == nullptr) { return false; }
	if (data == node->data) { return true; }
	if (data < node->data)
		return find(node->left, data);
	if (data > node->data)
		return find(node->right, data);
	return false;

}
void AVL::postOrder(Node* node, ostream& os)
{
	if (node == nullptr) return;
	postOrder(node->left, os);
	postOrder(node->right, os);
	os << node->data << " ";
}
AVL::~AVL()
{
}
void AVL::inOrder(Node* node, ostream& os) {

	if (node == nullptr) return;
	inOrder(node->left, os);
	os << node->data << " ";
	inOrder(node->right, os);
}
void AVL::preOrder(Node* node, ostream& os) {
	if (node == nullptr) return;
	os << node->data << " ";
	preOrder(node->left, os);
	preOrder(node->right, os);

}

bool AVL::insert(int data) {
	return insert(root, data);
}
bool AVL::remove(int data) {
	return remove(root, data);
}
bool AVL::find(int data) {
	return find(root, data);
}
void AVL::inOrder(ostream& os) {
	inOrder(root, os);
}
void AVL::preOrder(ostream& os) {
	preOrder(root, os);
}
void AVL::postOrder(ostream& os) {
	postOrder(root, os);
}