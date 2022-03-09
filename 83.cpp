// Problem : 83. Remove Duplicates from Sorted List
// Link : https://leetcode.com/problems/remove-duplicates-from-sorted-list/

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
    ListNode *deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        while(curr && curr->next ){
            if(curr->val == curr->next->val)
                curr->next = curr->next->next;
            else
                curr = curr->next;
        }
        return head;
    }
};

int main() {
    ListNode head = ListNode(1, new ListNode(2, new ListNode(3, new ListNode(3, new ListNode(4, new ListNode(4, new ListNode(5, nullptr)))))));
//    ListNode head = ListNode(1, new ListNode(2, nullptr));
    Solution ob;
    ListNode *output = ob.deleteDuplicates(&head);
    while (output != nullptr) {
        cout << output->val << endl;
        output = output->next;
    }
    return 0;
}