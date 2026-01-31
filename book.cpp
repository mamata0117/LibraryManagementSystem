#include "book.h"
#include <iostream>
using namespace std;

Book::Book() {
    issuedCondition = false;
}

void Book::input() {
    cout << "\nEnter Book ID: ";
    cin >> bookId;
    cin.ignore();

    cout << "Enter Book Title: ";
    getline(cin, bookName);

    cout << "Enter Author: ";
    getline(cin, author);

    cout << "Enter Category: ";
    getline(cin, category);
}

void Book::displayBook() {
    cout << "\nBook ID  : " << bookId;
    cout << "\nName     : " << bookName;
    cout << "\nAuthor   : " << author;
    cout << "\nCategory : " << category;
    cout << "\nStatus   : " << (issuedCondition ? "Issued" : "Available") << "\n";
}

int Book::getId() {
    return bookId;
}
bool Book::searchById(int id) {
    if (bookId == id) {
        displayBook();
        return true;
    }
    return false;
}

