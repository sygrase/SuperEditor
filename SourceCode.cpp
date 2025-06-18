#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
using namespace std;
string gaddr;
string test = "";
void clearScreen()
{
    system("cls");
}

void openTest(string addr)
{
    ifstream f(addr);
    if (!f.is_open())
    {
        cout << "Failed to open file: " << addr << endl;
        Sleep(1000);
        return;
    }

    test = "";
    string line;
    while (getline(f, line))
    {
        test += line;
    }
    f.close();
    rewind(stdin);
}
void saveFile(int n);
void editTest()
{
    clearScreen();
    int n;
    cout << test;
    while (true)
    {
        if (kbhit())
        {
            n = getch();
            if (n == 8)
            {
                test = test.substr(0, test.size() - 1);
                clearScreen();
                cout << test;
            }
            else if (n == 13)
            {
                test = test + '\n';
                clearScreen();
                cout << test;
            }
            else if (n == 224)
            {
                n = getch();
                if (n == 134)
                {
                    clearScreen();
                    saveFile(1);
                    return;
                }
                if (n == 133)
                {
                    clearScreen();
                    saveFile(0);
                    return;
                }
            }
            else
            {
                test = test + char(n);
                cout << char(n);
            }
        }
    }
    rewind(stdin);
}
void saveFile(int n)
{
    string addr = gaddr;
    clearScreen();
    if (n == 1)
    {
        cout << "Where do you want to save this file?(last time " << addr << ")";
        cin >> addr;
    }
    ofstream fo;
    fo.open(addr);
    fo << test;
    fo.close();
    rewind(stdin);
}
void codeFile()
{
    reverse(test.begin(), test.end());
    for (int i = 0; i < int(test.size()); i++)
    {
        test[i] = char(test[i] + 14);
    }
    clearScreen();
    cout << "the coded file will like this:(press any key to continue)\n";
    cout << test;
    getch();
    saveFile(1);
    rewind(stdin);
}

void uncodeFile()
{
    reverse(test.begin(), test.end());
    for (int i = 0; i < int(test.size()); i++)
    {
        test[i] = char(test[i] - 14);
    }
    cout << "the uncoded file will like this:(press any key to continue)\n";
    cout << test;
    getch();
    saveFile(1);
    rewind(stdin);
}
void choiceTest(int n)
{
    rewind(stdin);
    clearScreen();
    string addr;
    cout << "Please tell me the address of the file:";
    cin >> addr;
    gaddr = addr;
    ifstream f(addr);
    if (!f.is_open())
    {
        cout << "Failed to open file: " << addr << endl;
        Sleep(1000);
        return ;
    }
    if (n == 1)
    {
        openTest(addr);
        editTest();
    }
    else if (n == 2)
    {
        openTest(addr);
        codeFile();
    }
    else if (n == 3)
    {
        openTest(addr);
        uncodeFile();
    }
    rewind(stdin);
}

void menu()
{
    cout << "Welcome here=)";
    Sleep(1000);
    clearScreen();
    while (true)
    {
        test = "";
        clearScreen();
        cout << "What do you want to do?\n";
        cout << "1.Create File\n";
        cout << "2.Open File\n";
        cout << "3.Code File\n";
        cout << "4.Uncode File\n";
        cout << "0.Quit\n";

        int choice;
        cin >> choice;
        switch (choice)
        {
        case 0:
            clearScreen();
            cout << "Are you really want to quit?( 1=yes )\n";
            cin >> choice;
            if (choice == 1)
            {
                return ;
            }
            break;

        case 1:
            test = "";
            editTest();
            break;

        case 2:
            choiceTest(1);
            break;
        case 3:
            choiceTest(2);
            break;
        case 4:
            choiceTest(3);
        default:
            cout << "Please input a right number~";
            Sleep(1000);
            clearScreen();
        }
    }
    rewind(stdin);
    return ;
}
int main()
{
    menu();
    return 0;
}