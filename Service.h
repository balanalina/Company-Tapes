#pragma once
#include"Repository.h"

class Service
{
private:
	Repository& repo;

public:
	//Service() { this->repo = repo{} }
	Service(Repository& r) : repo{ r } {}

	Repository& getRepo() { return this->repo; }
	DynamicArray<TElem> getAllTapes() const { return this->repo.getTapes(); }

	void addTapeToRepository(const std::string& title, const std::string& section, const Date& date, const unsigned int& access, const std::string& source);
	void removeTapeFromRepository(const std::string& title);
	void updateTape(const std::string& title, const std::string& newTitle, const std::string& newSection, const Date& data, const unsigned int& newAccess, const std::string& newSource);




};

