#include <iostream>
using namespace std;
// base class
class log
{
public:
    log()
    {
    }

    virtual void logMessage()
    {
        cout << "class log\n";
    }
};

class ConsoleLogger : public log
{

public:
    ConsoleLogger()
    {
    }

    void logMessage() override
    {
        cout << "Class ConsoleLogger\n";
    }
};

class FileLogger : public log
{

public:
    FileLogger()
    {
    }

    void logMessage() override
    {
        cout << "Class FileLogger\n";
    }
};

class DatabaseLogger : public log
{

public:
    DatabaseLogger()
    {
    }

    void logMessage() override
    {
        cout << "Class DatabaseLogger\n";
    }
};

int main()
{
    ConsoleLogger obj1;
    FileLogger obj2;
    DatabaseLogger obj3;

    obj1.logMessage();
    obj2.logMessage();
    obj3.logMessage();
    

    return 0;
}