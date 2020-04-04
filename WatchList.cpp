#include "WatchList.h"
typedef Tape TElem;

WatchList::WatchList()
{
	this->current = 0;
}

void WatchList::add(const Tape & tape)
{
	this->tapes.add(tape);
}

bool WatchList::isEmpty()
{
	if (this->tapes.getSize() == 0)
		return true;
	return false;
}

void WatchList::play()
{
	this->tapes.getElem(this->current).play();
}

TElem WatchList::getCurrentTape()
{
	return this->tapes.getElem(this->current);
}

void WatchList::next()
{
	this->current++;
	if (this->current == this->tapes.getSize()) 
		this->current = 0;
	
}

bool WatchList::find(std::string title) {
	for (int i = 0; i < this->tapes.getSize(); i++)
		if (this->tapes.getElem(i).getTitle().compare(title) == 0)
			return true;
	return false;
}