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

    
    void printReverseRecursive(Node *node)
    {
        if (node == nullptr)
            return;

        printReverseRecursive(node->next); 
        cout << node->data << " ";        
    }

public:
    linkedlist()
    {
        head = nullptr;
    }

    void push(int val)
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
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void printReverse()
    {
        printReverseRecursive(head);
        cout << endl;
    }

    bool Isempty()
    {
        return head == nullptr;
    }

    ~linkedlist()
    {
        while (!Isempty())
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main()
{
    linkedlist ll;

    ll.push(1);
    ll.push(2);
    ll.push(3);
    ll.push(4);
    ll.push(5);

    cout << "Original Linked List: ";
    ll.print();

    cout << "Linked List in Reverse (Recursive): ";
    ll.printReverse(); 

    return 0;
}
