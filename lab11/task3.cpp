#include <iostream>
using namespace std;

double power(double base, double exp)
{
    cout<<"calling power("<<base<<" ,"<<exp<<")"<<endl;
    if (exp == 0)
        return 1;
    double result=  base * power(base, exp - 1);
    cout<<"result: "<<result<<endl;
    return result;
}

double power_simple(double base, double exp)
{
    if (exp == 0)
        return 1;
      
    return base * power_simple(base, exp - 1);
}


double power_negative(double base, double exp)
{
    if (exp < 0){return 1 / power_negative(base, -exp);};

    if (exp == 0)
        return 1;
      
    return base * power_negative(base, exp - 1);
}




int main()
{
        cout << "power_simple(2,0): "
            << power(2, 0)
            << " actual answer: 1"
            << endl
            << "power_simple(2,5): "
            << power(2, 5)
            << " actual answer: 32"
            << endl
            << "power_simple(3,3): "
            << power(3, 3)
            << " actual answer: 27"
            << endl;

        power(2, 4);
        cout<<"Negative power: ";
        cout<< power_negative(2.0,-3);
            

    return 0;
}