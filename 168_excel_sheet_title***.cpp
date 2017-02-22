#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        while (n) {
            ans = char ((n - 1) % 26 + 'A') + ans;
            n = (n - 1) / 26;
        }
        return ans;
    }
};

int main(){
    int n = 28;
    Solution m;
    string res = m.convertToTitle(n);
    cout << res << endl;
    return 0;
}