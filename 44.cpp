// 44. Wildcard Matching
// Link : https://leetcode.com/problems/wildcard-matching/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int patternPointer = 0;
        int stringPointer = 0;
        // looop over string and check it in pattern, if pattern is not wildcard then increase the patternPointer.
        for (; stringPointer < s.size();) {
            if (patternPointer >= p.size()) {
                return false;
            }
            if (p.at(patternPointer) == '?' || p.at(patternPointer) == s.at(stringPointer)) {
                patternPointer++;
            } else if (p.at(patternPointer) == '*') {
                if (patternPointer < p.size() - 1)
                    return isMatch(s, p.erase(patternPointer));
                return true;
            }
            return false;
        }
        if (patternPointer < p.size() && p.at(patternPointer) != '*' && p.at(patternPointer) != '?')
            return false;
        return true;
    }
};

int main() {
    Solution ob;
    cout << ob.isMatch("adceb", "*a*b");
}
