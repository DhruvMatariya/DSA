class Solution {
public:
int sum(vector<int> &nums, int limit,int mid){
    long long ans=0;
    for(int i=0;i<nums.size();i++){
        ans += (nums[i] + mid - 1) / mid;

    }
    if(ans<=limit) return 1;
    else return 0;
  }
int minimumRateToEatBananas(vector<int> nums, int h) {
   int maxi=*max_element(nums.begin(),nums.end());
       int low=1,high=maxi;
       while(low<=high){
        int mid=(low+high)/2;
        if(sum(nums,h,mid)) high=mid-1;
        else low=mid+1;
       }
       return low;
    }
};
