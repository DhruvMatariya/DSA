class DisjointSet{
vector<int>parent,size;
public:
DisjointSet(int n){
    parent.resize(n+1,0);
    size.resize(n+1,1);
    for(int i=0;i<=n;i++) parent[i]=i;
}
int findUpar(int node){
    if(parent[node]==node) return node;
    return parent[node]=findUpar(parent[node]);
}
void unionBySize(int u,int v){
    int ulp_u=findUpar(u);
    int ulp_v=findUpar(v);
    if(ulp_u==ulp_v) return;
    if(size[ulp_u]<size[ulp_v]){
        parent[ulp_u]=ulp_v;
        size[ulp_v]+=size[ulp_u];
    }
    else{
         parent[ulp_v]=ulp_u;
        size[ulp_u]+=size[ulp_v];
    }
}
};
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        DisjointSet ds(n);
        for(int i=1;i<n;i++){
           if(nums[i]-nums[i-1]<=maxDiff){
            int u=i;
            int v=i-1;
            if(ds.findUpar(u)!=ds.findUpar(v)){
                ds.unionBySize(u,v);
            }
           }
        }
        vector<bool>ans;
        for(auto it: queries){
            int u=it[0];
            int v=it[1];
            ans.push_back(ds.findUpar(u)==ds.findUpar(v));
        }
        return ans;
    }
};