// Problem : 33. Search in Rotated Sorted Array
// Link : https://leetcode.com/problems/search-in-rotated-sorted-array/description/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int lo = 0, hi = int(nums.size()) - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if ((nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid]))
                lo = mid + 1;
            else
                hi = mid;
        }
        return lo == hi && nums[lo] == target ? lo : -1;
    }
};

int main() {
    vector<int> data;
    data.push_back(4);
    data.push_back(5);
    data.push_back(6);
    data.push_back(7);
    data.push_back(0);
    data.push_back(1);
    data.push_back(2);
    int target = 1;
    Solution ob;
    cout << ob.search(data, target);
    return 0;
}