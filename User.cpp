#include <ostream>
#include <string>
#include "Login.cpp"
#include "Librarian.cpp"
#include <windows.h>
#include <cstdio>
#include <sstream>


class User : public Login {
private :
    bool login_status = false;

public :

    //getter setter login Status
    void set_login_status(bool a) {
        login_status = a;
    }

    bool get_login_status() {
        return login_status;
    }

public :
    /*
    * User function declation
    * UserMenu -> main of UserClass
    * Search book
    * Rent Book
    */
    void UserMenu() {

        if (get_status()) {

            int usermenuchoice;
            cout << "===================================================================" << endl;
            cout << "Welcome, " << getloginid() << ". " << endl;
            cout << "Choose the Menu" << endl;
            cout << "1. Search the books" << endl;
            cout << "2. Rent a Book" << endl;
            cout << "3. Display the books " << endl;
            cout << "4. End Program" << endl;
            cout << "===================================================================" << endl;
            cin >> usermenuchoice;

            switch (usermenuchoice) {
                case 1:
                    searchbooks();
                    break;

                case 2:
                    rentabook();
                    break;

                case 3:
                    cout << "===================" << endl;
                    display_book();
                    cout << "===================" << endl;
                    int choice;
                    cout << "Finish Display?"<<endl;
                    cout << "If yes, press 1"<<endl;
                    cin >>choice;
                    if(choice == 1){
                        UserMenu();
                    }else{
                        UserMenu();
                    }
                    break;
                case 4:
                    break;
                default:
                    cout << "Invalid input." << endl;
                    UserMenu();
                    break;

            }//switch end


        }//valid condition end
    }//UserMenu end
    void searchbooks() {
        ifstream Myfile("DataFile/BookData.txt");
        int choosemenu;
        string line;
        string delim = "\t";
        string inputtype;
        ofstream inputTbook;
        ifstream outputTbook;
        int counter = 0;


        cout << "===================" << endl;
        cout << "choose search Method" << endl;
        cout << "1. Book ID" << endl;
        cout << "2. Book Name" << endl;
        cout << "3. Go back to Menu" << endl;
        cout << "===================" << endl;
        cin >> choosemenu;
        switch (choosemenu) {
            case 1: {
                cout << "Type Book ID: " << endl;
                cin >> inputtype;

                while (!Myfile.eof()) {
                    getline(Myfile, line);
                    string found = line.substr(0, line.find(delim));
                    if (found == inputtype) {
                        //open the Tbook.txt
                        inputTbook.open("DataFile/TBook.txt", ios::out);
                        // append the line
                        inputTbook << line << endl;
                        //counting exist searching variable
                        counter++;
                    }

                }
                Myfile.close();
                inputTbook.close();
                if (counter == 0) {
                    cout << "dont have such a book";
                } else {
                    outputTbook.open("DataFile/TBook.txt");
                    cout << "we found the following " << counter << " books" << endl;
                    cout << "ID     BOOKNAME        NumOfBooks" << endl;
                    while (!outputTbook.eof()) {
                        getline(outputTbook, line);
                        cout << line << endl;
                    }

                    outputTbook.close();
                    // open the searched file
                    //cout << line <<endl;

                }

                cout << "Which Process You want to do ? " << endl;
                cout << "1.Search More books" << endl;
                cout << "2.Go back to Menu" << endl;
                cout << "Type Number: " << endl;
                int searchchoice;
                cin >> searchchoice;
                switch (searchchoice) {
                    case 1:
                        searchbooks();
                        break;
                    case 2:
                        UserMenu();
                        break;
                    default:
                        cout << "Invalid Input. Going Back to Menu" << endl;
                        UserMenu();
                }

            }
                break;
            case 2: {
                string search;
                int offset;
                cout << "Type Book Name:  ";
                cout << endl;
                getline(cin, search);
                getline(cin, search);
                cout << "Searching...." << endl;
                Sleep(1000);
                cout << "================================" << endl;
                cout << "ID     BookName    NumberOfBooks" << endl;
                cout << "--------------------------------" << endl;
                while (!Myfile.eof()) {
                    getline(Myfile, line);
                    if ((offset = line.find(search, 0)) != string::npos) {
                        cout << line << endl;
                    }
                }
                Myfile.close();
                cout << "================================" << endl;
                cout << endl;
                cout << "Which Process You want to do ? " << endl;
                cout << "1.Search More books" << endl;
                cout << "2.Go back to Menu" << endl;
                cout << "Type Number: " << endl;
                int searchchoice;
                cin >> searchchoice;
                switch (searchchoice) {
                    case 1:
                        searchbooks();
                        break;
                    case 2:
                        UserMenu();
                        break;
                    default:
                        cout << "Invalid Input. Going Back to Menu" << endl;
                        UserMenu();
                }
            }
                break;
            case 3:
                UserMenu();
                break;

            default:
                cout << "wrong input. Choose again" << endl;
                UserMenu();
                break;

        }

    }

