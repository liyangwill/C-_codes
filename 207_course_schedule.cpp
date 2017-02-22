// BFS
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
        vector<int> degrees = compute_indegree(graph);
        // search n times, each time take a course
        for (int i = 0; i < numCourses; i++) {
            int j = 0;
            for (; j < numCourses; j++)
                if (!degrees[j]) break;
            
            //no course can be taken (when degree != 0)
            if (j == numCourses) return false;
            degrees[j] = -1; //degreen = -1 for taken courses
            
            //after taking a course, deduct from other course degree.
            for (int neigh : graph[j])
                degrees[neigh]--;
        }
        return true;
    }
    
// 1 : 2, 3, 5
// 2 : 4, 6, 7
//  .....
    
private:
    //create a graph, first is course number, seconde is prerequisted course number.
    vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        for (auto pre : prerequisites)
            graph[pre.second].insert(pre.first);
        return graph;
    }
    //create a vector, storing number of prerequisted course numbers.
    vector<int> compute_indegree(vector<unordered_set<int>>& graph) {
        vector<int> degrees(graph.size(), 0);
        for (auto neighbors : graph)
            for (int neigh : neighbors)
                degrees[neigh]++;
        return degrees;
    }
};