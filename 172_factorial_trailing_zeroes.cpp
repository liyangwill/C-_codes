#include<iostream>
using namespace std;

class Solution{
public:
    int trailingZeros(int n){
        return n == 0 ? 0 : (n/5 + trailingZeros(n/5));
    }
};

int main(){
    int n = 100;
    Solution m;
    int res = m.trailingZeros(n);
    cout << res << endl;
    return 0;
}