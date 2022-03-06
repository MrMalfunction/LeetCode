// Problem : 40. Combination Sum II
// Link : https://leetcode.com/problems/combination-sum-ii/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution {
    void combination(vector<int>& candidates, int target, vector<int> curr_combination, int currSum, int currIndex, vector<vector<int>>& ans){
        if(currSum > target)
            return;
        if(currSum == target){
            ans.push_back(curr_combination);
            return;
        }
        for (int i = currIndex; i < candidates.size(); ++i) {
            if(i > currIndex && candidates[i] == candidates[i-1])
                continue;
            curr_combination.push_back(candidates[i]);
            currSum += candidates[i];
            combination(candidates, target, curr_combination, currSum, i + 1, ans);
            curr_combination.pop_back();
            currSum -= candidates[i];
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort( candidates.begin(), candidates.end() );
        vector<vector<int>> ans;
        vector<int> curr_combination;
        combination(candidates, target, curr_combination, 0, 0, ans);
        return ans;
    }
};

int main() {
    Solution ob;
    vector<int> candidates{10,1,2,7,6,1,5};
    vector<vector<int>> solution = ob.combinationSum(candidates, 8);
    for(const vector<int>& i : solution){
        for(int j : i)
            cout << j << ",";
        cout << endl;
    }
    return 0;
}