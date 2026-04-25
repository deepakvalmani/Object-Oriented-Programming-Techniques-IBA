
# Revision

## Array
### 1D Array
An array is a collection of a fixed number of elements of the same data type.

### 2D Array
A 2-D Array is a collection of fixed elements arranged in rows and columns.

## Pointers
To declare a single pointer variable, you need to specify the data type, an asterisk symbol (*) and the
pointer variable name.

The pointer variable holds the memory address of the variable of the same data type.

•To assign the memory address of a variable to a pointer variable, use the address-of operator (&)

## Dynamic Variables
Variables created during the program execution are called dynamic variables.

To create a dynamic variable, use the new operator

## Structures
A structure is a collection of fixed number of components, which can be of different types, and the components
are accessed by name.

Components of a structure are called members.
To declare a structure, use the struct keyword.

## Encapsulation
Encapsulation is one of the fundamental concepts in object-oriented programming (OOP). It describes the
idea of bundling data and methods that work on that data within one unit, e.g., a class in C++. 

This concept is also often used to hide the internal representation, or state, of an object from the outside. This is called information hiding.

Encapsulation can be achieved by making instance variables of the class private and the access to the
members is then controlled by public member functions of the class. 

For instance, the Student class below has three private instance variables erpID, name, and cgpa.

Encapsulation is achieved by making instance variables private and providing controlled access through
public member functions


## ADT
A class in C++ can be used to implement an abstract data type (ADT). As discussed in lecture, the first
step in designing an ADT is to decide upon the API, i.e., the set of operations that can be performed on
the data. The next step is to decide upon the representation of the data. The instance variables (also called
attributes) of the class are used to represent the data.
The representation of the data is hidden from the user of the ADT. The user can only access the data
through the operations defined in the API. This is called data encapsulation or information hiding.
The attributes and methods of a class are collectively called the members of the class

## Constructors
A constructor is a special member function that is automatically invoked when an object of a class is created.
It has the same name as the class and no return type.
Constructors are used to:

•Initialize object attributes
•Ensure the object starts in a valid state

### Copy Constructors: Shallow vs Deep Copy
When an object contains dynamically allocated memory, a copy constructor must be carefully designed.

#### Shallow Copy
A shallow copy copies only the memory address, not the data itself.
Shallow copy is acceptable only when memory is intentionally shared

#### Deep Copy
A deep copy creates a new independent copy of the data
Deep copy is mandatory when objects own their memory

## Operator Overloading
Operator overloading allows objects to behave like built-in data types.

## Stack and Queue
Stack and queue are two important Abstract Data Types (ADTs). A stack stores items in a last-in,
first-out (LIFO) manner, whereas a queue stores items in a first-in, first-out (FIFO) manner.

•Stack example: Function calls, undo operations, expression evaluation.
•Queue example: Printer jobs, customer service lines, task scheduling.

The following table summarizes the operations of a stack and a queue.
Stack Queue Description
push(x) enqueue(x) Insert an item x
pop() dequeue() Remove an item (top for stack, front for queue)
empty() empty() Return true if empty
size() size() Return number of stored items


## Polymorphism
Polymorphims means that a call to a member function will cause a different function to be executed de-
pending on the type of object that invokes the function. Typically, polymorphism occurs when there is a
hierarchy of classes and they are related by inheritance.

### Real world example
A real life example of polymorphism is that a person at the same time can have different characteristics.
A man at the same time is a father, a husband, an employee, so the same person possesses different
behavior in different situations. This is called as polymorphism

### TYPES OF POLYMORPHISM
In C++ polymorphism is mainly divided into two types:
•Compile time Polymorphism
•Runtime Polymorphism

#### Compile time Polymorphism
This type of polymorphism is achieved by function overloading or operator overloading.
Function overloading When there are multiple functions with same name but different parameters then
these functions are said to be overloaded. Functions can be overloaded by a change in the number of
arguments or/and change in the type of arguments

#### Operator Overloading
In C++, the purpose of operator overloading for an operator is to specify more than one meaning in one
scope. It gives special meaning of an operator for a user-defined data type. You can redefine most of the
C++ operators with the help of operator overloading. To perform multiple operations using one operator,
you can also use operator overloading. Syntax of operator overloading:
To overload a C++ operator, you should define a special function inside the Class 

#### C++ Operators that can and cannot be Overloaded
##### Unary Operators Overloading
The unary operators operate on a single operand and following are the examples of Unary operators.
•The increment (++) and decrement (-) operators.
•The unary minus (-) operator.
•The logical not (!) operator.
The unary operators operate on the object for which they were called and normally, this operator appears
on the left side of the object, as in !obj, -obj, and ++obj but sometime they can be used as postfix as well
like obj++ or obj-. Following example explain how minus (-) operator can be overloaded for prefix as well
as postfix usage


