/**
 * search from two ends to inside, search sum > 0 
 */
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
        vector<int> twoSum(vector<int>& nums, int target) {
                unordered_map<int, int> hash;
                vector<int> result;
                for (int i=0; i<nums.size(); i++){
                        int numberToFind = target-nums[i];
                        //if no found, .find returns .end()
                        if(hash.find(numberToFind) != hash.end()){
                                result.push_back(hash[numberToFind]+1);
                                result.push_back(i+1);
                                return result;
                        }
                        hash[nums[i]]=i;
                }
                return result;
        }
};

int main(){
    int start_s=clock();
    int target=10;
    int num[] = {2, 3, 4, 5, 6, 4};
    vector<int> nums(num, num+6);
    Solution m;
    vector<int> res = m.twoSum(nums, target);
    cout << "2 sum index:" << res[0] << "  " << res[1] << endl;
    int stop_s=clock();
    cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
    return 0;
}