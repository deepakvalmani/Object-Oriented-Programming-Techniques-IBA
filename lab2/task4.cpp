#include <iostream>
#include <cstring>

using namespace std;

class User
{
private:
    string name;
    int age;
    char *profile_bio;
    int *session_ID;

public:
    User(string name, int age, const char *bio, int session_id)
    {
        this->name = name;
        this->age = age;
        this->profile_bio = new char[strlen(bio) + 1];
        strcpy(this->profile_bio, bio);
        this->session_ID = new int(session_id);
    }

    User(const User &other)
    {
        name = other.name;
        age = other.age;
        profile_bio = new char[strlen(other.profile_bio) + 1];
        strcpy(profile_bio, other.profile_bio);
        session_ID = other.session_ID;
    }

    ~User()
    {
        delete[] profile_bio;
    }

    void setprofile_bio(const char *bio)
    {
        delete[] profile_bio;
        profile_bio = new char[strlen(bio) + 1];
        strcpy(profile_bio, bio);
    }
    void print() const
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Profile Bio: " << profile_bio << endl;
        cout << "Session ID: " << *session_ID << endl;
    }
    void setSessionID(int id)
    {
        *session_ID = id;
    }

    void setName(const string &name)
    {
        this->name = name;
    }
    void setAge(int age)
    {
        this->age = age;
    }

    int *getsessionID_pointer() const
    {
        return session_ID;
    }
};
int main()
{

    User user1("Ali", 22, "Initial bio", 1001);
    cout << "User1 initial state:\n";
    user1.print();

    User user2(user1);
    cout << "User2 copied from User1:\n";
    user2.print();

    user1.setprofile_bio("Updated bio for user1");
    cout << "After modifying user1 profile bio:\n";
    cout << "User1:\n";
    user1.print();
    cout << "User2:\n";
    user2.print();

    user2.setSessionID(2002);
    cout << "After modifying session ID via user2:\n";
    cout << "User1:\n";
    user1.print();
    cout << "User2:\n";
    user2.print();

    return 0;
}