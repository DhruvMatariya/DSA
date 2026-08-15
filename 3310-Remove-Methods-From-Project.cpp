class Solution {
public:
    void dfs(vector<int>adj[],vector<int>&d,vector<int>&vis,int node){
            vis[node]=1;
            d[node]=1;
            for(auto it: adj[node]){
                if(!vis[it]){
                 dfs(adj,d,vis,it);
                }
            }
            return;
    }
    bool check(vector<int>&d,vector<vector<int>>& invocations){
        for(auto e: invocations){
            if (d[e[1]] && !d[e[0]])
    return false;
        }
        return true;
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int>adj[n];
        vector<int>d(n,0);
        vector<int>vis(n,0);
        vector<int>ans;
        for(auto e: invocations){
            adj[e[0]].push_back(e[1]);
        }
        dfs(adj,d,vis,k);
        if(check(d,invocations)==false){
            for(int i=0;i<n;i++){
                ans.push_back(i);
            }
        }
        else{
            for(int i=0;i<n;i++){
               if(!d[i]) ans.push_back(i);
            }
        }
        return ans;
    }
};