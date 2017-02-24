//longest substr without repeated letters
//create a dict storing index of last appearance

class Solution {
public:
        int lengthOfLongestSubstring(string s) {
                vector<int> dict(256, -1); // a vector of 256 -1s.
                int maxLen = 0, start = -1; //start is for substring start.
            
                for(int i=0; i<s.length();i++){
                        if(dict[s[i]] > start)
                                start = dict[s[i]];
                        dict[s[i]]=i;
                        maxLen = max(maxLen, i-start);
                }
                return maxLen;
        }
};


for (int i=0; i<s.length(); i++){
    if(dict[s[i]]>start){
        start = dict[s[i]];
    }
    dict[s[i]] = i;
    maxLen = max(maxLen, i-start);
}