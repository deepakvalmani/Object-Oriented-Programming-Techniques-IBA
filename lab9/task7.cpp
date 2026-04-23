#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>

using namespace std;

int main()
{

    vector<double> data = {4, 8, 15, 16, 23, 42, 7, 3, 19, 11};

    int n = data.size();
    // Sum
    double sum = accumulate(data.begin(), data.end(), 0.0);

    // Mean
    double mean = sum / n;

    // using accumulate
    auto minval = accumulate(data.begin() + 1, data.end(), data[0], [](double a, double b)
                             { return min(a, b); });
    auto maxval = accumulate(data.begin() + 1, data.end(), data[0], [](double a, double b)
                             { return max(a, b); });
    auto squareSum = accumulate(data.begin(), data.end(), 0.0, [](double acc, double x)
                                { return acc + x * x; });
    auto variance = accumulate(data.begin(), data.end(), 0.0, [mean](double acc, double x)
                               { return acc + (x - mean) * (x - mean); }) /
                    n;

    //  Using std::reduce (C++17)
    double sum_reduce = reduce(data.begin(), data.end(), 0.0);
    double mean_reduce = sum_reduce / n;

    // Output
    cout << fixed << setprecision(2);

    cout << "Sum: " << sum << endl;
    cout << "Mean: " << mean << endl;
    cout << "Min: " << minval << endl;
    cout << "Max: " << maxval << endl;
    cout << "Sum of Squares: " << squareSum << endl;
    cout << "Variance: " << variance << endl;

    cout << "\nUsing std::reduce:" << endl;
    cout << "Sum (reduce): " << sum_reduce << endl;
    cout << "Mean (reduce): " << mean_reduce << endl;

    // Verification
    if (abs(sum - sum_reduce) < 1e-9 && abs(mean - mean_reduce) < 1e-9)
        cout << "Results match!" << endl;
    else
        cout << "Mismatch detected!" << endl;

    return 0;
}