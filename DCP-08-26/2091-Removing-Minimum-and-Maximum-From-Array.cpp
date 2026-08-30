class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int mini=1e9;
        int maxi=-1e9;
        int minInd=0,maxInd=0;
        for(int i=0;i<n;i++){
            if(nums[i]<mini){
                mini=nums[i];
                minInd=i;
            }
            if(nums[i]>maxi){
                maxi=nums[i];
                maxInd=i;
            }
        }
        int ans=n;
        ans=1+max(minInd,maxInd);
        ans=min(ans,n-min(minInd,maxInd));
        ans=min(ans,min(minInd,maxInd)+1+n-max(minInd,maxInd));
        return ans;
    }
};