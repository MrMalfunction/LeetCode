// Problem : 34. Find First and Last Position of Element in Sorted Array
// Link : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        vector<int> v(2, -1); // array of 2 -1's
        if (!binary_search(nums.begin(), nums.end(), target)) //binary search for target
            return v;
        v.clear();
        v.push_back(lower_bound(nums.begin(), nums.end(), target) - nums.begin()); // find lower bound for target
        v.push_back((upper_bound(nums.begin(), nums.end(), target) - nums.begin()) - 1); // find upper bound of target
        return v;
    }
};

int main() {
    vector<int> data;
    data.push_back(5);
    data.push_back(7);
    data.push_back(7);
    data.push_back(8);
    data.push_back(8);
    data.push_back(10);
    Solution ob;
    vector<int> solution = ob.searchRange(data, 8);
    for (auto i: solution) {
        cout << i << " ";
    }
}