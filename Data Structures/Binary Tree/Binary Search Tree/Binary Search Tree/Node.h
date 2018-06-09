#pragma once

template <typename Type>
class Node
{
private:
	Type data;
	Node<Type> *left;
	Node<Type> *right;

public:
	Node(Type data)
		: data(data)
	{
	}

	Type getData() { return data; }
	Node<Type>* getLeft() { return left; }
	Node<Type>* getRight() { return right; }

	void setLeft(Node<Type> *node) { left = node; }
	void setRight(Node<Type> *node) { right = node; }
};