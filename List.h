#pragma once

#include <iostream>
#include <Windows.h>

using std::cin;
using std::cout;

struct Queue
{
	bool data;
	Queue* next;
};

using pQueue = Queue*;

void initQueue(pQueue& head, pQueue& tail);
bool popQueue(pQueue& tail, pQueue& head);
void PushQueue(pQueue& tail, bool x);
void Task(pQueue& tail, pQueue& head, int count_cards);
void First(pQueue& tail, pQueue& head, bool x);