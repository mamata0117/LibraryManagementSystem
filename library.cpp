#include <iostream>
#include <fstream>

#include "library.h"

using namespace std;

Library::Library() {
    bookHead = NULL;
    studentHead = NULL;
}

void Library::addBook() {
    Book b;
    b.input();
    BookNode* newNode = new BookNode;
    newNode->data = b;
    newNode->next = bookHead;
    bookHead = newNode;
}
void Library::saveStudentsToFile() {
    ofstream file("students.txt");

    StudentNode* temp = studentHead;
    while (temp != NULL) {
        temp->data.saveToFile(file);
        temp = temp->next;
    }

    file.close();
}
void Library::loadStudentsFromFile() {
    ifstream file("students.txt");

    if (!file) return;

    while (!file.eof()) {
        student s;
        s.loadFromFile(file);

        if (file.fail()) break;

        StudentNode* newNode = new StudentNode;
        newNode->data = s;
        newNode->next = studentHead;
        studentHead = newNode;
    }

    file.close();
}
void Library::addStudent() {
    student s;
    s.inputstudent();

    StudentNode* newNode = new StudentNode;
    newNode->data = s;
    newNode->next = studentHead;
    studentHead = newNode;

    cout << "Student added successfully!\n";
}
void Library::removeStudent(int id) {
    if (studentHead == NULL) {
        cout << "No students found.\n";
        return;
    }

    StudentNode* temp = studentHead;
    StudentNode* prev = NULL;

    while (temp != NULL) {
        if (temp->data.getId() == id) {

            // if first node
            if (prev == NULL)
                studentHead = temp->next;
            else
                prev->next = temp->next;

            delete temp;
            cout << "Student removed successfully!\n";
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    cout << "Student ID not found.\n";
}
void Library::displayStudents() {
    StudentNode* temp = studentHead;

    while (temp != NULL) {
        temp->data.displaystudent();
        temp = temp->next;
    }
}
