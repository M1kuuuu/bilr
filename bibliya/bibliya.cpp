#include <iostream>
#include <limits>
#include "Library.h"

using namespace std;

void clearScreen() {
    system("cls");
}

void pause() {
    cout << "\nНажмите Enter для продолжения...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

int main() {
    setlocale(0, "");
    Library myLibrary;
    int choice;

    do {
        clearScreen();
        cout << "=== БИБЛИОТЕКА (проект bibliya) ===" << endl;
        cout << "1. Добавить книгу" << endl;
        cout << "2. Удалить книгу по ISBN" << endl;
        cout << "3. Найти книгу по названию" << endl;
        cout << "4. Показать все книги" << endl;
        cout << "5. Показать количество книг" << endl;
        cout << "6. Очистить библиотеку" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            string title, author, isbn;
            int year;

            cout << "\n--- Добавление новой книги ---" << endl;
            cout << "Введите название: ";
            getline(cin, title);
            cout << "Введите автора: ";
            getline(cin, author);
            cout << "Введите год издания: ";
            cin >> year;
            cin.ignore();
            cout << "Введите ISBN: ";
            getline(cin, isbn);

            Book newBook(title, author, year, isbn);
            myLibrary.addBook(newBook);
            pause();
            break;
        }

        case 2: {
            string isbn;
            cout << "\n--- Удаление книги ---" << endl;
            cout << "Введите ISBN книги для удаления: ";
            getline(cin, isbn);
            myLibrary.removeBook(isbn);
            pause();
            break;
        }

        case 3: {
            string title;
            cout << "\n--- Поиск книги ---" << endl;
            cout << "Введите название книги: ";
            getline(cin, title);

            Book* foundBook = myLibrary.findBookByTitle(title);
            if (foundBook != nullptr) {
                cout << "\nКнига найдена!" << endl;
                foundBook->displayInfo();
            }
            else {
                cout << "Книга \"" << title << "\" не найдена!" << endl;
            }
            pause();
            break;
        }

        case 4: {
            myLibrary.displayAllBooks();
            pause();
            break;
        }

        case 5: {
            cout << "\nКоличество книг в библиотеке: " << myLibrary.getBookCount() << endl;
            pause();
            break;
        }

        case 6: {
            myLibrary.clearLibrary();
            pause();
            break;
        }

        case 0:
            cout << "\nДо свидания!" << endl;
            break;

        default:
            cout << "\nНеверный выбор! Попробуйте снова." << endl;
            pause();
        }
    } while (choice != 0);

    return 0;
}