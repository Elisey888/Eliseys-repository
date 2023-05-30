#include "Header.h"

void init(ptrNODE& head)
{
	head = nullptr;
}

bool empty(ptrNODE head)
{
	return head == nullptr;
}

void addToHead(ptrNODE& head, TInfo elem)
{
	head = new NODE(elem, head);
}

void addAfter(ptrNODE& ptr, TInfo elem)
{
	if (ptr)
	{
		ptr->next = new NODE(elem, ptr->next);
	}
}

void printt(ptrNODE head, const char* message)
{
	std::cout << message << '\n';
	ptrNODE ptr = head;
	while (ptr)
	{
		std::cout << ptr->info << ' ';
		ptr = ptr->next;
	}
	std::cout << '\n';
}

void createByQueue(ptrNODE& head, std::ifstream& file)
{
	TInfo elem;
	init(head);
	file >> elem;
	addToHead(head, elem);
	ptrNODE tail = head;
	while (file >> elem)
	{
		addAfter(tail, elem);
		tail = tail->next;
	}
}

void delAfter(ptrNODE ptr)
{
	if (ptr && ptr->next)
	{
		ptrNODE p = ptr->next;
		ptr->next = ptr->next->next;
		delete p;
	}
}

void delFromHead(ptrNODE& head)
{
	if (head)
	{
		ptrNODE p = head;
		head = head->next;
		delete p;
	}
}

void task(ptrNODE& head)
{
	ptrNODE ptr = head;
	if (!empty(head))
	{
		while (ptr->next)
		{
			if (ptr->info == ptr->next->info)
				delAfter(ptr);
			else
				ptr = ptr->next;
		}
	}
}

void clear(NODE*& head)
{
	while (!empty(head))
		delFromHead(head);
}
