#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to check if user exists
bool userExists(const string& username) {
    ifstream infile("users.txt");
    string storedUsername, storedPassword;
    while (infile >> storedUsername >> storedPassword) {
        if (storedUsername == username) {
            return true;
        }
    }
    return false;
}

// Function to sign up a new user
void signUp() {
    string username, password;
    cout << "=== Sign Up ===" << endl;
    cout << "Enter username: ";
    cin >> username;
    if (userExists(username)) {
        cout << "Username already exists. Try a different one." << endl;
        return;
    }
    cout << "Enter password: ";
    cin >> password;

    ofstream outfile("users.txt", ios::app);
    outfile << username << " " << password << endl;
    cout << "Sign up successful! You can now log in." << endl;
}

// Function to log in
void logIn() {
    string username, password;
    cout << "=== Log In ===" << endl;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream infile("users.txt");
    string storedUsername, storedPassword;
    bool found = false;
    while (infile >> storedUsername >> storedPassword) {
        if (storedUsername == username && storedPassword == password) {
            found = true;
            break;
        }
    }
    if (found) {
        cout << "Log in successful! Welcome, " << username << "!" << endl;
    } else {
        cout << "Invalid username or password. Please try again." << endl;
    }
}

int main() {
    int choice;
    do {
        cout << "\n==== Menu ====" << endl;
        cout << "1. Sign Up" << endl;
        cout << "2. Log In" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                signUp();
                break;
            case 2:
                logIn();
                break;
            case 0:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
