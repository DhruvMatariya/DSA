class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l=0;
        int n=nums.size();
        int maxLen=0;
        unordered_map<int,int>mpp;
        for(int r=0;r<n;r++){
            mpp[nums[r]]++;
             while(mpp[nums[r]]>k && l<=r){
                mpp[nums[l]]--;
                l++;
             }
             maxLen=max(maxLen,r-l+1);
        }
        return maxLen;
    }
};