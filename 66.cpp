// Problem : 66. Plus One
// Link : https://leetcode.com/problems/plus-one/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i = digits.size() - 1; i >= 0; i--){
            if(digits[i] == 9)
                digits[i] = 0;
            else{
                ++digits[i];
                return digits;
            }
        }
        digits.push_back(0);
        digits[0] = 1;
        return digits;
    }
};

int main() {
    Solution ob;
    vector<int> digits{9,9,9,9};
    vector<int> solution = ob.plusOne(digits);
    for(int i : solution){
        cout << i << ",";
    }
    return 0;
}