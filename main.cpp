/*
 * Program:       Math Tutor V3
 * Programmer(s): William Wilkey, Cash Vollertsen
 * Date:          2025.10.05
 * GitHub:        https://github.com/Will-the-Rat/Math-Tutor-V3
 * Description:   This program teches math to students. It first
 *                gives them an intro, has them give a name, and then
 *                asks math question with various levels and ranges
 *                and tells them if they answered the question correctly.
 *                It has loops that allow a person to infinitely play
 *                the math tutor.
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
    int lvlNum = 1;       // what level they are currently on
    int temp = 0;
    int mathType = 0;
    const int NUM_ATTEMPTS = 3;
    int numAnsCrt = 0;    // answers they have gotten corret
    int numAnsIncr = 0;   // answers they have gotten wrong
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


        switch (mathType) { // start of switch
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
                } // end of if statement
                correctAns = leftNum - rightNum;
                break;
            case MT_MUL: // Multiplication problem
                mathSymb = '*';
                correctAns = leftNum * rightNum;
                break;
            case MT_DIV: // Division problem
                mathSymb = '/';
                leftNum = leftNum * rightNum; //makes division without decimals possible
                correctAns = leftNum / rightNum;
                break;
            default: //ends the code if problems occur
                cout << "Invalid question type: " << mathType << endl;
                cout << "Program ended with an error -1" << endl;
                cout << "Please report this error to Cash Vollertsen or William Wilkey";
                return -1;
        } // end of switch statement

        cout << "[Level " << lvlNum << "]" << endl; // level number is a seperate value moved with range
        cout << leftNum << " " << mathSymb << " " << rightNum << endl;
        while (!(cin >> userAns)) { // cin has to be a number otherwise it will loop
            cin.clear();

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "invalid input!" << endl;
            cout << "Please enter a number";
        } // end of cin loop while statement

        // this counts the number of times they missed one problem
        for (int i = 0; userAns != correctAns && i < NUM_ATTEMPTS; i++) { // start of incorrect answer for logic
            cout << "That is incorrect you have " << NUM_ATTEMPTS - i << " attempts left: " << endl;
            cout << leftNum << " " << mathSymb << " " << rightNum << endl;
            cin >> userAns;
            if ((i + 1) == NUM_ATTEMPTS) { // if they run out of attempts
                cout << "You are out of attempts." << endl;
                numAnsIncr++; // increments the total number of Answers Incorrect
            } // end of if statement
        } // end of incorrect answer for logic

        if (userAns == correctAns) {    // if they got it correct
            numAnsCrt++;                // increment the total number correct
            cout << "You got it correct!" << endl << endl;
        } // end of if they got it correct

        if (numAnsCrt == 3) {   // leveling up logic for if they get three right
            levelRang += 10;    // adds to the level range
            lvlNum++;           // increases the level number
            numAnsCrt = 0;      // clears total number correct
            numAnsIncr = 0;     // clears total number incorrect
            cout << "Leveling up!" << "The Levels will be a smidge harder." << endl;
            cout << "The new range of numbers is 1-" << levelRang << endl <<endl;

        }
        if (numAnsIncr == 3 && levelRang != 10) { // leveling down logic
            levelRang -= 10;
            numAnsCrt = 0;
            numAnsIncr = 0;
            lvlNum--;

            cout << "Leveling down! The levels will be a little easier." << endl;
            cout << "The new range of numbers is 1-" << levelRang << endl;
        }
        while (true) {

            cout << "Do you want to continue (y=yes | n=no)? ";
            getline(cin, loop);

            // to lower case the user's input
            for (int i = 0; i < loop.size(); i++) {
                loop.at(i) = tolower(loop.at(i));
            }
            if (loop == "yes" || loop == "y" || loop == "no" || loop == "n") {
                break;
            } else {
                cout << "Invalid input, please try again..." << endl;
                cout << endl;
            } // end of if (y, yes, n , no)
        }





    }while (loop == "y" || loop == "yes") ;


    return 0;
}