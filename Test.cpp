#include "Test.h"
#include"Tape.h"
using namespace std;

Test::Test() {}

void Test::testAll()
{
	testTape();
	testDA();
	testRepository();
	testService();
	testWatchList();
}

void Test::testTape() {
	Tape tape{};
	getSetTitle(tape);
	getSetSection(tape);
	getSetDate(tape);
	getSetAccess(tape);
	getSetSource(tape);
}

void Test::testDA() {
	DynamicArray<TElem> da{ 1 };
	da.add(Tape{ "Tape1","FoodCourt",Date{2019,5,16},3,"https://www.youtube.com/watch?v=gpviAfHcVmw" });
	da.add(Tape{ "Tape2","FoodCourt",Date{2019,5,16},3,"https://www.youtube.com/watch?v=gpviAfHcVmw" });
	da.add(Tape{ "Tape3","FoodCourt",Date{2019,5,16},3,"https://www.youtube.com/watch?v=gpviAfHcVmw" });
	da.add(Tape{ "Tape4","FoodCourt",Date{2019,5,16},3,"https://www.youtube.com/watch?v=gpviAfHcVmw" });
	assert(da.getSize() == 4);
	da.remove(1);
	da.remove(1);
	assert(da.getSize() == 2);
	assert(da.getElem(1).getTitle().compare("Tape4") == 0);
	DynamicArray<TElem> da2{};
	da2 = da;
	assert(da2.getSize() == 2);
	assert(da2.getElem(1).getTitle().compare("Tape4") == 0);
}

void Test::testRepository() {
	Repository repo{};
	repo.addTape(Tape{ "Tape1","FoodCourt",Date{2019,5,16},3,"https://www.youtube.com/watch?v=gpviAfHcVmw" });
	repo.addTape(Tape{ "Tape2","FoodCourt",Date{2019,5,16},3,"https://www.youtube.com/watch?v=gpviAfHcVmw" });
	repo.addTape(Tape{ "Tape3","FoodCourt",Date{2019,5,16},3,"https://www.youtube.com/watch?v=gpviAfHcVmw" });
	repo.addTape(Tape{ "Tape4","FoodCourt",Date{2019,5,16},3,"https://www.youtube.com/watch?v=gpviAfHcVmw" });
	assert(repo.getTapes().getSize() == 4);
	repo.remove(1);
	repo.remove(1);
	assert(repo.getTapes().getSize() == 2);
	assert(repo.findByTitle("Tape4").getTitle().compare("Tape4") == 0);
	assert(repo.findPosByTitle("Tape4") == 1);
}

void Test::testService() {
	Repository r{};
	Service service{ r };
	addService_Successful(service);
	addService_Duplicat_NotAdded(service);
	removeService_Succssesful(service);
	removeService_NotInRepo(service);
	updateService_Successful(service);
	updateService_NotInRepo(service);
}

void Test::testWatchList()
{
	WatchList wl{};
	assert(wl.isEmpty() == true);
	wl.add(Tape{ "Tape1","FoodCourt",Date{2019,5,16},3,"https://www.youtube.com/watch?v=gpviAfHcVmw" });
	wl.add(Tape{ "Tape2","FoodCourt",Date{2019,5,16},3,"https://www.youtube.com/watch?v=gpviAfHcVmw" });
	wl.add(Tape{ "Tape3","FoodCourt",Date{2019,5,16},3,"https://www.youtube.com/watch?v=gpviAfHcVmw" });
	wl.add(Tape{ "Tape4","FoodCourt",Date{2019,5,16},3,"https://www.youtube.com/watch?v=gpviAfHcVmw" });
	assert(wl.isEmpty() == false);
	assert(wl.getCurrentTape().getTitle().compare("Tape1") == 0);
	wl.next();
	assert(wl.getCurrentTape().getTitle().compare("Tape1") != 0);
	wl.next();
	wl.next();
	wl.next();
	assert(wl.getCurrentTape().getTitle().compare("Tape1") == 0);
}

void Test::updateService_NotInRepo(Service& s) {
	s.updateTape("Tape23541212", "", "", Date{}, 0, "");
	assert(s.getAllTapes().getElem(0).getAccess() != 0);
}

void Test::updateService_Successful(Service& s) {
	s.updateTape("Tape2", "Tape1", "Food", Date{ 2020,5,20 }, 20, "link");
	assert(s.getAllTapes().getElem(0).getAccess() == 20);
	assert(s.getAllTapes().getElem(0).getCreationDate().getYear() == 2020);
}

void Test::removeService_NotInRepo(Service& s) {
	s.removeTapeFromRepository("Taoe345");
	assert(s.getAllTapes().getSize() == 1);
}

void Test::removeService_Succssesful(Service& s) {
	s.removeTapeFromRepository("Tape1");
	assert(s.getRepo().getTapes().getSize() == 1);
}

void Test::addService_Successful(Service& s) {
	s.addTapeToRepository("Tape1", "FoodCourt", Date{ 2019,5,16 }, 3, "https://www.youtube.com/watch?v=gpviAfHcVmw");
	s.addTapeToRepository("Tape2", "FoodCourt", Date{ 2019,5,16 }, 3, "https://www.youtube.com/watch?v=gpviAfHcVmw");
	//s.addTapeToRepository("Tape4", "FoodCourt", Date{ 2019,5,16 }, 3, "https://www.youtube.com/watch?v=gpviAfHcVmw");
	assert(s.getAllTapes().getSize() == 2);
}

void Test::addService_Duplicat_NotAdded(Service& s) {
	s.addTapeToRepository("Tape1", "FoodCourt", Date{ 2019,5,16 }, 3, "https://www.youtube.com/watch?v=gpviAfHcVmw");
	assert(s.getAllTapes().getSize() == 2);
}

void Test::getSetTitle(Tape& t) {
	t.setTitle("Tape12");
	assert(t.getTitle().compare("Tape12") == 0);
}

void Test::getSetSection(Tape& t) {
	t.setSection("Food");
	assert(t.getSection().compare("Food") == 0);
}

void Test::getSetDate(Tape& t) {
	t.setDate(Date{ 2019,5,6 });
	assert(t.getCreationDate().getDay() == 6);
	assert(t.getCreationDate().getMonth() == 5);
	assert(t.getCreationDate().getYear() == 2019);
}

void Test::getSetAccess(Tape& t) {
	t.setAccess(13);
	assert(t.getAccess() == 13);
}

void Test::getSetSource(Tape& t) {
	t.setSource("https://www.youtube.com/watch?v=gpviAfHcVmw");
	assert(t.getSource().compare("https://www.youtube.com/watch?v=gpviAfHcVmw") == 0);
}