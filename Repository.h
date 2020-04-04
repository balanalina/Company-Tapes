#pragma once
#include"DynamicArray.h"
#include<string>

typedef Tape TElem;
class Repository
{
private:
	DynamicArray<TElem> tapes;

public:
	//constructor
	Repository() {}
	//adds a new tape to the repository
	void addTape(TElem newElem);
	//removes the element from position pos from the repository
	void remove(int pos);
	//searches the tape with the gien title
	//returns an emty tape if none of the existing tapes match
	Tape findByTitle(const std::string& title);
	//returns the position on whitch the tape with the given title is
	//returns -1 if there is no such tape
	int findPosByTitle(const std::string& title);
	//returns the dynamic vector containing all tapes
	DynamicArray<TElem> getTapes() const { return tapes; }
	void updateTape(const unsigned int& pos, const std::string& newTitle, const std::string& newSection, const Date& data, const unsigned int& newAccess, const std::string& newSource);




};

