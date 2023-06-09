#include<iostream>
#include<memory>
#include<random>

class Game {
public:
    // Constructor that sets up a new game with a random number between 1 and maxNumber
    explicit Game(int maxNumber) : maxNumber(maxNumber)
    {
        // Initialize the random number generator
        randomEngine.seed(std::random_device()());
        // Generate the random number that the player needs to guess
        randomNumber = std::uniform_int_distribution<int>(1, maxNumber)(randomEngine);
    }

    // The main game loop where the player guesses the number
    void play()
    {
        int guess;
        int attempts = 0;
        int capacity = 5;                 // Initial capacity of the dynamic array
        int* guesses = new int[capacity]; // Dynamic array to store guesses

        // Infinite loop until the correct guess is made
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
    int maxNumber;  // Maximum number that can be guessed
    int randomNumber;  // Randomly generated number that player must guess
    std::default_random_engine randomEngine;  // Random number generator
};

int main() {

    int maxNumber;
    std::cout << "Welcome to Guess The Number game!" << std::endl;
    std::cout << "Enter the maximum number for the game: ";
    std::cin >> maxNumber;

    // Use smart pointer to manage the game object
    std::unique_ptr<Game> game = std::make_unique<Game>(maxNumber);
    game->play();
    return 0;
}
