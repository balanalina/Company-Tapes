#pragma once
#include"DynamicArray.h"
typedef Tape TElem;
class WatchList
{
private:
	DynamicArray<TElem> tapes;
	unsigned int current;

public:
	WatchList();

	//adds a tape to the watch list
	void add(const TElem& tape);
	//checks if the watch list is empty
	bool isEmpty();
	//starts the watch list
	void play();
	//returns the tape that is currently playing
	TElem getCurrentTape();
	//moves to the next element
	void next();
	//checks by title if the tape is or not in the watchlist
	bool find(std::string title);
	//get all the tapes
	DynamicArray<TElem> getTapes() const { return tapes; }

};

