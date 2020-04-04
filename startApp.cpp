#include<crtdbg.h>
#include"Test.h"
#include"UI.h"
using namespace std;

int main() {
	{
		Test t{};
		t.testAll();
		Repository r{};
		Service s{ r };
		UI u{ s };
		u.run();
	}
	_CrtDumpMemoryLeaks();
	return 0;
}