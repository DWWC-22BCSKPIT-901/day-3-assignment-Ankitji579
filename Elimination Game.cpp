/*
You have a list arr of all integers in the range [1, n] sorted in a strictly increasing order. Apply the following algorithm on arr:
 Starting from left to right, remove the first number and every other number afterward until you reach the end of the list.
Repeat the previous step again, but this time from right to left, remove the rightmost number and every other number from the remaining numbers.
Keep repeating the steps again, alternating left to right and right to left, until a single number remains.
Given the integer n, return the last number that remains in arr.
 */


#include <iostream>
using namespace std;

int lastRemaining(int n) {
    int start = 1;      // Start of the list
    int step = 1;       // Step size for elimination
    int remaining = n;  // Remaining numbers
    bool leftToRight = true; // Direction of elimination

    while (remaining > 1) {
        // If eliminating from left or the number of remaining elements is odd
        if (leftToRight || remaining % 2 == 1) {
            start += step;
        }
        // Update step and remaining numbers
        step *= 2;
        remaining /= 2;
        leftToRight = !leftToRight; // Alternate direction
    }

    return start;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Last number remaining: " << lastRemaining(n) << endl;
    return 0;
}
