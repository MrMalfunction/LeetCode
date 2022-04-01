// Problem : 344. Reverse String
// Link : https://leetcode.com/problems/reverse-string/submissions/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int low_pointer = 0, high_pointer = s.size()-1;
        while (low_pointer < high_pointer){
            char temp = s[low_pointer];
            s[low_pointer++] = s[high_pointer];
            s[high_pointer--] = temp;
        }
    }
};

int main() {
    Solution ob;
    vector<char> s = {'H', 'e', 'l', 'l', 'o'};
    ob.reverseString(s);
    return 0;
}