/**
 *  count and say
 *  "1" "11" "21" "1211" .....
 */

class Solution {
public:
        string countAndSay(int n) {
                if(n==0) return "";
                string res = "1";
                while(--n){
                        string say = "";
                        for(int i = 0; i < res.size(); i++){ //search and move count steps
                                int count = 1;
                                while( i+1 < res.size() && res[i] == res[i+1]){
                                        count++;
                                        i++;
                                }
                                say += to_string(count) + res[i]; // to_string
                        }
                        res = say;
                }
                return res;
        }
};