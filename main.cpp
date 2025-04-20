#include <iostream>
#include "DynContainer.h"
#include "Book.h"
#include "Library.h"

using namespace std;

int main()
{

    DynContainer<int> myList; // Create a linked list of integers

    // Insert elements
    myList.insertLast(10);
    myList.insertLast(20);
    myList.insertLast(30);
    myList.insertFirst(5);
    myList.insertAtPosition(2, 15);

    // Print the list
    cout << "List: ";
    myList.print();

    // Search for an element
    int elementToSearch = 20;
    int position = myList.search(elementToSearch);
    if (position != -1)
    {
        cout << elementToSearch << " found at position " << position <<endl;
    }
    else
    {
        cout << elementToSearch << " not found in the list" <<endl;
    }

    // Sort the list
    myList.sortList();
    cout << "Sorted List: ";
    myList.print();

    // Reverse the list
    myList.reverse();
    cout << "Reversed List: ";
    myList.print();

    // Remove elements
    myList.removeLast();
    myList.removeFirst();
    myList.removeAtPosition(1);





    cout<<"***********************************************"<<endl;




    Library lib;

    int choice;
    string title, author, isbn;

    do
    {
        cout << "Library Book Program" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Remove Book" << endl;
        cout << "3. Search Book" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter book title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter book author: ";
            getline(cin, author);
            cout << "Enter book ISBN: ";
            getline(cin, isbn);
            lib.addBook(title, author, isbn);
            break;
        case 2:
            cout << "Enter book ISBN to remove: ";
            cin.ignore();
            getline(cin, isbn);
            lib.removeBook(isbn);
            break;
        case 3:
            cout << "Enter book title to search: ";
            cin.ignore();
            getline(cin, title);
            lib.searchBook(title);
            break;
        case 4:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }
    while (choice != 4);


    return 0;
}
