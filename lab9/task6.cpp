#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Event
{
    string level;
    string message;
    int code;
};

void PrintEvent(vector<Event> &event)
{
    for (auto e : event)
    {
        cout << e.level << " " << e.message << " " << e.code << endl;
    }
}

template <typename T, typename Pred>
vector<T> filter(const vector<T> &v, Pred pred)
{
    vector<T> result;
    copy_if(v.begin(), v.end(), back_inserter(result), pred);
    return result;
};

int main()
{
    vector<Event> events = {
        {"INFO", "System started", 100},
        {"WARN", "Low disk space", 200},
        {"ERROR", "File not found", 300},
        {"INFO", "User logged in", 101},
        {"ERROR", "Database failure", 301},
        {"WARN", "High CPU usage", 201},
        {"INFO", "Process completed", 102},
        {"ERROR", "Access denied", 302}};

    vector<Event> ErrorEvents;

    cout << "\nOriginal Events: \n";
    PrintEvent(events);
    copy_if(events.begin(), events.end(), back_inserter(ErrorEvents),
            [](Event &event)
            { return event.level == "ERROR"; });

    cout << "\nError Events: \n";
    PrintEvent(ErrorEvents);

    events.erase(

        remove_if(events.begin(), events.end(),
                [](Event &e)
                { return e.level == "INFO"; }),
        events.end());

    cout << "\nEvents after removing INFO: \n";
    PrintEvent(events);

    auto warnEvents = filter(events, [](const Event &e)
        { return e.level == "WARN"; });

    cout << "\nFiltered WARN Events (using generic filter):\n" << endl;
    PrintEvent(warnEvents);

    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    auto filterednumbers = filter(nums, [](const int &n)
        { return (n % 2 == 0); });
    cout << "\nFiltered Numbers: \n";
    for (auto n : filterednumbers)
    {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}