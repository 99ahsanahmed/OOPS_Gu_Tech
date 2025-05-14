// Task 2: Parameterized Constructor
// 1. Modify the Book class to include a parameterized constructor that accepts title,
// author, and year.
// 2. Create a Book object using user input and display its details.
#include<iostream>
using namespace std;
class Book{
    private : 
    string title;
    string author;
    int year;
    public : 
    Book(string t, string a, int y){
        title = t;
        author = a;
        year = y;
    }
    void display(){
        cout<<title<<" "<<author<<" "<<year<<endl;
    }
};
int main()
{
    string title,author;
    int year;
    cout<<"enter title";
    cin>>title;
    cout<<"enter author";
    cin>>author;
    cout<<"enter year";
    cin>>year;
    Book b1(title, author, year);
    b1.display();
    return 0;
}