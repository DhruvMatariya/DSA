class Solution {
public:
    string rearrangeString(string s, char x, char y) {
                          int cnt=0;
                          string t="";
                          for(int i=0;i<s.size();i++){
                            if(s[i]==x) cnt++;
                            else t+=s[i];
                          }      
                          while(cnt){
                            t+=x;
                            cnt--;
                          }    
                          return t;
    }
};