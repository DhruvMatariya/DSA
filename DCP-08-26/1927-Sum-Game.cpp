class Solution {
public:
    bool sumGame(string nums) {
        int n=nums.size();
        int left=0;
        int right=0;
        int s1=0,s2=0;
        for(int i=0;i<n;i++){
            if(i<n/2){
             if(nums[i]!='?') left+=nums[i]-'0';
             else s1++;
            }
            else{
            if(nums[i]!='?') right+=nums[i]-'0';
             else s2++;
            }
        }
        if((s1+s2)%2==1) return true;
        if((left-right)==((s2-s1)/2)*9) return false;
        return true;
    }
};