#include "Queue.h"
#include <iostream>

void Initialize(Queue& queue)
{
	queue.count = 0;
	queue.pHead = nullptr;
	queue.pTail = nullptr;
}

void DeleteAll(Queue& queue)
{
	Element* pElement{ queue.pHead };

	while (pElement != nullptr)
	{
		pElement = pElement->pNext;
		delete pElement->pPrev;
	}
	Initialize(queue);
}

void Enqueue(Queue& queue, int value)
{
	Element* pElement = new Element;
	pElement->value = value;

	if (queue.count == 0)
	{
		queue.pHead = pElement;
		queue.pTail = pElement;
		queue.count++;
	}
	else
	{
		queue.pTail->pNext = pElement;
		pElement->pPrev = queue.pTail;
		queue.pTail = pElement;

		queue.count++;
	}
}

bool Dequeue(Queue& queue)
{
	Element* pElement{ queue.pHead };

	if (queue.count == 0 || queue.pHead == nullptr)
	{
		std::cout << "QUEUE IS EMPTY!!" << std::endl;
		return false;
	}
	std::cout << "dequeue: " << queue.pHead->value << std::endl;

	queue.pHead = pElement->pNext;
	delete pElement;

	if (queue.pHead == nullptr)
	{
		std::cout << "QUEUE IS EMPTY!!" << std::endl;
		return false;
	}
	queue.pHead->pPrev = nullptr;

	queue.count--;
	return true;
}

void Print(Queue& queue)
{
	Element* pElement{ queue.pHead };

	while (pElement != nullptr)
	{
		std::cout << pElement->value << std::endl;
		pElement = pElement->pNext;
	}
}
