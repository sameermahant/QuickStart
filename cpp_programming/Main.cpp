#include <cstdlib>
#include <iostream>

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv, char* envp[])
{
    for (int i{0}; envp[i] != nullptr; ++i) {
        std::cout << envp[i] << "\n";
    }

    [](){ std::cout << "Hello modern C++\n"; }();

    return EXIT_SUCCESS;
}
