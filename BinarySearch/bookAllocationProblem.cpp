class Solution {
public:
int isValid(vector<int> &nums, int m,int mid){
    int n=nums.size();
    int students=1;
    int pages=0;
    for(int i=0;i<n;i++){
       if(pages+nums[i]<=mid){
        pages+=nums[i];
       }
       else{
       pages=nums[i];
       students++;
       }
    }
    return students<=m;
}
    int findPages(vector<int> &nums, int m)  {
        if(m > nums.size()) return -1;
   int low=*max_element(nums.begin(),nums.end());
   int high=accumulate(nums.begin(),nums.end(),0);
   while(low<=high){
    int mid=low+(high-low)/2;
  if(isValid(nums,m,mid)){
    high=mid-1;
  }
  else{
    low=mid+1;
  }
   }
   return low;
    }
};