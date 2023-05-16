#include<iostream>
#include<memory>
#include<random>

class Game {
public:
    explicit Game(int maxNumber) : maxNumber(maxNumber)
    {
        // Initialize random number generator
        randomEngine.seed(std::random_device()());
        randomNumber = std::uniform_int_distribution<int>(1, maxNumber)(randomEngine);
    }


private:
};




int main() {
	std::cout << "Hello World" << std::endl;

	return 0;
}