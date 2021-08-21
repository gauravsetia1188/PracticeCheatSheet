    bool detectCycleUtil(vector<vector<int>>& graph, vector<int>& visited, int i) {
        
        if(visited[i]==1)
            return true;
        if(visited[i]==2)
            return false;
        
        visited[i] = 1;
        
        for(int j=0;j<graph[i].size();j++) {
            if(detectCycleUtil(graph, visited,graph[i][j]))
                return true;
        }
        
        visited[i] = 2;
        return false;
        
    }
    
    bool detectCycle(vector<vector<int>>& graph, int n) {
        
        vector<int> visited(n,0);
        
        for(int i=0;i<n;i++) {
            if(visited[i]==0)
                if(detectCycleUtil(graph,visited,i))
                    return true;
        }
        
        return false;
        
    }
