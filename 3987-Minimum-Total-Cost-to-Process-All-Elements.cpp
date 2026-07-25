class Solution {
public:
int mod=1e9+7;
    int minimumCost(vector<int>& nums, int k) {
        long long cnt=0;
        long long res=k;
        long long cost=0;
        for(auto it: nums){
            if(it>res){
                long long req=it-res;
                long long ops=(req+k-1)/k;
                cnt+=ops;
                res+=ops*1LL*k;
            }
            res-=it;
        }
        if(cnt%2==0){
            return ((cnt/2)%mod)*((cnt+1)%mod)%mod;
        }
        return (cnt%mod)*(((cnt+1)/2)%mod)%mod;
    }
};