//sequentially traverse the string
//search to the left and right at a certain character

class Solution {
public:
        string longestPalindrome(string s) {
                if(s.empty()) return "";
                if(s.size()==1) return s;
                int start=0, max_len=1;
            
                for(int i=0; i<s.size();){
                        if(s.size()-i<=max_len/2) break;
                        //stop search after i if max_len>space left.
                    
                        //search j,k to the left and riht.
                        int j=i,k=i;
                    
                        //skip dulicates.
                        while(k<s.size()-1 && s[k+1]==s[k]) ++k;
                        i=k+1;
                    
                        //search j,k to the left and riht.
                        while(k<s.size()-1 && j>0 && s[k+1]==s[j-1]){++k; --j;}
                    
                        max_len = max(max_len, k-j+1);
                        start = max_len > k-j+1 ? start : j;
                }
                return s.substr(start, max_len);
        }
};