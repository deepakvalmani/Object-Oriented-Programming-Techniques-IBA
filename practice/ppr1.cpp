// #include <iostream>
// using namespace std;

// // class A
// // {
// //     A()
// //     {
// //         cout << "A";
// //     }
// // };
// // 2 class B
// // {
// // };
// // 3 class C : public B
// // {
// // };
// // 4 int main()
// // {
// //     5 A a;
// //     6 B b;
// //     7 C c;
// //     8
// // }

// // class Base
// // {
// // public:
// //     virtual void print() const
// //     {
// //         cout << "Base Class";
// //     }
// // };
// // class Derived : public Base
// // {
// // public:
// //     void print() const override
// //     {
// //         cout << "Derived Class";
// //     }
// // };
// // void display(const Base &obj)
// // {
// //     obj.print();
// // }
// // int main()
// // {
// //     Base b;
// //     Derived d;
// //     display(b);
// //     display(d);
// // }

// // class Point
// // {
// // public:
// //     Point() { cout << "Normal Constructor called\n"; }
// //     Point(Point &t) { cout << "Copy constructor called\n"; }
// // };
// // int main()
// // {
// //     Point *t1, *t2;
// //     t1 = new Point();
// //     t2 = new Point(*t1);
// //     Point t3 = *t1;
// //     Point t4;
// //     t4 = t3;
// //     Point t5 = t3;
// // }

// class CustomException : public std::exception
// {
// public:
//     const char *what() const throw()
//     {
//         return "Custom Exception";
//     }
// };
// void processNumber(int number)
// {
//     try
//     {
//         if (number < 0)
//             throw CustomException();
//         else if (number % 2 == 0)
//             throw "Even Number";
//         else
//             throw 42.42;
//     }
//     catch (const char *msg)
//     {
//         std::cout << "Caught Exception: " << msg << std::endl;
//     }
//     catch (double value)
//     {
//         std::cout << "Caught Exception: " << value << std::endl;
//     }
//     catch (...)
//     {
//         std::cout << "Caught Unknown Exception" << std::endl;
//         throw; // Rethrow the unknown exception
//     }
// }
// int main()
// {
//     try
//     {
//         processNumber(-5);
//         processNumber(8);
//         processNumber(17);
//     }
//     catch (const std::exception &e)
//     {
//         std::cerr << "Caught Standard Exception: " << e.what() << std::endl;
//     }
//     catch (...)
//     {
//         std::cerr << "Caught Unknown Exception in main" << std::endl;
//     }
//     return 0;
// }

// #include <iostream>
// using namespace std;
// class A
// {
// protected:
//     int x;

// public:
//     A(int val) : x(val) {}
//     void display()
//     {
//         cout << "Class A: x = " << x << endl;
//     }
// }
