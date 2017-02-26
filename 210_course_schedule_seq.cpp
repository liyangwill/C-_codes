: class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
        vector<int> degrees = compute_indegree(graph);
        
        //queue zeros to store taken courses;
        queue<int> zeros;
        
        // if degrees==0, can take the course, thus it push into queue.
        for (int i = 0; i < numCourses; i++)
            if (!degrees[i]) zeros.push(i);
        
        vector<int> toposort;
        
        // loop n times, each time take a course.
        for (int i = 0; i < numCourses; i++) {
            // if queue is empty, no course can be taken.
            if (zeros.empty()) return {};
            int zero = zeros.front();
            zeros.pop();
            toposort.push_back(zero);
            
            //after taking the course, delete it from others' prerequisites.
            for (int neigh : graph[zero]) {
                if (!--degrees[neigh])
                    zeros.push(neigh);
            }
        }
        return toposort;
    }
private:
    // a. make a graph: vector of unordered_set graph[index].insert(item).
    vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        for (auto pre : prerequisites)
            graph[pre.second].insert(pre.first);
        return graph;
    }
    // calculate numbers of the items in each index, return a vector of int.
    vector<int> compute_indegree(vector<unordered_set<int>>& graph) {
        vector<int> degrees(graph.size(), 0);
        for (auto neighbors : graph)
            for (int neigh : neighbors)
                degrees[neigh]++;
        return degrees;
    }
};
