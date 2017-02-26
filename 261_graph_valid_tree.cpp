// DFS
class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<vector<int>> g(n, vector<int>());
        
        // v[n]: if nth node is visited
        vector<bool> v(n, false);
        
        // keep edges relation in g, nth row is for node n.
        for (auto a : edges) {
            g[a.first].push_back(a.second);
            g[a.second].push_back(a.first);
        }
        
        // any loop in the graph
        if (!dfs(g, v, 0, -1)) return false;
        
        // search for unvisited node
        for (auto a : v) {
            if (!a) return false;
        }
        return true;
    }
                                        // cur, pre index pointers
    bool dfs(vector<vector<int>> &g, vector<bool> &v, int cur, int pre) {
        // if cur node has been visited, there is a loop.
        if (v[cur]) return false;
        v[cur] = true;
        
        for (auto a : g[cur]) {
            if (a != pre) {
                if (!dfs(g, v, a, cur)) return false;
            }
        }
        return true;
    }
};

// BFS, with queue
// traverse all node with queue, when visiting each node, add all connected nodes into the unordered_set and queque, and delete the connection in its partners' connection

class Solution2 {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<unordered_set<int>> g(n, unordered_set<int>());
        unordered_set<int> v; // v stores visited nodes.
        queue<int> q;
        q.push(0);
        v.insert(0);
        
        for (auto a : edges) {
            g[a.first].insert(a.second);
            g[a.second].insert(a.first);
        }
        
        while (!q.empty()) {
            int t = q.front(); q.pop();
            for (auto a : g[t]) {
                
                // if visited node exists, loop exists, return false
                if (v.find(a) != v.end()) return false;
                v.insert(a);
                q.push(a);
                //delete the connection in its partners' connection list
                g[a].erase(t);
            }
        }
        return v.size() == n;
    }
};