#pragma once

template <typename Type>
class Node
{
private:
	Type data;
	Node<Type>* next;

public:
	Node();	// +
	Node(Type data); // +

	void setNext(Node<Type>* node);  // +

	int getData();		// +
	Node<Type>* getNext();	// +
};

template <typename Type>
Node<Type>::Node()
	: data(0), next(nullptr)
{
}

template <typename Type>
Node<Type>::Node(Type data)
	: data(data), next(nullptr)
{
}

template<typename Type>
void Node<Type>::setNext(Node<Type>* node)
{
	next = node;
}

template<typename Type>
int Node<Type>::getData()
{
	return data;
}

template<typename Type>
Node<Type>* Node<Type>::getNext()
{
	return next;
}