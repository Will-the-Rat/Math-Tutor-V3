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
#include <limits>

using namespace std;

int main() {

    enum MATH_TYPE { MT_ADD = 1, MT_SUB = 2, MT_MUL = 3, MT_DIV= 4 };
    int leftNum = 0;
    int rightNum = 0;
    int correctAns = 0;
    int userAns = 0;
    int temp = 0;
    int mathType = 0;
    int NUM_ATTEMPTS = 3;
    int levelRang = 10;
    char mathSymb = 1;
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
            case MT_ADD: // Addition problem
                mathSymb = '+';
                correctAns = leftNum + rightNum;
                break;
            case MT_SUB: //Subtraction problem
                mathSymb = '-';
                if (leftNum < rightNum) {
                    temp = leftNum;
                    leftNum = rightNum;
                    rightNum = temp;
                }
                correctAns = leftNum - rightNum;
                break;
            case MT_MUL: // Multiplication problem
                mathSymb = '*';
                correctAns = leftNum * rightNum;
                break;
            case MT_DIV: // Division problem
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

        while (!(cin >> userAns)) {
            cin.clear();

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "invalid input!" << endl;
            cout << "Please enter a number";
        }

        while (userAns != correctAns && NUM_ATTEMPTS > 0) {
            NUM_ATTEMPTS = NUM_ATTEMPTS - 1;
            cout << "That is incorrect you have " << NUM_ATTEMPTS << " attempts left: " << endl;
            cout << leftNum << " " << mathSymb << " " << rightNum << endl;
            cin >> userAns;
        }



    return 0;
    }
