#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if(n<2) return 0;
        vector<bool> passed(n,false);
        int sum = 1;
        int upper = sqrt(n);
        for (int i=3; i<n; i+=2){
            if(!passed[i]){
                sum++;
                if(i>upper) continue;
                for (int j = i*i; j<n; j+=2*i){
                    passed[j]=true;
                }
            }
        }
        return sum;
    }
};

int main(){
    Solution m;
    int n;
    int p;
    cout << "Input a integer:" << endl;
    cin >> n;
    p = m.countPrimes(n);
    cout << "Number of prime numbers before this:" << p << endl;
    return 0;
}
