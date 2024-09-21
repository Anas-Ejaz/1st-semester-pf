#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int MAX_BOOKS = 10;

struct bookinfo{
    string booknames[MAX_BOOKS];
    string authornames[MAX_BOOKS];
    int bookids[MAX_BOOKS];
    bool issued[MAX_BOOKS];
    int book_count = 0;
};

void addbook(bookinfo& info);
void displaybooks(bookinfo& info);
void removebook(bookinfo& info);
void issuebook(bookinfo& info);
void returnbook(bookinfo& info);

int main() {
    bookinfo info;
    int choice,option,choice_student;
    do{
    cout << "\n \t\t\t\t\t Welcome to our Library Management System " << endl;
    cout<<"1. Admin Account"<<endl;
    cout<<"2. Students Account"<<endl;
    cout<<"3. Exit Library "<<endl;
    cout<<"Enter your choice : ";
    cin>>option;
    while (cin.fail()) {
            cin.clear();  
            while (cin.get() != '\n');  
                cout << "Invalid ! Please enter a valid number : ";
                cin >> option;
        }
    if(option == 1 ){
    int password;
    do {
        cout << "Password: ";
        cin >> password;
        while (cin.fail()) {
            cin.clear();  
            while (cin.get() != '\n');   
                cout << "Invalid ! Please enter digits only : ";
                cin >> password;
        }
        cout << endl;
        if (password == 1111) {
            do {
                system("cls");
                cout << "\n \t\t\t\t\t Welcome to our Library Management System " << endl;
                cout << "1. Add Book " << endl;
                cout << "2. Display Books " << endl;
                cout << "3. Remove Book " << endl;
                cout << "4. Exit " << endl;
                cout << endl;
                cout << "Enter your choice: ";
                cin >> choice;
                while (cin.fail()) {
                    cin.clear();  
                    while (cin.get() != '\n');  
                    cout << "Invalid ! Please enter a valid number : ";
                    cin >> choice;
                }
                cout << endl;
                
                switch (choice) {
                    case 1:
                        system("cls");
                        addbook(info);
                        break;
                    case 2:
                        system("cls");
                        displaybooks(info);
                        break;
                    case 3:
                        system("cls");
                        removebook(info);
                        break;
                    case 4:
                        system("cls");
                        cout << "Thank you for using the Library Management System. Hope we see you again." << endl;
                        break;
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                }
            } while (choice != 4);
        } else {
            cout << "Your password is incorrect. Please try again." << endl;
        }
    } while (password != 1111);
    }else if(option == 2){
            do {
                system("cls");
                cout << "\n \t\t\t\t\t Welcome to our Library Management System " << endl;
                cout << "1. Display Books " << endl;
                cout << "2. Issue Book " << endl;
                cout << "3. Return Book " << endl;
                cout << "4. Exit " << endl;
                cout << endl;
                cout << "Enter your choice: ";
                cin >> choice_student;
                while (cin.fail()) {
                    cin.clear();  
                    while (cin.get() != '\n');  
                        cout << "Invalid ! Please enter a number : ";
                        cin >> choice_student;
                }
                cout << endl;
                
                switch (choice_student) {
                    case 1:
                        system("cls");
                        displaybooks(info);
                        break;
                    case 2:
                        system("cls");
                        issuebook(info);
                        break;
                    case 3:
                        system("cls");
                        returnbook(info);
                        break;
                    case 4:
                        system("cls");
                        cout << "Thank you for using the Library Management System. Hope we see you again." << endl;
                        break;
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                }
            } while (choice_student != 4);
    }
    }while( option != 3 );
    return 0;
}


