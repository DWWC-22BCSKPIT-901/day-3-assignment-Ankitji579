/*
Q1 .Fibonnacci Series Using Recursion        
The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two prece ding ones, starting from 0 and 1. 
*/

#include <iostream>
using namespace std;

// Function to calculate Fibonacci numbers using recursion
int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    cout << "Enter the number of terms in the Fibonacci series: ";
    cin >> n;
       cout << "Fibonacci Series: \n";
    for (int i = 0; i < n; i++) {
        cout << fibonacci(i) << " ";
    }
    cout << endl;

    return 0;
}
