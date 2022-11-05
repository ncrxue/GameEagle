
#include <iostream>
#include <string>
#include "creative_combat.h"

using namespace std;

void combat(string n,int a1, int a2, int b, int health);

void creative_combat()
{
    
    string name;
    string atk1 = "Strike";
    string atk2 = "Heavy Slash";
    int atkval1 = 3;
    int atkval2 = 10;
    int upPts = 10;
    int hp = 25;
    int blockval = 5;
    int healval = 3;
    bool creating = true;
    int selection;
    int stamina = 15;
    
    cout << "Please name you're character: "; 
    cin >> name; // declares name
    cout << endl << "Welcome to Creative Combat, you have " << upPts << " points to upgrade your character with" << endl;
    while (creating)
    {
    cout << "Enter 1 to upgrade attacks, 2 to upgrade skills, 3 to upgrade HP, and 4 to view stats, 5 to complete character "; //base option that loops
    cin >> selection;
    
    if (selection == 1) // upgrade attacks
    {
        cout << "Enter 1 to upgrade Strike, Enter 2 to upgrade Heavyslash, Enter 3 to backout: ";
        cin >> selection;
        cout << endl;
        if (selection == 1) //upgrade strike
        {
            cout << "You have " << upPts << " to spend." << endl;
            cout << "Strike has an ATK of " << atkval1 << " with a stamina cost of 2, enter the amount of pts you want to upgrade Strike: ";
            cin >> selection;
            selection = abs(selection);
        while (selection > upPts)
        {
            cout << "Please enter a valid number of pts";
            cin >> selection;
            selection = abs(selection);
        }
        atkval1 += selection;
        upPts -= selection;
        cout << "You're Strike now has " << atkval1 << " ATK, you now have " << upPts << " upgrade points remaining" << endl;
        }
        if (selection == 2) //upgrade heavyslash
        {
            cout << "You have " << upPts << " to spend." << endl;
            cout << "Heavyslash has an ATK of " << atkval2 << " with a stamina cost of 5, enter the amount of pts you want to upgrade Heavyslash: ";
            cin >> selection;
            selection = abs(selection);
        while (selection > upPts && (atkval2 - selection) > 0)
        {
            cout << "Please enter a valid number of pts";
            cin >> selection;
            selection = abs(selection);
        }
        atkval2 += selection;
        upPts -= selection;
        cout << "Your Heavyslash has " << atkval2 << " ATK, you now have " << upPts << " upgrade points remaining" << endl;
        }
    }
    else if (selection == 2) //upgrade skills
    {
        cout << "Enter 1 to upgrade Block, Enter 2 to upgrade Heal, Enter 3 to backout: ";
        cin >> selection;
        
        if (selection == 1) //upgrade block
        {
            cout << "You have " << upPts << " to spend." << endl;
            cout << "Your Block creates a temporary barrier of " << blockval << " costing zero stamina" << endl<< "but disappears after the turn, enter the amount of points you want to upgrade Block: ";
            cin >> selection;
            selection = abs(selection);
        while (selection > upPts && (blockval - selection) > 0)
        {
            
            cout << "Please enter a valid number of points";
            cin >> selection;
            selection = abs(selection);
        }
        blockval += selection;
        upPts -= selection;
        cout << "Your Block has " << blockval << " block, you now have " << upPts << " upgrade points remaining" << endl;
        }
        if (selection == 2) //upgrade heal
        {
            cout << "You have " << upPts << " to spend." << endl;
            cout << "Your Heal restores " << healval << " costing 12 stamina" << endl;
            cin >> selection;
            selection = abs(selection);
        while (selection > upPts && (healval - selection) > 0)
        {
            cout << "Please enter a valid number of points";
            cin >> selection;
            selection = abs(selection);
        }
        healval += selection;
        upPts -= selection;
        cout << "Your heal has " << healval << " healing, you now have " << upPts << " upgrade points remaining" << endl;
        }
        
        
    }
    else if (selection == 3)
        {
            cout << "You have " << upPts << " to spend." << endl;
            cout << "You have "<< hp << " HP, going below this number will lose you the game, enter the amount of points you want to upgrade HP: ";
            cin >> selection;
            selection = abs(selection);
            cout << endl;
            while (selection > upPts && (hp - (selection*3)) < 0)
            {
                cout << "Please enter a valid number of points";
            cin >> selection;
            selection = abs(selection);
            }
            hp += selection * 3;
            upPts -= selection;
            cout<< "Your HP is now " << hp << " you now have " << upPts << " upgrade points remaining" << endl;
        }
    
    else if (selection == 4)
    {
        cout <<"Your Stats are as follows:" << endl;
        cout << "Name: " << name << endl;
        cout << "HP : " << hp << " Health" << endl;
        cout << "Attacks: " << endl;
        cout << "Strike : " << atkval1 << " ATK" << endl;
        cout << "Heavyslash : " << atkval2 << " ATK" << endl;
        cout << "Skills :" << endl;
        cout << "Block : " << blockval << " Block" << endl;
        cout << "Heal : " << healval << " HP" << endl;
        cout << "Upgrade Points: " << upPts << endl;
        cout << "Enter 0 to continue";
        cin >> selection;
    }
    else if (selection == 5)
    {
        cout << "You're character is as follows: " << endl;
        cout << "Name: " << name << endl;
        cout << "HP : " << hp << " Health" << endl;
        cout << "Attacks: " << endl;
        cout << "Strike : " << atkval1 << " ATK" << endl;
        cout << "Heavyslash : " << atkval2 << " ATK" << endl;
        cout << "Skills :" << endl;
        cout << "Block : " << blockval << " Block" << endl;
        cout << "Heal : " << healval << " HP" << endl;
        cout << "You have " << upPts <<" upgrade points remaining" << endl;
        cout << "Enter 1 to continue, 2 to go back: ";
        cin >> selection;
        if (selection == 1)
        {
            creating = false;
        }

        
    }
    
    }
    combat(name,atkval1,atkval2,blockval,hp);

    return;
    }
    
void combat(string n,int a1, int a2, int b, int health)
    {
        string names[10] = { "Clement", "Liya","Osian","Charlie","Darsh","Yazmin","John","Nicholas","Rudy","Surya"};
        string name = n;
        int atk1 = a1;
        int atk2 = a2;
        int block = b;
        int hp = health;
        cout << name << " " << atk1 << " " << atk2  << " " << block << " " << hp;
        
    }
