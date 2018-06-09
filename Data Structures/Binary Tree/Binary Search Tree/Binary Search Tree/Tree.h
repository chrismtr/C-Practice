#pragma once

#include <iostream>

#include "Node.h"

template <class Type>
class Tree
{
private:
	Node<Type> *root;

	Node<Type>* pushUtil(Type data, Node<Type> *node); // +
	void deleteTreeUtil(Node<Type> *node);  // +
	void printUtil(Node<Type> *node);  // +
public:
	Tree();  // +
	Tree(const Tree<Type> &source);  // ?????
	~Tree();  // +

	void push(Type data); // +
	void deleteTree();  // +
	void print();  // +
	Node<Type>* search();  // ?????

	int size();  // ?????
	bool empty();  // ?????
};

template <class Type>
Tree<Type>::Tree()
	: root(nullptr)
{
}

template <class Type>
Tree<Type>::~Tree()
{
	deleteTree();
}

template <class Type>
void Tree<Type>::push(Type data)
{
	root = pushUtil(data, root);
}

template <class Type>
Node<Type>* Tree<Type>::pushUtil(Type data, Node<Type> *node)
{
	if (!node)
	{
		node = new Node<Type>(data);
	}
	else
	{
		if (data <= node->getData())
		{
			node->setLeft(pushUtil(data, node->getLeft()));
		}
		else
		{
			node->setRight(pushUtil(data, node->getRight()));
		}
	}

	return node;
}

template <class Type>
void Tree<Type>::deleteTree()
{
	deleteTreeUtil(root);
}

template <class Type>
void Tree<Type>::deleteTreeUtil(Node<Type> *node)
{
	if (node)
	{
		deleteTreeUtil(node->getLeft());
		deleteTreeUtil(node->getRight());

		delete node;
	}
}

template <class Type>
void Tree<Type>::print()
{
	printUtil(root);
}

template <class Type>
void Tree<Type>::printUtil(Node<Type> *node)
{
	if (node)
	{
		printUtil(node->getLeft());
		
		std::cout << node->getData() << '\n';

		printUtil(node->getRight());
	}
}