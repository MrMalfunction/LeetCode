// Problem : 74. Search a 2D Matrix
// Link : https://leetcode.com/problems/search-a-2d-matrix/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row_size = matrix[0].size();
        for(int i = 0; i < matrix.size(); i++){
            if(target <= matrix[i][row_size - 1]){
                if(target < matrix[i][0])
                    return false;
                if (binary_search(matrix[i].begin(), matrix[i].end(), target))
                    return true;
                else
                    return false;
            }
        }
        return false;
    }
};

int main() {
    Solution ob;
    vector<vector<int>> matrix = {{1,1}};
    int target = 2;
    cout << ob.searchMatrix(matrix, target);
    return 0;
}