#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
/*
 * Login Class && Librarian Class
 */
using namespace std;

class Login {
    /*
     * Login Menu
     * User Login
     * Sign-up
     */
    //login variable
private:
    string enter_login_id;

    bool status = false;
public:

    string getloginid() {
        return enter_login_id;
    }

    bool get_status() {
        return status;
    }

public:

    //UserSide
    bool UserLoginMenu() {
        //bool status = false;
        bool cond = false;
        string line;
        string id, password;
        int choice;


        cout << "===================" << endl;
        cout << "1.Login" << endl;
        cout << "2.Sign_up" << endl;
        cout << "===================" << endl;
        cin >> choice;

        switch (choice) { //login
            case 1: {
                cout << "===================" << endl;
                cout << "Type ID: " << endl;
                cout << "===================" << endl;
                cin >> id;

                cout << "===================" << endl;
                cout << "Type Password: " << endl;
                cout << "===================" << endl;
                cin >> password;
                cout << "Checking ID & Password..." << endl;
                Sleep(1000);
                string delim = " ";
                string line;
                ifstream Usera("UserData.txt");
                bool cond = true;

                    while (!Usera.eof() & cond) {
                        getline(Usera, line); //get data from UserData.txt to string line.
                        enter_login_id = line.substr(0, line.find(delim));
                        if (id == enter_login_id) {
                            line.erase(0, line.find(delim) + 1);
                            if (password == line) {
                                Sleep(1000);
                                cout << "Login Success." << endl;
                                cout << "Welcome " + id + "." << endl;
                                cout << endl;
                                status = true;
                                cond = false;

                            }
                            else {
                                cout << "Password is Wrong. Going Back to Login Menu..."<<endl;
                                UserLoginMenu();

                            }
                        }else{
                            cout << "Invalid ID. Going Back to Login Menu...."<<endl;
                            UserLoginMenu();
                        }//ID if statement
                    }//get line
                //while loop for cond
                Usera.close();
                break;
                }

            //case 1

            case 2:
            {
                ofstream UserData("UserData.txt", ios::app);
                string inputid, inputpassword;

                cout << "Type Id: " << endl;
                cin >> inputid;
                cout << "Type Password " << endl;
                cin >> inputpassword;

                string add = inputid + " " + inputpassword;

                UserData <<endl <<add ;
                cout << "Register Processing...."<<endl;
                Sleep(2000);
                cout << "Thank You. Going to Login Menu" << endl;
                Sleep(1000);
                UserLoginMenu();
            }//case 2
            default : {
                cout << "Invalid Input. Restart" << endl;
                UserLoginMenu();
            }//default case



        }//switch


        return status;
    }//login menu end

    bool LibrarianLoginMenu() {
        string line;
        string id, password;
        string delim = " ";
        int pos;
        int choice;

        cout << "===================" << endl;
        cout << "1.Login" << endl;
        cout << "2.Sign_up" << endl;
        cout << "===================" << endl;
        cin >> choice;

        switch (choice) { //login
            case 1: {
                cout << "===================" << endl;
                cout << "Type ID: " << endl;
                cout << "===================" << endl;
                cin >> id;

                cout << "===================" << endl;
                cout << "Type Password: " << endl;
                cout << "===================" << endl;
                cin >> password;
                cout<<"Checking ID & Password...."<<endl;
                Sleep(1000);
                //system("cls");

                ifstream Libdata("LibrarianData.txt");
                while (!Libdata.eof()) {
                    getline(Libdata, line); //get data from UserData.txt to string line.
                    pos = line.find(delim);
                    enter_login_id = line.substr(0, line.find(delim));

                    if (id == enter_login_id) {
                        line.erase(0, pos + 1);
                        pos = line.find(delim);
                        string matchingpassword = line.substr(0, pos);
                        if (password == matchingpassword) {
                            Sleep(1000);
                            cout << "Login Success." << endl;
                            cout << "Welcome " + id + "." << endl;
                            cout << endl;
                            status = true;
                            break;
                        } else {
                            cout << "Password Data: " << matchingpassword << endl;
                            cout << "Invalid Password.  Re-Try " << endl;
                            LibrarianLoginMenu();
                        }
                    } else {
                        cout << "Invalid Password.  Re-Try " << endl;
                        LibrarianLoginMenu();
                    }
                }

                Libdata.close();
                break;

            }//case 1

            case 2: //signup
            {
                cout << "Librarian Can not sign-up with this Page. Ask to Manager"<<endl;
                LibrarianLoginMenu();
            }//case2
            default : {
                cout << "Invalid Input. Restart" << endl;
                LibrarianLoginMenu();
            }
        }//switch
        return status;
    }//login menu end
};


