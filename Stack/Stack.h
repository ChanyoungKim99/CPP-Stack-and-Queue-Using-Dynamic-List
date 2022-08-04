#pragma once

enum Command
{
	PUSH = 1,
	POP = 2,
	EXIT = 3	// 프로그램 종료
};

struct Element
{
	int value;
	Element* pNext;
};

struct Stack
{	
	int count;				// push = count++ , pop = count--
	Element* pTop;			// 스택은 제일 위에 있는 정보만 필요
};

void Initialize(Stack& stack);
void DeleteAll(Stack& stack);
void Push(Stack& stack, int value);
bool Pop(Stack& stack);		// bool의 목적 = 갯수의 제한이 있을 때 
							// push는 계속해도 제한없지만, 
							// pop는 갯수만큼만 가능하다
void Print(Stack& stack);

