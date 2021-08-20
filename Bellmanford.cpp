class Solution {
	public:
		int networkDelayTime(vector<vector<int>>& times, int N, int K) {
			
			int n = times.size();
			if (!n) return 0;
			
			vector<int>dist(N+1, INT_MAX);
			int res = 0;
			
			dist[K] = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < n; j++) {
					int u = times[j][0];
					int v = times[j][1];
					int w = times[j][2];
					if (dist[u] != INT_MAX && dist[u] + w < dist[v])
						dist[v] = w + dist[u];
				}
			}
			
			for (int i = 1; i <= N; i++)
				res = max(res, dist[i]);

			return res == INT_MAX ? -1 : res;
		}
	}
