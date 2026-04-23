#include <iostream>
using namespace std;

class Device
{
    static int device_count;

    const int serial_no; 

public:
    static void display()
    {
        cout << "Number of products: " << device_count << endl;
    }

    Device(int serial) : serial_no(serial)
    {
        device_count++;
    }
};

int Device::device_count = 0;

int main()
{

    Device d1(1001);
    Device d2(1002);
    Device d3(1003);
    Device d4(1004);

    Device::display();
    return 0;
}