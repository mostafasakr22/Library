#ifndef LIBRARY_H
#define LIBRARY_H
#include <iostream>
#include <Book.h>
#include <DynContainer.h>
using namespace std;
class Library
{
public:
    Book* head;

    Library()
    {
        head = 0;
    }

    // Function to add a book to the linked list
    void addBook(string title, string author, string isbn)
    {
        Book* newBook = new Book(title, author, isbn);
        if (head == 0)
        {
            head = newBook;
        }
        else
        {
            Book* current = head;
            while (current->next != 0)
            {
                current = current->next;
            }
            current->next = newBook;
        }
        cout << "Book added successfully!" << endl;
    }

    // Function to remove a book from the linked list
    void removeBook(string isbn)
    {
        if (head == 0)
        {
            cout << "Library is empty." << endl;
            return;
        }
        if (head->isbn == isbn)
        {
            Book* temp = head;
            head = head->next;
            delete temp;
            cout << "Book removed successfully!" << endl;
            return;
        }
        Book* current = head;
        while (current->next != 0)
        {
            if (current->next->isbn == isbn)
            {
                Book* temp = current->next;
                current->next = temp->next;
                delete temp;
                cout << "Book removed successfully!" << endl;
                return;
            }
            current = current->next;
        }
        cout << "Book not found." << endl;
    }

    // Function to search for a book in the linked list
    void searchBook(string title)
    {
        if (head == 0)
        {
            cout << "Library is empty." << endl;
            return;
        }
        Book* current = head;
        while (current != 0)
        {
            if (current->title == title)
            {
                cout << "Book found!" << endl;
                cout << "Title: " << current->title << endl;
                cout << "Author: " << current->author << endl;
                cout << "ISBN: " << current->isbn << endl;
                return;
            }
            current = current->next;
        }
        cout << "Book not found." << endl;
    }

    // Function to print all books in the library
    void printLibrary()
    {
        if (head == 0)
        {
            cout << "Library is empty." << endl;
            return;
        }
        Book* current = head;
        while (current != 0)
        {
            cout << "Title: " << current->title << endl;
            cout << "Author: " << current->author << endl;
            cout << "ISBN: " << current->isbn << endl;
            cout << "---------------------------" << endl;
            current = current->next;
        }
    }
};

#endif // LIBRARY_H
