#include <iostream>
#include <limits>
#include "creative_combat.h"
#include "LightsOut.h"
#include "hurdle.h"

using namespace std;

int main() {

    cout << "This is our project, Game eagle for CutieHack 2022." << endl;
    cout << endl;
    char choice = '#';
    while (choice != 'q') {
        cout << "-----GAMES-----" << endl;
        cout << endl;
        cout << "a - Creative Combat" << endl;
        cout << "b - Lights Out" << endl;
        cout << "c - Hurdle" << endl;
        cout << "q - quit" << endl;
        cout << endl;
        
        do {
            cout << "Enter the number of the game you want to play: ";
            cin >> choice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (choice == 'a' || choice == 'b' || choice == 'c' || choice == 'q') {
                break;
            }
            cout << "Invalid option." << endl;
        } while (choice != 'a' && choice != 'b' && choice != 'c' && choice != 'q');
        switch (choice) {
            case 'a':
            creative_combat();
            case 'b':
            LightsOut();
            case 'c':
            hurdle();
            case 'q':
            break;
        }
    }
    return 0;
}
