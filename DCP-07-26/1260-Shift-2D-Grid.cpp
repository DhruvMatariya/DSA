class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int>v;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                v.push_back(grid[i][j]);
            }
        }
        int size=n*m;
        k=k%size;
        reverse(v.begin(),v.begin()+size-k);
        reverse(v.begin()+size-k,v.end());
        reverse(v.begin(),v.end());
        for(int i=0;i<size;i++){
            grid[i/m][i%m]=v[i];
        }
        return grid;
    }
};