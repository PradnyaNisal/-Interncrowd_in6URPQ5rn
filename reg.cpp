#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, string> users;

void registerUser()
{
    string username, password;

    cout << "Enter a username: ";
    cin >> username;

    cout << "Enter a password: ";
    cin >> password;

    users[username] = password;

    cout << "User registered successfully." << endl;
}

bool login()
{
    string username, password;

    cout << "Enter your username: ";
    cin >> username;

    cout << "Enter your password: ";
    cin >> password;

    if (users.find(username) != users.end() && users[username] == password)
    {
        cout << "Login successful." << endl;
        return true;
    }
    else
    {
        cout << "Invalid username or password." << endl;
        return false;
    }
}

int main()
{
    int choice;

    do
    {
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            registerUser();
            break;
        case 2:
            login();
            break;
        case 3:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
        }

    } while (choice != 3);

    return 0;
}
