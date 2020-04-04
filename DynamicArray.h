#pragma once
#include"Tape.h"
#include<string>

using namespace std;

template<typename A>
class DynamicArray
{
private:
	A* elems;
	unsigned int size;
	unsigned int capacity;

	//resize the dynamic vector by doubling its capacity
	void resize();

public:
	//default construcot
	DynamicArray(int capacity = 10);

	//copy constructor and destroyer
	DynamicArray(const DynamicArray<A>& da);
	~DynamicArray();

	//overloading the assignment operator for the dynamic array
	DynamicArray& operator=(const DynamicArray& da);

	void add(const A& newElem);

	void remove(int position);

	unsigned int getSize();

	//returns the element on position position
	A getElem(unsigned int position);

	void updateTape(const unsigned int& pos, const std::string& newTitle, const std::string& newSection, const Date& data, const unsigned int& newAccess, const std::string& newSource);
};

template<typename A>

void DynamicArray<A>::resize()
{
	this->capacity *= 2;
	A* newElems = new A[this->capacity];

	for (int i = 0; i < this->size; i++)
		newElems[i] = this->elems[i];

	delete[] this->elems;
	this->elems = newElems;
}
template<typename A>
DynamicArray<A>::DynamicArray(int capacity)
{
	this->size = 0;
	this->capacity = capacity;
	this->elems = new A[capacity];
}
template<typename A>
DynamicArray<A>::DynamicArray(const DynamicArray<A> & da)
{
	this->size = da.size;
	this->capacity = da.capacity;
	this->elems = new A[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = da.elems[i];
}
template<typename A>
DynamicArray<A>::~DynamicArray()
{
	delete[] this->elems;
}
template<typename A>
DynamicArray<A>& DynamicArray<A>::operator=(const DynamicArray & da)
{
	if (this == &da)
		return *this;
	this->size = da.size;
	this->capacity = da.capacity;

	delete[] this->elems;
	this->elems = new A[this->capacity];
	for (int i = 0; i < da.size; i++)
		this->elems[i] = da.elems[i];

	return *this;
}
template<typename A>
void DynamicArray<A>::add(const A& newElem)
{
	if (this->size == this->capacity)
		this->resize();
	this->elems[this->size] = newElem;
	this->size++;
}
template<typename A>
void DynamicArray<A>::remove(int position)
{
	for (int i = position; i < this->size - 1; i++)
		this->elems[i] = this->elems[i + 1];

	this->size--;
}
template<typename A>
unsigned int DynamicArray<A>::getSize()
{
	return this->size;
}
template<typename A>
A DynamicArray<A>::getElem(unsigned int position)
{
	return this->elems[position];
}
template<typename A>
void DynamicArray<A>::updateTape(const unsigned int & pos, const std::string & newTitle, const std::string & newSection, const Date & data, const unsigned int & newAccess, const std::string & newSource)
{
	this->elems[pos].setTitle(newTitle);
	this->elems[pos].setSection(newSection);
	this->elems[pos].setDate(data);
	this->elems[pos].setAccess(newAccess);
	this->elems[pos].setSource(newSource);
}




