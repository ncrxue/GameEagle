#include <iostream>
#include "Hurdle.h"

using namespace std;
void hurdle() {
    cout << "Welcome to Hurdle!! This is a simple game, all you need to do is answer the question correctly with a 4 digit answer. If the question is correct you may move on to the next question. BUT, if the answer is wrong you will only have 3 more tries after that to get it right or you're OUT! In which case, you can just start a new game and try again :) Hint: Green = Correct; Yellow = Right number, wrong place; Red = Wrong\n" << endl;
    cout << "Press S to start the game:";
    string userin;
    cin >>  userin;
    cout << endl;

    cout << "When was the declaration of independence signed?";
    string userout;
    cin >> userout;
    string answer = "1776";
    bool userArr[userout.length()];
    bool answerArr[answer.length()];
    for (int i = 0; i < userout.length(); i++){

        if (userout[i] == answer[i]){
            userArr[i] = true;
            answerArr[i] = true;
        }
        else
        {
            for(int j = 0; j < answer.length(); j++)
            {
                if(userout[i] == answer[j] && userArr[i] == false) {
                    userArr[i] = true;
                    answerArr[j] = false;
                }


            }

        }

    }

    for(int j = 0; j < userout.length(); j++)
    {
        if(userArr[j] == true && answerArr[j] == true)
        {
            cout << "\x1B[32m" << userout[j]<< "\033[0m\t\t";
        }
        else if(userArr[j] == true && answerArr[j] == false)
        {
            cout << "\x1B[33m" << userout[j]<< "\033[0m\t\t";
        }
        else
        {
            cout << "\x1B[31m" << userout[j]<< "\033[0m\t\t";
        }

    }


    return;
}
