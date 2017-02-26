//longest substr without repeated letters

//create a dict storing index of last appearance

//256 ASCII

class Solution {
public:
        int lengthOfLongestSubstring(string s) {
                vector<int> dict(256, -1); // a vector of 256 -1s.
                int maxLen = 0, start = -1; //start is for substring start.
            
                for(int i=0; i<s.length();i++){
                        if(dict[s[i]] > start)
                                start = dict[s[i]];
                    
                        // update char's last appearance index
                        dict[s[i]]=i;
                        maxLen = max(maxLen, i-start);
                }
                return maxLen;
        }
};

//

