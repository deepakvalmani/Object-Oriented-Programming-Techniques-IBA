#include <iostream>
using namespace std;

class Patient
{
public:
    string name;
    int arrival_time;
    int severity_level;
    string arrival_string;

    Patient() {}

    Patient(string n, int h, int m, string ampm, int s)
    {
        name = n;
        arrival_time = convertToMinutes(h, m, ampm);
        severity_level = s;
        arrival_string = to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m) + " " + ampm;
    }

    void print()
    {
        cout << name << " (Severity: " << severity_level << ", Arrival: " << arrival_string << ")" << endl;
    }
    int convertToMinutes(int hour, int minute, string ampm)
    {
        if (ampm == "PM" && hour != 12)
            hour += 12;
        if (ampm == "AM" && hour == 12)
            hour = 0;
        return hour * 60 + minute;
    }
};

class Node
{
public:
    Patient data;
    Node *next;

    Node(Patient val)
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

    bool Isempty()
    {
        return head == nullptr;
    }

    Patient front()
    {
        if (Isempty())
        {
            return Patient();
        }
        return head->data;
    }

    void popFront()
    {
        if (Isempty())
            return;

        Node *temp = head;
        head = head->next;
        delete temp;
    }

    ~linkedlist()
    {
        while (!Isempty())
        {
            popFront();
        }
    }
};

class Emergency_Queue
{
    linkedlist ER_Queue;

public:
    void Add_Patient(string n, int h, int m, string ampm, int s)
    {
        Patient p(n, h, m, ampm, s);
        Node *NewNode = new Node(p);

        if (ER_Queue.head == nullptr)
        {
            ER_Queue.head = NewNode;
            return;
        }

        if (NewNode->data.severity_level > ER_Queue.head->data.severity_level ||
            (NewNode->data.severity_level == ER_Queue.head->data.severity_level &&
             NewNode->data.arrival_time < ER_Queue.head->data.arrival_time))
        {
            NewNode->next = ER_Queue.head;
            ER_Queue.head = NewNode;
            return;
        }

        Node *temp = ER_Queue.head;

        while (temp->next != nullptr &&
               (temp->next->data.severity_level > NewNode->data.severity_level ||
                (temp->next->data.severity_level == NewNode->data.severity_level &&
                 temp->next->data.arrival_time <= NewNode->data.arrival_time)))
        {
            temp = temp->next;
        }

        NewNode->next = temp->next;
        temp->next = NewNode;
    }

    void treat()
    {
        if (ER_Queue.Isempty())
        {
            cout << "No patients in queue.\n";
            return;
        }

        cout << "Treating: ";
        ER_Queue.head->data.print();
        ER_Queue.popFront();
    }

    void peek()
    {
        if (ER_Queue.Isempty())
        {
            cout << "No patients in queue.\n";
            return;
        }

        cout << "Next patient: ";
        ER_Queue.head->data.print();
    }

    bool empty()
    {
        return ER_Queue.Isempty();
    }
};

int main()
{
    Emergency_Queue ER;

    ER.Add_Patient("Ali", 10, 2, "AM", 9);
    ER.Add_Patient("Sara", 10, 6, "AM", 10);
    ER.Add_Patient("Ahmed", 10, 9, "AM", 8);
    ER.Add_Patient("Hina", 10, 3, "AM", 9);

    ER.peek();

    cout << "\nTreating Order:\n";
    while (!ER.empty())
    {
        ER.treat();
    }

    return 0;
}
