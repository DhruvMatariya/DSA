class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
      int prev=0;
      int prevOfPrev=0;
      int cnt1=0,cnt0=0;
      int maxi=0;
      for(int i=0;i<s.size();){
        if(s[i]=='1'){
             cnt1++;
             i++;
        }
        else{
            while(i<s.size() && s[i]=='0') 
            {cnt0++;
            i++;
            }
            prevOfPrev=prev;
             prev=cnt0;
             cnt0=0;
             maxi=max(maxi,prev+prevOfPrev);
             
        }
      }
             if(prevOfPrev==0) return cnt1;
      return maxi+cnt1;
    }
};