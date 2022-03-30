#include <iostream>
#include <iomanip>
#include <fstream>

#include "SLL/SLL.h"
#include "SLL/SLL.cpp"

using namespace std;

class passenger {
public:
    string name;
    passenger();
    passenger(string pname);
    bool operator==(passenger &p);
    bool operator<=(passenger &p);
    bool operator<(passenger &p);
    friend istream &operator>>(istream &ist, passenger &p);
    friend ostream &operator<<(ostream &ost, passenger &p);
};

void reserve(SLL<passenger> &list, passenger p);
void cancelReservation(SLL<passenger> &list, passenger p);
void checkReservation(SLL<passenger> &list, passenger p);
void toUpper(string &str);

int main() {

try {
    cout << "Starting the program" << "\n";
    cout << "Reading files" << "\n";

    // Input the data
    ifstream ist{};
    string fname{"reservations.txt"};
    ist.open(fname);
    if(!ist)
        throw runtime_error("Unable to open file " + fname);

    SLL<passenger> passenger_list{};
    while(!ist.eof()) {
        string str;
        ist >> str;
        toUpper(str);
        if(str!="")
            passenger_list.addToTail(passenger{str});
    }
    ist.close();

    cout << "WELCOME TO INDIAN AIRLINES" << "\n"; 
    cout << "Please select a service" << "\n"; 
    cout << "1. Reserve a ticket" << "\n"; 
    cout << "2. Cancel a reservation" << "\n"; 
    cout << "3. Check whether a ticket is reserved for a particular person" << "\n";
    cout << "4. Display the passengers" << "\n";

    int choice;
    cout << "Your choice: ";
    cin >> choice;

    // Modify the data
    if(choice<1 && choice>4)
        throw runtime_error("Incorrect choice");
    switch(choice) {
        case 1:
        {
            cout << "Enter passenger name: " << "\n";
            string pass_name;
            cin >> pass_name;
            toUpper(pass_name);
            passenger psgr{pass_name};
            reserve(passenger_list,psgr);
            break;
        }
        case 2:
        {
            cout << "Enter passenger name: ";
            string pass_name{};
            cin >> pass_name;
            passenger p{pass_name};
            cancelReservation(passenger_list,p);
            break;
        }
        case 3:
        {
            cout << "Enter passenger name: ";
            string pass_name{};
            cin >> pass_name;
            passenger p{pass_name};
            checkReservation(passenger_list,p);
            break;
        }
        case 4:
        {
            cout << "Passengers for current flight: " << "\n";
            passenger_list.print();
        }
            break;
    }

    // Output the resulting data
    ofstream ost{};
    ost.open(fname);
    SLLNode<passenger>* ptr=passenger_list.head;
    while(ptr!=nullptr) {
        ost << ptr->info;
        ost << "\n";
        ptr = ptr->next;
    }
    ost.close();
}
catch(runtime_error &e) {
    cout << "ERROR! " << e.what() << "\n";
    return 1;
}

    return 0;
}

passenger::passenger()
    : name{"NULL"} {}
passenger::passenger(string pname)
    : name{pname} {}
bool passenger::operator==(passenger &p) {
    return this->name==p.name;
}
bool passenger::operator<(passenger &p) {
    return this->name < p.name;
}
bool passenger::operator<=(passenger &p) {
    return this->name<p.name || this->name==p.name;
}
istream &operator>>(istream &ist, passenger &p) {
    ist >> p.name;
    return ist;
}
ostream &operator<<(ostream &ost, passenger &p) {
    ost << p.name;
    return ost;
}

void reserve(SLL<passenger> &list, passenger p) {
    if(p.name=="NULL")
        throw runtime_error("Invalid Name");
    if(list.size()==0)
        list.addToHead(p);
    else if(p<=list.head->info)
        list.addToHead(p);
    else if(list.tail->info<=p)
        list.addToTail(p);
    else {
        SLLNode<passenger>* ptr=list.head;
        while(ptr->next!=nullptr) {
            if((p<=ptr->next->info) && (ptr->info<=p)) {
                list.insertAfter(p,ptr);
                break;
            }
            ptr = ptr->next;
        }
    }
    cout << "Ticket reserved for " << p.name << ".\n";
    cout << "Thank you." << "\n";
}
void toUpper(string &str) {
    for(int i=0; i<str.size(); i++) {
        str[i] = toupper(str[i]);
    }
}
void cancelReservation(SLL<passenger> &list, passenger p) {
    if(list.size()==0)
        return;
    list.deleteNode(p);
    cout << "Reservation cancelled for " << p.name << "\n";
}
void checkReservation(SLL<passenger> &list, passenger p) {
    if(list.size()==0)
        cout << p.name << " name not found in passenger list" << "\n";
    else
        if(list.isInList(p))
            cout << p.name << " name found in the passenger list" << "\n";
}