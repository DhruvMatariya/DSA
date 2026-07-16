class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
                    vector<int>prefixGcd(n,0);
                    int maxi=nums[0];
                    for(int i=0;i<n;i++){
                        maxi=max(maxi,nums[i]);
                        prefixGcd[i]=__gcd(maxi,nums[i]);
                    }
                    sort(prefixGcd.rbegin(),prefixGcd.rend());
                    int left=0;
                    int right=n-1;
                    long long sum=0;
                    while(left<right){
                    sum+=(__gcd(prefixGcd[left],prefixGcd[right]));
                    left++;
                    right--;
                    }       
                    return sum;         
    }
};