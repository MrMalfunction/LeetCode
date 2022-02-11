// Problem : 24. Swap Nodes in Pairs
// Link : https://leetcode.com/problems/swap-nodes-in-pairs/

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (head == nullptr || head->next == nullptr) // Edge case handle, edge cases : [], [1]
            return head;

        ListNode *newHead = new ListNode(-1, head); // new virtual head
        ListNode *curr = newHead; // current node pointer

        while (curr->next->next != nullptr) {
            ListNode *temp = curr->next; // save the next node
            curr->next = temp->next; // connect current node to node 2 ahead
            curr = curr->next; //move 1 step
            temp->next = curr->next;
            curr->next = temp; // insert temp node 2 pos ahead of it's original
            curr = curr->next;
            if (curr->next == nullptr) //edge case
                break;
        }
        return newHead->next;
    }
};

int main() {
    ListNode head = ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, nullptr))));
    Solution ob;
    ListNode* output = ob.swapPairs(&head);
    while (output != nullptr){
        cout << output->val << endl;
        output = output->next;
    }
    return 0;
}
