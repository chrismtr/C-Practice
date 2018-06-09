#pragma once
#include <iostream>

#include "Node.h"

template <typename Type>
class Stack
{
private:
	Node<Type>* top;
	int m_size;
public:
	Stack();  // +
	Stack(const Stack<Type> &source);  // +
	~Stack();  // +

	void push(Type data);  // +
	void pop();  // +
	void print();  // +

	bool empty();  // +
	int size() { return m_size; }  // +
};

template <typename Type>
Stack<Type>::Stack()
	: top(nullptr), m_size(0)
{
}

template <typename Type>
Stack<Type>::Stack(const Stack<Type> &source)
	: top(nullptr), m_size(0)
{
	Node<Type>* node = source.top;

	while (node)
	{
		push(node->getData());
		node = node->getNext();
	}
}

template <typename Type>
Stack<Type>::~Stack()
{
	while (top)
		pop();
}

template <typename Type>
void Stack<Type>::push(Type data)
{
	Node<Type>* node = new Node<Type>(data);
	node->setNext(top);
	top = node;
	++m_size;
}

template <typename Type>
void Stack<Type>::pop()
{
	Node<Type> *newHead;

	newHead = top->getNext();
	delete top;
	top = newHead;
	--m_size;
}

template <typename Type>
void Stack<Type>::print()
{
	if (top)
	{
		Node<Type> *node = top;

		while (node)
		{
			std::cout << node->getData() << '\n';
			node = node->getNext();
		}
		std::cout << '\n';
	}
	else
		std::cout << "Stack is empty\n";
}

template <typename Type>
bool Stack<Type>::empty()
{
	if (top) return false;

	return true;
}