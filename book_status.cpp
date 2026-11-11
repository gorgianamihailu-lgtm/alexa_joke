#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

struct Book {
    string title;
    string author;
    int pages;
    string id;
    bool isAvailable;
};

string toLowerCase(string text) {
    for (char &c : text) {
        c = tolower(static_cast<unsigned char>(c));
    }
    return text;
}

int main() {
    vector<Book> books = {
        {"The Great Gatsby", "F. Scott Fitzgerald", 180, "001", true},
        {"1984", "George Orwell", 328, "002", false},
        {"To Kill a Mockingbird", "Harper Lee", 281, "003", true},
        {"Pride and Prejudice", "Jane Austen", 279, "004", false},
        {"The Catcher in the Rye", "J.D. Salinger", 214, "005", true},
        {"Moby-Dick", "Herman Melville", 635, "006", false},
        {"War and Peace", "Leo Tolstoy", 1225, "007", true},
        {"The Hobbit", "J.R.R. Tolkien", 310, "008", false},
        {"Crime and Punishment", "Fyodor Dostoevsky", 671, "009", true},
        {"Brave New World", "Aldous Huxley", 268, "010", false}
    };

    cout << "Library book status checker\n";
    cout << "Enter a book title, or type 'exit' to quit.\n\n";

    while (true) {
        cout << "Enter book title: ";

        string input;
        getline(cin, input);

        if (!cin) {
            break;
        }

        string searchTitle = toLowerCase(input);

        if (searchTitle == "exit") {
            cout << "Goodbye!\n";
            break;
        }

        bool found = false;

        for (const Book &book : books) {
            if (toLowerCase(book.title) == searchTitle) {
                cout << "\nBook ID: " << book.id << "\n";
                cout << "Title: " << book.title << "\n";
                cout << "Author: " << book.author << "\n";
                cout << "Pages: " << book.pages << "\n";
                cout << "Available: " << (book.isAvailable ? "true" : "false") << "\n\n";
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Book not found. Please try another title.\n\n";
        }
    }

    return 0;
}