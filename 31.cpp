// Problem : 31. Next Permutation
// Link : https://leetcode.com/problems/next-permutation/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i,j,c=0;
        for(i=nums.size()-1;i>0;i--)
        {
            if(nums[i-1]<nums[i])
            {
                c++;
                j = i-1;
                break;
            }
        }

        if(c)
        {
            reverse(nums.begin()+j+1,nums.end());
            int x = upper_bound(nums.begin()+j+1,nums.end(),nums[j]) - nums.begin();
            swap(nums[x],nums[j]);
        }
        else
            sort(nums.begin(),nums.end());
    }
};

int main() {
    Solution ob;
    vector<int> nums = {1,2,3};
    ob.nextPermutation(nums);
    return 0;
}