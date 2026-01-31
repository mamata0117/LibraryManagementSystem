#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book {
    string bookName, author, category;
    int bookId;
    bool issuedCondition;

public:
    Book();
    void input();
    void displayBook();
    int getId();
};

#endif
