int computeShortest(vector<vector<int>>& arr, int n, int src) {
	
			priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
			vector<int>dist(N+1, INT_MAX);
			
			pq.push(make_pair(0, src)); // {distance, node}
			dist[src] = 0;
			
			unordered_map<int, vector<pair<int, int>>>graph; // create graph
			for (int i = 0; i < arr.size(); i++)
				graph[arr[i][0]].push_back(make_pair(arr[i][1], arr[i][2]));    //  node : {node1, dist}
			
			while (!pq.empty()) {
				pair<int, int>p = pq.top();
				pq.pop();
				
				int u = p.second;
				for (auto it = hm[u].begin(); it != hm[u].end(); it++) {
					int v = it->first;
					int w = it->second;
					
					if (dist[v] > dist[u] + w) {
						dist[v] = dist[u] + w;
						pq.push(make_pair(dist[v], v));
					}
				}
			}
			
			int res = 0;
			for (int i = 1; i <= N; i++)
				res = max(res, dist[i]);
			
			return res == INT_MAX ? -1 : res;
		}
	};
