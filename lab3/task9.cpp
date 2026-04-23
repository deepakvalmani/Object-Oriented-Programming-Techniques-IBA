#include <iostream>
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class linkedlist
{

private:
    Node *head;

public:
    linkedlist()
    {
        head = nullptr;
        
    }

    void reverse()
    {
        Node *prev = nullptr;
        Node *current = head;
        Node *next = nullptr;

        while (current != nullptr)
        {
            next = current->next; // Store the next node
            current->next = prev; // Reverse the current node's pointer
            prev = current;       // Move prev to the current node
            current = next;       // Move to the next node
        }
        head = prev; // Update head to the new front of the list
    }

    void append(int val)
    {
        Node *NewNode = new Node(val);
        if (head == nullptr)
        {
            head = NewNode;
            return;
        }

        Node *temp = head;

        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = NewNode;
    }


    void print()
    {
        Node *temp;
        temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        delete temp;
    }


       bool Isempty()
    {
        return head == nullptr;
    }

    void pop()
    {
        if (Isempty())
        {
            cout << "Stack is Empty." << endl;
        }
        else
        {
            Node *temp = head;
            
            head = head->next;

            delete temp;
        }
    }

    ~linkedlist(){
        while (!Isempty())
        {
            pop();
        }
    }


};

int main()
{

    linkedlist ll;
    ll.append(4);
    ll.append(5);
    ll.append(6);
    ll.print();
    ll.reverse();
    cout << endl;
    ll.print(); 

    return 0;
}