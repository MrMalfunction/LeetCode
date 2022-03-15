// Problem : 1249. Minimum Remove to Make Valid Parentheses
// Link : https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/

#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> bracket_pos;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(')
                bracket_pos.push(i);
            else if(s[i] == ')' && !bracket_pos.empty())
                bracket_pos.pop();
            else if(s[i] == ')')
                s.erase(s.begin() + i--);
        }
        while(!bracket_pos.empty()){
            s.erase(s.begin() + bracket_pos.top());
            bracket_pos.pop();
        }
        return s;
    }
};

int main() {
    Solution ob;
    cout << ob.minRemoveToMakeValid("lee(t(c)o)de)");
    return 0;
}