// Problem : 316. Remove Duplicate Letters
// Link : https://leetcode.com/problems/remove-duplicate-letters/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        vector<int> cnt(26, 0);
        vector<bool>vis(26, false);
        string ans = "";

        for (int i = 0; i < n; i++)
            cnt[s[i] - 'a']++;

        for (char x : s) {
            cnt[x - 'a']--;

            if (! vis[x - 'a']) {

                while (ans.size() && ans.back() > x && cnt[ans.back() - 'a']) {
                    vis[ans.back() - 'a'] = false;
                    ans.pop_back();
                }

                ans += x;
                vis[x - 'a'] = true;
            }
        }
        return ans;
    }

};

int main() {
    Solution ob;
    cout << ob.removeDuplicateLetters("cbacdcbc");
    return 0;
}