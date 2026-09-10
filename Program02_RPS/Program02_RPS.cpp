// Roman A, CSC 222, Rock Paper Scissors Tournament - Testing Branch

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

const int ROCK = 1;
const int PAPER = 2;
const int SCISSORS = 3;
const int QUIT = 4;

const int PLAYER_WIN = 1;
const int COMPUTER_WIN = 2;
const int TIE = 3;

// function prototypes
void displayMenu();
int getPlayerChoice();
int getComputerChoice();
string choiceToString(int choice);
int determineRoundWinner(int playerChoice, int computerChoice);
void displayRoundResult(int playerChoice, int computerChoice, int result);
void updateScores(int result, int& playerScore, int& computerScore, int& ties);
void displayFinalResults(int roundsPlayed, int playerScore, int computerScore, int ties);

int main()
{
    //random seed
    srand(static_cast<unsigned int>(time(0))); 

    int playerChoice = 0;
    int computerChoice = 0;
    int result = 0;

    int roundsPlayed = 0;
    int playerScore = 0;
    int computerScore = 0;
    int ties = 0;

    cout << "===============================================" << endl;
    cout << "   Welcome to the Rock, Paper, Scissors Tournament!" << endl;
    cout << "===============================================" << endl;

    do
    {
        displayMenu();
        playerChoice = getPlayerChoice();

        if (playerChoice != QUIT)
        {
            computerChoice = getComputerChoice();
            result = determineRoundWinner(playerChoice, computerChoice);
            displayRoundResult(playerChoice, computerChoice, result);
            updateScores(result, playerScore, computerScore, ties);
            roundsPlayed++;
        }

    } while (playerChoice != QUIT);

    displayFinalResults(roundsPlayed, playerScore, computerScore, ties);

    return 0;
}

// display menu
void displayMenu()
{
    cout << "\n-----------------------------------" << endl;
    cout << "1. Rock" << endl;
    cout << "2. Paper" << endl;
    cout << "3. Scissors" << endl;
    cout << "4. Quit" << endl;
    cout << "-----------------------------------" << endl;
}

int getPlayerChoice()
{
    int choice = 0;

    cout << "Enter your choice (1-4): ";
    cin >> choice;

    while (cin.fail() || choice < ROCK || choice > QUIT)
    {
        // clear error flags and discard invalid input from the buffer
        cin.clear();
        cin.ignore(10000, '\n');

        cout << "Invalid choice. Please enter a number between 1 and 4: ";
        cin >> choice;
    }

    return choice;
}

int getComputerChoice()
{
    // rand() % 3 gives 0, 1, or 2; add 1 to match ROCK=1, PAPER=2, SCISSORS=3.
    return (rand() % 3) + 1;
}

string choiceToString(int choice)
{
    if (choice == ROCK)
        return "Rock";
    else if (choice == PAPER)
        return "Paper";
    else if (choice == SCISSORS)
        return "Scissors";
    else
        return "Unknown";
}

int determineRoundWinner(int playerChoice, int computerChoice)
{
    if (playerChoice == computerChoice)
        return TIE;

    if ((playerChoice == ROCK && computerChoice == SCISSORS) ||
        (playerChoice == PAPER && computerChoice == ROCK) ||
        (playerChoice == SCISSORS && computerChoice == PAPER))
    {
        return PLAYER_WIN;
    }

    return COMPUTER_WIN;
}

void displayRoundResult(int playerChoice, int computerChoice, int result)
{
    cout << "\nYou chose:      " << choiceToString(playerChoice) << endl;
    cout << "Computer chose: " << choiceToString(computerChoice) << endl;

    if (result == PLAYER_WIN)
        cout << ">> You win this round!" << endl;
    else if (result == COMPUTER_WIN)
        cout << ">> Computer wins this round!" << endl;
    else
        cout << ">> This round is a tie!" << endl;
}

void updateScores(int result, int& playerScore, int& computerScore, int& ties)
{
    if (result == PLAYER_WIN)
        playerScore++;
    else if (result == COMPUTER_WIN)
        computerScore++;
    else
        ties++;
}

void displayFinalResults(int roundsPlayed, int playerScore, int computerScore, int ties)
{
    cout << "\n===============================================" << endl;
    cout << "           FINAL TOURNAMENT RESULTS" << endl;
    cout << "===============================================" << endl;
    cout << "Rounds played:   " << roundsPlayed << endl;
    cout << "Player wins:     " << playerScore << endl;
    cout << "Computer wins:   " << computerScore << endl;
    cout << "Ties:            " << ties << endl;
    cout << "-----------------------------------------------" << endl;

    if (playerScore > computerScore)
        cout << "Congratulations! YOU WIN THE TOURNAMENT!" << endl;
    else if (computerScore > playerScore)
        cout << "The COMPUTER WINS THE TOURNAMENT. Better luck next time!" << endl;
    else
        cout << "The tournament ends in a DRAW!" << endl;

    cout << "===============================================" << endl;
    cout << "Thanks for playing!" << endl;
}