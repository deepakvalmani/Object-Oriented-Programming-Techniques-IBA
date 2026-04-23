#include <iostream>
using namespace std;

class Player
{
private:
    int id;
    string name;
    int level;
    string type;
    int arrival_order;

public:
    Player(int i, string n, int l, string t, int ao)
    {
        id = i;
        name = n;
        level = l;
        type = t;
        arrival_order = ao;
    }
    int getid() { return id; }
    string getname() { return name; }
    int getlevel() { return level; }
    string gettype() { return type; }
    int getarrval() { return arrival_order; }
    void setlevel(int l) { level = l; }
};

class node
{
public:
    Player *data;
    node *next;
    node(Player *p)
    {
        data = p;
        next = nullptr;
    }
};

class priorityqueue
{
public:
    node *head;
    priorityqueue() { head = nullptr; }

    bool isEmpty() { return head == nullptr; }

    void insert(Player *p)
    {
        node *newnode = new node(p);
        if (!head || p->getlevel() > head->data->getlevel() ||
            (p->getlevel() == head->data->getlevel() && p->getarrval() < head->data->getarrval()))
        {
            newnode->next = head;
            head = newnode;
            return;
        }

        node *temp = head;
        while (temp->next && (temp->next->data->getlevel() > p->getlevel() ||
                              (temp->next->data->getlevel() == p->getlevel() && temp->next->data->getarrval() <= p->getarrval())))
            temp = temp->next;

        newnode->next = temp->next;
        temp->next = newnode;
    }

    Player *extractTop()
    {
        if (isEmpty())
            return nullptr;
        node *temp = head;
        Player *topPlayer = temp->data;
        head = head->next;
        delete temp;
        return topPlayer;
    }

