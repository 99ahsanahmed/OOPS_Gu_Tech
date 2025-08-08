#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

class Book
{
public:
    string isbn, author, title;
    Book() {};
    Book(string isbn, string title, string author) : isbn(isbn), title(title), author(author) {};
};

// Function to search books by author
int search(unordered_map<string, Book> &bookList, string author, multimap<string, Book> &searchResult)
{
    int count = 0;

    for (auto &pair : bookList)
    {
        Book book = pair.second;
        if (book.author == author)
        {
            searchResult.insert({book.isbn, book});
            count++;
        }
    }
    return count;
}

int main()
{
    Book b0("9635280258938", "Mercury", "Asad");
    Book b1("4702599831795", "Venus", "Asad");
    Book b2("8417392305289", "Earth", "Asad");
    Book b3("4323267170016", "Mars", "Taimoor");
    Book b4("8951093252041", "Saturn", "Unknown");
    Book b5("5580166798252", "Jupiter", "Taimoor");

    unordered_map<string, Book> bookList =
        {
            {"9635280258938", b0},
            {"4702599831795", b1},
            {"8417392305289", b2},
            {"4323267170016", b3},
            {"8951093252041", b4},
            {"5580166798252", b5}
        };

    multimap<string, Book> searchResult;
    string authorToSearch = "Asad";

    int resultCount = search(bookList, authorToSearch, searchResult);

    cout << "Books written by \"" << authorToSearch << "\":" << endl;
    for (auto &pair : searchResult)
    {
        Book book = pair.second;
        cout << "ISBN: " << book.isbn << ", Title: " << book.title << endl;
    }

    cout << "Total books found: " << resultCount << endl;

    return 0;
}
