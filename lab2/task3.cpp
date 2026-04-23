#include <iostream>
#include <vector>
#include <string>

using namespace std;

class IntegerSet
{
private:
    vector<bool> my_set;

public:
    IntegerSet()
    {
        my_set = vector<bool>(100, false);
    }
    IntegerSet(int arr[], int size)
    {
        my_set = vector<bool>(100, false);
        for (int i = 0; i < size; i++)
        {
            my_set[arr[i]] = true;
        }
    }

    IntegerSet UnionOfSets(const IntegerSet &s1, const IntegerSet &s2)
    {
        IntegerSet s;
        for (int i = 0; i < 100; i++)
        {
            s.my_set[i] = s1.my_set[i] || s2.my_set[i];
        }
        return s;
    }

    IntegerSet intersectionOfSets(const IntegerSet &s1, const IntegerSet &s2)
    {
        IntegerSet s;
        for (int i = 0; i < 100; i++)
        {
            s.my_set[i] = s1.my_set[i] && s2.my_set[i];
        }
        return s;
    }

    void insertElement(int element)
    {
        if (element >= 0 && element < 100)
            my_set[element] = true;
    }

    void deleteElement(int element)
    {
        if (element >= 0 && element < 100)
            my_set[element] = false;
    }

    string to_string()
    {
        string s = "";
        bool empty = true;
        for (int i = 0; i < 100; i++)
        {
            if (my_set[i])
            {
                s += std::to_string(i) + " ";
                empty = false;
            }
        }
        return empty ? "" : s;
    }

    bool isEqualTo(const IntegerSet &other)
    {
        for (int i = 0; i < 100; i++)
        {
            if (this->my_set[i] != other.my_set[i])
            {
                return false;
            }
        }
        return true;
    }
};
int main()
{

    int arr[] = {1, 5, 10, 15, 20};
    IntegerSet setA(arr, 5);
    cout << setA.to_string() << endl;

    IntegerSet setB;
    setB.insertElement(10);
    setB.insertElement(20);
    setB.insertElement(30);
    setB.insertElement(40);
    cout << setB.to_string() << endl;

    setB.deleteElement(20);
    cout << "Set B " << setB.to_string() << endl;

    IntegerSet setUnion = setA.UnionOfSets(setA, setB);
    cout << "Union (A | B): " << setUnion.to_string() << endl;

    IntegerSet setInter = setA.intersectionOfSets(setA, setB);
    cout << "Intersection (A & B): " << setInter.to_string() << endl;

    IntegerSet setC(arr, 5);
    cout << "Is Set A equal to Set C? " << (setA.isEqualTo(setC) ? "Yes" : "No") << endl;
    cout << "Is Set A equal to Set B? " << (setA.isEqualTo(setB) ? "Yes" : "No") << endl;

    IntegerSet setEmpty;
    cout << "Empty Set: " << setEmpty.to_string() << endl;

    return 0;
}