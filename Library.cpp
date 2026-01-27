#include<iostream>
#include<string>
using namespace std;
 class Book
 {
    string bookName,author,category;
    int bookId;
    bool issuedCondition;
    public:

    Book()
    {
        issueCondition=false;
    }
   void input()
   {
    cout<<"Enter Book details :\n";
    cout<<"\n Enter book title:";
    getline(cin,bookName);
    cout<<"\n Enter book author:";
    getline(cin,author);
    cout<<"\n Enter book category:";
       getline(cin,category);
     cout<<"\n Enter book Id:";
    cin>>bookId;
    cout << (issueCondition ? "Book is issued " : "Book isavailable ");
    cout<<endl;
 }
 void display()
 {  cout<<"\n                      \n";
    cout<<"\n     Book Details     \n";
    cout<<"\n                      \n";   
    cout<<"Book Name: "<<bookName<<endl;
    cout<<"Book ID  : "<<bookId<<endl;
    cout<<"Author   : "<<author<<endl;
    cout<<"Category : "<<category<<endl;
 }
void issueBook()
{
    if(issuedCondition==false){
        cout<<"Book is available for issue.You can issue it now.\n";
        issuedCondition=true;
        cout<<"Book issued successfully.\n";
    }
    else
    {
        cout<<"Book is already issued.\n";
    }
    cout<<endl;
}

void returnBook(){
    if(issuedCondition==true)
    {
cout<<"You are returning the book. Book returned successfully.\n"
    }
    cout<<endl;
}
};