#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Book {
public:
    string title;
    string author;
    string ISBN;
    bool isCheckedOut;

    Book(const string& title, const string& author, const string& ISBN)
        : title(title), author(author), ISBN(ISBN), isCheckedOut(false) {}
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(const string& title, const string& author, const string& ISBN) {
        books.emplace_back(title, author, ISBN);
    }

    Book* findBook(const string& searchKey) {
        for (Book& book : books) {
            if (book.title == searchKey || book.author == searchKey || book.ISBN == searchKey) {
                return &book;
            }
        }
        return nullptr;
    }

    bool checkOutBook(Book* book) {
        if (book && !book->isCheckedOut) {
            book->isCheckedOut = true;
            return true;
        }
        return false;
    }

    bool returnBook(Book* book) {
        if (book && book->isCheckedOut) {
            book->isCheckedOut = false;
            return true;
        }
        return false;
    }
};

int main() {
    Library library;

    library.addBook("Book 1", "Author 1", "ISBN1");
    library.addBook("Book 2", "Author 2", "ISBN2");

    Book* bookToCheckout = library.findBook("Book 1");
    if (library.checkOutBook(bookToCheckout)) {
        cout << "Book 1 has been checked out." << endl;
    } else {
        cout << "Book 1 is not available for checkout." << endl;
    }

    Book* bookToReturn = library.findBook("Book 1");
    if (library.returnBook(bookToReturn)) {
        cout << "Book 1 has been returned." << endl;
    } else {
        cout << "Book 1 cannot be returned or is not checked out." << endl;
    }

    return 0;
}