    void remove(int id)
    {
        if (!head)
            return;
        if (head->data->getid() == id)
        {
            node *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        node *temp = head;
        while (temp->next && temp->next->data->getid() != id)
            temp = temp->next;
        if (!temp->next)
            return;
        node *toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    void boost(int id, int x)
    {
        node *temp = head;
        Player *p = nullptr;
        while (temp)
        {
            if (temp->data->getid() == id)
            {
                p = temp->data;
                break;
            }
            temp = temp->next;
        }
        if (!p || p->gettype() != "VIP")
            return;

        remove(id);
        p->setlevel(p->getlevel() + x);
        insert(p);
    }

    void printStatus()
    {
        node *temp = head;
        cout << "VIP Queue: ";
        while (temp)
        {
            cout << temp->data->getname() << "(" << temp->data->getlevel() << ") ";
            temp = temp->next;
        }
        cout << endl;
    }
};

class normalqueue
{

public:
    node *front;
    node *rear;
    normalqueue() { front = rear = nullptr; }

    void enqueue(Player *p)
    {
        node *newnode = new node(p);
        if (!rear)
        {
            front = rear = newnode;
            return;
        }
        rear->next = newnode;
        rear = newnode;
    }

    Player *dequeue()
    {
        if (!front)
            return nullptr;
        node *temp = front;
        Player *p = temp->data;
        front = front->next;
        if (!front)
            rear = nullptr;
        delete temp;
        return p;
    }

    bool isEmpty() { return front == nullptr; }

    void remove(int id)
    {
        if (!front)
            return;
        if (front->data->getid() == id)
        {
            node *temp = front;
            front = front->next;
            if (!front)
                rear = nullptr;
            delete temp;
            return;
        }
        node *temp = front;
        while (temp->next && temp->next->data->getid() != id)
            temp = temp->next;
        if (!temp->next)
            return;
        node *toDelete = temp->next;
        temp->next = temp->next->next;
        if (!temp->next)
            rear = temp;
        delete toDelete;
    }

    void printStatus()
    {
        node *temp = front;
        cout << "Normal Queue: ";
        while (temp)
        {
            cout << temp->data->getname() << "(" << temp->data->getlevel() << ") ";
            temp = temp->next;
        }
        cout << endl;
    }
};

class TournamentManager
{
private:
    priorityqueue vipqueue;
    normalqueue normalqueue;
    int arrivalorder;

    struct ActionNode
    {
        string actionType;
        Player *player;
        int oldLevel;
        ActionNode *next;
        ActionNode(string type, Player *p, int level = 0)
        {
            actionType = type;
            player = p;
            oldLevel = level;
            next = nullptr;
        }
    };
    ActionNode *actionTop;

    void pushAction(string type, Player *p, int oldLevel = 0)
    {
        ActionNode *newAction = new ActionNode(type, p, oldLevel);
        newAction->next = actionTop;
        actionTop = newAction;
    }

    ActionNode *popAction()
    {
        if (!actionTop)
            return nullptr;
        ActionNode *temp = actionTop;
        actionTop = actionTop->next;
        return temp;
    }

public:
    TournamentManager()
    {
        arrivalorder = 0;
        actionTop = nullptr;
    }

    void REGISTER(int id, string name, int level, string type)
    {
        Player *p = new Player(id, name, level, type, arrivalorder++);
        if (type == "VIP")
            vipqueue.insert(p);
        else
            normalqueue.enqueue(p);
        pushAction("REGISTER", p);
    }

    void play()
    {
        Player *p = nullptr;
        if (!vipqueue.isEmpty())
            p = vipqueue.extractTop();
        else if (!normalqueue.isEmpty())
            p = normalqueue.dequeue();

        if (p)
        {
            cout << p->getid() << " " << p->getname() << endl;
            pushAction("PLAY", p);
        }
        else
        {
            cout << "no Players" << endl;
        }
    }

    void boost(int id, int x)
    {
        node *temp = vipqueue.head;
        while (temp)
        {
            if (temp->data->getid() == id)
            {
                pushAction("BOOST", temp->data, temp->data->getlevel());
                break;
            }
            temp = temp->next;
        }
        vipqueue.boost(id, x);
    }

    void withdraw(int id)
    {
        // Find player before removing
        Player *p = nullptr;
        node *temp = vipqueue.head;
        while (temp)
        {
            if (temp->data->getid() == id)
            {
                p = temp->data;
                break;
            }
            temp = temp->next;
        }
        if (!p)
        {
            temp = normalqueue.front;
            while (temp)
            {
                if (temp->data->getid() == id)
                {
                    p = temp->data;
                    break;
                }
                temp = temp->next;
            }
        }
        if (p)
            pushAction("WITHDRAW", p);
        vipqueue.remove(id);
        normalqueue.remove(id);
    }

    void status()
    {
        vipqueue.printStatus();
        normalqueue.printStatus();
    }

    void UNDO()
    {
        ActionNode *last = popAction();
        if (!last)
        {
            cout << "Nothing to undo\n";
            return;
        }

        if (last->actionType == "REGISTER")
            withdraw(last->player->getid());
        else if (last->actionType == "PLAY")
        {
            if (last->player->gettype() == "VIP")
                vipqueue.insert(last->player);
            else
                normalqueue.enqueue(last->player);
        }
        else if (last->actionType == "BOOST")
        {
            vipqueue.remove(last->player->getid());
            last->player->setlevel(last->oldLevel);
            vipqueue.insert(last->player);
        }
        else if (last->actionType == "WITHDRAW")
        {
            if (last->player->gettype() == "VIP")
                vipqueue.insert(last->player);
            else
                normalqueue.enqueue(last->player);
        }

        delete last;
    }
};

int main()
{
    TournamentManager TM;

    TM.REGISTER(1, "Arin", 5, "VIP");
    TM.REGISTER(2, "Mehran", 8, "VIP");
    TM.REGISTER(3, "Faris", 7, "VIP");
    TM.REGISTER(4, "Ameen", 4, "NORMAL");

    TM.status();

    TM.play();
    TM.status();

    TM.boost(3, 3);
    TM.status();

    TM.withdraw(2);
    TM.status();

    cout << "\nUNDO last action:\n";
    TM.UNDO();
    TM.status();

    cout << "\nUNDO last action:\n";
    TM.UNDO();
    TM.status();

    return 0;
}