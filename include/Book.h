#ifndef BOOK_H
#define BOOK_H
#include <iostream>
using namespace std;

class Book {
public:
    string title;
    string author;
    string isbn;
    Book* next;

    Book(string title, string author, string isbn) {
        this->title = title;
        this->author = author;
        this->isbn = isbn;
        this->next = 0;
    }
};

#endif // BOOK_H
