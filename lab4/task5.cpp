#include <iostream>
using namespace std;

class CircularDerive
{

private:
    int *arr;
    int front, rear, size, capacity;

public:
    CircularDerive(int cap)
    {

        capacity = cap;
        arr = new int[cap];
        front = rear = size = 0;
    }

    bool IsEmpty()
    {
        return size == 0;
    }
    bool IsFull()
    {
        return size == capacity;
    }

    bool ParkCar(int car_num)
    {
        if (IsFull())
        {
            cout << "Full " << endl;
            return false;
        }
        arr[rear] = car_num;
        rear = (rear + 1) % capacity;
        size++;
        return true;
    }
    int car_leaves()
    {
        if (IsEmpty())
        {
            return -1;
        }
        int car = arr[front];
        front = (front + 1) % capacity;
        size--;
        return car;
    }

    int frontCar()
    {
        if (IsEmpty())
        {
            return -1;
        }
        return arr[front];
    }
    int LastCar()
    {
        if (IsEmpty())
        {
            return -1;
        }
        int LastIndex = (rear - 1 + capacity) % capacity;
        return arr[LastIndex];
    }

    ~CircularDerive()
    {
        delete[] arr;
    }
};
int main()
{

    CircularDerive lane = CircularDerive(3);
    lane.ParkCar(101);
    lane.ParkCar(102);
    lane.ParkCar(103);
    lane.ParkCar(104);

    cout << "Front Car: " << lane.frontCar() << endl;
    cout << "Last Car: " << lane.LastCar() << endl;

    lane.car_leaves();
    cout<<"Removing........"<<endl;
    lane.ParkCar(104);
    

    cout << "Front Car: " << lane.frontCar() << endl;
    cout << "Last Car: " << lane.LastCar() << endl;

    return 0;
}