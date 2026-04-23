#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

// Simple function composition (variadic)
template <typename F>
auto chain(F f)
{
    return f;
}

template <typename F, typename G>
auto chain(F f, G g)
{
    return [=](auto x)
    {
        return f(g(x));
    };
}

template <typename F, typename G, typename... Rest>
auto chain(F f, G g, Rest... rest)
{
    return [=](auto x)
    {
        return f(chain(g, rest...)(x));
    };
}

int main()
{
    // Different naming + same idea
    auto minusOne = [](int x) { return x - 1; };
    auto multiplyByTwo = [](int x) { return x * 2; };
    auto square = [](int x) { return x * x; };

    // Two-function chain
    auto first = chain(multiplyByTwo, minusOne);

    cout << "Result (multiplyByTwo minusOne): ";
    for (int i = 1; i <= 5; i++)
    {
        cout << first(i) << " ";
    }
    cout << endl;

    // Three-function chain
    auto second = chain(square, multiplyByTwo, minusOne);

    vector<int> v = {1, 2, 3, 4, 5};
    vector<int> res(v.size());

    transform(v.begin(), v.end(), res.begin(), second);

    cout << "Result (square multiplyByTwo minusOne): ";
    for (int x : res)
    {
        cout << x << " ";
    }
    cout << endl;

    function<long long(int)> fib = [&](int n) -> long long
    {
        if (n <= 1)
            return n;
        return fib(n - 1) + fib(n - 2);
    };

    cout << "Fibonacci: ";
    for (int i = 0; i <= 10; i++)
    {
        cout << fib(i) << " ";
    }
    cout << endl;

    return 0;
}