#include <iostream>
using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node<T> *next;

public:
    Node(T val)
    {
        data = val;
        next = nullptr;
    }
};
template <class T>
class Linkedlist
{
    Node<T> *head;

public:
    Linkedlist()
    {
        head = nullptr;
    }

    void insert(T val)
    {
        Node<T> *newnode = new Node<T>(val);
        if (head == nullptr)
        {
            head = newnode;
        }
        else
        {
            Node<T> *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }
    void display()
    {
        if (head == nullptr)
        {
            throw "linked list is Empty";
        }
        else
        {
            Node<T> *temp = head;
            while (temp != nullptr)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
    }
    void deleteNode(T val)
    {
        if (head == nullptr)
        {
            throw "Linked list is empty";
        }

        Node<T> *current = head;
        Node<T> *previous = nullptr;
        if (current->data == val)
        {
            head = head->next;
            delete current;
            return;
        }
        while (current != nullptr && current->data != val)
        {
            previous = current;
            current = current->next;
        }
        if (current == nullptr)
            throw "not found";
        previous->next = current->next;
        delete current;
    }
};
int main()
{
    try
    {
        Linkedlist<int> L;

        L.insert(10);
        L.insert(20);
        L.insert(30);
        L.insert(40);
        L.display();
        cout << endl;
        L.deleteNode(20);
        cout << "After deletion: ";
        L.display();
    }
    catch (const char *msg)
    {
        cout << "Exception: " << msg << endl;
    }
    return 0;
}