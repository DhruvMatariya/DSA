class Solution {
public:
bool isJoinerHyphen(string &s, int i) {
    return s[i] == '-' &&
           i > 0 &&
           i + 1 < s.size() &&
           s[i - 1] >= 'a' && s[i - 1] <= 'z' &&
           s[i + 1] >= 'a' && s[i + 1] <= 'z';
}
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        unordered_map<string,int>mpp;
        string s="";
        for(auto &x: chunks) s+=x;
        int n=s.size();
        string x="";
        for(int i=0;i<n;i++){
            if (s[i] >= 'a' && s[i] <= 'z') {
        x += s[i];
    }
    else if (isJoinerHyphen(s, i)) {
        x += '-';
    }
    else {
        if (!x.empty()) {
            mpp[x]++;
            x.clear();
        }
    }
        }
         if (!x.empty()) {
            mpp[x]++;
        }
        vector<int>ans;
        for(auto &it: queries){
ans.push_back(mpp[it]);
        }
        return ans;
    }
};