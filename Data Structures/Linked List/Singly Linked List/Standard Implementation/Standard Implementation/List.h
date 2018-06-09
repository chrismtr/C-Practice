#pragma once

#include <iostream>

#include "Node.h"

template <typename Type>
class List
{
private:
	int m_size;
	Node<Type>* head;

public:
	List();		// +
	List(const List<Type> &source); // +
	List(List<Type> &&source); // +
	~List();	// +

	void addFront(Type data); // +
	void addEnd(Type data);	//  +
	void removeFront();		  // +
	void removeEnd();		// +
	void print();		  // +

	bool empty();	// +
	int size() { return m_size; }	// +
};

template <typename Type>
List<Type>::List()
	: head(nullptr), m_size(0)
{
}

template <typename Type>
List<Type>::List(const List<Type> &source)
	: head(nullptr), m_size(0) 
{
	Node<Type>* node = source.head;
	
	while (node)
	{
		addEnd(node->getData());
		node = node->getNext();
	}
}

template <typename Type>
List<Type>::List(List<Type> &&source)
{
	head = source.head;
	m_size = source.m_size;

	source.head = nullptr;
	source.m_size = 0;
}

template <typename Type>
List<Type>::~List()
{
	while (head)
	{
		removeFront();
	}
}

template <typename Type>
void List<Type>::addFront(Type data)
{
	Node<Type>* newHead = new Node<Type>(data);

	newHead->setNext(head);
	head = newHead;
	++m_size;
}

template <typename Type>
void List<Type>::addEnd(Type data)
{
	if (!head)
	{
		addFront(data);
		return;
	}

	Node<Type>* node = head;

	while (node->getNext())
	{
		node = node->getNext();
	}

	node->setNext(new Node<Type>(data));
	++m_size;
}

template <typename Type>
void List<Type>::removeFront()
{
	if (head)
	{
		Node<Type>* newHead = head;
		head = head->getNext();
		delete newHead;
	}
	--m_size;
}

template <typename Type>
void List<Type>::removeEnd()
{
	if (head)
	{
		Node<Type>* current = head;
		Node<Type>* prev = nullptr;

		while (current->getNext())
		{
			prev = current;
			current = current->getNext();
		}
		delete current;
		prev->setNext(nullptr);
		--m_size;
	}
}

template <typename Type>
void List<Type>::print()
{
	if (!head)
	{
		std::cout << "The list is empty.\n";
		return;
	}

	Node<Type>* node = head;

	while (node)
	{
		std::cout << node->getData() << ' ';
		node = node->getNext();
	}
	std::cout << '\n';
}

template <typename Type>
bool List<Type>::empty()
{
	if (head) return false;

	return true;
}
