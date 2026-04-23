
#include <iostream>
using namespace std;

class A
{
protected:
    int x;
public:
    A(int val) : x(val) {}
    virtual void display() 
    {
        cout << "Class A: x = " << x << endl;
    }

};

class B : public A
{
public:
    B(int val) : A(val) {}
    void display()
    {
        cout << "Class B: x = " << x * 2 << endl;
    }
    void call(){
        cout<<"Call "<<endl;
    }
};


int main()
{
    A *obj = new B(5);
    obj->display();
    // obj->call(); // can not be called becasue call() function is not declared in base class 
    
    // C * obj1 = &obj;   
    return 0;
}