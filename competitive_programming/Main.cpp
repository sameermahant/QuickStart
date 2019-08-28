#include <cstdlib>
#include <fstream>
#include <iostream>

std::ifstream input("input.txt");
std::ofstream output("output.txt");

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv, char* envp[])
{
    for (int i{0}; envp[i] != nullptr; ++i) {
        std::cout << envp[i] << "\n";
    }

    int number1{0}, number2{0};
    input >> number1 >> number2;
    output << number1 + number2 << std::endl;

    return EXIT_SUCCESS;
}
