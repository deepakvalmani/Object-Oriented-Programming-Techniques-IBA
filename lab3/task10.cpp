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

class LLStack
{
private:
    Node *head;

public:
    LLStack()
    {
        head = nullptr;
    }

    LLStack(int val)
    {
        head = new Node(val);
    }
    LLStack(LLStack &other)
    {
        head = nullptr;

        if (other.head == nullptr)
        {
            return;
        }
        Node *Other_temp = other.head;
        Node *prev = nullptr;

        while (Other_temp != nullptr)
        {
            Node *new_Node = new Node(Other_temp->data);

            if (head == nullptr)
            {
                head = new_Node;
            }
            else
            {
                prev->next = new_Node;
            }
            prev = new_Node;
            Other_temp = Other_temp->next;
        }
    }

    void push(int val)
    {
        Node *NewNode = new Node(val);
        if (head == nullptr)
        {
            head = NewNode;
            return;
        }
        else
        {
            NewNode->next = head;
            head = NewNode;
        }
        cout << "Pushed " << val << endl;
    }

    void print()
    {
        if (Isempty())
        {
            cout << "Stack is Empty." << endl;
            return;
        }

        Node *temp = head;

        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout<<endl;
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
            cout << "poped " << head->data << endl;
            head = head->next;

            delete temp;
        }
    }

    ~LLStack()
    {
        while (!Isempty())
        {
            pop();
        }
    }
};

int main() {
    cout << "Copy Constructor Test\n\n";
    
    // original stack
    LLStack original;
    original.push(10);
    original.push(20);
    original.push(30);
    
    cout << "Original stack after pushing 10, 20, 30:\n";
    original.print();
    cout << endl;
    
    //copy using copy constructor
    LLStack copy = original;
    
    
    cout << "Copied stack (should be same as original):\n";
    copy.print();
    cout << endl;
    
    //  independence
    cout << "Testing independence...\n";
    
    cout << "Modifying original - pushing 40:\n";
    original.push(40);
    cout << "Original now: ";
    original.print();
    cout << "Copy should be unchanged: ";
    copy.print();
    cout << endl;
    
    cout << "Modifying copy - popping once:\n";
    copy.pop();
    cout << "Copy now: ";
    copy.print();
    cout << "Original should be unchanged: ";
    original.print();
    cout << endl;
    
    //copy of empty stack
    cout << "Testing copy of empty stack:\n";
    LLStack empty;
    LLStack emptyCopy = empty;
    
    cout << "Is empty original empty? " << (empty.Isempty() ? "Yes" : "No") << endl;
    cout << "Is empty copy empty? " << (emptyCopy.Isempty() ? "Yes" : "No") << endl;
    
    return 0;
}