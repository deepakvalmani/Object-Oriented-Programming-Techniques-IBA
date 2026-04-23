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

public:
    Node *head;
    linkedlist()
    {
        head = nullptr;
    }
    void pushFront(int val)
    {
        Node *NewNode = new Node(val);
        NewNode->next = head;
        head = NewNode;
    }

    int front()
    {
        if (Isempty())
        {
            cout << "List is empty!\n";
            return -1;
        }
        return head->data;
    }

    int back()
    {
        if (Isempty())
        {
            cout << "List is empty!\n";
            return -1;
        }

        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        return temp->data;
    }

    void reverse()
    {
        Node *prev = nullptr;
        Node *current = head;
        Node *next = nullptr;

        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    void pushBack(int val)
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
        if (Isempty())
        {
            cout << "List is Empty." << endl;
            return;
        }
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    bool Isempty()
    {
        return head == nullptr;
    }

    void popFront()
    {
        if (Isempty())
        {
            cout << "Empty." << endl;
            return;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
    void popBack()
    {
        if (Isempty())
        {
            cout << "Empty." << endl;
            return;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            delete temp;
        }
    }

    ~linkedlist()
    {
        while (!Isempty())
        {
            popBack();
        }
    }
};

class Queue
{
public:
    linkedlist my_queue;

    void enqueue(int val)
    {
        my_queue.pushBack(val);
    }
    void dequeue()
    {
        my_queue.popBack();
    }
    void moveNthToFront(int n)
    {
        if (my_queue.head == nullptr || n <= 0)
            return;

        if (n == 1)
            return;

        Node *prev = nullptr;
        Node *curr = my_queue.head;

        for (int i = 1; i < n && curr != nullptr; i++)
        {
            prev = curr;
            curr = curr->next;
        }

        if (curr == nullptr)
            return;

        prev->next = curr->next;

        curr->next = my_queue.head;
        my_queue.head = curr;
    }

    void print()
    {
        my_queue.print();
    }
};

int main()
{
    Queue q;
    q.enqueue(5);
    q.enqueue(11);
    q.enqueue(34);
    q.enqueue(67);
    q.enqueue(43);
    q.enqueue(55);
    q.print();
    q.moveNthToFront(3);
    q.print();
}