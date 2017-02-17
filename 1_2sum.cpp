/**
 * search from two ends to inside, search sum > 0 
 */
class Solution {
public:
        vector<int> twoSum(vector<int>& nums, int target) {
                unordered_map<int, int> hash;
                vector<int> result;
                for (int i=0; i<numbers.size(); i++){
                        int numberToFind = target-numbers[i];
                        if(hash.find(numberToFind) != hash.end()){
                                result.push_back(hash[numberToFind]+1);
                                result.push_back(i+1);
                                retuen result;
                        }
                        hash[numbers[i]]=i;
                }
                return result;
        }
};