#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

struct compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val; // Min Heap
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {

    priority_queue<ListNode*, vector<ListNode*>, compare> pq;

    // Insert first node of each list
    for (auto node : lists) {
        if (node)
            pq.push(node);
    }

    ListNode dummy(0);
    ListNode* tail = &dummy;

    while (!pq.empty()) {
        ListNode* temp = pq.top();
        pq.pop();

        tail->next = temp;
        tail = tail->next;

        if (temp->next)
            pq.push(temp->next);
    }

    return dummy.next;
}

// Function to print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    // List 1: 1 -> 4 -> 5
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);

    // List 2: 1 -> 3 -> 4
    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    // List 3: 2 -> 6
    ListNode* l3 = new ListNode(2);
    l3->next = new ListNode(6);

    vector<ListNode*> lists = {l1, l2, l3};

    ListNode* result = mergeKLists(lists);

    cout << "Merged List: ";
    printList(result);

    return 0;
}