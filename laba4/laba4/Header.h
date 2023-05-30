#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>



using TInfo = std::string;

struct NODE
{
	TInfo info;
	NODE* next;
	NODE(TInfo info, NODE* ptr = nullptr) :
		info(info), next(ptr) {}
	~NODE()
	{
		next = nullptr;
	}
};

using ptrNODE = NODE*;
void init(ptrNODE& head);
bool empty(ptrNODE head);
void addToHead(ptrNODE& head, TInfo elem);
void addAfter(ptrNODE& ptr, TInfo elem);
void printt(ptrNODE head, const char* message);
void createByQueue(ptrNODE& head, std::ifstream& file);
void delAfter(ptrNODE ptr);
void delFromHead(ptrNODE& head);
void task(ptrNODE& head);
void clear(NODE*& head);