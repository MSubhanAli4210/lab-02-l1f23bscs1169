#include <iostream>
using namespace std;

class Publication {
protected:
    string title;

public:
    Publication(string t) : title(t) {}

    virtual void display() const = 0;

    string getTitle() const { return title; }
};

class Book : public Publication {
private:
    string author;
    int pages;

public:
    Book() : Publication(""), author(""), pages(0) {}

    Book(string t, string a, int p)
        : Publication(t), author(a), pages(p) {}

    void display() const override {
        cout << "Book: " << title << " by " << author << " - " << pages << " pages\n";
    }

    int getPages() const { return pages; }
};

class Newspaper : public Publication {
private:
    string date;
    string edition;

public:
    Newspaper() : Publication(""), date(""), edition("") {}

    Newspaper(string t, string d, string e)
        : Publication(t), date(d), edition(e) {}

    void display() const override {
        cout << "Newspaper: " << title << " - " << date << " (" << edition << ")\n";
    }

    string getEdition() const { return edition; }
};

class Library {
private:
    Book books[10];
    Newspaper newspapers[10];
    int bookCount, newspaperCount;

public:
    Library() : bookCount(0), newspaperCount(0) {}

    void addBook(const Book& book) {
        if (bookCount < 10) {
            books[bookCount++] = book;
        }
    }

    void addNewspaper(const Newspaper& newspaper) {
        if (newspaperCount < 10) {
            newspapers[newspaperCount++] = newspaper;
        }
    }

    void displayCollection() const {
        cout << "\nBooks:\n";
        for (int i = 0; i < bookCount; i++) {
            books[i].display();
        }
        cout << "\nNewspapers:\n";
        for (int i = 0; i < newspaperCount; i++) {
            newspapers[i].display();
        }
    }

    Book* searchBookByTitle(string t) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i].getTitle() == t) {
                return &books[i];
            }
        }
        return nullptr;
    }

    Newspaper* searchNewspaperByName(string t) {
        for (int i = 0; i < newspaperCount; i++) {
            if (newspapers[i].getTitle() == t) {
                return &newspapers[i];
            }
        }
        return nullptr;
    }
};

int main() {
    Book book1("Ali's Journey", "Ali", 200);
    Book book2("Ahmad's World", "Ahmad", 250);
    Book book3("Aliya's Story", "Aliya", 300);

    Newspaper newspaper1("Daily News", "2025-03-24", "Morning Edition");
    Newspaper newspaper2("City Times", "2025-03-24", "Evening Edition");
    Newspaper newspaper3("The Weekly Journal", "2025-03-24", "Special Edition");

    Library library;

    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);
    library.addNewspaper(newspaper1);
    library.addNewspaper(newspaper2);
    library.addNewspaper(newspaper3);

    cout << "Library Collection:\n";
    library.displayCollection();

    Book* foundBook = library.searchBookByTitle("Ali's Journey");
    if (foundBook) {
        cout << "\nFound Book:\n";
        foundBook->display();
    }
    else {
        cout << "\nBook not found.\n";
    }

    Newspaper* foundNewspaper = library.searchNewspaperByName("City Times");
    if (foundNewspaper) {
        cout << "\nFound Newspaper:\n";
        foundNewspaper->display();
    }
    else {
        cout << "\nNewspaper not found.\n";
    }

    return 0;
}
