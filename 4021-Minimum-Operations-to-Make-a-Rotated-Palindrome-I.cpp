class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        int mini=1e9;
        for(int i=0;i<n;i++){
            int costs=i;
            int left=0;
            int right=n-1;
            while(left<=right){
                int idx1=(left+i)%n;
                int idx2=(right+i)%n;
                int diff=abs(s[idx1]-s[idx2]);
                costs+=min(diff,26-diff);
                left++;
                right--;
            }
            mini=min(mini,costs);
        }
        return mini;
    }
};