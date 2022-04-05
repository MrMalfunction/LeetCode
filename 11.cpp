// Problem : 11. Container With Most Water
// Link : https://leetcode.com/problems/container-with-most-water/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int Area = 0;
        int x1 = 0;
        int x2 = height.size() - 1;
        while(x1 != x2){
            int newArea = (x2 - x1) * min(height[x1], height[x2]);
            Area = max(newArea, Area);
            if(height[x1] < height[x2]){
                ++x1;
                continue;
            }
            --x2;
        }
        return Area;
    }
};

int main() {
    Solution ob;
    vector<int> height{10,1,2,7,6,1,5};
    cout << ob.maxArea(height);
    return 0;
}