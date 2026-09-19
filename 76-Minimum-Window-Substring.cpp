class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mpp;
        int n=s.size();
        int l=0,r=0;
        int minLen=INT_MAX;
        int cnt=0,sIndex=-1;
        for(auto ch: t) mpp[ch]++;
        while(r<n){
           if(mpp[s[r]]>0){
            cnt++;
           }
            mpp[s[r]]--;
           while(cnt==t.size()){
            if((r-l+1)<minLen){
                minLen=r-l+1;
                sIndex=l;
            }
            mpp[s[l]]++;
            if(mpp[s[l]]>0) cnt--;
            l++;
           }
           r++;
        }
        return minLen==INT_MAX?"":s.substr(sIndex,minLen);
    }
};