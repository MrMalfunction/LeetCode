// 268. Missing Number
// Link : https://leetcode.com/problems/missing-number/description/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        int sum = 0;
        for (int num: nums) {
            sum += num;
        }
        return (size * (size + 1) / 2) - sum;
    }
};

int main() {
    Solution ob;
    cout << ob.missingNumber(*new vector<int>{9, 6, 4, 2, 3, 5, 7, 0, 1});
}
