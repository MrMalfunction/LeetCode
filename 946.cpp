// Problem : 946. Validate Stack Sequences
// Link : https://leetcode.com/problems/validate-stack-sequences/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int j = 0;
        for(int x : pushed){
            st.push(x);
            while (!st.empty() && st.top() == popped[j]){
                st.pop();
                j++;
            }
        }
        return j == pushed.size();
    }
};

int main() {
    Solution ob;
    vector<int> pushed {1,2,3,4,5};
    vector<int> popped {4,5,3,2,1};
    cout << ob.validateStackSequences(pushed, popped);
    return 0;
}