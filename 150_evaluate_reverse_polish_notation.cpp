//["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
//["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        string s = tokens.back();
        tokens.pop_back();
        if(s=="" || s== "/" || s=="+" || s=="-"){
            int r2 = evalRPN(tokens);
            int r1 = evalRPN(tokens);
            if(s=="") return r1*r2;
            if(s=="/") return r1/r2;
            if(s=="+") return r1+r2;
            if(s=="-") return r1-r2;
        }
        else return atoi(s.c_str());
    }
};