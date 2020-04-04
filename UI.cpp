#include "UI.h"
#include<ctime>
#include<stdlib.h>

void UI::run()
{
	cout << "Enter the mode (A / B) :";
	std::string mode;
	getline(cin, mode);
	this->setMode(mode);
	int command;
	UI::init();
	while (true) {
		UI::printMenu();
		cout << "Enter the commmand:";
		cin >> command;
		if (command == 0)
			break;
		if (command == 4 && this->Mode.compare("A") == 0) {
			DynamicArray<TElem> d = this->service.getAllTapes();
			for (int i = 0; i < d.getSize(); i++)
				cout << d.getElem(i).toString();
		}
		if (command == 1 && this->Mode.compare("A") == 0) {
			std::string title = UI::readTitle();
			std::string section = UI::readSection();
			Date d = UI::readDate();
			std::string source = UI::readSource();
			if (this->err == false) //valid data,can be added to the repo
				this->service.addTapeToRepository(title, section, d, 0, source);
			else
				this->err = false; //invalid data,it is not added to the repo
		}
		if (command == 3 && this->Mode.compare("A") == 0) {
			std::string title;
			title = UI::readTitle();
			if (this->err == false)
				this->service.removeTapeFromRepository(title);
			else
				this->err = false;
		}
		if (command == 2 & this->Mode.compare("A") == 0) {
			std::string title;
			title = UI::readTitle();
			cout << "Enter the new values!" << endl;
			std::string newTitle = UI::readTitle();
			std::string section = UI::readSection();
			Date d = UI::readDate();
			std::string source = UI::readSource();
			if (this->err == false)
				this->service.updateTape(title, newTitle, section, d, 0, source);
			else
				this->err = false;
		}
		if (command == 1 && this->Mode.compare("B") == 0) {
			std::string userC = "";
			int i = 0;
			DynamicArray<TElem> da = this->service.getAllTapes();
			while (true) {
				if (i == da.getSize())
					i = 0;
				if (userC.compare("add") != 0) {
					cout << da.getElem(i).toString();
					da.getElem(i).play();
				}
				cout << "add (add the tape to your watchlist)" << endl;
				cout << "next (view the next tape)" << endl;
				cout << "exit" << endl;
				cin >> userC;
				if (userC.compare("next") == 0)
					i++;
				else
					if (userC.compare("add") == 0) {
						if (this->myWl.find(da.getElem(i).getTitle()) == false)
							this->myWl.add(da.getElem(i));
					}
					else
						break;
			}
		}
		if (command == 2 && this->Mode.compare("B") == 0) {
			DynamicArray<TElem> da = this->myWl.getTapes();
			for (int i = 0; i < da.getSize(); i++)
				cout << da.getElem(i).toString();
		}
		if (command == 3 && this->Mode.compare("B") == 0) {
			std::string section = UI::readSection();
			unsigned int access = UI::readAccess();
			if (this->err == false) {
				DynamicArray<TElem> da = this->service.getAllTapes();
				for (int i = 0; i < da.getSize(); i++)
					if (da.getElem(i).getSection().compare(section) == 0 && da.getElem(i).getAccess() < access)
						cout << da.getElem(i).toString();
			}

		}
		
	}
}

void UI::init()
{
	this->service.addTapeToRepository("Tape1", "Food Court", Date{ 2019,5,16 }, 3, "https://www.youtube.com/watch?v=U-ZA98K_jac");
	this->service.addTapeToRepository("Tape2", "East Side", Date{ 2018,4,20 }, 2, "https://www.youtube.com/watch?v=gpviAfHcVmw");
	this->service.addTapeToRepository("Tape3", "Parking Lot", Date{ 2017,10,10 }, 6, "https://www.youtube.com/watch?v=Ijr5tcSQHuE ");
	this->service.addTapeToRepository("Tape4", "Food Cout", Date{ 2018,4,20 }, 4, "https://www.youtube.com/watch?v=PcIhYJCgUWM");
	this->service.addTapeToRepository("Tape5", "Parking Lot", Date{ 2019,4,20 }, 7, "https://www.youtube.com/watch?v=-fNY7DTbyps");
	this->service.addTapeToRepository("Tape6", "East Side", Date{ 2020,5,20 }, 5, "https://www.youtube.com/watch?v=XJ-IpdLeJeU");
	this->service.addTapeToRepository("Tape7", "Parking Lot", Date{ 2019,6,11 }, 4, "https://www.youtube.com/watch?v=0AMQlQFJ0LY");
	this->service.addTapeToRepository("Tape8", "North Side", Date{ 2018,2,20 }, 3, "https://www.youtube.com/watch?v=MzlSVFtxb4c");
	this->service.addTapeToRepository("Tape9", "Food Court", Date{ 2019,1,15 }, 2, "https://www.youtube.com/watch?v=6cfu_6qWSu4&list=RD6cfu_6qWSu4&start_radio=1");
	this->service.addTapeToRepository("Tape10", "Parking Lot", Date{ 2020,6,17 }, 8, "https://www.youtube.com/watch?v=KpYaj-hsIkA&list=RD6cfu_6qWSu4&index=2");

}

void UI::printMenu()
{
	if (this->Mode.compare("A") == 0) {
		cout << "Menu:" << endl;
		cout << "0.Exit" << endl;
		cout << "1.Add Tape" << endl;
		cout << "2.Update Tape" << endl;
		cout << "3.Delete Tape" << endl;
		cout << "4.List Tapes" << endl;
	}
	else {
		cout << "Menu:" << endl;
		cout << "0.Exit" << endl;
		cout << "1.List Tapes" << endl;
		cout << "2.See Watch List" << endl;
		cout << "3.List Section Access Count" << endl;
	}

}

const std::string UI::readTitle() {
	cout << "Enter the title of the tape: ";
	std::string title;
	//getline(cin,title);
	//getline(cin, title);
	cin >> title;
	if (title.length() == 0) {
		cout << "Enter a valid title!" << endl;
		std::exit;
	}
	return title;
}

const std::string UI::readSection() {
	cout << "Enter the section presented in the tape: ";
	std::string section;
	getline(cin,section);
	getline(cin, section);
	//cin >> section;
	if (section.length() == 0) {
		cout << "Enter e valid section!" << endl;
		this->err = true;
		std::exit;
	}
	return section;
}

const Date UI::readDate() {
	unsigned int year, month, day;
	cout << "Enter the year of the tape's creation: ";
	cin >> year;
	if (year > 2020 || year < 2015) {
		cout << "Enter a valid year!" << endl;
		this->err = true;
		std::exit;
	}
	cout << "Enter the month:";
	cin >> month;
	if (month > 12 || month == 0) {
		cout << "Enter a valid month!" << endl;
		this->err = true;
		std::exit;
	}
	cout << "Enter the day:";
	cin >> day;
	if (day == 0 || day > 31) {
		cout << "Enter a valid day!" << endl;
		this->err = true;
		std::exit;
	}
	return Date(year, month, day);
}

const unsigned int UI::readAccess() {
	unsigned int access;
	cout << "Enter the access count: ";
	cin >> access;
	return access;
}

const std::string UI::readSource()
{
	std::string source;
	cout << "Enter the footage preview: ";
	cin >> source;
	if (source.length() == 0) {
		cout << "Enter a valid footage!" << endl;
		this->err = true;
		std::exit;
	}
	return source;
}
