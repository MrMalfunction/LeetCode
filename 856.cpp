// Problem : 856. Score of Parentheses
// Link : https://leetcode.com/problems/score-of-parentheses/

#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans = 0, bal = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(')
                bal++;
            else{
                bal--;
                if (s[i-1] == '(')
                    ans += 1 << bal;
            }
        }
        return ans;
    }
};

int main() {
    Solution ob;
    cout << ob.scoreOfParentheses("(())");
    return 0;
}