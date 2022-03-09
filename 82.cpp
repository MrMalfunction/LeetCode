// Problem : 82.
// Link :

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *sentinal = new ListNode(-200, head);
        ListNode *prev = sentinal;
        while (head) {
            if (head->next && head->next->val == head->val) {
                while (head->next && head->val == head->next->val) {
                    head = head->next;
                }
                prev->next = head->next;
            } else
                prev = prev->next;
            head = head->next;
        }
        return sentinal->next;
    }
};

int main() {
//    ListNode head = ListNode(1, new ListNode(2, new ListNode(3, new ListNode(3, new ListNode(4, new ListNode(4, new ListNode(5, nullptr)))))));
    ListNode head = ListNode(1, new ListNode(1, nullptr));

    Solution ob;
    ListNode *output = ob.deleteDuplicates(&head);
    while (output != nullptr) {
        cout << output->val << endl;
        output = output->next;
    }
    return 0;
}