#include "student.h"
#include <iostream>
using namespace std;
 void student::inputstudent()
 {
    cout<<"Enter student's id number:";
    cin>>idnum;
    cout<<"Enter student's phone number:";
    cin>>phonenum;
    cout<<"Enter student's age:";
    cin>>age;
    cin.ignore();
    cout<<"Enter student's name :";
     getline(cin,name);
    cout<<"Enter student's email :";
     getline(cin,email);
    cout<<"Enter student's department :";
     getline(cin,department);

 }
 void student::displaystudent()
 {
    cout<<"\n Student's Name         :"<<name;
    cout<<"\n Student's Age          :"<<age;
    cout<<"\n Student's Id           :"<<idnum;
    cout<<"\n Student's Phone number :"<<phonenum;
    cout<<"\n Student's Email        :"<<email;
    cout<<"\n Student's Department   :"<<department;
 }

void student::saveToFile(ofstream &file) {
    file << idnum << endl;
    file << age << endl;
    file << phonenum << endl;
    file << name << endl;
    file << email << endl;
    file << department << endl;
}

void student::loadFromFile(ifstream &file) {
    file >> idnum;
    file >> age;
    file >> phonenum;
    file.ignore();
    getline(file, name);
    getline(file, email);
    getline(file, department);
}int student::getId() {
    return idnum;
}
