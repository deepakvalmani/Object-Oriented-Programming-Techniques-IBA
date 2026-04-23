#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int job_Id;
    string data;
    Node *next;

    Node(int id, string val)
    {
        job_Id = id;
        data = val;
        next = nullptr;
    }
};

class linkedlist
{

private:
    Node *head;
    Node *tail;

public:
    linkedlist()
    {
        head = nullptr;
        tail = nullptr;
    }

    int frontId()
    {
        if (Isempty())
        {
            cout << "List is empty!\n";
            return -1;
        }
        return head->job_Id;
    }

    string frontJob()
    {
        if (Isempty())
        {
            cout << "List is empty!\n";
            return " ";
        }
        return head->data;
    }

    int backId()
    {
        if (Isempty())
        {
            cout << "List is empty!\n";
            return -1;
        }
        return tail->job_Id;
    }

    string backJob()
    {
        if (Isempty())
        {
            cout << "List is empty!\n";
            return " ";
        }
        return tail->data;
    }

    void reverse()
    {
        Node *prev = nullptr;
        Node *current = head;
        Node *next = nullptr;

        tail = head;

        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    void push(int id, string val)
    {
        Node *NewNode = new Node(id, val);

        if (head == nullptr)
        {
            head = NewNode;
            tail = NewNode;
            return;
        }

        tail->next = NewNode;
        tail = NewNode;
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
            cout << temp->job_Id << " " << temp->data << " ";
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

            if (head == nullptr)
            {
                tail = nullptr;
            }
        }
    }

    bool removeById(int id)
    {
        if (Isempty())
            return false;

        if (head->job_Id == id)
        {
            pop();
            return true;
        }

        Node *prev = head;
        Node *curr = head->next;

        while (curr != nullptr)
        {
            if (curr->job_Id == id)
            {
                prev->next = curr->next;

                if (curr == tail)
                {
                    tail = prev;
                }

                delete curr;
                return true;
            }
            prev = curr;
            curr = curr->next;
        }
        return false;
    }

    ~linkedlist()
    {
        while (!Isempty())
        {
            pop();
        }
    }
};

class Queue
{
    linkedlist my_queue;

public:
    void enqueue(int id, string ch)
    {
        my_queue.push(id, ch);
    }
    string dequeue()
    {
        string ch = my_queue.frontJob();
        my_queue.pop();
        return ch;
    }
    void print()
    {
        my_queue.print();
    }
    string peek()
    {
        return my_queue.frontJob();
    }
    int peekId()
    {
        return my_queue.frontId();
    }
    bool IsEmpty()
    {
        return my_queue.Isempty();
    }
    bool remove(int jobId)
    {
        return my_queue.removeById(jobId);
    }
    void clear()
    {
        while (!my_queue.Isempty())
        {
            my_queue.pop();
        }
    }
};

class Job_System
{

public:
    Queue jobs;

    void enqueue(int id, string job)
    {
        jobs.enqueue(id, job);
    }
    void dequeue()
    {
        jobs.dequeue();
    }

    string peek()
    {
        return jobs.peek();
    }

    int peekId()
    {
        return jobs.peekId();
    }

    void remove(int jobId)
    {
        jobs.remove(jobId);
    }
    bool IsEmpty()
    {
        return jobs.IsEmpty();
    }
};

int main()
{
    Job_System js;

    js.enqueue(101, "Print Assignment");
    js.enqueue(102, "Print Resume");
    js.enqueue(103, "Print Report");

    cout << "Queue: ";
    js.jobs.print();

    cout << "\nNext Job ID: " << js.peekId() << endl;
    cout << "Next Job: " << js.peek() << endl;

    js.dequeue();

    cout << "\nAfter Dequeue: ";
    js.jobs.print();

    js.remove(103);

    cout << "\nAfter Removing Job 103: ";
    js.jobs.print();

    return 0;
}
