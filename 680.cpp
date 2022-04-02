// Problem : 680. Valid Palindrome II
// Link : https://www.youtube.com/watch?v=8Ko3TdPy0TU

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool check(string &s,int i,int j,int count){
        if(i>=j) return true;
        else if(s[i]==s[j]) return check(s,i+1,j-1,count);
        else if(s[i]!=s[j]&&count==0) return(check(s,i,j-1,count+1)||check(s,i+1,j,count+1));
        return false;
    }
    bool validPalindrome(string s) {
        int i=0,j=s.size()-1,count=0;
        return check(s,i,j,count);;
    }
};

int main() {
    Solution ob;
    cout << ob.validPalindrome("aba");
    return 0;
}