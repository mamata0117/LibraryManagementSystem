#include <iostream>
#include "library.h"

using namespace std;

void Library::menu() {
    int choice, id;

    while (true) {
        cout << "\n1. Add Book\n2. Display Book\n3. Search Book\n4. Add Student\n5. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1: b.input(); break;
            case 2: b.displayBook(); break;
            case 3:
                cout << "Enter ID: ";
                cin >> id;
                if (!b.searchById(id))
                    cout << "Book not found\n";
                break;
            case 4: s.input(); break;
            case 5: return;
        }
    }
}
