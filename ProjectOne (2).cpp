#include <iostream>

using namespace std;
// variables here
int userInput = 0;
int Clock12 = 0;
int Clock24 = 0;
int Second = 0;
int Minute = 0;
string ampm = "A M";

void displayClock()
{
    cout << "***************************   ***************************" << endl;
    cout << "*      12-Hour Clock      *   *      24-Hour Clock      *" << endl;
    cout << "*       ";
    if (Clock12 <= 9)
        cout << "0" << Clock12 << ":";
    else
        cout << Clock12 << ":";
    if (Minute <= 9)
        cout << "0" << Minute << ":";
    else
    {
        cout << Minute << ":";
    }

    if (Second <= 9)
        cout << "0" << Second;
    else
    {
        cout << Second;
    }
    cout << " " << ampm;
    cout << "      *   *         ";

    if (Clock24 <= 9)
        cout << "0" << Clock24 << ":";
    else
        cout << Clock24 << ":";
    if (Minute <= 9)
        cout << "0" << Minute << ":";
    else
    {
        cout << Minute << ":";
    }

    if (Second <= 9)
        cout << "0" << Second;
    else
    {
        cout << Second;
    }
    cout << "        *";
    cout << "***************************   ***************************" << endl;


}


void addHour()
{
    Clock12 = Clock12 + 1;
    if (Clock12 >= 12)
    {
        Clock12 = Clock12 - 12;
        if (ampm == "A M")
        {
            ampm = "P M";
        }
        else
        {
            ampm = "A M";
        }
    }
    if (ampm == "P M")
    {
        Clock24 = Clock12 + 12;
        if (Clock24 >= 24)
        {
            Clock24 = Clock24 - 24;
        }
    }
    else
    {
        Clock24 = Clock12;
    }
    displayClock();
}

void addMinute()
{
    Minute = Minute + 1;
    if (Minute == 59)
    {
        addHour();
        Minute = 0;
    }
    displayClock();
}

void addSecond()
{
    Second = Second + 1;
    if (Second == 59)
    {
        addMinute();
        Second = 0;
    }
    displayClock();
}

void displayMenu()
{
    do
    {
        cout << "               **************************" << endl;
        cout << "               * 1- Add One Hour        *" << endl;
        cout << "               * 2- Add One Minute      *" << endl;
        cout << "               * 3- Add One Second      *" << endl;
        cout << "               * 4- Exit Program        *" << endl;
        cout << "               **************************" << endl;

        cin >> userInput;

        if (userInput == 1)
        {
            addHour();
        }
        if (userInput == 2)
        {
            addMinute();
        }
        if (userInput == 3)
        {
            addSecond();
        }
    } while (userInput != 4);
    cout << "Program is exiting" << endl;
}


int main() {

    displayClock();
    displayMenu();

    return 0;
}




