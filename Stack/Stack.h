#pragma once

enum Command
{
	PUSH = 1,
	POP = 2,
	EXIT = 3	// ���α׷� ����
};

struct Element
{
	int value;
	Element* pNext;
};

struct Stack
{	
	int count;				// push = count++ , pop = count--
	Element* pTop;			// ������ ���� ���� �ִ� ������ �ʿ�
};

void Initialize(Stack& stack);
void DeleteAll(Stack& stack);
void Push(Stack& stack, int value);
bool Pop(Stack& stack);		// bool�� ���� = ������ ������ ���� �� 
							// push�� ����ص� ���Ѿ�����, 
							// pop�� ������ŭ�� �����ϴ�
void Print(Stack& stack);

