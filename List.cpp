#include "List.h"

void initQueue(pQueue& tail, pQueue& head)
{
	head = NULL;
	tail = NULL;
}

void PushQueue(pQueue& tail, bool x)
{
	pQueue q = new Queue;
	q->data = x;
	q->next = tail;
	tail = q;
}

bool popQueue(pQueue& tail, pQueue& head)
{
	bool x = head->data;
	if (head == tail)
	{
		delete tail;
		initQueue(tail, head);
	}
	else
	{
		pQueue temp = tail;
		while (temp->next != head) temp = temp->next;

		head = temp;
		temp = head->next;
		head->next = NULL;
		delete temp;
	}
	return x;
}

void First(pQueue& tail, pQueue& head, bool x)
{
	pQueue q = new Queue;
	q->data = x;
	q->next = NULL;
	tail = q;
	head = q;
}

void Task(pQueue& tail, pQueue& head, int count_cards)
{
	bool t = count_cards % 2;
	First(tail, head, t);
	t = !t;
	for (int i(0); i < count_cards - 2; ++i)
	{
		PushQueue(tail, t);
		PushQueue(tail, popQueue(tail, head));
		t = !t;
	}
	PushQueue(tail, 1);
	for (int j(0); j < count_cards; ++j) cout << popQueue(tail, head);
}

// 1 - белый, 0 - черный