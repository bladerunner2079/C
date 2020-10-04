#include <iostream>
#include <ctime>

void PrintIntrudction(int Difficulty)
{
    std::cout << "\nYou are secret agent breaking into a level " << Difficulty; 
    std::cout << " secure server room \nEnter the correct code to continue\n";
}


bool PlayGame(int Difficulty)
{
    PrintIntrudction(Difficulty);

    const int CodeA = rand() % Difficulty + Difficulty; // Define static variable
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << std::endl;
    std::cout << "There are 3 numbers in code" << std::endl;
    std::cout << "The code adds up to: " << CodeSum << std::endl;
    std::cout << "The code multipy to give: " << CodeProduct << std::endl;

    int GuessA, GuessB, GuessC; // Stored guess data
    std::cin >> GuessA >> GuessB >> GuessC;
 
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC; 


    if (GuessSum==CodeSum && GuessProduct==CodeProduct)
    {
        std::cout << "\nYou Win!";
        return true;
    }
    else
    {
        std::cout << "\nYou Suck!";
        return false;
    }
}

int main()
{
    srand(time(NULL)); // Create a new random sequence base don time of day

    int LevelDifficulty = 1;
    int const MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty) // Loop game until all levels are cleared
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // Clear any errors
        std::cin.ignore(); // Dsicard the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty; // Increase level difficulty
        }
        
    }
    std::cout << "\n*** Great work agent! You got all of the files.***\n";
    return 0;
}



