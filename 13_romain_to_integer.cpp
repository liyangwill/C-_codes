/**
 * Create a hash talble that stores the letter-value pairs.
 *
 * travers from the back, s[i] < s[i+1] deduction, s[i] > s[i+1] add to the sum.
 *
 * unordered_map T[char] = int; str.length; str.back;
 * 
 */
class Solution {
public:
        int romanToInt(string s) {
                unordered_map<char, int> T = { { 'I' , 1 },
                                        { 'V' , 5 },
                                        { 'X' , 10 },
                                        { 'L' , 50 },
                                        { 'C' , 100 },
                                        { 'D' , 500 },
                                        { 'M' , 1000 } };
                
                int sum = T[s.back()];
                for (int i = s.length() - 2; i >= 0; --i){
                        if (T[s[i]] < T[s[i + 1]]){
                                sum -= T[s[i]];
                        }
                        else{
                                sum += T[s[i]];
                        }
                }
                
                return sum;  
        }
};