#ifndef DYNCONTAINER_H
#define DYNCONTAINER_H
#include <iostream>
#include <Node.h>

using namespace std;

template<class t>

class DynContainer
{
private:
    Node<t> *last;
    Node<t> *first;
    int length;
public:
    DynContainer()
    {
        last=first=NULL;
        length=0;
    }
    Node<t>* begin()
    {
        return first;
    }
    Node<t>* end()
    {
        return last;
    }
    Node<t>* prev(Node<t>* current)
    {
        if(current!=nullptr)
            return current->prev;
        else
            return nullptr;
    }
    Node<t>* next(Node<t>* current)
    {
        if(current!=nullptr)
            return current->next;
        else
            return nullptr;
    }
    void insertFirst(t element)
    {
        Node<t>* newNode = new Node<t>;
        newNode->item = element;
        if (length == 0)
        {
            last = first = newNode;
            newNode->next = newNode->prev = NULL;
        }
        else
        {
            newNode->next =first;
            newNode->prev = NULL;
            first->prev=newNode;
            first = newNode;
        }
        length++;
    }
    void insertLast(t element)
    {
        Node<t>* newNode = new Node<t>;
        newNode->item = element;
        if (length == 0)
        {
            last = first = newNode;
            newNode->next = newNode->prev = NULL;
        }
        else
        {
            newNode->next = NULL;
            newNode->prev = last;
            last->next = newNode;
            last = newNode;
        }
        length++;
    }
    void insertAtPosition(int position,t element)
    {
        Node<t>* newNode = new Node<t>;
        newNode->item = element;
        if (position == 0)
        {
            insertFirst(element);
        }
        else if(position==length)
        {
            insertLast(element);
        }
        else
        {
            Node<t> *current=first;
            for(int i=1; i<position; i++)
            {
                current=current->next;
            }
            newNode->next=current->next;
            newNode->prev=current;
            current->next->prev=newNode;
            current->next=newNode;
            length++;
        }

    }
    void removeFirst()
    {
        if(length==0)
        {
            cout<<"Linked List is Empty cannot remove element"<<endl;
        }
        else
        {
            Node<t> *current=first;
            first=first->next;
            first->prev=NULL;
            current->next=current->prev=NULL;
            delete current;
            length--;
        }
    }
    void removeLast()
    {
        if(length==0)
        {
            cout<<"Linked List is Empty cannot remove element"<<endl;
        }
        else
        {
            Node<t> *current=last;
            last=last->prev;
            last->next=NULL;
            current->next=current->prev=NULL;
            delete current;
            length--;
        }
    }
    void removeAtPosition(int position)
    {
        if(position==0)
        {
            removeFirst();
        }
        else if(position==length-1)
        {
            removeLast();
        }
        else
        {
            Node<t> *current=first;
            for(int i=0; i<position; i++)
            {
                current=current->next;
            }
            current->next->prev=current->prev;
            current->prev->next=current->next;
            current->next=current->prev=NULL;
            delete current;
            length--;
        }
    }
    int search(t element)
    {
        Node<t>*current=first;
        for(int i=0; i<length; i++)
        {
            if(current->item==element)
            {
                return i;
            }
            current=current->next;

        }
        return -1;
    }
    void sortList()
    {
        Node<t>*prev=first;
        Node<t>*current=NULL;
        while(prev!=NULL)
        {
            current=prev->next;
            while(current!=NULL)
            {
                if(prev->item>current->item)
                {
                    swap(prev->item,current->item);
                }
                current=current->next;
            }
            prev=prev->next;
        }

    }
    void reverse()
    {
        if(first == NULL)
        {
            cout<<"Linked List is Empty "<<endl;
        }
        else
        {
            Node<t> *prev = first;
            Node<t> *current = first->next;
            Node<t> *next = current->next;
            while(current != NULL)
            {
                if(prev->prev == NULL)
                {
                    prev->prev = current;
                    prev->next = NULL;
                    last = prev;
                }
                current->next = prev;
                current->prev= next;
                prev = current;
                current = next;
                if(next != NULL)
                {
                    next = next->next;
                }
            }
            first = prev;
        }
    }
    void print()
    {
        Node<t>* temp = first;
        cout<<"[";
        while (temp != NULL)
        {
            cout << temp->item << " ";
            temp = temp->next;
        }
        cout<<"]"<<endl;
    }
};
#endif // DYNCONTAINER_H
