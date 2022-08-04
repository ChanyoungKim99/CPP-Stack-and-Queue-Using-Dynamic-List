#include "Queue.h"
#include <iostream>

void PrintInfo()
{
	std::cout << "<QUEUE>" << std::endl;
	std::cout << "[1] enqueue" << std::endl;
	std::cout << "[2] dequeue" << std::endl;
	std::cout << "[3] exit" << std::endl;
	std::cout << "--------------" << std::endl;
}

void ProcessUserInput(Queue& queue)
{
	int command{};
	bool isExit{ false };

	while (true)			
	{
		Print(queue);

		std::cout << std::endl;
		std::cout << ">: ";
		std::cin >> command;

		switch (command)
		{
		case ENQUEUE:
		{
			int value;
			std::cout << "	value : ";
			std::cin >> value;
			Enqueue(queue, value);
			break;
		}

		case DEQUEUE:
			Dequeue(queue);
			break;

		case EXIT:
			isExit = true;	
			break;			

		default:
			std::cout << "Invalid Command!" << std::endl;
			break;
		}

		if (isExit == true)
		{
			break;				
		}
	}
}


int main()
{
	// Double Linked List¸¦ »ç¿ë

	Queue myQueue;

	Initialize(myQueue);

	PrintInfo();
	ProcessUserInput(myQueue);

	DeleteAll(myQueue);
}