void addbook(bookinfo& info) {
    int return_back;
    if (info.book_count >= MAX_BOOKS) {
        cout << "Library is full. Cannot add more books." << endl;
        return;
    }
    
    cout << "\t\t\t\t\t\t Add a New Book " << endl;
    do {
        cout << "Enter Book Name: ";
        cin.ignore();
        getline(cin, info.booknames[info.book_count]);

        cout << "Enter Author Name: ";
        getline(cin, info.authornames[info.book_count]);

        cout << "Enter Book ID: ";
        cin >> info.bookids[info.book_count];
        while (cin.fail()) {
            cin.clear();  
            while (cin.get() != '\n');  
                cout << "Invalid ! Please enter book id again : ";
                cin >> info.bookids[info.book_count];
        }
    
        cout << endl;
        cout << "Enter an Option below " << endl;
        cout << "1. Add Books " << endl;
        cout << "2. Return to the Main Menu " << endl;
        cout << "Enter your Option : ";
        cin >> return_back;
        while (cin.fail()) {
            cin.clear();  
            while (cin.get() != '\n');  
                cout << "Invalid ! Please enter a valid number : ";
                cin >> return_back;
        }
        switch (return_back){
        	case 1:
        		cout<< "Adding more books... "<<endl;
        		cout<< endl;
        		break;
            case 2:
                cout << "Returning to the Main Menu... " << endl;
                break;
            default:
                cout<< "Invalid choice.Please try again... " <<endl;
        }
        info.issued[info.book_count] = false;
        info.book_count++;
    } while (return_back != 2); 
    cout << "Book added successfully." << endl;

    ofstream file("books.txt");
    if(!file){
        cout<<"File opening error ";
        exit(1);
    }
    for (int i = 0; i < info.book_count; i++) {
        file << "Book Name: " << info.booknames[i] << endl;
        file << "Author Name: " << info.authornames[i] << endl;
        file << "Book ID: " << info.bookids[i] << endl;
        file << "Issued: " << (info.issued[i] ? "Yes" : "No") << endl;
        file << "---------------------------" << endl;
        file.close();
    }
}

void displaybooks(bookinfo& info) {
    int return_back;
    cout << "\t\t\t\t\t Display All Books " << endl;
    if(info.book_count == 0){
       cout<<"No Book Found ..."<<endl;
    }else{
        for (int i = 0; i < info.book_count; i++) {
            cout << "Book Name: " << info.booknames[i] << endl;
            cout << "Author Name: " << info.authornames[i] << endl;
            cout << "Book ID: " << info.bookids[i] << endl;
            cout << "Issued: " << (info.issued[i] ? "Yes" : "No") << endl;
            cout << "---------------------------" << endl;
    }}  
    do{
	    cout << endl;
	    cout << "Enter an Option below " << endl;
        cout << "1. Return to the Main Menu " << endl;
        cout << "Enter your Option : ";
        cin >> return_back;
        while (cin.fail()) {
            cin.clear();  
            while (cin.get() != '\n');  
                cout << "Invalid ! Please enter a valid number : ";
                cin >> return_back;
        }
	    switch (return_back){
         	case 1:
        		cout << "Returning to the Main Menu... " << endl;
                break;
            default:
                cout<< "Invalid choice.Please try again... " <<endl;
        }
    }while(return_back!=1);
}

void removebook(bookinfo& info) {
    int book_id,return_back;
    for (int i = 0; i < info.book_count; i++) {
        cout << "Book Name: " << info.booknames[i] << endl;
        cout << "Book ID: " << info.bookids[i] << endl;
        cout << "---------------------------" << endl;
    }
    cout << "Enter the Book ID to remove: ";
    cin >> book_id;
    while (cin.fail()) {
            cin.clear();  
            while (cin.get() != '\n');  
            cout << "Invalid ! Please enter a valid book id : ";
            cin >> book_id;
        }
    cout << endl;

    bool found = false;
    for (int i = 0; i < info.book_count; i++) {
        if (info.bookids[i] == book_id) {
            found = true;
            for (int j = i; j < info.book_count - 1; ++j) {
                info.booknames[j] = info.booknames[j + 1];
                info.authornames[j] = info.authornames[j + 1];
                info.bookids[j] = info.bookids[j + 1];
                info.issued[j] = info.issued[j + 1];
            }
            info.book_count--;
            cout << "Book removed successfully..." << endl;
            break;
        }
    }
    if (!found) {
        cout << "Book ID not found" << endl;
    }
    do{
	    cout << endl;
	    cout << "Enter an Option below " << endl;
        cout << "1. Return to the Main Menu " << endl;
        cout << "Enter your Option : ";
        cin >> return_back;
        while (cin.fail()) {
            cin.clear();  
            while (cin.get() != '\n');  
                cout << "Invalid ! Please enter a valid number : ";
                cin >> return_back;
        }
	    switch (return_back){
         	case 1:
        		cout << "Returning to the Main Menu... " << endl;
                break;
            default:
                cout<< "Invalid choice.Please try again... " <<endl;
        }
    }while(return_back!=1);
}

