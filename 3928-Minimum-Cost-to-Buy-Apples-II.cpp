class Solution {
public:
    using ll = long long;
    using P = pair<ll, int>;
    const ll INF = LLONG_MAX / 4;

    vector<ll> dijkstra(int src, vector<vector<pair<int, ll>>> &adj) {

        int n = adj.size();
        vector<ll> dist(n, INF);

        priority_queue<P, vector<P>, greater<P>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {

            auto [d, node] = pq.top();
            pq.pop();

            if (d != dist[node])
                continue;

            for (auto &[adjNode, wt] : adj[node]) {

                if (dist[adjNode] > d + wt) {

                    dist[adjNode] = d + wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }

    vector<int> minCost(int n, vector<int>& prices, vector<vector<int>>& roads) {

        vector<vector<pair<int, ll>>> normal(n), taxi(n);

        for (auto &e : roads) {

            int u = e[0];
            int v = e[1];
            ll cost = e[2];
            ll tax = e[3];

            normal[u].push_back({v, cost});
            normal[v].push_back({u, cost});

            taxi[u].push_back({v, cost * tax});
            taxi[v].push_back({u, cost * tax});
        }

        vector<int> ans;

        for (int src = 0; src < n; src++) {

            vector<ll> distEmpty = dijkstra(src, normal);
            vector<ll> distTaxi = dijkstra(src, taxi);

            ll best = prices[src];

            for (int shop = 0; shop < n; shop++) {

                if (distEmpty[shop] == INF || distTaxi[shop] == INF)
                    continue;

                best = min(best,
                           distEmpty[shop] +
                           distTaxi[shop] +
                           (ll)prices[shop]);
            }

            ans.push_back((int)best);
        }

        return ans;
    }
};