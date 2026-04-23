#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct FileException
{
    string message;
    explicit FileException(const string &msg)
        : message(msg)
    {
    }
};

class FileHandler
{
private:
    string f_name;
    fstream file;
    bool r_access;
    bool w_access;
    bool o_access;

public:
    explicit FileHandler(const string &filename)
        : f_name(filename), r_access(false), w_access(false), o_access(false)
    {
    }

    void set_r_access(bool access)
    {
        r_access = access;
    }

    void set_w_access(bool access)
    {
        w_access = access;
    }

    void set_o_access(bool access)
    {
        o_access = access;
    }

    void set_all_access(bool access)
    {
        r_access = w_access = o_access = access;
    }

    void open_for_read()
    {
        if (!o_access)
        {
            throw FileException("Open permission denied for file '" + f_name + "'.");
        }
        if (!r_access)
        {
            throw FileException("Read permission denied for file '" + f_name + "'.");
        }

        file.open(f_name.c_str(), ios::in);
        if (!file)
        {
            throw FileException("File not found or cannot open for reading: '" + f_name + "'.");
        }
    }

    void open_for_write()
    {
        if (!o_access)
        {
            throw FileException("Open permission denied for file '" + f_name + "'.");
        }
        if (!w_access)
        {
            throw FileException("Write permission denied for file '" + f_name + "'.");
        }

        file.open(f_name.c_str(), ios::out);
        if (!file)
        {
            throw FileException("Cannot open file for writing: '" + f_name + "'.");
        }
    }

    void open_for_append()
    {
        if (!o_access)
        {
            throw FileException("Open permission denied for file '" + f_name + "'.");
        }
        if (!w_access)
        {
            throw FileException("Write permission denied for file '" + f_name + "'.");
        }

        file.open(f_name.c_str(), ios::out | ios::app);
        if (!file)
        {
            throw FileException("Cannot open file for appending: '" + f_name + "'.");
        }
    }

    string read()
    {
        if (!file.is_open())
        {
            throw FileException("File is not open for reading: '" + f_name + "'.");
        }
        if (!r_access)
        {
            throw FileException("Read permission denied for file '" + f_name + "'.");
        }

        string contents;
        string line;
        while (getline(file, line))
        {
            contents += line;
            contents += '\n';
        }

        if (file.bad())
        {
            throw FileException("Error while reading file '" + f_name + "'.");
        }

        return contents;
    }

    void write(const string &text)
    {
        if (!file.is_open())
        {
            throw FileException("File is not open for writing: '" + f_name + "'.");
        }
        if (!w_access)
        {
            throw FileException("Write permission denied for file '" + f_name + "'.");
        }

        file << text;
        if (!file)
        {
            throw FileException("Error while writing to file '" + f_name + "'.");
        }
    }

    void close()
    {
        if (file.is_open())
        {
            file.close();
        }
    }

    ~FileHandler()
    {
        close();
    }
};

int main()
{
    try
    {
        FileHandler handler("testfile.txt");
        handler.set_all_access(true);

        handler.open_for_append();
        handler.write("This is a sample line.\n");
        handler.close();

        handler.open_for_read();
        string contents = handler.read();
        handler.close();

        cout << "File contents:\n" << contents;
    }
    catch (const FileException &ex)
    {
        cerr << "Error: " << ex.message << '\n';
        return 1;
    }

    return 0;
}
