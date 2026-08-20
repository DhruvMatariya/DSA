class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
       vector<long long> ans;

        for (long long x : nums) {
            ans.push_back(x);

            while (ans.size() >= 2 &&
                   ans[ans.size() - 1] == ans[ans.size() - 2]) {
                
                long long val = ans.back();
                ans.pop_back();
                ans.pop_back();

                ans.push_back(val * 2);
            }
        }

        return ans;
    }
};