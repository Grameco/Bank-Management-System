#include<iostream>
#include<iomanip>
using namespace std;
class bank {
    private:
    double acc_number, contact_number;
    string name, email;
    public:
    void accept() {
        cout << endl << "Enter Name Again: ";
        getline(cin, name);
        cout << endl << "Enter Account Number: ";
        cin >> acc_number;
        cout << endl << "Enter Contact Number: ";
        cin >> contact_number;
        cout << endl <<"Enter Email Id: ";
        cin >> email;
    }
    void display() {
        cout << endl;
        cout << left;
        cout << setw(30);
        cout << name;
        cout << setw(30);
        cout << acc_number;
        cout << setw(30);
        cout << contact_number;
        cout << setw(30);
        cout << email << endl; 
    }

    friend void add_account();
    friend void show_all_accounts();
    friend void search_by_name();
    friend void search_by_account_number();
    friend void update_account_holder_info(); 
    friend void delete_account();
};