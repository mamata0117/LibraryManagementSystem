#ifndef STUDENT_H
#define STUDENT_H
#include<string>
#include <fstream>

using namespace std;
 
class student {
    string name,email,department;
    int idnum,age;
    long long phonenum;
    public:
    void inputstudent();
    void displaystudent();

int getId();

    void saveToFile(ofstream &file);
    void loadFromFile(ifstream &file);
};
#endif