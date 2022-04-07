// Problem : 1046. Last Stone Weight
// Link : https://leetcode.com/problems/last-stone-weight/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones)
    {
        priority_queue<int> pq(stones.begin(),stones.end());
        while(pq.size()>1)
        {
            int y=pq.top();
            pq.pop();
            int x=pq.top();
            pq.pop();
            if(x!=y) pq.push(y-x);
        }
        return pq.empty()? 0 : pq.top();
    }
};

int main() {
    Solution ob;
    vector<int> arr{2,7,4,1,8,1};
    cout << ob.lastStoneWeight(arr);
    return 0;
}