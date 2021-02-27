#include <bits/stdc++.h>
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::setfill;
using std::setw;
using std::string;

class Contact {
    string name;
    int prefix;
    int number;
    int calls;
public:
    Contact();
    void setContact(const string &newName, int newPrefix, int newNumber);
    bool nameLike(const string &partOfName);
    bool numberLike(int numberSuffix);
    int getCalls();
    void newCall();
    void print();
};

Contact::Contact() {
    name = "";
    prefix = 0;
    number = 0;
    calls = 0;
}

void Contact::setContact(const string &newName, int newPrefix, int newNumber) {
    name = newName;
    prefix = newPrefix;
    number = newNumber;
}

bool Contact::nameLike(const string &partOfName) {
    if (strlen(partOfName.c_str()) > strlen(name.c_str())) {
        return false;
    } else {
        if (name.substr(0, strlen(partOfName.c_str())) == partOfName) {
            return true;
        } else {
            return false;
        }
    }
}

bool Contact::numberLike(int numberSuffix) {
    if (numberSuffix < 0 || numberSuffix > number) {
        return false;
    } else {
        int k = 1;
        while (numberSuffix > k) {
            k *= 10;
        }
        if (number % k == numberSuffix) {
            return true;
        } else {
            return false;
        }
    }
}

int Contact::getCalls() {
    return calls;
}

void Contact::newCall() {
    calls++;
}

void Contact::print() {
    cout << name << '\t' << std::setfill('0') << 
    std::setw(3) << prefix << '\t' << std::setfill('0') 
    << std::setw(7) << number << '\t' << calls << endl;  
}

int main() {
    Contact contact;
    string name;
    int prefix;
    int number;
    string partofname;
    cin >> name >> prefix >> number;
    contact.setContact(name, prefix, number);
    contact.print();
    return 0;
}

