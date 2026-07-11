class Solution {
public:
    int minInsertions(string s) {
         int n=s.size();
        int m=n;
        string str1=s;
        string str2=s;
        reverse(str2.begin(),str2.end());
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1)); 
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        for (int i = 0; i <= m; i++) {
            dp[0][i] = 0;
        }
        for (int ind1 = 1; ind1 <= n; ind1++) {
            for (int ind2 = 1; ind2 <= m; ind2++) {
                if (str1[ind1 - 1] == str2[ind2 - 1])
                    dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];   
                else
                    dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]); 
            }
        }
        return s.size()-dp[n][m]; 
    }
};