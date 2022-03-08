// Problem : 27. Remove Element
// Link : https://leetcode.com/problems/remove-element/submissions/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        nums.erase(remove(nums.begin(), nums.end(), val), nums.end());
        return nums.size();
    }
};

int main() {
    vector<int> vect = {3,2,2,3};
    Solution ob;
    cout << ob.removeElement(vect,3);
    return 0;
}