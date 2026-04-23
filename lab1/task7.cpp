#include <iostream>
using namespace std;

class Book
{
private:
    string name;
    string ISBN;
    string author;
    string publisher;

public:
    // Constructor
    Book(string n, string i, string a, string p)
    {
        name = n;
        ISBN = i;
        author = a;
        publisher = p;
    }

    // Getters
    string getName() const { return name; }
    string getISBN() const { return ISBN; }
    string getAuthor() const { return author; }
    string getPublisher() const { return publisher; }

    // Setters
    void setName(string n) { name = n; }
    void setISBN(string i) { ISBN = i; }
    void setAuthor(string a) { author = a; }
    void setPublisher(string p) { publisher = p; }

    // Query method
    string getInfo() const
    {
        return ISBN + " " + name + " " + author + " " + publisher;
    }
};

int main()
{
    Book books[5] = {
        Book("book1", "1320985748", "Unknown author", "Unknown publisher"),
        Book("book2", "2320985748", "Unknown author", "Unknown publisher"),
        Book("book3", "3320985748", "Unknown author", "Unknown publisher"),
        Book("book4", "4320985748", "Unknown author", "Unknown publisher"),
        Book("book5", "5320985748", "Unknown author", "Unknown publisher")};

    for (int i = 0; i < 5; i++)
    {
        cout << books[i].getInfo() << endl;
    }

    return 0;
}
