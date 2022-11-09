#include "ProjectModernCpp.h"

class Test {

private:
	int test1;
	int test2;
	double test3;

public:
	Test() {
		test1 = 1;
		test2 = 2;
		test3 = 3.3;
	}
	void test() {
		std::cout << test1;
		std::cout << test2;
		std::cout << test3;
	}

};

int main()
{
	std::cout << "Testing\n";
	std::cout << "Test2\n";


	return 0;
}
