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



    void play()
    {
        int guess;
        int attempts = 0;
        int capacity = 5;                 // Initial capacity of the dynamic array
        int* guesses = new int[capacity]; // Dynamic array to store guesses

        while (true)
        {
            std::cout << "Enter your guess (1-" << maxNumber << "): ";
            std::cin >> guess;
            attempts++;

            if (attempts > capacity)
            {
                // Resize the dynamic array if the capacity is exceeded
                int* newGuesses = new int[capacity * 2];
                for (int i = 0; i < capacity; i++)
                {
                    newGuesses[i] = guesses[i];
                }
                delete[] guesses;
                guesses = newGuesses;
                capacity *= 2;
            }

            guesses[attempts - 1] = guess; // Store the guess in the dynamic array

            if (guess == randomNumber)
            {
                std::cout << "Congratulations! You guessed the correct number in " << attempts << " attempts." << std::endl;
                break;
            }
            else if (guess < randomNumber)
            {
                std::cout << "Too low! Try again." << std::endl;
            }
            else
            {
                std::cout << "Too high! Try again." << std::endl;
            }
        }

        // Print the guessed numbers
        std::cout << "Your guesses: ";
        for (int i = 0; i < attempts; i++)
        {
            std::cout << guesses[i] << " ";
        }
        std::cout << std::endl;

        delete[] guesses; // Deallocate the dynamic array
    }


private:
    int maxNumber;
    int randomNumber;
    std::default_random_engine randomEngine;
};





int main() {
	std::cout << "Hello World" << std::endl;

	return 0;
}