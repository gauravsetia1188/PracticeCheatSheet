class Solution {
        
public:
    
    
    void dfs(vector<vector<int>>& graph, vector<bool>& visited, stack<int>& s, int i) {
        
        visited[i] = true;
        
        for(int j=0;j<graph[i].size();j++) {
            if(!visited[graph[i][j]])
                dfs(graph, visited, s, graph[i][j]);
        }
        
        s.push(i);
        
    }
    
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        int n = prerequisites.size();
        vector<vector<int>> graph(numCourses+1);
        
        for(int i=0;i<n;i++) {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        vector<int> ans;
       
        vector<bool> visited(numCourses, false);
        
        stack<int> s;
        
        for(int i=0;i<numCourses;i++) {
            if(!visited[i])
                dfs(graph,visited, s,i); // for topological sort
        }
        
        while(!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        
        return ans;
        
    }
};
