#include<iostream>
#include<string.h>
#include<fstream>
#include"bank.cpp"
using namespace std;
bank b;
int flag;

void add_account() {
    string name;
    cout << endl << "Enter Name: ";
    getline( cin, name );

    fstream rd;
    rd.open( "bank.txt", ios :: in );
    rd.seekg( 0, ios :: end );
    int size = rd.tellg() / sizeof(b);
    rd.seekg( 0, ios :: beg );
    for( int i = 0; i <= size; i++ ) {
        rd.read( (char*)& b, sizeof(b) );
        if( b.name == name ) {
            cout << "Account name already exist." << endl;
            return;
        }
    }

    b.accept();
    fstream wr;
    wr.open( "bank.txt", ios :: app );
    wr.write( (char*)& b, sizeof(b) );
    wr.close();
    cout << "Account added." << endl << endl;
}

void show_all_accounts() {
    fstream rd;
    rd.open( "bank.txt", ios :: in );
    rd.seekg( 0, ios :: end );
    int size = rd.tellg() / sizeof(b);
    rd.seekg( 0, ios :: beg );

    if( size == 0 ) {
        cout << endl << "File is empty." << endl;
        return;
    }

    cout << endl << endl;
    cout << left;
    cout << setw(30);
    cout << "Name";
    cout << setw(30);
    cout << "Account Number";
    cout << setw(30);
    cout << "Contact Number";
    cout << setw(30);
    cout << "Email Id";
    cout << endl << "-----------------------------------------------------------------------------------------------------------------------------------";

    for( int i = 1; i <= size; i++ ){
        rd.read( (char*)& b, sizeof(b) );
        b.display();
        cout << endl << "-----------------------------------------------------------------------------------------------------------------------------------";
    }

}

void search_by_name() {
    string name;
    cout << endl << "Enter Name: ";
    getline( cin, name );

    fstream rd;
    rd.open( "bank.txt", ios :: in );
    rd.seekg( 0, ios :: end );
    int size = rd.tellg() / sizeof(b);
    rd.seekg( 0, ios :: beg );

    if( size == 0 ) {
        cout << endl << "File is empty." << endl;
        rd.close();
        return;
    }

    fstream wr;
    wr.open( "name_search.txt", ios :: out );

    for( int i = 0; i < size; i++ ) {
        rd.read( (char*)& b, sizeof(b) );
        if( b.name == name ) {
            wr.write( (char*)& b, sizeof(b) );
            cout << "Account Found." << endl;
            flag = 1;
            break;
        }
    }
    if( flag != 1 ){
        cout<<endl<<"No Record Matched";
        rd.close();
        wr.close();
        remove( "name_search.txt" );
        return;
    }

    else {
        rd.close();
        wr.close();

        rd.open( "name_search.txt", ios :: in );
        rd.seekg( 0, ios :: end );
        int s = rd.tellg() / sizeof(b);
        rd.seekg( 0, ios :: beg );

        cout << endl << endl;
        cout << left;
        cout << setw(30);
        cout << "Name";
        cout << setw(30);
        cout << "Account Number";
        cout << setw(30);
        cout << "Contact Number";
        cout << setw(30);
        cout << "Email Id";
        cout << endl << "-----------------------------------------------------------------------------------------------------------------------------------";

        for( int i = 1; i <= s; i++ ){
            rd.read( (char*)& b, sizeof(b) );
            b.display();
            cout<<endl<<"-----------------------------------------------------------------------------------------------------------------------------------";
        }

        rd.close();
        remove( "name_search.txt" );
    }
}

void search_by_account_number() {
    int account_number;
    cout << endl << "Enter Account Number: ";
    cin >> account_number;

    fstream rd;
    rd.open( "bank.txt", ios :: in );
    rd.seekg( 0, ios :: end );
    int size = rd.tellg() / sizeof(b);
    rd.seekg( 0, ios :: beg );

    if( size == 0 ) {
        cout << endl << "File is empty." << endl;
        rd.close();
        return;
    }

    fstream wr;
    wr.open( "account_search.txt", ios :: out );

    for( int i = 0; i < size; i++ ) {
        rd.read( (char*)& b, sizeof(b) );
        if( b.acc_number == account_number ) {
            wr.write( (char*)& b, sizeof(b) );
            cout << "Account Found." << endl;
            flag = 1;
            break;
        }
    }
    if( flag != 1 ){
        cout<<endl<<"No Record Matched";
        rd.close();
        wr.close();
        remove( "account_search.txt" );
        return;
    }

    else {
        rd.close();
        wr.close();

        rd.open( "account_search.txt", ios :: in );
        rd.seekg( 0, ios :: end );
        int s = rd.tellg() / sizeof(b);
        rd.seekg( 0, ios :: beg );

        cout << endl << endl;
        cout << left;
        cout << setw(30);
        cout << "Name";
        cout << setw(30);
        cout << "Account Number";
        cout << setw(30);
        cout << "Contact Number";
        cout << setw(30);
        cout << "Email Id";
        cout << endl << "-----------------------------------------------------------------------------------------------------------------------------------";

        for( int i = 1; i <= s; i++ ){
            rd.read( (char*)& b, sizeof(b) );
            b.display();
            cout<<endl<<"-----------------------------------------------------------------------------------------------------------------------------------";
        }

        rd.close();
        remove( "account_search.txt" );
    }
}

