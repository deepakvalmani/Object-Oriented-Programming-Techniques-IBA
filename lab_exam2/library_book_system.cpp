#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

class Book
{
protected:
    std::string title;
    std::string author;
    double price;

public:
    Book(string title,
         string author,
         double price)
    {
        this->title = title;
        this->author = author;
        if (price < 0)
        {
            std::invalid_argument("Price cannot be negative.");
        }
        this->price = price;
    }

    virtual void display() const = 0;

    string get_title() const { return title; }
    double get_price() const { return price; }

    virtual ~Book() = default;
};

class PhysicalBook : public Book
{

private:
    int page_count;

public:
    PhysicalBook(string title,
                 string author,
                 double price,
                 int page_count) : Book(title, author, price)
    {
        this->page_count = page_count;
    }

    virtual void display() const override
    {
        std::fixed;
        std::setprecision(2);
        cout << "Physical "
             << title
             << " by "
             << author
             << " Price: "
             << price
             << " Pages: "
             << page_count
             << endl;
    }
};

class EBook : public Book
{
private:
    double file_size_MB;

public:
    EBook(std::string title,
          std::string author,
          double price,
          double file_size_MB) : Book(title, author, price)
    {
        this->file_size_MB = file_size_MB;
    }

    virtual void display() const override
    {
        std::fixed;
        std::setprecision(2);
        cout << "EBook "
             << title
             << " by "
             << author
             << " Price: "
             << price
             << " Size: "
             << file_size_MB
             << endl;
    }
};

class Library
{
private:
    vector<Book *> books;

public:
    void addBook(Book *b)
    {
        books.push_back(b);
    }

    void removeBook(const std::string &title)
    {
        int count = 0;
        for (Book *b : books)
        {
            if (b->get_title() == title)
            {
                books.erase(books.begin() + count);
                cout << "Removed: " << title << endl;
                exit;
            }
            count++;
        }
        cout << "Not Found!\n";
    }

    void displayAll() const
    {
        if (books.empty())
        {
            cout << "Library is Empty!\n";
        }
        else
        {
            for (Book *b : books)
            {
                b->display();
                cout << endl;
            }
        }
    }
// no lambda used 
    void displayAbovePrice(double threshold) const
    {
        int count = 0;
        for (Book *b : books)
        {
            if (b->get_price() > threshold)
            {
                b->display();
                cout << endl;
                count++;
            }

            if (count == 0)
            {
                cout << "No books above threshold \n";
            }
        }
    }

    ~Library()
    {
        for (Book *b : books)
        {
            delete b;
        }
    }
};

int main()
{
    Library lib;
    lib.addBook(new PhysicalBook("The Pragmatic Programmer",
                                 "Hunt & Thomas", 45.99, 352));
    lib.addBook(new EBook("Clean Code",
                          "Robert Martin", 29.99, 3.5));
    lib.addBook(new PhysicalBook("Introduction to Algorithms",
                                 "CLRS", 89.99, 1292));
    lib.addBook(new EBook("Design Patterns",
                          "Gang of Four", 39.99, 5.2));
    lib.addBook(new PhysicalBook("The Mythical Man-Month",
                                 "Fred Brooks", 19.99, 336));
    lib.addBook(new EBook("Effective Modern C++",
                          "Scott Meyers", 34.99, 2.8));
    std::cout << "=== All Books ===" << std::endl;
    lib.displayAll();
    std::cout << "\n=== Books above $35.00 ===" << std::endl;
    lib.displayAbovePrice(35.0);
    std::cout << "\n=== Removing Clean Code ===" << std::endl;
    lib.removeBook("Clean Code");
    std::cout << "\n=== Removing Nonexistent Book ===" << std::endl;
    lib.removeBook("Nonexistent Book");
    std::cout << "\n=== Remaining Books ===" << std::endl;
    lib.displayAll();
    std::cout << "\n=== Testing exception for negative price ===" << std::endl;
    try
    {
        Book *bad = new PhysicalBook("Bad Book", "No Author", -5.00, 100);
        lib.addBook(bad);
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}