Operator Description / Overloadability
Operators That CAN Be Overloaded
Arithmetic +, -, *, /, % (Basic arithmetic operations)
Bitwise ˆ, &, |,  ̃ (Bitwise XOR, AND, OR, NOT)
Assignment =, +=, -=, *=, /=, %=, ˆ=, &=, |=, «=, »=
Relational ==, !=, <, >, <=, >= (Comparison operators)
Logical &&, ||, ! (Logical AND, OR, NOT)
Increment/Decrement ++, - (Prefix and postfix)
Pointer and Member Access ->, * (Pointer dereference and member access)
Stream «, » (Used in cout and cin)
Function Call () (Allows an object to be called like a function)
Indexing [] (Array-style indexing)
Dynamic Memory new, new[], delete, delete[] (Custom mem-
ory management)
Operators That CANNOT Be Overloaded
Scope Resolution :: (Used for accessing global or class members)
Pointer-to-Member .* (Used for member pointer access)
Member Access . (Cannot be directly overloaded, but -> can)
Size Query sizeof (Evaluated at compile-time)
Type Identification typeid (Used for runtime type checking)
Alignment Query alignof (Checks memory alignment)
Type Casting static_cast, dynamic_cast, const_cast,
reinterpret_cast (Used for explicit type con-
versions)
Table 1: Overloadable and Non-Overloadable Operators in C++


##### Binary Operators Overloading
The binary operators take two arguments and following are the examples of Binary operators. You use binary
operators very frequently like addition (+) operator, subtraction (-) operator and division (/) operator.
Following example explains how addition (+) operator can be overloaded. Similar way, you can overload
subtraction (-) and division (/) operators

##### Assignment Operator Overloading
You can overload the assignment operator (=) just as you can other operators and it can be used to create
an object just like the copy constructor. Following example explains how an assignment operator can be
overloaded


##### Function Call() Operator Overloading
The function call operator () can be overloaded for objects of class type. When you overload () , you are
not creating a new way to call a function. Rather, you are creating an operator function that can be passed
an arbitrary number of parameters. Following example explains how a function call operator () can be
overloaded.

##### Things to remember for Operator Overloading
Here are rules for Operator Overloading:
•At least one of the operands in overloaded operators must be user-defined, which means we cannot
overload the minus operator to work with one integer and one double. However, you could overload
the minus operator to work with an integer and a mystring.
•We can only overload the operators that exist and cannot create new operators or rename existing
operators.
•You can make the operator overloading function a friend function if it needs to access the private and
protected class members.
•Some operators cannot be overloaded using a friend function. However, such operators can be over-
loaded using member function. Eg. Assignment overloading operator = and function call() operator
etc


#### Run time Polymorphism
This type of polymorphism is achieved by Function Overriding.

##### Function Overriding
Function overriding is a feature that allows us to have a same function in child class which is already present
in the parent class.
•A child class inherits the data members and member functions of parent class, but when you want to
override a functionality in the child class then you can use function overriding. It is like creating a
new version of an old function, in the child class.
•To override a function you must have the same signature in the child class


## Inheritance
Inheritance is one of the core features of Object-Oriented Programming that allows a class (called the
derived or child class) to acquire the properties and behaviours of another class (called the base or
parent class). Inheritance promotes code reusability, establishes an is-a relationship between classes, and
forms the backbone of runtime polymorphism

### Real World Example
Consider a Vehicle as a base class. A Car and a Truck are both vehicles they inherit common
characteristics such as having an engine, wheels, and a fuel type. However, each also has its own
specialised attributes (e.g., a Car has a sunroof while a Truck has a cargo capacity). This is the
essence of inheritance

The access_specifier controls how the members of the base class are accessible in the derived class. It
can be public, protected, or private.
Last updated: 2026-02-26 20:36 Page 1 of 11

### Access Specifiers: Quick Recap
Before studying how access specifiers affect inheritance, recall what they mean inside a single class:
Specifier Meaning inside the class
public Accessible from anywhere (inside the class, derived classes,
and outside).
protected Accessible inside the class and in derived classes, but not
from outside.
private Accessible only inside the class itself; not accessible in de-
rived classes or from outside.
Table 1: Access Specifiers in C++

### Public Inheritance
When a class is derived with public inheritance, the access levels of base class members are preserved in
the derived class:
•public members of the base →public in the derived class.
•protected members of the base →protected in the derived class.
•private members of the base →inaccessible in the derived class (still inherited but hidden)

### Protected Inheritance
When a class is derived with protected inheritance, both public and protected members of the base
class become protected in the derived class:
•public members of the base →protected in the derived class.
•protected members of the base →protected in the derived class.
•private members of the base →inaccessible in the derived class.

### Private Inheritance
When a class is derived with private inheritance (the default in C++ if no specifier is given), all inherited
members become private in the derived class:
•public members of the base →private in the derived class.
•protected members of the base →private in the derived class.
•private members of the base →inaccessible in the derived class.

### Constructor and Destructor Behaviour in Inheritance
When a derived class object is created, the base class constructor is called first, followed by the derived
class constructor. When the object is destroyed, the derived class destructor is called first, followed
by the base class destructor

