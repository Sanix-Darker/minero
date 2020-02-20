#include "./include/sha256/sha256.h"
#include "./include/minero.h"

void hello() {

    std::string message = "hello world";
    std::cout << hash_sha256(message) << std::endl;
}

int main() {
    hello();

    return 0;
}
