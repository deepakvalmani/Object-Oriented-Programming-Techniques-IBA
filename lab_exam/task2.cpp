#include <iostream>
using namespace std;

class SinglyLinkedList
{
    struct Node
    {
        int val;
        Node *next;
        Node(int v)
        {
            val = v;
            next = nullptr;
        }
    };

    Node *head;

public:
    SinglyLinkedList()
    {
        head = nullptr;
    }

    void pushFront(int value)
    {
        Node *N_Node = new Node(value);

        {
            N_Node->next = head;
            head = N_Node;
        }
    }
    bool is_empty()
    {
        return head == nullptr;
    };

    int popFront()
    {
        if (is_empty())
        {
            throw "out_of_range";
        }
        Node *temp = head;
        int val = temp->val;
        head = head->next;
        delete temp;
        return val;
    }

    void insertAt(int value, int index)
    {
        if (is_empty())
        {

            cout << "can not insert at " << index << endl;
            return;
        }
        Node *N_Node = new Node(value);
        Node *temp = head;
        for (int i = 0; i < index; i++)
        {
            if (temp->next == nullptr)
            {
                cout << "can not insert \n";
                return;
            }
            temp = temp->next;
        }
        N_Node->next = temp->next;
        temp->next = N_Node;
    }

    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    Node *reorderOddEven(Node *head)
    {
        Node *odd = head;
        Node *even = head->next;
        Node *even_head = even;
        while (even != nullptr && even->next != nullptr)
        {
            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }
        odd->next = even_head;
        return head;
    }
    void applyreorder()
    {
        head = reorderOddEven(head);
    }

    ~SinglyLinkedList()
    {
        while (!is_empty())
        {
            popFront();
        }
    }
};

int main()
{
    SinglyLinkedList list;
    list.pushFront(3);
    list.pushFront(4);
    list.pushFront(5);
    list.pushFront(6);
    list.pushFront(7);
    list.pushFront(8);
    list.pushFront(9);

    list.display();
    cout << "reordered: ";
    list.applyreorder();
    list.display();

    return 0;
}