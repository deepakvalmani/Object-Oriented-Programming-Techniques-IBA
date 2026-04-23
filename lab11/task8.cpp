#include <iostream>
using namespace std;

/*


Values are printed while going down recursion stack

5 4 3 2 1 
*/

void countdown(int n) {
    if (n == 0) {
        cout << "Go!" << endl;
        return;
    }

    // Print before recursion
    cout << n << endl;

    countdown(n - 1);
}


void countup(int n) {
    if (n == 0) {
        cout << "Go!" << endl;
        return;
    }

    countup(n - 1);

    // Print after recursion 
    cout << n << endl;
}

int main() {
    cout << "Countdown:" << endl;
    countdown(5);

    cout << "\nCountup:" << endl;
    countup(5);

    return 0;
}
/*Swapping cout changes the order because printing 
before recursion outputs while going down the call 
stack descending order, while printing after recursion outputs 
while returning back up the stack ascending order, reversing the sequence.
*/