#include <iostream>

using namespace std;


void checkGreen(string &userout, string &answer, bool userArr[], bool answerArr[])
{
    for (int i = 0; i < userout.length(); i++){
        if (userout[i] == answer[i])
        {
            userArr[i] = true;
            answerArr[i] = true;
        }
    }
}

void checkYellow(string &userout, string &answer, bool userArr[], bool answerArr[])
{
    for(int k = 0; k < userout.length(); k++)
    {
        for(int j = 0; j < answer.length(); j++)
        {
            if(userout[k] == answer[j] && answerArr[j] == false) {
                userArr[k] = true;
                answerArr[j] = false;
            }
        }
    }
}

void printNumbers(string &userout, string &answer, bool userArr[], bool answerArr[])
{
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
}

void hurdle() {
    cout << "Welcome to Hurdle!! This is a simple game, all you need to do is answer the question correctly with a 4 digit answer.\nIf the question is correct you may move on to the next question. BUT, if the answer is wrong you will only have 3 more tries after that to get it right or you're OUT!\nIn which case, you can just start a new game and try again :) \nHint:\nGreen = Correct\nYellow = Right number, wrong place, or the number already exists\nRed = Wrong\n" << endl;
    cout << "Press S to start the game:";
    string userin = "";
    cin >>  userin;
    cout << endl;

    string questions[5] = {"What year was the Vietnam Veterans Memorial dedicated in Washington D.C?",
                          "In what year did child labor laws start in the United States?",
                          "What year did the French Revolution start?",
                          "What year did India gain Independence from Britain?",
                          "What year did the North American Free Trade Agreement go into effect?"};
    string answers[] = {"1982","1938", "1789","1947","1994"};
    bool repeated[5];
    string answer;
    int correctAns;
    srand(time(NULL));
    int index = 0;
    int i = 0;

    while(i < 5)
    {
        index = rand() % 5 + 0;

        if(repeated[index] != true)
        {
            cout << "Question " << (i + 1) << endl;
            repeated[index] = true;
            for(int j = 0; j < 3; j++)
            {

                string userout = "";

                bool userArr[userout.length()];
                bool answerArr[answer.length()];
                cout << questions[index] << endl;
                cin >> userout;
                answer = answers[index];

                if(userout == answer) {
                    cout << "CORRECT ANSWER!" << endl;
                    correctAns++;
                    j = 3;
                }
                else
                {
                    checkGreen(userout, answer, userArr,answerArr);
                    checkYellow(userout,answer,userArr,answerArr);
                    printNumbers(userout,answer,userArr,answerArr);
                    cout << "\nINCORRECT " << endl;
                    cout << "Attempts left: " << (3-j - 1) << endl;

                }





                if(3-j - 1 == 0)
                {
                    cout << "Answer: " << answer << endl;
                    cout << "GAME OVER " << endl;
                    i = 5;
                }
            }
            i++;
        }
    };

    if(correctAns == 5)
    {
        cout << "YOU WON THE GAME! " << endl;
    }

    return;
}
