#pragma once
#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    int year;
    string isbn;

public:
    Book() {
        title = "";
        author = "";
        year = 0;
        isbn = "";
    }

    Book(string t, string a, int y, string i) {
        title = t;
        author = a;
        year = y;
        isbn = i;
    }

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    int getYear() const { return year; }
    string getIsbn() const { return isbn; }

    void setTitle(string t) { title = t; }
    void setAuthor(string a) { author = a; }
    void setYear(int y) { year = y; }
    void setIsbn(string i) { isbn = i; }

    void displayInfo() const {
        cout << "Название: " << title << endl;
        cout << "Автор: " << author << endl;
        cout << "Год издания: " << year << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "------------------------" << endl;
    }
};