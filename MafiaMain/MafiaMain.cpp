// MafiaMain.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <random>

#include <thread>
#include <chrono>
#include <mutex>

#include"mafia.h"


// Global variables
string userInput;
mutex userInputMutex;

// Function to be run in the separate thread
void inputThreadFunction() {
    while (true) {
        // Sleep for 500 milliseconds
        this_thread::sleep_for(chrono::milliseconds(100));

        // Check for console input
        string input;
        getline(cin, input);

        // Lock the mutex before updating the shared variable
        lock_guard<mutex> lock(userInputMutex);
        userInput = input;
    }
}

int main()
{
    mafia MafiaObj(0);
    MafiaObj.EnterUserSeed();

    // Create a thread to handle input
    thread inputThread(inputThreadFunction);

    // Main thread
    while (true) {
        // Lock the mutex before accessing the shared variable
        lock_guard<mutex> lock(userInputMutex);

        // Check if there is new input
        if (!userInput.empty()) {
            // Display the input
            cout << "User input: " << userInput << endl;

            // Check for specific user input
            if (userInput == "shuffle")
            {
                MafiaObj.ShuffleDeck();
            }
            else if (userInput == "sudo")
            {
                MafiaObj.SudoDisplay();
            }
            else if (userInput == "clear")
            {
                MafiaObj.ClearConsole();
            }
            else {
                MafiaObj.ShowRole(userInput);
            }

            // Clear the stored input
            userInput.clear();
        }

        this_thread::sleep_for(chrono::milliseconds(100));
    }

    inputThread.join();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
