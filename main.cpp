#include <iostream>
#include <fstream>
using namespace std;

// this class is used to handle login, signup, and password recovering
class temp {
    // sign-up vars
    string userName, Email, password;
    // login and forgot vars
    string searchName, searchPass, searchEmail;

    fstream file;

    /*
     * this public allows the methods to be accessed from everywhere
     * including outside the class
     */

    public:
        void login();
        void signUP();
        void forgot();

}obj;

int main() {
    char choice;

    cout << "\n1- Login";
    cout << "\n2- Sign-Up";
    cout << "\n3- Forgot Password";
    cout << "\n4- Exit";
    cout << "\nEnter your choice: ";

    cin >> choice;
    /** when reading in a character from the user
     * a new line is left over and it is consumed
     * instead of waiting for user input
     */
    cin.ignore();

    // char of choice determines which method is called
    switch (choice) {
        case '1':
            obj.login();
        break;

        case '2':
            obj.signUP();
        break;

        case '3':
            obj.forgot();
        break;

        case '4':
            return 0;
        default:
            cout << "Invalid Choice";
    }
}

// handles user sign-up and saves it to the file
void temp :: signUP() {
    cout << "\nEnter Username: ";
    getline(cin, userName);
    cout << "\nEnter Email: ";
    getline(cin, Email);
    cout << "\nEnter Password: ";
    getline(cin, password);

    /**
     * a new formatted file is made with the previous data
     */
    file.open("loginData.txt", ios::out | ios::app);
    file << userName << "*" << Email << "*" << password << "\n";
    file.close();
}

// handles user login and saves it to the file
void temp :: login() {
    // string searchName, searchPass;
    cout << "------LOGIN------" << endl;
    cout << "Enter Username: " << endl;
    getline(cin, searchName);
    cout << "Enter Password: " << endl;
    getline(cin, searchPass);

    file.open("loginData.txt", ios::in);
    getline(file, userName, '*');
    getline(file, Email, '*');
    getline(file, password, '\n');

    while (!file.eof()) {
        if (userName == searchName) {
            if (password == searchPass) {
                cout << "\nLogin Successful!" << endl;
                cout << "\nUsername: " << userName << endl;
                cout << "\nEmail: " << Email << endl;
            } else {
                cout << "Password is incorrect" << endl;
            }
        }
        getline(file, userName, '*');
        getline(file, Email, '*');
        getline(file, password, '\n');
    }
    file.close();
}

// handles password recovery by verifying username and email
void temp :: forgot() {
    cout << "\nEnter Username: " << endl;
    getline(cin, searchName);
    cout << "\nEnter Email: " << endl;
    getline(cin, searchEmail);

    /* this boolean is need to flag if the
     * account has been found or not
     */
    bool accountFound = false;
    file.open("loginData.txt", ios::in);

    // this loop continues while the following formatted file is true
    while(getline(file, userName, '*') &&
        getline(file, Email, '*') &&
        getline(file, password, '\n')) {

        if (userName == searchName && Email == searchEmail) {
                cout << "\nAccount Found!" << endl;
                cout << "\nYour Password: " << password << endl;
                accountFound = true;
                break;
            }
        }
        file.close();

        if (!accountFound) {
        cout << "\nAccount Not Found!" << endl;
    }
}