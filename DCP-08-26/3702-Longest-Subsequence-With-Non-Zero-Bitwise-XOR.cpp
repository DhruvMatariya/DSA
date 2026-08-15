class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int Xor=0;
        int cnt0=0;
        for(int i=0;i<nums.size();i++){
        Xor^=nums[i];
        if(nums[i]==0) cnt0++;
        }
        if(cnt0==nums.size()) return 0;
        if(Xor!=0) return nums.size();
        else return nums.size()-1;
    }
};