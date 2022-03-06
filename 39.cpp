// Problem : 39. Combination Sum
// Link : https://leetcode.com/problems/combination-sum/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    void combination(vector<int>& candidates, int target, vector<int> curr_combination, int currSum, int currIndex, vector<vector<int>>& ans){
        if(currSum > target)
            return;
        if(currSum == target){
            ans.push_back(curr_combination);
            return;
        }
        for (int i = currIndex; i < candidates.size(); i++) {
            curr_combination.push_back(candidates[i]);
            currSum += candidates[i];
            combination(candidates, target, curr_combination, currSum, i, ans);
            curr_combination.pop_back();
            currSum -= candidates[i];
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr_combination;
        combination(candidates, target, curr_combination, 0, 0, ans);
        return ans;
    }
};

int main() {
    Solution ob;
    vector<int> candidates{2,3,6,7};
    vector<vector<int>> solution = ob.combinationSum(candidates, 7);
    for(vector<int> i : solution){
        for(int j : i)
            cout << j << ",";
        cout << endl;
    }
    return 0;
}