    void display_book() {


        ifstream Myfile("DataFile/BookData.txt");
        string line;


        while (!Myfile.eof()) {
            getline(Myfile, line);
            cout << line << endl;
        }
        Myfile.close();


    }


    void rentabook() {
//open & read a file

        // Check for the available
        bool status = false;
        string bookid;
        ifstream Myfile("DataFile/BookData.txt");
        string line;
        string delim = "\t";
        cout << "Type Book's ID for Rent" << endl;
        cin >> bookid;
        string founda;

        while (!Myfile.eof()) {
            getline(Myfile, line);
            string founda = line.substr(0, line.find(delim));
            if (founda == bookid) {
                status = true;
            }
        }
        Myfile.close();

        //if book exist, proceed rent process.
        if (status) {
            ifstream Bookfile("DataFile/BookData.txt");
            ofstream Tempfile("DataFile/ModifieData.txt", ios::app);
            //variable
            int pos;
            string found;
            while (!Bookfile.eof()) {
                //get all data from .txt file
                getline(Bookfile, line);
                pos = line.find(delim);
                found = line.substr(0, pos);
                //match the row with bookid

                if (found == bookid) {

                    //find specific value
                    line.erase(0, pos + 1); //erase book id from the line
                    pos = line.find(delim); //initiate new position in the line

                    // pos is number of line index so pos +1 => next index of current index  (-'0' => null == -48) current status -> int
                    char *value =  new char[line.length()-pos];

                    for(int i=0; i<=line.length()-pos;i++){
                        value[i]= line[pos+1+i];
                    }

                    int item_val =0;
                    stringstream intValue(value);
                    intValue >> item_val;
                    delete [] value;
                    //change the value of Number of books in the line. also check the value is not a '0'.
                    if (item_val != 0) {
                        //minus 1 from the current value. (The reason it possible it when we save the value, numbook is int value)
                        item_val--;
                        // re-initiate the item_val.  //item_val(int) -> change status from int to char. +48 is the way to change int to char.
                        // The reason why we change is Line -> string and we want to save changed item_val's value so that it need to change char

                    }
                    line = found + "\t" + line.substr(0,pos) + "\t"  + to_string(item_val);
                    Tempfile << line << endl;
                } else {
                    Tempfile << line << endl;
                }// if(found) end
            }//while(!BookData.eof()) end

            Bookfile.close();
            Tempfile.close();

            remove("DataFile/BookData.txt");

            char oldname[] = "DataFile/ModifieData.txt";
            char newname[] = "DataFile/BookData.txt";

            if (rename(oldname, newname) != 0) {
                perror("Error Occur. Please ask to Librarian");
            } else {
                cout << "Successfully Rent a book" << endl;
                cout << "-------------------------" << endl;
                display_book();
                cout << "-------------------------" << endl;
            }


        } //if(status) statement end
        int rentbookmenuchoice;
        cout << endl;
        cout << endl;
        cout << "Do You want to rent more books ?" << endl;
        cout << "1. Yes || 2. No" << endl;
        cout << "Choose Number: " << endl;
        cin >> rentbookmenuchoice;
        switch (rentbookmenuchoice) {
            case 1:
                rentabook();
                break;
            case 2:
                UserMenu();
                break;
            default:
                cout << "Invalid Input. Going Back to Menu" << endl;
                UserMenu();
        }


    }//rentbook end


};//User end


