class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) return n;
        else if(n==3) return 4;
        for(int i=4;i<=140000;i=i*2){
            if(n<i) return i;
        } 
        return -1;
    }
};