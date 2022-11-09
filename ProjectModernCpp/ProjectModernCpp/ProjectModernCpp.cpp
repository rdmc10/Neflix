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
		// test
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				std::cout << "Test? ";
			}
			std::cout << "\n";
		}
		int a;
		std::cin >> a;
		if (a == 2)
			return;
	}
	void AltTest() {
		std::cout << "Test";
		std::string var = "Test";
		std::cout << var << " ";
		std::string tmp;
		tmp = var;
		std::cout << tmp;
	}

};

int main()
{
	std::cout << "Testing\n";
	std::cout << "Test2\n";


	return 0;
}
