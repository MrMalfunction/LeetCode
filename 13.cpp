
// Problem : 13. Roman to Integer
// Link : https://leetcode.com/problems/roman-to-integer/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        char symbols[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        int values[7] = {1, 5, 10, 50, 100, 500, 1000};
        int len = s.length();
        int num;
        int answer = 0;
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < 7; j++) {
                if (int(s.at(i)) == int(symbols[j])) {
                    if (i == 0) {
                        answer = answer + values[j];
                        num = values[j];
                        break;
                    }
                    if (num < values[j]) {
                        answer = answer - num;
                        answer = answer + values[j] - num;
                    }
                    else
                        answer = answer + values[j];
                    num = values[j];
                    break;
                }
            }
        }
        return answer;
    }
};

int main() {
    Solution ob;
    cout << ob.romanToInt("MCMXCIV");
    return 0;
}