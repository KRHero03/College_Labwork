#include <bits/stdc++.h>

using namespace std;

unordered_map<string, unordered_map<string, bool>> fileSystem;
string user = "";

void login()
{
    cout << "Please enter Username: " << endl;
    cin >> user;
    cout << user << " Logged in!" << endl;
}

void logout()
{
    user = "";
    cout << user << " Logged out!" << endl;
}

void insertFile()
{
    if (user == "")
    {
        cout << "Please Login first!" << endl;
        return;
    }
    cout << "Enter File Name: ";
    string fileName;
    cin >> fileName;
    fileSystem[user][fileName] = 1;
    cout << "File " << fileName << " inserted in User File Directory!" << endl;
}

void displayFiles()
{
    if (fileSystem.size() == 0)
    {
        cout << "No Files in User File Directory!" << endl;
        return;
    }
    cout << "Displaying all Files in User File Directory: " << endl;
    for (auto i : fileSystem)
    {
        cout << i.first << ":" << endl;
        for (auto j : i.second)
        {
            cout << "-" << j.first << endl;
        }
    }
}

void deleteFile()
{
    if (user == "")
    {
        cout << "Please Login first!" << endl;
        return;
    }
    cout << "Enter File Name: ";
    string fileName;
    cin >> fileName;
    if (fileSystem[user].find(fileName) == fileSystem[user].end())
    {
        cout << "File " << fileName << " not found in User File Directory!" << endl;
        return;
    }
    fileSystem[user].erase(fileName);
    cout << "File " << fileName << " deleted!" << endl;
}

void searchFile()
{
    if (user == "")
    {
        cout << "Please Login first!" << endl;
        return;
    }
    cout << "Enter File Name: ";
    string fileName;
    cin >> fileName;
    if (fileSystem[user].find(fileName) == fileSystem[user].end())
    {
        cout << "File " << fileName << " not found in User File Directory!" << endl;
        return;
    }
    cout << "File " << fileName << " found in User File Directory!" << endl;
}

void printMenu()
{
    cout << "----------------------------------------------------------------" << endl;
    cout << "User Options:" << endl;
    cout << "1. Login" << endl;
    cout << "2. Logout" << endl;
    cout << "3. Create File" << endl;
    cout << "4. Display All Files" << endl;
    cout << "5. Delete File" << endl;
    cout << "6. Search File" << endl;
    cout << "7. Exit Program" << endl;
    cout << ">> ";
}

int main()
{
    cout << "Two Level Directory System" << endl;
    int choice = -1;
    while (choice != 5)
    {
        printMenu();
        cin >> choice;
        if (choice == 1)
        {
            login();
        }
        else if (choice == 2)
        {
            logout();
        }
        else if (choice == 3)
        {
            insertFile();
        }
        else if (choice == 4)
        {
            displayFiles();
        }
        else if (choice == 5)
        {
            deleteFile();
        }
        else if (choice == 6)
        {
            searchFile();
        }
        else if (choice == 7)
        {
            break;
        }
        else
        {
            cout << "Invalid Choice!" << endl;
        }
    }
}