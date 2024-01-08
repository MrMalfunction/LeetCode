// Problem : 448. Find All Numbers Disappeared in an Array
// Link : https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        for (int i: nums) {
            ans[i - 1] = i;
        }
        vector<int> solution;
        for (int i = 0; i < nums.size(); i++) {
            if (ans[i] == 0)
                solution.push_back(i);
        }
        return solution;
    }
};

int main() {
    Solution ob;
    vector<int> solution = ob.findDisappearedNumbers(*new vector<int>{4, 3, 2, 7, 8, 2, 3, 1});
    for (int i: solution)
        cout << i << ',';
}
