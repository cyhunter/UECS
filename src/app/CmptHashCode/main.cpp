#include <UTemplate/TypeID.h>

#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	if (argc != 2)
		return 1;

	std::cout << Ubpa::TypeID(argv[1]).GetValue() << std::endl;

	return 0;
}
