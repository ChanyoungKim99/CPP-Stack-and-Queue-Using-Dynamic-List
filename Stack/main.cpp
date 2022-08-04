#include <iostream>
#include "Stack.h"

void PrintInfo()
{
	std::cout << "<STACK>" << std::endl;
	std::cout << "[1] push" << std::endl;
	std::cout << "[2] pop" << std::endl;
	std::cout << "[3] exit" << std::endl;
	std::cout << "--------------" << std::endl;
}

void ProcessUserInput(Stack& stack)
{
	int command{};
	bool isExit{ false };

	while (true)			// 무한 루프
	{
		Print(stack);

		std::cout << std::endl;
		std::cout << ">: ";
		std::cin >> command;

		switch (command)
		{
			case PUSH:
			{
				int value;
				std::cout << "	value : ";
				std::cin >> value;
				Push(stack, value);
				break;
			}

			case POP:
				Pop(stack);
				break;

			case EXIT:
				isExit = true;	// 종료 플래그
				break;			// switch를 깨고 나오는 break

			default:
				std::cout << "Invalid Command!" << std::endl;
				break;
		}

		if (isExit == true)
		{
			break;				// while을 깨고 나오는 break
		}
	}
}
int main()
{
	// Single Linked List를 사용 (Double은 거슬러 올라와야 하는지의 여부가 결정)

	Stack myStack;

	Initialize(myStack);

	PrintInfo();
	ProcessUserInput(myStack);

	DeleteAll(myStack);
}