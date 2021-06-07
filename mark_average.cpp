// Copyright (c) 2021 Caylee Annett All rights reserved
//
// Created by Caylee Annett
// Created on June 2021
// This program calculates the average of marks in a list

#include <iostream>
#include <iomanip>
#include <list>

float CalculateAverage(std::list<int> listOfMarks) {
    // This function calculates the average

    float sumOfNumbers = 0;
    float average;
    float roundedAverage;

    for (int mark : listOfMarks) {
        sumOfNumbers = sumOfNumbers + mark;
    }
    average = sumOfNumbers / listOfMarks.size();
    roundedAverage = average * 10;
    roundedAverage = roundedAverage + 0.5;
    roundedAverage = static_cast<int>(roundedAverage);
    roundedAverage = roundedAverage / 10;

    return roundedAverage;
}

main() {
    // This function gets the marks
    std::string markInputString;
    int markInputInteger;
    float answer;
    std::list<int> markList;

    // Input & Process
    std::cout << "This program calculates the average of your marks."
        << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Enter one mark at a time and -1 to end." << std::endl;
    std::cout << "Enter a mark (%): ";
    std::cin >> markInputString;
    while (true) {
        try {
            markInputInteger = std::stoi(markInputString);

            if (markInputInteger == -1) {
                break;
            } else if (markInputInteger < 0 || markInputInteger > 100) {
                std::cout << "Invalid input. Enter a mark (%): ";
                std::cin >> markInputString;
            } else {
                std::cout << "Enter a mark (%): ";
                std::cin >> markInputString;
                markList.push_back(markInputInteger);
            }
        } catch (std::invalid_argument) {
            std::cout << "Invalid input. Enter a mark (%): ";
                std::cin >> markInputString;
        }
    }

    // Call functions
    answer = CalculateAverage(markList);

    // Output
    std::cout << "" << std::endl;
    std::cout << "The average is: " << answer << "%" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Done." << std::endl;
}
