// brute force
// Given "aacecaaa", return "aaacecaaa".
// substr(index1, index2) return substr[index1, index2-1]
// space O(n), time O(n^2)

class Solution {
public:
    string shortestPalindrome(string s) {
        string s2=s;
        reverse(s2.begin(),s2.end());
        int n=s.size(),l;
        
        for(l=n;l>=0;l--)
        {
            if(s.substr(0,l)==s2.substr(n-l, l))
                break;
        }
        return s2.substr(0,n-l)+s;
    }
};