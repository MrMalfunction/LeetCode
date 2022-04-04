// Problem : 1721. Swapping Nodes in a Linked List
// Link : https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* left = head;
        ListNode* right = head;
        ListNode* curr = head;

        int counter = 1;
        while(curr!=NULL){
            if (counter<k){
                left = left->next;
            }
            if (counter>k){
                right = right->next;
            }
            curr = curr->next;
            counter++;
        }
        //swap values
        int temp = left->val;
        left->val = right->val;
        right->val = temp;

        return head;
    }
};

int main(){
    ListNode head = ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, nullptr))));
    Solution ob;
    ListNode* output = ob.swapNodes(&head);
    while (output != nullptr){
        cout << output->val << endl;
        output = output->next;
    }
    return 0;
}