class Librarian : public Login {
private :
    bool login_status = false;

public :
    void set_login_status(bool a) {
        login_status = a;
    }

    bool get_login_status() {
        return login_status;
    }

public:
    /*
     * Librarian Functions
     * LibMenu -> Librarian Class Main Menu
     * Add Book
     * Search Book ( this is for Update). Not visible to User
     * Update Book
     * Check User List
     */

    void LibMenu() {
        if (get_status()) {
            int libmenuchoice;
            cout << "===================================================================" << endl;
            cout << "Inside Lib Menu" << endl;
            cout << "Welcome, " << getloginid() << ". " << endl;
            cout << "Choose the Menu" << endl;
            cout << "1. ADD BOOK" << endl;
            cout << "2. UPDATE BOOK" << endl;
            cout << "3. CHANGE USER PASSWORD" << endl;
            cout << "4. End Program" << endl;
            cout << "===================================================================" << endl;
            cin >> libmenuchoice;


            switch (libmenuchoice) {
                case 1:
                    addbook();
                    break;

                case 2:
                    updatenumbook();
                    break;
                case 3:
                    changePassword();
                    break;
                case 4:
                    break;
                default:
                    cout << "Invalid input. Re-Try" << endl;
                    LibMenu();
            }//switch end
        }

    }//LibMenu end

    void addbook() {
        ofstream Myfile("BookData.txt", ios::app);
        string bookid, bookname, numbook;
        cout << "================================" << endl;
        cout << "Type BookID: " << endl;
        cin >> bookid;
        cout << "Type Book Name: " << endl;
        getline(cin, bookname);
        getline(cin, bookname);
        cout << "Type Number of Book: " << endl;
        cin >> numbook;

        string add = bookid + "\t" + bookname + "\t" + numbook;
        Myfile << add;

        Myfile.close();

        cout << "================================" << endl;
        cout << "Do you want to add more books ? " << endl;
        cout << "1. Yes                   2.No" << endl;
        cout << "Type Num: " << endl;
        cout << "================================" << endl;
        int choice;
        cin >> choice;
        if (choice == 1) {
            addbook();
        } else if (choice == 2) {
            LibMenu();
        } else {
            cout << "Invalid input Type. Go back to Main Menu" << endl;
            LibMenu();
        }


    }//end add_book function

    bool searchbook() {
        //variable
        bool status = false;
        string searchbook;
        string line;
        string delim = "\t";
        int count = 0;
        //search function need
        cout << "=======================================" << endl;
        cout << "\t\tCheck Books Before Update " << endl;
        cout << "TYPE BOOK ID WHICH YOU GOING TO UPDATE" << endl;
        cout << "=======================================" << endl;
        cout << "TYPE ID : " << endl;

        cin >> searchbook;

        ofstream inputbookname;
        ifstream outputbookname;

        ifstream MyFile("BookData.txt");
        while (!MyFile.eof()) {
            getline(MyFile, line);
            string found = line.substr(0, line.find(delim));
            if (found == searchbook) {
                inputbookname.open("Temp.txt", ios::out);
                inputbookname << line << endl;
                count++;
            }
        }
        MyFile.close();
        inputbookname.close();
        if (count == 0) {
            cout << "Checking...."<<endl;
            Sleep(1000);
            cout << "Don't have such a book" << endl;
        } else {
            outputbookname.open("Temp.txt");
            cout << "Checking...."<<endl;
            Sleep(1000);
            cout << "Found the following" << count << " book(s)" << endl;
            cout << "ID     BOOK NAME   || NUMBER OF BOOKS" << endl;
            while (!outputbookname.eof()) {
                getline(outputbookname, line);
                cout << line << endl;
            }

            outputbookname.close();
            status = true;
        }

        //need to open 2 text file
        return status;

    }//end searchbook function

