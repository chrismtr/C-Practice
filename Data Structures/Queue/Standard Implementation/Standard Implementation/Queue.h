#pragma once

#include <iostream>

#include "Node.h"

template <typename Type>
class Queue
{
private:
	Node<Type>* head;
	Node<Type>* tail;
	int m_size;

public:
	Queue();  // +
	Queue(const Queue<Type> &queue);  // +
	~Queue();  // +

	void pop();  // +
	void push(int data);  // +
	void print();  // +

	Node<Type>* front();  // +
	Node<Type>* back();  // +
	bool empty();  // +
	int size();  // +
};

template <typename Type>
Queue<Type>::Queue()
	: head(nullptr), tail(nullptr), m_size(0)
{
}

template <typename Type>
Queue<Type>::Queue(const Queue<Type>& queue)
	: head(nullptr), tail(nullptr), m_size(0)
{
	Node<Type> *node = queue.head;

	while (node)
	{
		push(node->getData());
		node = node->getNext();
	}
}

template <typename Type>
Queue<Type>::~Queue()
{
	while (head)
		pop();
}

template <typename Type>
void Queue<Type>::pop()
{
	Node <Type>* newHead = head;
	head = head->getNext();

	delete newHead;
	--m_size;
}

template<typename Type>
void Queue<Type>::push(int data)
{
	Node<Type> *node = new Node <Type>(data);
	if (!tail)
		head = tail = node;
	else
	{
		tail->setNext(node);
		tail = node;
	}

	++m_size;
}

template <typename Type>
void Queue<Type>::print()
{
	if (head)
	{
		Node<Type>* node = head;

		while (node)
		{
			std::cout << node->getData() << '\n';
			node = node->getNext();
		}
		std::cout << '\n';
	}
	else
		std::cout << "The queue is empty.\n";
}

template<typename Type>
Node<Type>* Queue<Type>::front()
{
	return head;
}

template<typename Type>
Node<Type>* Queue<Type>::back()
{
	return tail;
}

template<typename Type>
bool Queue<Type>::empty()
{
	if (tail)
		return false;
	return true;
}

template<typename Type>
int Queue<Type>::size()
{
	return m_size;
}
