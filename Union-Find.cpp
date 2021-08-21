class Solution {
public:
    // path compression log(n)
    int find(vector<int>& parent, int node) {
        
        
        if(parent[node]==-1) {
            return node;
        }
        
        return parent[node] = find(parent,parent[node]);
        
    }
    
       
    int findCircleNum(vector<vector<int>>& edges) {
        
        int n = edges.size();
        
        vector<int> parent(n+1,-1);
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {

                if(edges[i][j]==1) {
                    int x = find(parent,i);
                    int y = find(parent,j);
                    
                    if(x!=y) {
                        parent[x]=y;
                    }
                }            
            
            }
        }
        int ans=0;
        for(int i=0;i<n;i++) {
            if(parent[i]==-1)
                ans++;
        }
        return ans;
        
    }
};
