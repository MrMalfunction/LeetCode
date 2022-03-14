// Problem : 71. Simplify Path
// Link : https://leetcode.com/problems/simplify-path/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string return_path;
        for (int i = 0; i < path.size(); ++i) {
            if (path[i] == '/')
                continue;
            string temp;
            while (i < path.size() && path[i] != '/') {
                temp += path[i];
                ++i;
            }
            if (temp == ".")
                continue;
            else if (temp == "..") {
                if (!st.empty())
                    st.pop();
            } else
                st.push(temp);
        }

        while (!st.empty()) {
            return_path = "/" + st.top() + return_path;
            st.pop();
        }

        if (return_path.size() == 0)
            return "/";

        return return_path;
    }
};

int main() {
    Solution ob;
    cout << ob.simplifyPath("/..hidden");
    return 0;
}