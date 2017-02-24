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
                    
                        //search and move count steps
                        for(int i = 0; i < res.size(); i++){                                 int count = 1;
                                while( i+1 < res.size() && res[i] == res[i+1]){
                                        count++;
                                        i++;
                                }
                                //to_string
                                say += to_string(count) + res[i];
                        }
                        res = say;
                }
                return res;
        }
};