// Problem : 49. Group Anagrams
// Link : https://leetcode.com/problems/group-anagrams/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <string>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> mp;
        vector<vector<string>>ans;
        int i=0;
        while(i<n){
            string current_word = strs[i];
            sort(current_word.begin(), current_word.end());
            mp[current_word].push_back(strs[i]);
            i++;
        }
        for (auto &i: mp)
            ans.push_back(i.second);
        return ans;
    }
};

int main() {
    Solution ob;
    vector<string> data = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> output_data = ob.groupAnagrams(data);
    for (int i = 0; i < output_data.size(); i++)
    {
        for (int j = 0; j < output_data[i].size(); j++)
        {
            cout << output_data[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}