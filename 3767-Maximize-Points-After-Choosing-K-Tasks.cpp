#define P pair<int,int>
class Solution {
public:
    long long maxPoints(vector<int>& t1, vector<int>& t2, int k) {
        priority_queue<P,vector<P>,greater<P>>pq;
        int n=t1.size();
        long long ans=0;
        for(int i=0;i<n;i++){
            if(t1[i]>=t2[i]){
                ans+=t1[i];
                k--;
            }
            else{
                ans+=t2[i];
                pq.push({t2[i]-t1[i],i});
            }
        }
        while(k>0 && !pq.empty()){
            auto p=pq.top();
            pq.pop();
            ans-=p.first;
            k--;
        }
        return ans;
    }
};