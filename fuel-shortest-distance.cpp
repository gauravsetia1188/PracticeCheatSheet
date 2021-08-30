
// Anonymous User
// Anonymous User
// Last Edit: July 25, 2021 9:58 PM

// 1.3K VIEWS

// I recently attended Google Interview for Software Engineer role. In one of the rounds I was asked the below question:

// Question:
// A country has multiple cities which are represented as vertices of a graph and cities are interconnected with each other through roads. These roads are represented as undirected edges between the vertices with unit weight (same weight for all roads). Now calculate the shortest path between 'A' to 'B' such that you are travelling in a car with a capacity of 'c' and there are only few cities which have fuel stations where you can fill the car to complete capacity (when you visit that vertex). When you travel from one city to another you conume a unit of fuel and at the source city you start with full capacity of fuel.

// Sample Input:
// Roads: [[1,2],[2,3],[3,4],[4,5],[4,6],[6,7]]
// A: 1, B: 7, capacity 'c': 4
// fuel stations: [5]

// Graphical notation of input graph
// 1
// |
// 2
// |
// 3
// |
// 4 - 5
// |
// 6
// |
// 7



//cpp
int shortestPathWithTwist(int n, vector< pair<int, int> > edges, int st, int ed, int cap, vector<int> stations) {
    vector<vector<int>> adj(n);
    for (auto edge : edges) {
        adj[edge.first].push_back(edge.second);
        adj[edge.second].push_back(edge.first);
    }
    vector<int> capacity(n, 0);
    capacity[st] = cap;
    for (auto v : stations) {
        capacity[v] = cap;
    }
    vector<int> fuel(n, 0);
    fuel[st] = cap;
    queue<pair<int, int>> q;
    q.push({st, 0});
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        if (cur.first == ed) {
            return cur.second;
        }
        int u = cur.first;
        for (auto v : adj[u]) {
            if (max(capacity[v], fuel[u] - 1) > fuel[v]) {
                fuel[v] = max(capacity[v], fuel[u] - 1);
                q.push({v, cur.second + 1});
            }
        }
    }
    return -1;  // unreachable
}


// python
def minFuel(n, roads, stations, capacity):                  # BFS;
                                                            # Assuming vertices 1 to n, starting at 1 and target n.
    g, caps = [[] for _ in range(n + 1)], [0] * (n + 1)
    for u, v in roads:
        g[u].append(v)
        g[v].append(u)
    for v in stations:
        caps[v] = capacity

    fuel, q = [0, capacity] + [0] * (n - 1), collections.deque([(1, 0)])
    while q:
        u, dist = q.popleft()
        if u == n:
            return dist
        for v in g[u]:
            if (new := max(caps[v], fuel[u] - 1)) > fuel[v]: # new fuel more than the existing at next node.
                fuel[v] = new
                q.append((v, dist + 1))
    return -1
