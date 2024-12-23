/*
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
*/

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Function to add two numbers represented as linked lists
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummyHead = new ListNode(); // Dummy node to simplify code
    ListNode* current = dummyHead; // Pointer to the current node
    int carry = 0; // Carry for addition

    while (l1 != nullptr || l2 != nullptr || carry != 0) {
        int sum = carry; // Start with the carry from the previous operation
        if (l1 != nullptr) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != nullptr) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10; // Update carry
        current->next = new ListNode(sum % 10); // Add the digit to the result
        current = current->next; // Move to the next node
    }

    return dummyHead->next; // Return the result list, skipping the dummy head
}

// Helper function to create a linked list from a vector of integers
ListNode* createList(const vector<int>& nums) {
    ListNode* dummyHead = new ListNode();
    ListNode* current = dummyHead;
    for (int num : nums) {
        current->next = new ListNode(num);
        current = current->next;
    }
    return dummyHead->next;
}

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Input lists
    vector<int> list1 = {2, 4, 3};
    vector<int> list2 = {5, 6, 4};

    // Create linked lists
    ListNode* l1 = createList(list1);
    ListNode* l2 = createList(list2);

    // Add the two numbers
    ListNode* result = addTwoNumbers(l1, l2);

    // Print the result
    cout << "Resultant Linked List: ";
    printList(result);

    return 0;
}
