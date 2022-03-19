// Problem : 895. Maximum Frequency Stack
// Link : https://leetcode.com/problems/maximum-frequency-stack/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class FreqStack {
    priority_queue<vector<int>>pq;
    map<int,int>fre;
    int serial=0;
public:
    FreqStack() {}

    void push(int val) {
        fre[val]++;
        pq.push({fre[val],++serial,val});
    }

    int pop() {
        auto vc=pq.top();
        pq.pop();
        fre[vc[2]]--;
        return vc[2];
    }
};

int main() {
    // Didn't write as too much work.
    return 0;
}