void update_account_holder_info(){
    string name;
    cout << endl << "Enter Name: ";
    getline( cin, name );

    fstream rd;
    rd.open( "bank.txt", ios :: in );
    rd.seekg( 0, ios :: end );
    int size = rd.tellg() / sizeof(b);
    rd.seekg( 0, ios :: beg );

    fstream wr;
    wr.open( "tempfile.txt", ios :: app );
    for( int i = 1; i <= size; i++ ){
        rd.read( (char*)& b, sizeof(b) );
        if( b.name == name ){
            cout << endl << "Record Matched." << endl << "Enter the updated contact details: " << endl;
            b.accept();
            flag=1;
        }

        wr.write( (char*)& b, sizeof(b));
    }

    if(flag!=1){
        cout<<endl<<"No Record Matched";
    }
    rd.close();
    wr.close();
    remove("bank.txt");
    rename("tempfile.txt","bank.txt");
}

void delete_account() {
    string name;
    cout << endl << "Enter Name: ";
    getline( cin, name );

    fstream rd;
    rd.open( "bank.txt", ios :: in );
    rd.seekg( 0, ios :: end );
    int size = rd.tellg() / sizeof(b);
    rd.seekg( 0, ios :: beg );

    fstream wr;
    wr.open( "tempfile.txt", ios :: app );
    for( int i = 1; i <= size; i++ ){
        rd.read( (char*)& b, sizeof(b) );
        if(b.name == name ){
            cout << endl << "Record Removed.";
            flag = 1;
        }
        else{
            wr.write( (char*)&b, sizeof(b));
        }
    }

    if(flag!=1){
        cout<<endl<<"Account not found.";
    }
    rd.close();
    wr.close();
    remove("bank.txt");
    rename("tempfile.txt","bank.txt"); 

}

void clear_record(){
    fstream rd;
    rd.open( "bank.txt", ios :: out | ios :: trunc );
    cout << "File is cleared." << endl;
    rd.close();
}

int main() {
    int option;
    string x;
    cout << endl << "\t\t Welcome to THE NATIONAL BANK" << endl << endl;
    do{
        cout << "\t\t MAIN MENU " << endl << endl;
        cout << "\t\t 1. Add New Account" << endl;
        cout << "\t\t 2. Show All Accounts" << endl;
        cout << "\t\t 3. Search Account by Name" << endl;
        cout << "\t\t 4. Search Account by Account Number" << endl;
        cout << "\t\t 5. Delete Account" << endl;
        cout << "\t\t 6. Clear Entire Record" << endl;
        cout << "\t\t 7. Update Account Holder Information" << endl;
        cout << "\t\t 0. Exit" << endl << endl;
        cout << endl << "\t\tSelect your Option: ";
        cin >> option;

        switch(option) {
            case 0: {
                break;
            }
            case 1: {
                cin.ignore();
                add_account();
                cout << endl << "Press 'C' if you want to continue or 0 to exit." << endl;
                break;
            }
            case 2: {
                show_all_accounts();
                cout << endl << "Press 'C' if you want to continue or 0 to exit." << endl;
                break;
            }
            case 3: {
                cin.ignore();
                search_by_name();
                cout << endl << "Press 'C' if you want to continue or 0 to exit." << endl;
                break;
            }
            case 4: {
                search_by_account_number();
                cout << endl << "Press 'C' if you want to continue or 0 to exit." << endl;
                break;
            }
            case 5: {
                cin.ignore();
                delete_account();
                cout << endl << "Press 'C' if you want to continue or 0 to exit." << endl;
                break;
            }
            case 6: {
                clear_record();
                cout << endl << "Press 'C' if you want to continue or 0 to exit." << endl;
                break;
            }
            case 7: {
                cin.ignore();
                update_account_holder_info();
                cout << endl << "Press 'C' if you want to continue or 0 to exit." << endl;
                break;
            }
            default : {
                cout << "Invalid Option." << endl;
            }
        }
        if( option != 0 ) {
            cout << "Enter your response: ";
            cin >> x;
        }
    
    }while( ( x == "C" || x == "c" ) && option != 0 );

    if( x != "C" || x != "c" ) {
        cout << "Thanks for visiting." << endl;
    }

    return 0;
}