// https://leetcode.com/problems/minimum-number-of-refueling-stops/

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        
        int curr = startFuel;
        int n = stations.size();
        priority_queue<int> pq;
        int stops = 0;
        int i = 0;
        while(curr<target) {
            
            while(i<n && curr>=stations[i][0]) {
                pq.push(stations[i][1]);
                i++;
            }
            
            if(pq.empty()) {
                return -1;
            }
            int additionalFuel = pq.top();
            pq.pop();
            
            curr+=additionalFuel;
            stops++;                       
        }
        
        return stops;
        
        
    }
};
