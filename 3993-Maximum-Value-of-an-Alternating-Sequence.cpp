class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if(n==1) return s;
        if(n%2==1){
            return s+1LL*m*(n/2)-(n/2-1);
        }
        else{
            return s+1LL*m*(n/2)-(n/2-1);
        }
    }
};