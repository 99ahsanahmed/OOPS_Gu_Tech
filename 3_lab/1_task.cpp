#include<iostream>
using namespace std;

class Book{
    private : 
    string title;
    string author;
    int year;
    public : 
    Book(){
        title = "abc";
        author = "abcd";
        year = 1990;
    }
    void display(){
        cout<<title<<" "<<author<<" "<<year<<endl;
    }
};
int main()
{
    Book b1;
    b1.display();
    return 0;
}