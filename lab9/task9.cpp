#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

string formatMessage(const string& prefix,
                     const string& msg,
                     const string& suffix)
{
    return prefix + msg + suffix;
}

int main()
{
    using namespace placeholders;

    function<string(const string&)> makeInfo =
        bind(formatMessage, "[INFO] ", _1, "");

    function<string(const string&)> makeError =
        bind(formatMessage, "[ERROR] ", _1, " !!!");

    function<string(const string&)> makeDebug =
        bind(formatMessage, "[DEBUG] ", _1, " (line?)");

    vector<function<string(const string&)>> formatters = {
        makeInfo, makeError, makeDebug
    };

    string msg = "Connection timeout";

    cout << "Formatted single message:\n";
    for (auto& f : formatters)
    {
        cout << f(msg) << endl;
    }

    vector<string> errors = {
        "File not found",
        "Access denied",
        "Disk full",
        "Timeout error",
        "Invalid input"
    };

    vector<string> formattedErrors;

    transform(errors.begin(), errors.end(), back_inserter(formattedErrors),
              makeError);

    cout << "\nFormatted error messages:\n";
    for (const auto& e : formattedErrors)
    {
        cout << e << endl;
    }

    return 0;
}