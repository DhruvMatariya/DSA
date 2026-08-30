class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }
        vector<int> depth(n, 0);
        queue<int> q;
        depth[0] = 1;
        q.push(0);
        int h = 1;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            h = max(h, depth[node]);
            for (int child : adj[node]) {
                depth[child] = depth[node] + 1;
                q.push(child);
            }
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += 1LL * nums[i] * (h - depth[i] + 1);
        }
        return ans;
    }
};