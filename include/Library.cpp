//
// Created by Parsa Jahanbani on 1/30/23.
//

#include "Library.h"
#include <iostream>
#include <string>

using namespace std;
namespace library {

    void Library::start() {
        cout << "Welcome to the Library";
        cout << "\n1. Login";
        cout << "\n2. Register";
        cout << "\n3. Exit";
        cout << "\nPlease enter your choice: ";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1: {
                map<string, User> user_map = User::loadUsersFromFile();

                const User user = User::login(user_map);
//                        user.getRole() == "user" ?
//                            Library::student() :
//                            Library::librarian();
                break;
            }
            case 2:
                signUp();
                break;
            case 3:
                cout << "Exit";
                break;
            default:
                cout << "Invalid choice\n";
                start();
                break;
        }
    }

//    TODO: Actually implement student and librarian functions
    void Library::student() {
        cout << "Welcome to the Library";
        cout << "\n1. Search";
        cout << "\n2. Borrow";
        cout << "\n3. Return";
        cout << "\n4. Exit";
        cout << "\nPlease enter your choice: ";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Search";
                break;
            case 2:
                cout << "Borrow";
                break;
            case 3:
                cout << "Return";
                break;
            case 4:
                cout << "Exit";
                break;
            default:
                cout << "Invalid choice";
                student();
                break;
        }
    }

    void Library::librarian() {
        cout << "Welcome to the Library";
        cout << "\n1. Add Book";
        cout << "\n2. Remove Book";
        cout << "\n3. Add User";
        cout << "\n4. Remove User";
        cout << "\n5. Exit";
        cout << "\nPlease enter your choice: ";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Add Book";
                break;
            case 2:
                cout << "Remove Book";
                break;
            case 3:
                cout << "Add User";
                break;
            case 4:
                cout << "Remove User";
                break;
            case 5:
                cout << "Exit";
                break;
            default:
                cout << "Invalid choice";
                librarian();
                break;
        }
    }

    void Library::signUp() {
        string username, firstName, lastName, password, birthdate;
        cout << " ******* Add User *******";
        cout << "\nEnter Username: ";
        cin >> username;
        cout << "\nEnter Your Name ";
        cin >> firstName >> lastName;
        cout << "\nEnter Password: ";
        cin >> password;
        cout << "\nEnter Birthdate: ";
        cin >> birthdate;

        cout << "Select a role: ";
        cout << "\n1. User";
        cout << "\n2. Librarian";
        cout << "\n3. Go back";
        cout << "\n4. Exit";
        cout << "\nPlease enter your choice: ";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1: {
                string role = "user";
                Database db;
                db.insertUser(username, firstName, lastName, password, birthdate, role);
                break;
            }
            case 2: {
                string role = "librarian";
                Database db;
                db.insertUser(username, firstName, lastName, password, birthdate, role);
                break;
            }
            case 3:
                start();
                break;
            case 4:
                cout << "Exit";
                break;
            default:
                cout << "Invalid choice";
                signUp();
                break;
        }
    }

    Library::Library() {
    }

    Library::~Library() {
    }
} // library