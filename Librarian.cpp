/*
#include <ostream>
#include <string>
#include "Login.cpp"

#include <cstdio>

using namespace std;
//function declaration
void addbook();
void updatenumbook();
void checkuser();
bool searchbook();

class Librarian : public Login {
private :
    bool login_status = false;

public :
    void set_login_status(bool a){
    login_status = a;
}

    bool get_login_status(){
    return login_status;
}

public:
    //functions
    void LibMenu(){
    if(get_login_status()){
        int libmenuchoice;
        cout << "===================================================================" << endl;
        cout << "Inside Lib Menu" <<endl;
        cout << "Welcome, " << getloginid() << ". " << endl;
        cout << "Choose the Menu" << endl;
        cout << "1. ADD BOOK" << endl;
        cout << "2. UPDATE BOOK" << endl;
        cout << "3. CHECK USER ID" << endl;
        cout << "===================================================================" << endl;
        cin >> libmenuchoice;


        switch(libmenuchoice){
            case 1:
                addbook();
                break;

            case 2:
                updatenumbook();
                break;
            case 3:
                checkuser();
                break;
            default:
                cout<<"Invalid input. Re-Try"<<endl;
                LibMenu();
        }//switch end
    }

}//LibMenu end

void addbook(){
    ofstream Myfile("BookData.txt", ios::app);
    string bookid,bookname,numbook;
    cout << "================================" << endl;
    cout << "Type BookID: " <<endl;
    cin >> bookid;
    cout << "Type Book Name: " << endl;
    cin >> bookname;
    cout << "Type Number of Book: "<<endl;
    cin >> numbook;

    string add = bookid+"\t"+bookname+"\t"+numbook;
    Myfile << add <<endl;

    Myfile.close();

}//end add_book function

bool searchbook(){
    //variable
    bool status = false;
    string searchbook;
    string line;
    string delim = "\t";
    int count =0;
    //search function need
    cout << "=======================================" << endl;
    cout << "\t\tCheck Books Before Update "<<endl;
    cout << "TYPE BOOK ID WHICH YOU GOING TO UPDATE" <<endl;
    cout << "=======================================" << endl;
    cout << "TYPE ID : "<<endl;

    cin >> searchbook;

    ofstream inputbookname;
    ifstream outputbookname;

    ifstream MyFile("BookData.txt");
    while(!MyFile.eof()){
        getline(MyFile,line);
        cout << "Line: "<<line<<endl;
        string found = line.substr(0,line.find(delim));
        cout << found <<":"<<endl;
        if(found == searchbook){
            inputbookname.open("Temp.txt",ios::out);
            inputbookname << line << endl;
            count ++;
        }
    }
    MyFile.close();
    inputbookname.close();
    if(count == 0){
        cout<<"Don't have such a book"<<endl;
    }else{
        outputbookname.open("Temp.txt");
        cout << "Found the following" << count << " book(s)" <<endl;
        cout << "ID     BOOK NAME      NUMBER OF BOOKS" <<endl;
        while(!outputbookname.eof()){
            getline(outputbookname,line);
            cout << line << endl;
        }

        outputbookname.close();
        status = true;
    }

    //need to open 2 text file
    return status;

}//end searchbook function

void updatenumbook(){
    bool status = searchbook();
    string found;
    string line, bookid;
    string delim ="\t";
    int changenumval;

    if(status){
        ifstream Myfile("BookData.txt");
        ofstream Newfile("Modified.txt",ios::app);
        cout<<"========================================"<<endl;
        cout<<"RE-TYPE BOOKID WHICH YOU WANT TO UPDATE"<<endl;
        cout<<"========================================"<<endl;
        cout<<"TYPE: "<<endl;
        cin >> bookid;

        while(!Myfile.eof()){
            getline(Myfile,line);
            found = line.substr(0,line.find(delim));
            if(found == bookid){

                line.erase(0,line.find(delim)+1);
                cout <<" Line after eratrisng "<<  line <<endl;
                    cout << "TYPE NUMBOOKS: "<<endl;
                    cin >> changenumval;
                    line[line.find(delim) +1] = changenumval ;

                cout << "change number of books : "<<changenumval << endl;
                cout << "Full Change : " << line <<endl;
                Newfile << found+"\t"+line << endl;
            } else {
                Newfile << line << endl;
            }

        }
        Myfile.close();
        Newfile.close();

        remove("BookData.txt");

        char oldname[] = "Modified.txt";
        char newname[] = "BookData.txt";

        if(rename(oldname, newname)!=0){
            perror("Error in renaming");
        }else{
            cout << "Successfully updated and replaced the file 0" <<endl;
        }



    }//end status Statement
}//end updatenumbook function

void checkuser(){

}//end checkuser function


};//end class
 */