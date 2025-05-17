#include<iostream>
using namespace std;
class Book{
    public:
        string title;
        string author;
        int year;
        float price;
        bool isAvailable;

        Book(string title,string author,int year,float price ,bool isAvailable){
            this->title = title;
            this->author = author;
            this->year = year;
            this->price = price;
            this->isAvailable = isAvailable;
        }
        void getInfo(){
            cout<<"title"<<title<<endl;
            cout<<"author"<<author<<endl;
            cout<<"year"<<year<<endl;
            cout<<"price"<<price<<endl;
            if (isAvailable) cout<<"available";
            else cout<<"Not available";            
        }  

        void setPrice(float newPrice){
            this->price = newPrice;
        }

        void toggleAvailability(){
            this->isAvailable = !(this->isAvailable);
        }
};
int main()
{
    Book book1("football" , "james" , 2016 , 19.9 , false);
    Book kingBook("king" , "shamoeel" , 2000 , 100 , true);
    Book book3("computer" , "abdul" , 2017 , 10.9 , true);
    
    book1.getInfo();
    book1.toggleAvailability();
    book1.setPrice(99.1);
    return 0;
}