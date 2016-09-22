#include "list.h"

List::List()
{
	tail = new Item;
	head = new Item;
	tail = nullptr;
	head->next = nullptr;
}

List::~List()
{
	delete tail;
	delete head;

}

List::Item::Item (void (*f)(), uint16_t p)
{
	period_ms = p;
	func = f;
	next = new Item;
}

List::Item::Item ()
{
	next = new Item;
}

List::Item::~Item ()
{
	delete next;
}

void List::addToHead (void (*f)(), uint16_t p_)
{
	Item * i = new Item (f, p_);
	i->next = head->next;
	head->next = i;
}

void List::addToTail (void (*f)(), uint16_t p_)
{
	Item * i = new Item (f, p_);
	i->next = head->next;
	head->next = i;
}


