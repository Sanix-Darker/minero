#include <iostream>
#include "sha256.h"

int main(int argc, char* argv[])
{
	std::cout << hash_sha256("Hello world") << std::endl;
    return 0;
}