/*
 * Program:       Math Tutor V2
 * Programmer(s): William Wilkey, Cash Vollertsen
 * Date:          2025.10.05
 * Github:        https://github.com/emkin07/MathTutorV1.git
 * Description:   An easy math tutor. It has math jokes,
 *                asks for the user's name, and to answer a simple
 *                math question and tells the user if they answered
 *                the question correctly.
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;

int main() {

    int leftNum = 0;
    int rightNum = 0;
    int correctAns = 0;
    int userAns = 0;
    int temp = 0;
    int mathType = 0;
    int NUM_ATTEMPTS = 3;
    int levelRang = 0;
    char mathSymb = '?';
    string name;
    srand(time(nullptr));

    cout << "********************************************************************" << endl;
    cout << "                                  ___                               " << endl;
    cout << "                   |V| _ _|_|_     |    _|_ _  __                   " << endl;
    cout << "                   | |(_| |_| |    | |_| |_(_) |                    " << endl;
    cout << "********************************************************************" << endl;
    cout << "*                 Welcome to the Simple Math Tutor                 *" << endl;
    cout << "********************************************************************" << endl;
    cout << endl;

    cout << "Math Jokes:" << endl;
    cout << "   * Why is six afraid of seven? Because seven eight nine!" << endl;
    cout << "   * What did zero say to eight? 'Nice belt!'" << endl;
    cout << "   * Why was the math book so sad? Because it had too many problems!" << endl;
    cout << endl;
    cout << "********************************************************************" << endl;

    cout << endl;
    cout << "What is your name? ";
    getline(cin, name); // gets their entire name
    cout << "Welcome, " << name << ", to the Simple Math Tutor!" << endl;

    // determines number and forces the left number to be greater
    leftNum = (rand() % 10) + 1;
    rightNum = (rand() % 10) + 1;
    mathType = (rand() % 4) + 1;

    switch (mathType) { // Code that displays the correct math problem and then finds the answer
        case 1: // Addition problem
            mathSymb = '+';
            correctAns = leftNum + rightNum;
            break;
        case 2: //Subtraction problem
            mathSymb = '-';
            if (leftNum < rightNum) {
                temp = leftNum;
                leftNum = rightNum;
                rightNum = temp;
            }
            correctAns = leftNum - rightNum;
            break;
        case 3: // Multiplication problem
            mathSymb = '*';
            correctAns = leftNum * rightNum;
            break;
        case 4: // Division problem
            mathSymb = '/';
            leftNum = leftNum * rightNum;
            correctAns = leftNum / rightNum;
            break;
        default: // ends the code if problems occur
            cout << "Invalid question type: " << mathType << endl;
            cout << "Program ended with an error -1" << endl;
            cout << "Please report this error to Emma Kinney or William Wilkey";
            return -1;
    }
    cout << leftNum << " " << mathSymb << " " << rightNum << endl;

    cin >> userAns;
    while (userAns != correctAns && NUM_ATTEMPTS > 0) {
        NUM_ATTEMPTS = NUM_ATTEMPTS - 1;
        cout << "That is incorrect you have " << NUM_ATTEMPTS << " attempts left: " << endl;
        cout << leftNum << " " << mathSymb << " " << rightNum << endl;
        cin >> userAns;
    }

    return 0;
    }
