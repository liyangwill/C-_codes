#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    int minSubArrayLen(int s, vector<int>& nums){
        int n=nums.size(), start=0, sum=0, minlen=INT_MAX;
        for (int i=0; i<n; i++) {
            sum+=nums[i];
            while (sum>=s) {
                minlen=min(minlen, i-start+1);
                sum-=nums[start++];
            }
        }
        return minlen == INT_MAX ? 0 : minlen;
    }
};

int main(){
    int s, input;
    vector<int> nums;
    cout<< "sum:"<<endl;
    cin >> s;
    cout<<"number arrays (non-integer to stop):" <<endl;
    while (cin >> input) //enter any non-integer to end the loop!
    {
        nums.push_back(input);
    }
    Solution m;
    int res = m.minSubArrayLen(s, nums);
    
    cout << "mininum length of numbers that have larger sum :" <<res<<endl;
    return 0;
}