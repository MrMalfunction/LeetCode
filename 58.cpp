// Problem : 58. Length of Last Word
// Link : https://leetcode.com/problems/length-of-last-word/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int size = 0, i;
        for(i = s.size() - 1; i >=0 ; --i)
            if(s[i] != ' ')
                ++size;
            else if(size != 0)
                break;
        return size;
    }
};

int main() {
    Solution ob;
    cout << ob.lengthOfLastWord("   fly me   to   the moon  ");
    return 0;
}