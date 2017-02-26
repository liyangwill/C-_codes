// depth-first-search

class Solution{
public:
    vector<vector<int>> getFactors(int n){
        vector<vector<int>> ret;
        vector<int> cur;
        dfs(n, ret, cur, 1, 2);
        return ret;
    }


    void dfs(int n, vector<vector<int>>& ret, vector<int>& cur, int& production, int& pos){
        
        if (production==n)
            if (!cur.empty())
                ret.push_back(cur);
        
        
        else if(product<n && pos<n){
            for (int i=pos; i<n; ++i) {
                if (product*i>n) break;
                if (n%i!=0) continue;
                
                cur.push_back(i);
                dfs(n, ret, cur, product*i, i);
                cur.pop_back();
            }
        }
    }

};