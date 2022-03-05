// Problem : 38. Count and Say
// Link : https://leetcode.com/problems/count-and-say/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) //edge case
            return "1";
        if(n == 2) //edge case
            return "11";
        string solution_string = "11"; //starting string
        for (int i = 3; i <= n; i++) {
            int sol_length = solution_string.length();
            string temp_string;
            int curr_counter = 1; // counter of current element

            for (int j = 0; j < sol_length; j++) {
                solution_string += "$"; // adding a delimiter to catch last char of string
                if (solution_string.at(j) == solution_string.at(j + 1))
                    curr_counter++;
                else{
                    temp_string += to_string(curr_counter) + solution_string.at(j);
                    curr_counter = 1;
                }
            }
            solution_string = temp_string;
        }
        return solution_string;
    }
};

int main() {
    Solution ob;
    cout << ob.countAndSay(20);
    return 0;
}