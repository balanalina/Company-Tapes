#include "Repository.h"

void Repository::addTape(TElem newElem)
{
	this->tapes.add(newElem);
}

void Repository::remove(int pos)
{
	this->tapes.remove(pos);
}

int Repository::findPosByTitle(const std::string & title)
{
	for (int i = 0; i < this->tapes.getSize(); i++)
		if (this->tapes.getElem(i).getTitle().compare(title) == 0)
			return i;

	return -1;
}

void Repository::updateTape(const unsigned int& pos, const std::string & newTitle, const std::string & newSection, const Date & data, const unsigned int & newAccess, const std::string & newSource)
{
	this->tapes.updateTape(pos, newTitle, newSection, data, newAccess, newSource);
}

TElem Repository::findByTitle(const std::string& title)
{
	for (int i = 0; i < this->tapes.getSize(); i++)
		if (this->tapes.getElem(i).getTitle().compare(title) == 0)
			return this->tapes.getElem(i);
	return Tape{};
}
