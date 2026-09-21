class Solution {
public:
    bool solve(string s1,string s2,string s3,int i,int j,int k,vector<vector<int>>&dp){
        int n=s1.size();
        int m=s2.size();
        if (k == s3.size())
            return true;
        bool take1=false;
        bool take2=false;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i<n && s1[i]==s3[k]){
          take1=solve(s1,s2,s3,i+1,j,k+1,dp);
        }
        if(j<m && s2[j]==s3[k]){
          take2=solve(s1,s2,s3,i,j+1,k+1,dp);
        }
        return dp[i][j]=take1||take2;
    }
    bool isInterleave(string s1, string s2, string s3) {
         if (s1.size() + s2.size() != s3.size())
            return false;
                int n=s1.size();
        int m=s2.size();
            vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(s1, s2, s3, 0, 0, 0,dp);
    }
};