#include <iostream>
#include "User.cpp"


using namespace std;

void MainMenu();

int main() {

    MainMenu();

    return 0;
}

void MainMenu() {
    User A;
    Librarian B;
    cout << "=========================================================" << endl;
    cout << "\t\tLibrary Management Program." << endl;
    cout << "\t\tMade by Ethan Nah." << endl;
    cout << "\t\tVer.ProtoType" << endl;
    cout << "=========================================================" << endl;
    cout << endl;
    cout << endl;
    cout << "=========================================================" << endl;
    cout << "\t\t\tchoose The menu" << endl;
    cout << "\t\t\t===================" << endl;
    cout << "\t\t\t1.Using by User" << endl;
    cout << "\t\t\t2.Using by Librarian" << endl;
    cout << "\t\t\t===================" << endl;
    cout << "=========================================================" << endl;
    cout << "Choice: " << endl;
    int choice;
    cin >> choice;

    bool log_status;
    switch (choice) {
        case 1:

            log_status = A.UserLoginMenu();
            if (log_status) {
                A.UserMenu();
            }

            break;
        case 2:
            log_status = B.LibrarianLoginMenu();

            if (log_status) {
                B.LibMenu();
            }
            break;
        default :
            MainMenu();
            break;
    }

}