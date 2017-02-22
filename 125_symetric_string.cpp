class Solution {
public:
        bool isPalindrome(string s) {
                for(int i=0, j=s.size()-1; i<j; i++,j--){   //two pointers from both ends
                        while(!isalnum(s[i]) && i < j) i++;
                        while(!isalnum(s[j]) && i< j) j--;    // isalnum()
                        if (toupper(s[i]) != toupper(s[j])) return false; // toupper() 
                }
                return true;
        }
};