class Solution {
public:
bool isValid(int mid,vector<int>&nums,int limit){
 int ans=0;
 for(auto it:nums){
    ans+=((it+mid-1)/mid);
 }
 return ans<=limit;
}
  int smallestDivisor(vector<int> &nums, int limit) {
       int low=1;
       int high=*max_element(nums.begin(),nums.end());
       while(low<=high){
         int mid=low+(high-low)/2;
         if(isValid(mid,nums,limit)){
            high=mid-1;
         }
         else{
            low=mid+1;
         }
       }
       return low;
    }
};