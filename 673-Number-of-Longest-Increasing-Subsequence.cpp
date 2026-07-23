class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
         int n = arr.size(); 
        vector<int> dp(n, 1); 
               vector<int> count(n, 1); 
        int maxLen = 0;
        for(int i = 0; i < n; i++) {
            for(int prevInd = 0; prevInd < i; prevInd++) {
                if(arr[prevInd] < arr[i] && dp[i]<dp[prevInd]+1) {
                        dp[i] = dp[prevInd] + 1; 
                         count[i] = count[prevInd];
                }
                else if(arr[prevInd] < arr[i] && dp[i]==dp[prevInd]+1){
                  count[i] += count[prevInd];
                }
            }
            if(dp[i] > maxLen) {
                maxLen = dp[i];
            } 
        }
        int ans=0;
        for(int i=0;i<n;i++){
 if(dp[i]==maxLen) ans+=count[i];
        }
        return ans;
    }
};