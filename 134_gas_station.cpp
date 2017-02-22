/**
 * search from two ends to inside, search sum > 0 
 */
class Solution {
public:
        int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
                
                int start = gas.size()-1;
                int end = 0;
                int sum = gas[start] - cost[start];
                while (start > end) {
                        if (sum >= 0) {
                                sum += gas[end] - cost[end];
                                ++end;
                        }
                        else {
                                --start;
                                sum += gas[start] - cost[start];
                        }
                }
                return sum >= 0 ? start : -1;
        }
};
/**
 * method 2:
 * equivalent problem: find the minsum(from 0 to index)
 */
class Solution {
public:
        int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
                int n = gas.size();
                int sum(0), minsum(INT_MAX), start_index(0);
                for(int i=0; i!=n; ++i){
                        sum += gas[i]-cost[i];
                        if(sum<minsum){
                                minsum = sum;
                                start_index = i+1;
                        }
                }
                return (sum < 0) ?  -1 : start_index%n;
        }
};