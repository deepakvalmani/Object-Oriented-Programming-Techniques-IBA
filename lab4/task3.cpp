#include <iostream>

using namespace std;

class Node
{
public:
    char data;
    Node *next;

    Node(char val)
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
    void pushFront(char val)
    {
        Node *NewNode = new Node(val);
        NewNode->next = head;
        head = NewNode;
    }

    char front()
    {
        if (Isempty())
        {
            cout << "List is empty!\n";
            return -1;
        }
        return head->data;
    }

    char back()
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

    void pushBack(char val)
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

    void Delete(char ch)
    {

        if (Isempty())
        {
            cout << "Empty" << endl;
            return;
        }
        else
        {
            Node *curr = head;
            Node *prev = nullptr;
            while (curr->data != ch && curr->next != nullptr)
            {
                prev = curr;
                curr = curr->next;
            }

            if (curr == head && curr->data == head->data)
            {

                head = head->next;
                delete curr;
            }
            else
            {
                prev->next = curr->next;
                delete curr;
            }
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

int main()
{

    linkedlist list_arr;
    char arr[3] = {'A', 'C', 'E'};

    list_arr.pushBack('A');
    list_arr.pushBack('B');
    list_arr.pushBack('C');
    list_arr.pushBack('D');
    list_arr.pushBack('E');
    list_arr.pushBack('F');
    cout << "Linked List Before deleting..." << endl;

    list_arr.print();

    for (int i = 0; i < 3; i++)
    {
        list_arr.Delete(arr[i]);
    }
    cout << "Linked List After deleting. ";
    for (int i = 0; i < 3; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    list_arr.print();
    return 0;
}