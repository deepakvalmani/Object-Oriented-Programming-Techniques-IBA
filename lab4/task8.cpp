#include <iostream>
using namespace std;

class Plane
{

public:
    string FlightNumber;
    string OptType;
    int priority;
    string ArivalTime;

    Plane()
    {
    }
    
    Plane(string FlightNumber, string OptType, int priority, string ArivalTime)
    {
        this->FlightNumber = FlightNumber;
        this->OptType = OptType;
        this->priority = priority;
        this->ArivalTime = ArivalTime;
    }
};

class Node
{
public:
    Plane data;
    Node *next;

    Node(Plane p)
    {
        data = p;
        next = nullptr;
    }
};

class Stack
{

    Node *TopNode;

public:
    Stack()
    {
        TopNode = nullptr;
    }

    bool IsEmpty()
    {
        return TopNode == nullptr;
    }

    void push(Plane p)
    {
        Node *NewNode = new Node(p);
        NewNode->next = TopNode;
        TopNode = NewNode;
    }

    Plane top()
    {
        if (IsEmpty())
        {
            return Plane("None", "None", -1, "None");
        }
        return TopNode->data;
    }

    void pop()
    {
        if (IsEmpty())
        {
            cout << "Empty" << endl;
            return;
        }
        Node *temp = TopNode;
        TopNode = TopNode->next;
        delete temp;
    }

    void display()
    {
        if (IsEmpty())
        {
            cout << "Empty" << endl;
            return;
        }
        else
        {
            Node *temp = TopNode;
            while (temp->next != nullptr)
            {
                cout << "Fligh NO: " << temp->data.FlightNumber << " Arrival Time : " << temp->data.ArivalTime << endl;
                temp = temp->next;
            }
        }
    }

    ~Stack()
    {
        while (!IsEmpty())
        {
            pop();
        }
    }
};

class PriorityQueue
{

    Node *head;

public:
    PriorityQueue()
    {
        head = nullptr;
    }

    bool IsEmpty()
    {
        return head == nullptr;
    }

    void enqueue(Plane p)
    {
        Node *NewNode = new Node(p);

        if (head == nullptr || p.priority > head->data.priority)
        {

            NewNode->next = head;
            head = NewNode;
            return;
        }
        Node *temp = head;
        while (temp->next == nullptr && temp->next->data.priority >= p.priority)
        {
            temp = temp->next;
        }
        NewNode->next = temp->next;
        temp->next = NewNode;
    }
    Plane top()
    {
        if (IsEmpty())
        {
            return Plane("None", "None", -1, "None");
        }
        return head->data;
    }

    void dequeue()
    {
        if (IsEmpty())
        {
            cout << "Empty" << endl;
            return;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void display()
    {
        if (IsEmpty())
        {
            cout << "Empty" << endl;
            return;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                cout << "Fligh NO: " << temp->data.FlightNumber << " Priority: " << temp->data.priority << " Arrival Time: " << temp->data.ArivalTime << endl;
                temp = temp->next;
            }
        }
    }

    ~PriorityQueue()
    {
        while (!IsEmpty())
        {
            dequeue();
        }
    }
};

class Airport
{
    Stack takeoffstack;
    PriorityQueue EmergencyLandingQueue;

public:
    Airport()
    {
    }
    void takeoff(string FlightNumber, string time)
    {
        Plane p(FlightNumber, "TakeOff", 0, time);
        takeoffstack.push(p);
    }

    void EmergencyLanding(string FlightNumber, int priority, string time)
    {
        Plane p(FlightNumber, "TakeOff", priority, time);
        EmergencyLandingQueue.enqueue(p);
    }

    void nextAction()
    {
        if (!EmergencyLandingQueue.IsEmpty())
        {
            Plane p = EmergencyLandingQueue.top();
            EmergencyLandingQueue.dequeue();
            cout << "LAND: " << p.FlightNumber << " (Priority: " << p.priority << ", " << p.ArivalTime << ")" << endl;
        }
        else if (!takeoffstack.IsEmpty())
        {
            Plane p = takeoffstack.top();
            takeoffstack.pop();
            cout << "TAKEOFF: " << p.FlightNumber << " (" << p.ArivalTime << ")" << endl;
        }
        else
        {
            cout << "No planes in system." << endl;
        }
    }

    void showTakeoffStack()
    {
        cout << "\nTakeoff Stack:\n";
        takeoffstack.display();
    }

    void showLandingQueue()
    {
        cout << "\nEmergency Landing Queue:\n";
        EmergencyLandingQueue.display();
    }
};

int main()
{
    Airport airport;

    cout << "Adding takeoff planes...\n";
    airport.takeoff("AB123", "10:00 AM");
    airport.takeoff("CD456", "10:05 AM");
    airport.takeoff("EF789", "10:10 AM");

    cout << "\nAdding emergency landing planes...\n";
    airport.EmergencyLanding("GH101", 9, "10:02 AM");
    airport.EmergencyLanding("IJ202", 10, "10:06 AM");
    airport.EmergencyLanding("KL303", 8, "10:09 AM");

    cout << "\nCurrent Takeoff Stack:\n";
    airport.showTakeoffStack();

    cout << "\nCurrent Emergency Landing Queue:\n";
    airport.showLandingQueue();

    cout << "\nNext Actions:\n";
    airport.nextAction();
    airport.nextAction();
    airport.nextAction();
    airport.nextAction();
    airport.nextAction();
    airport.nextAction();

    return 0;
}
