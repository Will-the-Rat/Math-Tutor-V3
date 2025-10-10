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
#include <cctype>

using namespace std;

int main() {
    enum MATH_TYPE { MT_ADD = 1, MT_SUB = 2,  //used for the switch case
                    MT_MUL = 3, MT_DIV = 4 }; //for the math symbols

    int leftNum = 0;      //left number for the math problem
    int rightNum = 0;     //right number for the math problem
    int correctAns = 0;   // correct answer used for
    int userAns = 0;
    int lvlNum = 1;
    int temp = 0;
    int mathType = 0;
    const int NUM_ATTEMPTS = 3;
    int numAnsCrt = 0;
    int numAnsIncr = 0;
    int levelRang = 10;
    char mathSymb = '?';
    string loop;
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


    do {  //starts the do loop that generates math problems


        //left number and right number generation using levelRang(e)
        leftNum = (rand() % levelRang) + 1;
        rightNum = (rand() % levelRang) + 1;
        mathType = (rand() % 4) + 1; //Generates numbers 1-4 to use in the switch


        switch (mathType) {
            // Code that displays the correct math problem and then finds the answer
            case MT_ADD: // Addition problem
                mathSymb = '+';
                correctAns = leftNum + rightNum;
                break;
            case MT_SUB: //Subtraction problem
                mathSymb = '-';
                if (leftNum < rightNum) { //if statement that makes certain that the left number is greater
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
                leftNum = leftNum * rightNum; //makes division without decimals
                correctAns = leftNum / rightNum;
                break;
            default: //ends the code if problems occur
                cout << "Invalid question type: " << mathType << endl;
                cout << "Program ended with an error -1" << endl;
                cout << "Please report this error to Cash Vollertsen or William Wilkey";
                return -1;
        }
        cout << "Level [" << lvlNum << "]" << endl;
        cout << leftNum << " " << mathSymb << " " << rightNum << endl;
        while (!(cin >> userAns)) {
            cin.clear();

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "invalid input!" << endl;
            cout << "Please enter a number";
        }

        for (int i = 0; userAns != correctAns && i < NUM_ATTEMPTS; i++) {
            cout << "That is incorrect you have " << NUM_ATTEMPTS - i << " attempts left: " << endl;
            cout << leftNum << " " << mathSymb << " " << rightNum << endl;
            cin >> userAns;
            if ((i + 1) == NUM_ATTEMPTS) {
                cout << "You are out of attempts." << endl;
                numAnsIncr++;
            }
        }

        if (userAns == correctAns) {
            numAnsCrt = numAnsCrt + 1;
            cout << "You got it correct!" << endl << endl;
        }

        if (numAnsCrt == 3) {
            levelRang += 10;
            lvlNum++;
            numAnsCrt = 0;
            numAnsIncr = 0;
            cout << "Leveling up! Continue? (y=yes | n=no): ";
            cin >> loop;
            if (loop == "y" && loop == "yes")

                cout << endl;
            cout << "The Levels will be a smidge harder." << endl << endl;
            cout << "The new range of numbers will be 1-" << levelRang << endl;

            if (loop != "y" && loop != "yes")
                break;
        }
        else if (numAnsIncr == 3 && levelRang != 10) {
            levelRang -= 10;
            numAnsCrt = 0;
            numAnsIncr = 0;

            cout << "Leveling down! Continue? (y=yes | n=no): ";
            cin >> loop;
            if (loop == "y" && loop == "yes")

                cout << endl;
            cout << "The Levels will be a smidge harder." << endl << endl;
            cout << "The new range of numbers will be 1-" << levelRang << endl;

            if (loop != "y" && loop != "yes") break;
        }




    }while (true) ;


    return 0;
}