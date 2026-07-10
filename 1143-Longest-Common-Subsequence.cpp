class Solution {
  public:
    int longestCommonSubsequence(string str1, string str2) {
       int n1=str1.size();
       int n2=str2.size();
       vector<vector<int>>dp(n1,vector<int>(n2,0));
       for(int ind1=0;ind1<n1;ind1++){
         for(int ind2=0;ind2<n2;ind2++){
     int both=0;
if(str1[ind1]==str2[ind2]){
    both=1;
    if(ind1>0 && ind2>0)
        both+=dp[ind1-1][ind2-1];
}
    int s1=0;
    if(ind1-1>=0) s1=dp[ind1-1][ind2];
    int s2=0;
    if(ind2-1>=0) s2=dp[ind1][ind2-1];
    dp[ind1][ind2]=max({both,s1,s2});
         }
       }
       return dp[n1-1][n2-1];
    }
};
