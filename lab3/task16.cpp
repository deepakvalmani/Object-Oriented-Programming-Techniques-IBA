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

class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        top = nullptr;
    }

    void push(string val)
    {
        Node *newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    string pop()
    {
        if (isEmpty())
            return " ";

        Node *temp = top;
        string val = top->data;
        top = top->next;
        delete temp;
        return val;
    }

    string peek()
    {
        if (isEmpty())
            return " ";
        return top->data;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    void clear()
    {
        while (!isEmpty())
        {
            pop();
        }
    }

    ~Stack()
    {
        clear();
    }
};

class Queue
{
private:
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = rear = nullptr;
    }

    void enqueue(string val)
    {
        Node *newNode = new Node(val);

        if (isEmpty())
        {
            front = rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }

    string dequeue()
    {
        if (isEmpty())
            return " ";

        Node *temp = front;
        string val = front->data;
        front = front->next;

        if (front == nullptr)
            rear = nullptr;

        delete temp;
        return val;
    }

    string peek()
    {
        if (isEmpty())
            return " ";
        return front->data;
    }

    bool isEmpty()
    {
        return front == nullptr;
    }

    void clear()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }

    ~Queue()
    {
        clear();
    }
};

class Restaurant
{
private:
    Queue kitchenQueue;
    Stack completedStack;

public:
    void placeOrder(string order)
    {
        kitchenQueue.enqueue(order);
    }

    void processOrder()
    {
        if (kitchenQueue.isEmpty())
        {
            cout << "No kitchen orders to process.\n";
            return;
        }

        string order = kitchenQueue.dequeue();
        completedStack.push(order);
    }

    void deliverOrder()
    {
        if (completedStack.isEmpty())
        {
            cout << "No completed orders to deliver.\n";
            return;
        }

        string order = completedStack.pop();
        cout << "Delivered: " << order << endl;
    }

    string getNextKitchenOrder()
    {
        return kitchenQueue.peek();
    }

    string getNextDelivery()
    {
        return completedStack.peek();
    }
};

int main()
{
    Restaurant r;

    r.placeOrder("Pizza");
    r.placeOrder("Pasta");
    r.placeOrder("Salad");

    cout << "Next to cook: " << r.getNextKitchenOrder() << endl;

    r.processOrder();
    r.processOrder();

    cout << "Next to deliver: " << r.getNextDelivery() << endl;

    r.deliverOrder();
    r.deliverOrder();
    r.deliverOrder();

    return 0;
}