    void updatenumbook() {
        bool status = searchbook();
        string found,found1;
        string line, bookid;
        string delim = "\t";
        string changenumval;


        if (status) {
            ifstream Myfile("BookData.txt");
            ofstream Newfile("Modified.txt", ios::app);
            cout << endl;
            cout << endl;
            cout << endl;
            cout << "========================================" << endl;
            cout << "RE-TYPE BOOK ID WHICH YOU WANT TO UPDATE" << endl;
            cout << "========================================" << endl;
            cout << "TYPE: " << endl;
            cin >> bookid;

            while (!Myfile.eof()) {
                getline(Myfile, line);
                found = line.substr(0, line.find(delim));
                if (found == bookid) {

                    line.erase(0, line.find(delim) + 1);
                    cout << "TYPE NUMBOOKS: " << endl;
                    cin >> changenumval;
                    found1 = line.substr(0,line.find(delim));
                    line.erase(0,line.length()-line.find(delim));

                    cout << "change number of books : " << changenumval << endl;
                    cout << "Full Change : " << found +"\t"+found1+"\t"+changenumval << endl;
                    Newfile << found +"\t"+found1+"\t"+changenumval<<endl;
                } else {
                    Newfile << line << endl;
                }

            }
            Myfile.close();
            Newfile.close();

            remove("BookData.txt");

            char oldname[] = "Modified.txt";
            char newname[] = "BookData.txt";

            if (rename(oldname, newname) != 0) {
                perror("Error Occured");
            } else {
                cout << "Successfully updated " << endl;
            }

            cout << "Do You want to update more books?"<<endl;
            cout << "1. Yes || 2. No, Go back to Menu"<<endl;
            cout << "Type: ";
            int updatechoice;
            cin >> updatechoice;
            if(updatechoice ==1 ){
                updatenumbook();
            }else{
                cout<<"Going Back to Menu Page...."<<endl;
                Sleep(1000);
                LibMenu();
            }

        }//end status Statement
    }//end updatenumbook function

    void checkuser() {
        ifstream Myfile("DataFile/UserData.txt");
        string line, getidlist;
        string delim = " ";
        cout << "==================================================" << endl;
        cout << "User ID LIST" << endl;
        cout << "==================================================" << endl;
        while (!Myfile.eof()) {
            getline(Myfile, line);
            getidlist = line.substr(0, line.find(delim));
            cout << "'" << getidlist << "'" << endl;
        }
        Myfile.close();

        cout << "Go back to main menu?" << endl;
        cout << "1.Yes // 2.No" << endl;
        int backchoice;
        cin >> backchoice;
        if (backchoice == 1) {
            LibMenu();
        } else {
            cout << "There is no other option. Going Back to Menu" << endl;
            LibMenu();
        }
    }//end checkuser function

    void changePassword(){
        string checkuserid,line,found,newpassword,found2;
        string delim=" ";
        cout <<"Type User Id which you want to change password"<<endl;
        getline(cin,checkuserid);
        getline(cin,checkuserid);
        ofstream Temp;
        ifstream Myfile;
        Temp.open("UserTemp.txt",ios::app);
        Myfile.open("UserData.txt");
        while(!Myfile.eof()){
            getline(Myfile,line);
            found = line.substr(0,line.find(delim));
            cout << "found: "<<found << endl; // Test
            if(found == checkuserid){

                cout << "Type New Password: "<<endl;
                getline(cin, newpassword);
                string add;
                add = found+" "+newpassword;
                cout << "updated record: " << add <<endl;
                Temp << add <<endl;
            }else{
                Temp <<line<<endl;
            }

        }
        Temp.close();
        Myfile.close();

        remove("UserData.txt");

        char oldname[] = "UserTemp.txt";
        char newname [] = "UserData.txt";

        if(rename(oldname, newname) !=0){
            perror("Error Occur. Please ask to librarian Manager");
        }else{
            cout << "Successfully Password Changed."<<endl;
            cout << "------------------------------"<<endl;
        }
        cout << "Do You want to change more password? :"<<endl;
        cout << "1. Yes || 2. No for press any key"<<endl;
        string changechoice;
        getline(cin, changechoice);
        if(changechoice == "1"){
            changePassword();
        }else{
            cout <<"Going back to Menu.."<<endl;
            LibMenu();
        }
    } // end Change Password Function


};//end class






