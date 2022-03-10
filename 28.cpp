// Problem : 28. Implement strStr()
// Link : https://leetcode.com/problems/implement-strstr/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty())
            return 0;
        if (haystack.empty() && !needle.empty())
            return -1;

        if (haystack.size() < needle.size())
            return -1;

        if (haystack.size() == 1)
            if (haystack[0] == needle[0])
                return 0;
            else
                return -1;

        for (int i = 0; i < haystack.size(); i++) {
            if (haystack[i] == needle[0]) {
                int left = i;
                int right = left + needle.size() - 1;
                int next = left;
                if (right > haystack.size() - 1) { return -1; }

                while (left >= 0 && right <= haystack.size() - 1 && left <= right) {

                    if (next == i && haystack[left] == needle[0])
                        next = left;

                    if (haystack[left] == needle[left - i] && haystack[right] == needle[right - i]) {
                        left++;
                        right--;
                    }
                    else
                        break;
                }
                /*
                for odd length needles the left will be ahead and right will be behind the centre char
                or even length needles the left will be 1 step ahead of the right
                so check for that condition
                 */
                if (left - (needle.size() % 2 + 1) == right)
                    return i;
                // search from the next ptr
                if (next != i)
                    i = next - 1;
            }
        }

        // if not found return -1
        return -1;
    }
};

int main() {
    Solution ob;
    cout << ob.strStr("aaaaa", "aab");
    return 0;
}