#include <iostream>
using namespace std;

class Logger
{

    string filename;

public:
    void log(string message)
    {
        cout << "[LOG]: " << message << endl;
        this->filename = filename;
    }
};

class FileManager : private Logger
{

public:
    void saveFile(string filename)
    {
        log(filename);

        cout << "File saved: " << filename << endl;
    }
};

int main()
{

    FileManager obj;
    obj.saveFile("task3.cpp");
    //obj.log();  will not run successfuly as the logger class has been inherited privately
    // and private functions are not accesible out of the class


    return 0;
}