/*
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
You may not alter the values in the list's nodes, only nodes themselves may be changed.
*/


#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to reverse a portion of the linked list
ListNode* reverse(ListNode* head, ListNode* tail) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr != tail) {
        ListNode* nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev; // New head of the reversed list
}

// Function to reverse k nodes at a time
ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prevGroupEnd = dummy;

    while (true) {
        // Check if there are k nodes left to reverse
        ListNode* groupStart = prevGroupEnd->next;
        ListNode* groupEnd = prevGroupEnd;
        for (int i = 0; i < k; i++) {
            groupEnd = groupEnd->next;
            if (!groupEnd) return dummy->next; // Not enough nodes left
        }

        // Reverse the group
        ListNode* nextGroupStart = groupEnd->next;
        ListNode* newGroupHead = reverse(groupStart, groupEnd->next);

        // Connect the reversed group to the previous and next parts
        prevGroupEnd->next = newGroupHead;
        groupStart->next = nextGroupStart;

        // Move to the next group
        prevGroupEnd = groupStart;
    }
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Creating the linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 3;
    cout << "Original List: ";
    printList(head);

    ListNode* result = reverseKGroup(head, k);

    cout << "Reversed in Groups of " << k << ": ";
    printList(result);

    return 0;
}
