// 136. Single Number
// Link : https://leetcode.com/problems/single-number/description/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int num = 0;
        for (int i: nums)
            num ^= i;
        return num;
    }
};

int main() {
    Solution ob;
    cout << ob.singleNumber(*new vector<int>{2, 2, 1});
}
