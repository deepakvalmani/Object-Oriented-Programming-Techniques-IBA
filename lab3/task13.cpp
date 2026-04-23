#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string data;
    Node *next;

    Node(string val)
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
    void pushFront(string val)
    {
        Node *NewNode = new Node(val);
        NewNode->next = head;
        head = NewNode;
    }

    string front()
    {
        if (Isempty())
        {
            cout << "List is empty!\n";
            return " ";
        }
        return head->data;
    }

    string back()
    {
        if (Isempty())
        {
            cout << "List is empty!\n";
            return " ";
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

    void push(string val)
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
        Node *temp;
        temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    bool Isempty()
    {
        return head == nullptr;
    }

    void pop()
    {
        if (Isempty())
        {
            cout << "List is Empty." << endl;
        }
        else
        {
            Node *temp = head;

            head = head->next;
            delete temp;
        }
    }

    ~linkedlist()
    {
        while (!Isempty())
        {
            pop();
        }
    }
};

class Stack
{
private:
    linkedlist my_stack;

public:
    void push(string ch)
    {
        my_stack.pushFront(ch);
    }

    string pop()
    {
        string ch = my_stack.front();
        my_stack.pop();
        return ch;
    }

    void print()
    {
        my_stack.print();
    }
    string peek()
    {
        return my_stack.front();
    }
    bool IsEmpty()
    {
        return my_stack.Isempty();
    }
    void clear()
    {
        while (!my_stack.Isempty())
        {
            my_stack.pop();
        }
    }
};

class BrowserHist
{
    Stack my_browser_hist;

public:
    void push(string str)
    {
        my_browser_hist.push(str);
    }
    void pop()
    {
        if (my_browser_hist.IsEmpty())
        {
            cout << "Nothing to go back.\n";
            return;
        }
        my_browser_hist.pop();
    }

    string peek()
    {
        return my_browser_hist.peek();
    }

    bool IsEmpty()
    {
        return my_browser_hist.IsEmpty();
    }

    void clear()
    {
        my_browser_hist.clear();
    }
};

int main()
{
    BrowserHist history;

    history.push("google.com");
    history.push("youtube.com");
    history.push("github.com");

    cout << "Current: " << history.peek() << endl;

    history.pop();
    cout << "After back: " << history.peek() << endl;

    history.pop();
    cout << "After back: " << history.peek() << endl;

    history.push("stackoverflow.com");
    cout << "New page: " << history.peek() << endl;

    return 0;
}