void issuebook(bookinfo& info) {
    int book_id,return_back;
    for (int i = 0; i < info.book_count; i++) {
        cout << "Book Name: " << info.booknames[i] << endl;
        cout << "Book ID: " << info.bookids[i] << endl;
        cout << "---------------------------" << endl;
    }
    cout << "Enter the Book ID to issue: ";
    cin >> book_id;
    while (cin.fail()) {
            cin.clear();  
            while (cin.get() != '\n');  
                cout << "Invalid ! Please enter a valid book id : ";
                cin >> book_id;
        }
    cout << endl;
    
    bool found = false;
    for (int i = 0; i < info.book_count; i++) {
        if (info.bookids[i] == book_id) {
            found = true;
            if (info.issued[i]) {
                cout << "Book is already issued." << endl;
            } else {
                info.issued[i] = true;
                cout << "Book issued successfully..." << endl;
            }
            break;
        }
    }
    if (!found) {
        cout << "Book ID not found." << endl;
    }
    do{
	    cout << endl;
	    cout << "Enter an Option below " << endl;
        cout << "1. Return to the Main Menu " << endl;
        cout << "Enter your Option : ";
        cin >> return_back;
        while (cin.fail()) {
            cin.clear();  
            while (cin.get() != '\n');  
                cout << "Invalid ! Please enter a valid number : ";
                cin >> return_back;
        }
	    switch (return_back){
         	case 1:
        		cout << "Returning to the Main Menu... " << endl;
                break;
            default:
                cout<< "Invalid choice.Please try again... " <<endl;
        }
    }while(return_back!=1);
}

void returnbook(bookinfo& info) {
    int book_id,return_back;
    for (int i = 0; i < info.book_count; i++) {
        cout << "Book Name: " << info.booknames[i] << endl;
        cout << "Book ID: " << info.bookids[i] << endl;
        cout << "---------------------------" << endl;
    }
    cout << "Enter the Book ID to return: ";
    cin >> book_id;
    while (cin.fail()) {
            cin.clear();  
            while (cin.get() != '\n');  
                cout << "Invalid ! Please enter a valid book id : ";
                cin >> book_id;
        }
    cout << endl;
    
    bool found = false;
    for (int i = 0; i < info.book_count; i++) {
        if (info.bookids[i] == book_id) {
            found = true;
            if (!info.issued[i]) {
                cout << "Book was not issued." << endl;
            } else {
                info.issued[i] = false;
                cout << "Book returned successfully." << endl;
            }
            break;
        }
    }
    if (!found) {
        cout <<"Book ID not found."<<endl;
    }
    do{
	    cout << endl;
	    cout << "Enter an Option below " << endl;
        cout << "1. Return to the Main Menu " << endl;
        cout << "Enter your option : ";
        cin >> return_back;
        while (cin.fail()) {
            cin.clear();  
            while (cin.get() != '\n');  
                cout << "Invalid ! Please enter a valid number : ";
                cin >> return_back;
        }
	    switch (return_back){
         	case 1:
        		cout << "Returning to the Main Menu... " << endl;
                break;
            default:
                cout<< "Invalid choice.Please try again... " <<endl;
        }
    }while(return_back!=1);
}
