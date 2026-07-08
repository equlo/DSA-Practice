#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;

        while (prev->next && prev->next->next) {
            ListNode* first = prev->next;
            ListNode* second = first->next;

            // Swap
            first->next = second->next;
            second->next = first;
            prev->next = second;

            // Move to the next pair
            prev = first;
        }

        return dummy.next;
    }
};

// Function to insert node at end
void insert(ListNode*& head, int val) {
    if (!head) {
        head = new ListNode(val);
        return;
    }

    ListNode* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = new ListNode(val);
}

// Function to print list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next)
            cout << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    ListNode* head = nullptr;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        insert(head, x);
    }

    Solution obj;
    head = obj.swapPairs(head);

    printList(head);

    return 0;
}