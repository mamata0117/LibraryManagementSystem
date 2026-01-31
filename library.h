#ifndef LIBRARY_H
#define LIBRARY_H

#include "book.h"
#include "student.h"

struct BookNode {
    Book data;
    BookNode* next;
};

struct studentNode {
    student data;
    studentNode* next;
};

class Library {
    BookNode* bookHead;
    studentNode* studentHead;

public:
    Library();
    void addBook();
    void addStudent();     
    void displayBooks();
    void displayStudents();
    void menu();
    void removeStudent(int id);
    void saveStudentsToFile();
void loadStudentsFromFile();


};

#endif
