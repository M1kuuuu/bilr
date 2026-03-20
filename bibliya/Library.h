#pragma once
#include "Book.h"
#include <vector>

class Library {
private:
    vector<Book> books;

public:
    Library() {}

    void addBook(const Book& book) {
        books.push_back(book);
        cout << "Книга \"" << book.getTitle() << "\" добавлена в библиотеку!" << endl;
    }

    bool removeBook(const string& isbn) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->getIsbn() == isbn) {
                cout << "Книга \"" << it->getTitle() << "\" удалена из библиотеки!" << endl;
                books.erase(it);
                return true;
            }
        }
        cout << "Книга с ISBN " << isbn << " не найдена!" << endl;
        return false;
    }

    Book* findBookByTitle(const string& title) {
        for (auto& book : books) {
            if (book.getTitle() == title) {
                return &book;
            }
        }
        return nullptr;
    }

    void displayAllBooks() const {
        if (books.empty()) {
            cout << "Библиотека пуста!" << endl;
            return;
        }

        cout << "\n=== ВСЕ КНИГИ В БИБЛИОТЕКЕ ===" << endl;
        cout << "Всего книг: " << books.size() << endl;
        cout << "------------------------" << endl;

        for (const auto& book : books) {
            book.displayInfo();
        }
    }

    int getBookCount() const {
        return books.size();
    }

    void clearLibrary() {
        books.clear();
        cout << "Библиотека очищена!" << endl;
    }
};