#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head);
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;

        // Move fast n+1 steps ahead so slow ends up
        // just before the node to remove
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // Move both until fast reaches the end
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // slow->next is the node to remove
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;

        return dummy.next;
    }
};

// ---------- Helper functions for testing ----------

// Build a linked list from a vector
ListNode* buildList(const vector<int>& vals) {
    ListNode dummy;
    ListNode* tail = &dummy;
    for (int v : vals) {
        tail->next = new ListNode(v);
        tail = tail->next;
    }
    return dummy.next;
}

// Print a linked list as [1,2,3]
void printList(ListNode* head) {
    cout << "[";
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << ",";
        head = head->next;
    }
    cout << "]" << endl;
}

// Free all nodes in a linked list
void freeList(ListNode* head) {
    while (head != nullptr) {
        ListNode* next = head->next;
        delete head;
        head = next;
    }
}

int main() {
    Solution sol;

    // Example 1: head = [1,2,3,4,5], n = 2 -> [1,2,3,5]
    ListNode* l1 = buildList({1, 2, 3, 4, 5});
    ListNode* r1 = sol.removeNthFromEnd(l1, 2);
    cout << "Example 1: ";
    printList(r1);
    freeList(r1);

    // Example 2: head = [1], n = 1 -> []
    ListNode* l2 = buildList({1});
    ListNode* r2 = sol.removeNthFromEnd(l2, 1);
    cout << "Example 2: ";
    printList(r2);
    freeList(r2);

    // Example 3: head = [1,2], n = 1 -> [1]
    ListNode* l3 = buildList({1, 2});
    ListNode* r3 = sol.removeNthFromEnd(l3, 1);
    cout << "Example 3: ";
    printList(r3);
    freeList(r3);

    return 0;
}