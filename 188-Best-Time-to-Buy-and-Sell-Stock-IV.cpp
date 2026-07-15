class Solution {
public:
    int maxProfit(int k, vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(2*k+1,0));
      for(int ind=n-1;ind>=0;ind--){
        for(int transaction=1;transaction<=2*k;transaction++){
             int profit=INT_MIN;
    if(transaction%2==0){
        profit=max(-arr[ind]+dp[ind+1][transaction-1],0+dp[ind+1][transaction]);
    }
    else{
        profit=max(arr[ind]+dp[ind+1][transaction-1],0+dp[ind+1][transaction]);
    }
 dp[ind][transaction]=profit;
        }
      }
          return dp[0][2*k];
    }
};