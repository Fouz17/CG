#include <iostream>
#include <random>

int main() {
    // Create a random number generator engine
    std::random_device rd;  // Seed the random number generator
    std::mt19937 gen(rd()); // Mersenne Twister pseudo-random generator

    // Define a distribution (e.g., uniform distribution between 1 and 100)
    std::uniform_int_distribution<int> distribution(1, 100);

    // Generate random numbers
    for (int i = 0; i < 5; i++) {
        int random_number = distribution(gen);
        std::cout << "Random Number " << i + 1 << ": " << random_number << std::endl;
    }

    return 0;
}
