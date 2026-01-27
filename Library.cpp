#include <iostream>
#include <string>
using namespace std;

class Book {
    string bookName, author, category;
    int bookId;
    bool issuedCondition;

public:
    Book() { 
        issuedCondition = false; 
    }

    void input() {
        cout << "\n Enter Book ID: ";
        cin >> bookId;
        cin.ignore();

        cout << "Enter Book Title: ";
        getline(cin, bookName);

        cout << "Enter Author: ";
        getline(cin, author);

        cout << "Enter Category: ";
        getline(cin, category);
    }

    void displayBook() {
        cout << "\nBook ID  : " << bookId;
        cout << "\nName     : " << bookName;
        cout << "\nAuthor   : " << author;
        cout << "\nCategory : " << category;
        cout << "\nStatus   : " << (issuedCondition ? "Book is issued" : "Book is available") << "\n";
    }

    int getId() {
         return bookId; 
        }
};

struct Node {
    Book data;
    Node* next,* prev;
  
};

Node* head = NULL;

void insertBook() {
    Book b;
    b.input();

    Node* newNode = new Node; //newNode stores where the node is in memory
    newNode->data = b;

    if (head == NULL) {
        head = newNode;
        head->next = head;
        head->prev = head;
    } else {
        Node* last = head->prev;

        last->next = newNode;
        newNode->prev = last;
        newNode->next = head;
        head->prev = newNode;
    }

    cout << "Book inserted successfully!\n";
}

void deleteBook(int id) {
    if (head == NULL) {
        cout << "Library empty.\n";
        return;
    }

    Node* temp = head;

    do {
        if (temp->data.getId() == id) {

            if (temp->next == temp) {
                delete temp;
                head = NULL;
            } else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;

                if (temp == head)
                    head = temp->next;

                delete temp;
            }

            cout << "Book deleted.\n";
            return;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Book not found.\n";
}

void displayBooks() {
    if (head == NULL) {
        cout << "Library empty.\n";
        return;
    }

    Node* temp = head;
    do {
        temp->data.displayBook();
        temp = temp->next;
    } while (temp != head);
}

int main() {
    int choice, id;

    while (1) {
        cout << "\n1. Insert Book\n2. Delete Book\n3. Display Books\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: insertBook(); break;
            case 2:
                cout << "Enter Book ID to delete: ";
                cin >> id;
                deleteBook(id);
                break;
            case 3: displayBooks(); break;
            case 4: exit(0);
            default: cout << "Invalid choice.\n";
        }
    }
}
