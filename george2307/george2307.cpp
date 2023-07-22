// george2307.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include "Stack.cpp"

int EvaluateCommandStack(const std::string& option)
{
    if (option == "create")
    {
        // create stack
        Stack<int> intStack;
        Stack<char*> charPtrStack;

    }

    return 0;
}

void PrintOptionsStack()
{
    std::cout << "-- create" << std::endl;
    std::cout << "-- exit" << std::endl;
}

int main()
{
    std::cout << "Welcome to my REPL \n";

    //  main loop
    while (true)
    {
        PrintOptionsStack();
        std::cout << "Please Enter Option: ";

        std::string input;
        std::getline(std::cin, input);
        if (input == "exit")
        {
            break;
        }
        
        EvaluateCommandStack(input);
    }

    std::cout << "Thanks and goodbye!" << std::endl;
}




